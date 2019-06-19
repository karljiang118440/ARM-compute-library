/*
 * Copyright (c) 2016-2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "arm_compute/runtime/NEON/NEFunctions.h"

#include "arm_compute/core/Types.h"
#include "utils/ImageLoader.h"
#include "utils/Utils.h"

// define HOG

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <arm_compute/runtime/NEON/NEFunctions.h>
#include <arm_compute/runtime/HOG.h>
#include <arm_compute/core/Types.h>

using namespace arm_compute;
using namespace std;
using namespace cv;






using namespace arm_compute;
using namespace utils;

class NEHOGDescriptorExample : public Example

{


//for ComputeLibrary hog computing
     int x, y;
    // int width  = img.cols;
    // int height = img.rows;
     //int nchannels =  img.channels();

     int width  = 640;
     int height = 320;
     int nchannels =  3;

	cv::Mat img = imread("IMG_3824.JPG");

    uint8_t *src_data = (uint8_t*)img.data;

   // uint8_t *src1_data = new uint8_t[width*height];
    Size2D  detection_window_size = Size2D(64,64);
    Size2D  block_size = Size2D(16,16);
    Size2D  block_stride = Size2D(8,8);
    Size2D  cell_size = Size2D(8,8);



    HOG *hog = new HOG();
    HOGInfo hogInfo;
    hogInfo.init(cell_size,block_size,detection_window_size,block_stride, nbins,HOGNormType::L2HYS_NORM, 0.2f, PhaseType::UNSIGNED);
    hog->init(hogInfo);

    Size2D num_cells_per_block(hogInfo.block_size().width / hogInfo.cell_size().width,
                                         hogInfo.block_size().height / hogInfo.cell_size().height);
    size_t num_channels = (nbins * num_cells_per_block.width * num_cells_per_block.height);
  
    size_t block_num = ((detection_window_size.width-block_size.width)/(block_stride.width)+1)* ((detection_window_size.height-block_size.height)/(block_stride.height)+1);
    size_t HogDimensions = block_num*num_channels;
    float *dst_data = new float[HogDimensions];





public:
    bool do_setup(int argc, char **argv) override
    {
        /** [Accurate padding] **/
        PPMLoader ppm;

        if(argc < 2)
        {
            // Print help
            std::cout << "Usage: ./build/neon_convolution [input_image.ppm]\n\n";
            std::cout << "No input_image provided, creating a dummy 640x480 image\n";
            // Initialize just the dimensions and format of your buffers:
            src.allocator()->init(TensorInfo(640, 480, Format::U8));
        }
        else
        {
            ppm.open(argv[1]);
            // Initialize just the dimensions and format of your buffers:
            ppm.init_image(src, Format::U8);
        }

        // Initialize just the dimensions and format of the temporary and destination images:
        //tmp.allocator()->init(*src.info());

		const TensorShape shape_(block_num,1);	  //here I don't know how to  Initialize the TensorShape for output Tensor
		dst.allocator()->init(TensorInfo(shape_, num_channels, arm_compute::DataType::F32));
		
		
		

         // Apply a Gaussian 3x3 filter to the source image followed by a Gaussian 5x5:
        // The function will automatically update the padding information inside input and output to match its requirements
	   // gaus5x5.configure(&src, &dst, 100, 80, 3, 1, BorderMode::REPLICATE);
		HOGDescriptor.configure(&src,&dst,hog,BorderMode::REPLICATE,0);		 

        // Now that the padding requirements are known we can allocate the images:
        src.allocator()->allocate();
       // tmp.allocator()->allocate();
        dst.allocator()->allocate();

        // Fill the input image with the content of the PPM image if a filename was provided:
        if(ppm.is_open())
        {
            ppm.fill_image(src);
            //output_filename = std::string(argv[1]) + "_NEConvolution3x3.ppm";
			output_filename = "NEHOGDescriptor.ppm";
        }
        /** [Accurate padding] **/

        return true;
    }
    void do_run() override
    {


    Window input_window;
    input_window.use_tensor_dimensions(input.info());
   
    // Create an iterator:
    Iterator input_it(&input, input_window);

    // Except it works for an arbitrary number of dimensions
    execute_window_loop(input_window, [&](const Coordinates & id)
    {
        // std::cout << "Setting item [" << id.x() << "," << id.y() << "," << id.z() << "]\n";
        *reinterpret_cast<uint8_t *>(input_it.ptr()) = src_data[id.z() * (width_ * height_) + id.y() * width_ + id.x()];
    },
    input_it);

	
        //Execute the functions:
        HOGDescriptor.run();
		
		Window output_window;
		output_window.use_tensor_dimensions(output.info(), /* first_dimension =*/Window::DimY); 
		
		// Create an iterator:
		Iterator output_it(&output, output_window);
		
		execute_window_loop(output_window, [&](const Coordinates & id)
		{
			// Copy one whole row:
			memcpy(dst_data + id.z() * (width * height) + id.y() * width, output_it.ptr(), width * sizeof(float));
		},
		output_it);

		for(int i = 0;i<HogDimensions;i++)
		{
			std::cout<<(float)dst_data[i]<<"  ";
		}


#if 0		
			delete	hog; 
			delete [] src1_data;
			delete [] dst_data;

#endif		


    }
    void do_teardown() override
    {
        // Save the result to file:
        if(!output_filename.empty())
        {
            save_to_ppm(dst, output_filename); // save_to_ppm maps and unmaps the image to store as PPM
        }
    }

private:
    Image            src{},  dst{};
	NEHOGDescriptor       HOGDescriptor{};
    std::string      output_filename{};
};

/** Main program for convolution test
 *
 * @param[in] argc Number of arguments
 * @param[in] argv Arguments ( [optional] Path to PPM image to process )
 */
int main(int argc, char **argv)
{
    return utils::run_example<NEHOGDescriptorExample>(argc, argv);
}
