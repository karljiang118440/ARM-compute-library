# 1��ֱ�����н��������ļ�������ӿ�


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/root/karl/ACL/build


chmod a+x ./examples/graph_lenet
root@s32v234evb:~/karl# chmod a+x ACL*


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
