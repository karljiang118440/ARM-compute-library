# 1、直接运行交叉编译的文件包括添加库


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/root/karl/ACL/build

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/root/karl/build


chmod a+x ./examples/graph_lenet
root@s32v234evb:~/karl# chmod a+x ACL*

root@s32v234evb:~/karl# chmod a+x build/




##1.1、Linux 给文件夹或者文件增加权限

chmod -R 777 文件夹
参数-R是递归的意思
777表示开放所有权限

 

chmod 777 test.sh

chmod +x 某文件

如果给所有人添加可执行权限：chmod a+x 文件名；
如果给文件所有者添加可执行权限：chmod u+x 文件名；
如果给所在组添加可执行权限：chmod g+x 文件名；
如果给所在组以外的人添加可执行权限：chmod o+x 文件名




##1.2、Test

./examples/graph_lenet

>运行结果如下：

Threads : 1
Target : NEON
Data type : F32
Data layout : NHWC
Tuner enabled? : false
Tuner file :
Fast math enabled? : false

Can't load libOpenCL.so: libOpenCL.so: cannot open shared object file: No such f                                                                             ile or directory
Can't load libGLES_mali.so: libGLES_mali.so: cannot open shared object file: No                                                                              such file or directory
Can't load libmali.so: libmali.so: cannot open shared object file: No such file                                                                              or directory
Couldn't find any OpenCL library.
!!!!!!!!!!!!!!!!!!!!!!!!!!!

ERROR in get_default_target src/graph/Utils.cpp:53: No backend exists!
!!!!!!!!!!!!!!!!!!!!!!!!!!!

Test FAILED






./build/examples/neon_cartoon_effect  school_bus.ppm

terminate called after throwing an instance of 'std::ios_base::failure'
  what():  basic_ios::clear
Aborted


./build/examples/neon_scale 128x128.ppm



./build/examples/neon_convolution




root@s32v234evb:~/karl/build/examples# ./neon_copy_objects

./neon_copy_objects

 Dimensions of the input's iterator:
 X = [start=0, end=4, step=1]
 Y = [start=0, end=3, step=1]
 Z = [start=0, end=2, step=1]
Setting item [0,0,0]
Setting item [1,0,0]
Setting item [2,0,0]
Setting item [3,0,0]
Setting item [0,1,0]
Setting item [1,1,0]
Setting item [2,1,0]
Setting item [3,1,0]
Setting item [0,2,0]
Setting item [1,2,0]
Setting item [2,2,0]
Setting item [3,2,0]
Setting item [0,0,1]
Setting item [1,0,1]
Setting item [2,0,1]
Setting item [3,0,1]
Setting item [0,1,1]
Setting item [1,1,1]
Setting item [2,1,1]
Setting item [3,1,1]
Setting item [0,2,1]
Setting item [1,2,1]
Setting item [2,2,1]
Setting item [3,2,1]
 Dimensions of the output's iterator:
 X = [start=0, end=1, step=1]
 Y = [start=0, end=3, step=1]
 Z = [start=0, end=2, step=1]
Copying one row starting from [0,0,0]
Copying one row starting from [0,1,0]
Copying one row starting from [0,2,0]
Copying one row starting from [0,0,1]
Copying one row starting from [0,1,1]
Copying one row starting from [0,2,1]

Test passed


>：可以默认为能够通过编译了在板子中。
其他的neon 工程都是能够编译通过的。




#2、add the libopencl.so

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/djiango/NEON/ComputeLibrary-master/build/opencl-1.2-stubs



#3、对 cl 的编译


root@s32v234evb:~/karl/build/examples# ./gc_absdiff

./gc_absdiff

Can't load libEGL.so: libGLESv3.so: cannot open shared object file: No such file
!!!!!!!!!!!!!!!!!!!!!!!!!!!

ERROR in setup_context src/runtime/GLES_COMPUTE/GCScheduler.cpp:88: Failed to ge
!!!!!!!!!!!!!!!!!!!!!!!!!!!

Test FAILED


root@s32v234evb:~/karl/build/examples# ./gc_dc

./gc_dc

Can't load libEGL.so: libGLESv3.so: cannot open shared object file: No such file or directory
!!!!!!!!!!!!!!!!!!!!!!!!!!!

ERROR in setup_context src/runtime/GLES_COMPUTE/GCScheduler.cpp:88: Failed to get display: 0x0.
!!!!!!!!!!!!!!!!!!!!!!!!!!!

Test FAILED


#4、graph 的运行

root@s32v234evb:~/karl/build/examples# ./graph_alexnet

./graph_alexnet

Threads : 1
Target : NEON
Data type : F32
Data layout : NHWC
Tuner enabled? : false
Tuner file :
Fast math enabled? : false

Can't load libEGL.so: libGLESv3.so: cannot open shared object file: No such file or directory

Test passed

>为何也是 Test passed?并没有使用到 OpenGL 最直观的解释。



root@s32v234evb:~/karl/build/examples# ./graph_vgg16

./graph_vgg16

Threads : 1
Target : NEON
Data type : F32
Data layout : NHWC
Tuner enabled? : false
Tuner file :
Fast math enabled? : false

Can't load libEGL.so: libGLESv3.so: cannot open shared object file: No such file or directory

Test passed


>基本上除了需要使用 opencl的东西以外其他的都是可以拿来直接使用的。