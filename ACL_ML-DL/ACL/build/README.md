# 1��ֱ�����н��������ļ�������ӿ�


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/root/karl/ACL/build

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/root/karl/build

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/root/karl/build/opengles-3.1-stubs


chmod a+x ./examples/graph_lenet
root@s32v234evb:~/karl# chmod a+x ACL*

root@s32v234evb:~/karl# chmod a+x build/




##1.1��Linux ���ļ��л����ļ�����Ȩ��

chmod -R 777 �ļ���
����-R�ǵݹ����˼
777��ʾ��������Ȩ��

 

chmod 777 test.sh

chmod +x ĳ�ļ�

�������������ӿ�ִ��Ȩ�ޣ�chmod a+x �ļ�����
������ļ���������ӿ�ִ��Ȩ�ޣ�chmod u+x �ļ�����
�������������ӿ�ִ��Ȩ�ޣ�chmod g+x �ļ�����
��������������������ӿ�ִ��Ȩ�ޣ�chmod o+x �ļ���




##1.2��Test

./examples/graph_lenet

>���н�����£�

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


>������Ĭ��Ϊ�ܹ�ͨ���������ڰ����С�
������neon ���̶����ܹ�����ͨ���ġ�




#2��add the libopencl.so

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/djiango/NEON/ComputeLibrary-master/build/opencl-1.2-stubs



#3���� cl �ı���


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


#4��graph ������

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

>Ϊ��Ҳ�� Test passed?��û��ʹ�õ� OpenGL ��ֱ�۵Ľ��͡�



##4.1���޸� graph �����ʽ

./graph_alexnet <target> <cnn_data> <input_image> <labels>


./build/examples/graph_alexnet 1 /home/root/karl/compute_library_alexnet /home/root/karl/compute_library_alexnet/go_kart.ppm /home/root/karl/compute_library_alexnet/labels.txt


./build/examples/graph_alexnet 0 /home/root/karl/compute_library_alexnet /home/root/karl/compute_library_alexnet/go_kart.ppm /home/root/karl/compute_library_alexnet/labels.txt





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


>�����ϳ�����Ҫʹ�� opencl�Ķ������������Ķ��ǿ�������ֱ��ʹ�õġ�


�ؼ��� libEGL.so �Ŀ��Ѿ����ڲ�Ӧ��û�У�����û���ܹ���λ�ĳ�����






#5��cpuinfo �鿴cpu ��Ϣ

cat /proc/cpuinfo

root@s32v234evb:~/karl# cat /proc/cpuinfo
processor       : 0
BogoMIPS        : 20.00
Features        : fp asimd evtstrm crc32
CPU implementer : 0x41
CPU architecture: 8
CPU variant     : 0x0
CPU part        : 0xd03
CPU revision    : 4

processor       : 1
BogoMIPS        : 20.00
Features        : fp asimd evtstrm crc32
CPU implementer : 0x41
CPU architecture: 8
CPU variant     : 0x0
CPU part        : 0xd03
CPU revision    : 4

processor       : 2
BogoMIPS        : 20.00
Features        : fp asimd evtstrm crc32
CPU implementer : 0x41
CPU architecture: 8
CPU variant     : 0x0
CPU part        : 0xd03
CPU revision    : 4

processor       : 3
BogoMIPS        : 20.00
Features        : fp asimd evtstrm crc32
CPU implementer : 0x41
CPU architecture: 8
CPU variant     : 0x0
CPU part        : 0xd03
CPU revision    : 4
