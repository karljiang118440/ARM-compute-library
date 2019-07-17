#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <arm_compute/runtime/NEON/NEFunctions.h>
#include <arm_compute/runtime/HOG.h>
#include <arm_compute/core/Types.h>
#include <arm_compute/core/WindowIterator.h>
#include <vector>

using namespace arm_compute;
using namespace std;
using namespace cv;
using namespace std::chrono;


int main()
{


    cv::Mat img = imread("sample1.png");
    Mat gray;
    Mat reimg,img_pad;
    if(img.empty())
    {
        std::cout<<"error!"<<std::endl ;
        return 0;
    }
    resize(img,img,Size(80,80));
    cv::cvtColor(img,gray,CV_BGR2GRAY);
    int original_height=80;int original_width=80;

// for opencv hog computing

auto start=high_resolution_clock::now();
auto stop=high_resolution_clock::now();
auto duration=duration_cast<microseconds>(stop-start);
cout<<"opencvhog"<<duration.count()<<endl;
int width  = img.cols;
int height = img.rows;
double scale=0.8;
Size2D  detection_window_size = Size2D(80,80);
Size2D  block_size = Size2D(8,8);
Size2D  block_stride = Size2D(4,4);
Size2D  cell_size = Size2D(4,4);
size_t  nbins=6;
   
HOG *hog = new HOG();
HOGInfo hogInfo;
hogInfo.init(cell_size,block_size,detection_window_size,block_stride, nbins,HOGNormType::L2HYS_NORM, 0.2f, PhaseType::UNSIGNED);
hog->init(hogInfo);
double* inter_weights =new double;
int bb_num = 0;
float* weights=hog->descriptor();FILE* fp_load;
char filename[100];
char load[1000];
sprintf(filename,"weis.txt");
fp_load=fopen(filename,"r");
int ind=0;
while(!feof(fp_load))
  {
        fgets(load,sizeof(load),fp_load);
        //cout<<weights[ind];
        sscanf(load,"%lf\n",inter_weights);
        weights[ind]=(float)*inter_weights;
        //cout<<weights[ind]<<endl;
        ind++;
    } 

weights[ind]=(float)0.999710079;
Array<DetectionWindow>resultwindow((size_t)936);
DetectionWindow * acesswin=resultwindow.buffer();
start=high_resolution_clock::now();
//for ComputeLibrary hog computing
int cnt=0;int scaled_height,scaled_width,scaled_x,scaled_y;
while(width>100&& height>100)
{   
        
     int x, y;
     
     NEHOGDetector detectors; 
     
     for(int k=0;k<936;k++)
     acesswin[k].score=0;
     //resultwindow((size_t)936);
     int nchannels =  img.channels();

    uint8_t *src_data1 = (uint8_t*)gray.data;
    void *src_data = (void*)gray.data;
    
    //cout<<hogInfo.descriptor_size();
    NEHOGDescriptor HOGDescriptors;
    
    
    //auto inter_start=high_resolution_clock::now();
    Tensor   input,output,interinput;
    // Initialize the tensors dimensions and type:
    const TensorShape shape(width, height);
    
    input.allocator()->init(TensorInfo(shape,Format::U8));
    interinput.allocator()->init(TensorInfo(shape,Format::U8));
    input.allocator()->import_memory(src_data);
    TensorInfo tensor_info_hog_descriptor(hogInfo,width,height); 
    size_t num_cha=tensor_info_hog_descriptor.num_channels();
    TensorShape Spae=tensor_info_hog_descriptor.tensor_shape();
    TensorInfo output_info ;
    output_info.init(Spae,num_cha, arm_compute::DataType::F32);
    output.allocator()->init(output_info);
    // Configure HOGDescriptor:
    HOGDescriptors.configure(&input, &output,hog,BorderMode::REPLICATE,0);
    interinput.allocator()->allocate();
    NECopy crcopy;crcopy.configure(&input,&interinput);
    crcopy.run();
    output.allocator()->allocate();
    HOGDescriptors.run(); 
    detectors.configure(&output,hog,&resultwindow,Size2D(16,16),(float)0,(size_t)1);
    detectors.run();
    
    for (int k=0;k<936;k++)
    {
    if(acesswin[k].score>0)
    {
      cout<<endl<<acesswin[k].score<<"class"<<acesswin[k].idx_class<<endl;
    }  
        
    else
       break;
    }
    
    
    input.allocator()->free();output.allocator()->free(),interinput.allocator()->free();
    width=floor(width*scale);
    height=floor(height*scale);
    while((width-4)%8!=0)
        width--;
    while((height-4)%8!=0)
        height--;
   
    resize(gray,gray,Size(width,height));
    
    cnt++;
}

delete  hog;
stop=high_resolution_clock::now();
duration=duration_cast<microseconds>(stop-start);
cout<<duration.count()<<endl;
cout<<cnt;

}