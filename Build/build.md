



#一、参考资料

Compute Library	19.02

https://arm-software.github.io/ComputeLibrary/latest/#S3_1_build_options






#二、编译步骤

##1、Building for Linux
How to build the library ?
For Linux, the library was successfully built and tested using the following Linaro GCC toolchain:

gcc-linaro-4.9-2016.02-x86_64_arm-linux-gnueabihf
gcc-linaro-4.9-2016.02-x86_64_aarch64-linux-gnu



##2、具体操作

scons Werror=1 -j8 debug=0 asserts=1 neon=0 opencl=0 gles_compute=1 embed_kernels=1 os=linux arch=arm64-v8a

> sudo apt  install scons #安装scons 组件

> aarch64-linux-gnu-g++ -v # 查看g++ 版本信息




aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I. -Iinclude -std=c++11 -L. -larm_compute -larm_compute_core -o neon_convolution

> larm_compute  -larm_compute_core 信息

> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH::/home/djiango/NEON/ComputeLibrary-master/build  
>:无法被使用，找不到对应的库文件。


##3、还是需要安装 -larm_compute -larm_compute_core 才能够用 ，参考之前添加第三方库的方法。

>


##4、重新选择编译方式

aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I. -Iinclude -std=c++11 -L /home/djiango/NEON/ComputeLibrary-master/build -larm_compute -larm_compute_core -o neon_convolution

>明显有效果了，和以前并不一样。但是又出现新问题。

##5、出现 undefined 的问题

是否是因为头文件的问题？并没有指定头文件？
aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I/home/djiango/NEON/ComputeLibrary-master/include -std=c++11 -L /home/djiango/NEON/ComputeLibrary-master/build -larm_compute -larm_compute_core -o neon_convolution
/home/djiango/NEON/ComputeLibrary-master/include
