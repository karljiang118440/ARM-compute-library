



#һ���ο�����

Compute Library	19.02

https://arm-software.github.io/ComputeLibrary/latest/#S3_1_build_options






#�������벽��

##1��Building for Linux
How to build the library ?
For Linux, the library was successfully built and tested using the following Linaro GCC toolchain:

gcc-linaro-4.9-2016.02-x86_64_arm-linux-gnueabihf
gcc-linaro-4.9-2016.02-x86_64_aarch64-linux-gnu



##2���������

scons Werror=1 -j8 debug=0 asserts=1 neon=0 opencl=0 gles_compute=1 embed_kernels=1 os=linux arch=arm64-v8a

> sudo apt  install scons #��װscons ���

> aarch64-linux-gnu-g++ -v # �鿴g++ �汾��Ϣ




aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I. -Iinclude -std=c++11 -L. -larm_compute -larm_compute_core -o neon_convolution

> larm_compute  -larm_compute_core ��Ϣ

> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH::/home/djiango/NEON/ComputeLibrary-master/build


