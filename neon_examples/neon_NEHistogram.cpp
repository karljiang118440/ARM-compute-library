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

using namespace arm_compute;
using namespace utils;

class NEGaussian5x5Example : public Example

//class NEONConvolutionExample : public Example
{
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
        dst.allocator()->init(*src.info());

         // Apply a Gaussian 3x3 filter to the source image followed by a Gaussian 5x5:
        // The function will automatically update the padding information inside input and output to match its requirements
	   // gaus5x5.configure(&src, &dst, 100, 80, 3, 1, BorderMode::REPLICATE);
		gaus5x5.configure(&src, &dst,  BorderMode::REPLICATE);

        // Now that the padding requirements are known we can allocate the images:
        src.allocator()->allocate();
       // tmp.allocator()->allocate();
        dst.allocator()->allocate();

        // Fill the input image with the content of the PPM image if a filename was provided:
        if(ppm.is_open())
        {
            ppm.fill_image(src);
            //output_filename = std::string(argv[1]) + "_NEConvolution3x3.ppm";
			output_filename = "NEGaussian5x5.ppm";
        }
        /** [Accurate padding] **/

        return true;
    }
    void do_run() override
    {
        //Execute the functions:
        CannyEdge.run();
       // conv5x5.run();
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
   // NEConvolution3x3 conv3x3{};
	NEGaussian5x5           gaus5x5{};
	
    std::string      output_filename{};
};

/** Main program for convolution test
 *
 * @param[in] argc Number of arguments
 * @param[in] argv Arguments ( [optional] Path to PPM image to process )
 */
int main(int argc, char **argv)
{
    return utils::run_example<NEGaussian5x5Example>(argc, argv);
}
