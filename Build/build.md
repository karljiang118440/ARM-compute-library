



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

scons Werror=1 -j8 debug=0 asserts=1 neon=1 opencl=0 gles_compute=1 embed_kernels=1 os=linux arch=arm64-v8a


###2.1、原来的neon==0，并没有生成 Neon 的可执行文件，neon=1→ neon=0

scons Werror=1 -j8 debug=0 asserts=1 neon=0 opencl=0 gles_compute=1 embed_kernels=1 os=linux arch=arm64-v8a

scons Werror=1 debug=0 asserts=0 neon=1 opencl=0 examples=1 build=native -j4

> sudo apt  install scons #安装scons 组件

> aarch64-linux-gnu-g++ -v # 查看g++ 版本信息



###2.2、原来的neon==0，并没有生成 Neon 的可执行文件，opencl=0→ opencl=1

scons Werror=1 -j8 debug=0 asserts=1 neon=1 opencl=1 gles_compute=1 embed_kernels=1 os=linux arch=arm64-v8a



aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I. -Iinclude -std=c++11 -L. -larm_compute -larm_compute_core -o neon_convolution

> larm_compute  -larm_compute_core 信息

> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH::/home/djiango/NEON/ComputeLibrary-master/build  
>:无法被使用，找不到对应的库文件。


##3、还是需要安装 -larm_compute -larm_compute_core 才能够用 ，参考之前添加第三方库的方法。

>


##4、重新选择编译方式

aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I. -Iinclude -std=c++11 -L /home/djiango/NEON/ComputeLibrary-master/build -larm_compute -larm_compute_core -o neon_convolution

>明显有效果了，和以前并不一样。但是又出现新问题。


###4.1、如果是编译器的问题，则重新指定 gcc 可以



##5、出现 undefined 的问题

是否是因为头文件的问题？并没有指定头文件？
aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I/home/djiango/NEON/ComputeLibrary-master/include -std=c++11 -L /home/djiango/NEON/ComputeLibrary-master/build -larm_compute -larm_compute_core -o neon_convolution

/home/djiango/NEON/ComputeLibrary-master/include





##6、执行编译的文件

###6.1、scons 未指定 gcc 版本时候需要确定编译器

aarch64-linux-gnu-g++ -o build/examples/neon_cnn build/examples/neon_cnn.o build/utils/Utils.o -Lbuild -L. -lpthread -larm_compute -larm_compute_core


>以上为使用 scons 进行编译的命令，如果使用的是指定的 aarch64-linux-gnu-g++ ，则可以看到则应该不会有任何的错误吧。

djiango@ubuntu:~/NEON/ComputeLibrary-master$ aarch64-linux-gnu-g++ -v
Using built-in specs.
COLLECT_GCC=aarch64-linux-gnu-g++
COLLECT_LTO_WRAPPER=/home/djiango/bsp15.0/gcc-linaro-4.9-2015.05-x86_64_aarch64-linux-gnu/bin/../libexec/gcc/aarch64-linux-gnu/4.9.3/lto-wrapper
Target: aarch64-linux-gnu
Configured with: /home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/snapshots/gcc-linaro-4.9-2015.05/configure SHELL=/bin/bash --with-bugurl=https://bugs.linaro.org --with-mpc=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu --with-mpfr=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu --with-gmp=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu --with-gnu-as --with-gnu-ld --disable-libstdcxx-pch --disable-libmudflap --with-cloog=no --with-ppl=no --with-isl=no --disable-nls --enable-c99 --with-arch=armv8-a --enable-fix-cortex-a53-835769 --enable-fix-cortex-a53-843419 --enable-multiarch --with-build-sysroot=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/sysroots/aarch64-linux-gnu --enable-lto --enable-linker-build-id --enable-long-long --enable-shared --with-sysroot=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu/aarch64-linux-gnu/libc --enable-languages=c,c++,fortran,lto --enable-checking=release --disable-bootstrap --with-bugurl=https://bugs.linaro.org --build=x86_64-unknown-linux-gnu --host=x86_64-unknown-linux-gnu --target=aarch64-linux-gnu --prefix=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu
Thread model: posix
gcc version 4.9.3 20150413 (prerelease) (Linaro GCC 4.9-2015.05) 

以上为所使用的编译器环境，明显能够看到并没有什么问题




#三、x86-64平台使用 ACL 的库并执行

##1、指定编译器



