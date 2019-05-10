



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

scons Werror=1 -j8 debug=0 asserts=1 neon=1 opencl=0 gles_compute=1 embed_kernels=1 os=linux arch=arm64-v8a


###2.1��ԭ����neon==0����û������ Neon �Ŀ�ִ���ļ���neon=1�� neon=0

scons Werror=1 -j8 debug=0 asserts=1 neon=0 opencl=0 gles_compute=1 embed_kernels=1 os=linux arch=arm64-v8a

scons Werror=1 debug=0 asserts=0 neon=1 opencl=0 examples=1 build=native -j4

> sudo apt  install scons #��װscons ���

> aarch64-linux-gnu-g++ -v # �鿴g++ �汾��Ϣ



###2.2��ԭ����neon==0����û������ Neon �Ŀ�ִ���ļ���opencl=0�� opencl=1

scons Werror=1 -j8 debug=0 asserts=1 neon=1 opencl=1 gles_compute=1 embed_kernels=1 os=linux arch=arm64-v8a



aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I. -Iinclude -std=c++11 -L. -larm_compute -larm_compute_core -o neon_convolution

> larm_compute  -larm_compute_core ��Ϣ

> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH::/home/djiango/NEON/ComputeLibrary-master/build  
>:�޷���ʹ�ã��Ҳ�����Ӧ�Ŀ��ļ���


##3��������Ҫ��װ -larm_compute -larm_compute_core ���ܹ��� ���ο�֮ǰ��ӵ�������ķ�����

>


##4������ѡ����뷽ʽ

aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I. -Iinclude -std=c++11 -L /home/djiango/NEON/ComputeLibrary-master/build -larm_compute -larm_compute_core -o neon_convolution

>������Ч���ˣ�����ǰ����һ���������ֳ��������⡣


###4.1������Ǳ����������⣬������ָ�� gcc ����



##5������ undefined ������

�Ƿ�����Ϊͷ�ļ������⣿��û��ָ��ͷ�ļ���
aarch64-linux-gnu-g++ examples/neon_convolution.cpp utils/Utils.cpp -I/home/djiango/NEON/ComputeLibrary-master/include -std=c++11 -L /home/djiango/NEON/ComputeLibrary-master/build -larm_compute -larm_compute_core -o neon_convolution

/home/djiango/NEON/ComputeLibrary-master/include





##6��ִ�б�����ļ�

###6.1��scons δָ�� gcc �汾ʱ����Ҫȷ��������

aarch64-linux-gnu-g++ -o build/examples/neon_cnn build/examples/neon_cnn.o build/utils/Utils.o -Lbuild -L. -lpthread -larm_compute -larm_compute_core


>����Ϊʹ�� scons ���б����������ʹ�õ���ָ���� aarch64-linux-gnu-g++ ������Կ�����Ӧ�ò������κεĴ���ɡ�

djiango@ubuntu:~/NEON/ComputeLibrary-master$ aarch64-linux-gnu-g++ -v
Using built-in specs.
COLLECT_GCC=aarch64-linux-gnu-g++
COLLECT_LTO_WRAPPER=/home/djiango/bsp15.0/gcc-linaro-4.9-2015.05-x86_64_aarch64-linux-gnu/bin/../libexec/gcc/aarch64-linux-gnu/4.9.3/lto-wrapper
Target: aarch64-linux-gnu
Configured with: /home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/snapshots/gcc-linaro-4.9-2015.05/configure SHELL=/bin/bash --with-bugurl=https://bugs.linaro.org --with-mpc=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu --with-mpfr=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu --with-gmp=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu --with-gnu-as --with-gnu-ld --disable-libstdcxx-pch --disable-libmudflap --with-cloog=no --with-ppl=no --with-isl=no --disable-nls --enable-c99 --with-arch=armv8-a --enable-fix-cortex-a53-835769 --enable-fix-cortex-a53-843419 --enable-multiarch --with-build-sysroot=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/sysroots/aarch64-linux-gnu --enable-lto --enable-linker-build-id --enable-long-long --enable-shared --with-sysroot=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu/aarch64-linux-gnu/libc --enable-languages=c,c++,fortran,lto --enable-checking=release --disable-bootstrap --with-bugurl=https://bugs.linaro.org --build=x86_64-unknown-linux-gnu --host=x86_64-unknown-linux-gnu --target=aarch64-linux-gnu --prefix=/home/tcwg-buildslave/workspace/tcwg-make-release/label/tcwg-x86_64/target/aarch64-linux-gnu/_build/builds/destdir/x86_64-unknown-linux-gnu
Thread model: posix
gcc version 4.9.3 20150413 (prerelease) (Linaro GCC 4.9-2015.05) 

����Ϊ��ʹ�õı����������������ܹ�������û��ʲô����




#����x86-64ƽ̨ʹ�� ACL �ĿⲢִ��

##1��ָ��������



