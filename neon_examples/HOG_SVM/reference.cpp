#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <arm_compute/runtime/NEON/NEFunctions.h>
#include <arm_compute/runtime/HOG.h>
#include <arm_compute/core/Types.h>

using namespace arm_compute;
using namespace std;
using namespace cv;

double getTimeMillisecondMain();

int main()
{
    cv::Mat img = imread("IMG_3824.JPG");
    if(img.empty())
    {
        std::cout<<"error!"<<std::endl ;
        return 0;
    }

    cv::cvtColor(img,img,CV_RGB2GRAY);
    resize(img,img,cv::Size(width_,height_));

// for opencv hog computing
time = getTimeMillisecondMain();

HOGDescriptor hog(Size(64,64),Size(16,16),Size(8,8),Size(8,8),9);

vector<float> descriptors;

hog.compute(img,descriptors,Size(8,8), Size(0,0));

std::cout << "opencv  HOGDescriptor function takes   " << getTimeMillisecondMain()-time << " ms" << std::endl;


for(int i = 0;i<descriptors.size();i++)
{

    std::cout<<descriptors[i]<<" ";
}


//for ComputeLibrary hog computing
    int x, y;
     int width  = img.cols;
     int height = img.rows;
     int nchannels =  img.channels();

    uint8_t *src_data = (uint8_t*)img.data;

    uint8_t *src1_data = new uint8_t[width*height];
    Size2D  detection_window_size = Size2D(64,64);
    Size2D  block_size = Size2D(16,16);
    Size2D  block_stride = Size2D(8,8);
    Size2D  cell_size = Size2D(8,8);



    double start_t = getTimeMillisecondMain(); 

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


    std::cout<<"num_channels = "<<num_channels<<"  block_num = "<<block_num<<std::endl;


    Tensor   input, output;
    NEHOGDescriptor HOGDescriptor;
    
    // Initialize the tensors dimensions and type:
    const TensorShape shape(width, height);
    const TensorShape shape_(block_num,1);    //here I don't know how to  Initialize the TensorShape for output Tensor
    input.allocator()->init(TensorInfo(shape, 1, arm_compute::DataType::U8));

    // output.info()->set_format(arm_compute::Format::F32);
    output.allocator()->init(TensorInfo(shape_, num_channels, arm_compute::DataType::F32));


    // Configure HOGDescriptor:
    HOGDescriptor.configure(&input, &output,hog,BorderMode::REPLICATE,0);

    std::cout<<"HOGDescriptor.configure takes "<<getTimeMillisecondMain()-start_t<<" ms"<<std::endl;

    // Allocate the input / output tensors:
    input.allocator()->allocate();
    output.allocator()->allocate();



    start_t = getTimeMillisecondMain();


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



    std::cout<<"copy cpu memory to Itensor takes "<<getTimeMillisecondMain() - start_t<<" ms"<<std::endl;
    // Run NEON HOGDescriptor:
    HOGDescriptor.run();


    std::cout<<"HOGDescriptor.run takes "<<getTimeMillisecondMain()-start_t<<" ms"<<std::endl;


    start_t = getTimeMillisecondMain();
  
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
    
    std::cout<<"copy data to cpu memory takes "<<getTimeMillisecondMain()-start_t<<" ms"<<std::endl;



for(int i = 0;i<HogDimensions;i++)
{
    std::cout<<(float)dst_data[i]<<"  ";
}

    delete  hog; 
    delete [] src1_data;
    delete [] dst_data;

}