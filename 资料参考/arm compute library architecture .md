

.
������ arm_compute --> All the arm_compute headers
��   ������ core
��   ��   ������ CL
��   ��   ��   ������ CLKernelLibrary.h --> Manages all the OpenCL kernels compilation and caching, provides accessors for the OpenCL Context.
��   ��   ��   ������ CLKernels.h --> Includes all the OpenCL kernels at once
��   ��   ��   ������ CL specialisation of all the generic objects interfaces (ICLTensor, ICLImage, etc.)
��   ��   ��   ������ kernels --> Folder containing all the OpenCL kernels
��   ��   ��   ��   ������ CL*Kernel.h
��   ��   ��   ������ OpenCL.h --> Wrapper to configure the Khronos OpenCL C++ header
��   ��   ������ CPP
��   ��   ��   ������ CPPKernels.h --> Includes all the CPP kernels at once
��   ��   ��   ������ kernels --> Folder containing all the CPP kernels
��   ��   ��       ������ CPP*Kernel.h
��   ��   ������ GLES_COMPUTE
��   ��   ��   ������ GCKernelLibrary.h --> Manages all the GLES kernels compilation and caching, provides accessors for the GLES Context.
��   ��   ��   ������ GCKernels.h --> Includes all the GLES kernels at once
��   ��   ��   ������ GLES specialisation of all the generic objects interfaces (IGCTensor, IGCImage, etc.)
��   ��   ��   ������ kernels --> Folder containing all the GLES kernels
��   ��   ��   ��   ������ GC*Kernel.h
��   ��   ��   ������ OpenGLES.h --> Wrapper to configure the Khronos EGL and OpenGL ES C header
��   ��   ������ NEON
��   ��   ��   ������ kernels --> Folder containing all the NEON kernels
��   ��   ��   ��   ������ assembly --> headers for assembly optimised NEON kernels.
��   ��   ��   ��   ������ convolution --> headers for convolution assembly optimised NEON kernels.
��   ��   ��   ��   ��   ������ common --> headers for code which is common to several convolution implementations.
��   ��   ��   ��   ��   ������ depthwise --> headers for Depthwise convolultion assembly implementation
��   ��   ��   ��   ��   ������ winograd --> headers for Winograd convolution assembly implementation
��   ��   ��   ��   ������ detail --> Common code for several intrinsics implementations.
��   ��   ��   ��   ������ NE*Kernel.h
��   ��   ��   ������ NEKernels.h --> Includes all the NEON kernels at once
��   ��   ������ All common basic types (Types.h, Window, Coordinates, Iterator, etc.)
��   ��   ������ All generic objects interfaces (ITensor, IImage, etc.)
��   ��   ������ Objects metadata classes (ImageInfo, TensorInfo, MultiImageInfo)
��   ������ graph
��   ��   ������ algorithms
��   ��   ��   ������ Generic algorithms used by the graph backend (e.g Order of traversal)
��   ��   ������ backends --> The backend specific code
��   ��   ��   ������ CL --> OpenCL specific operations
��   ��   ��   ������ GLES  --> OpenGLES Compute Shaders specific operations
��   ��   ��   ������ NEON --> NEON specific operations
��   ��   ������ detail
��   ��   ��   ������ Collection of internal utilities.
��   ��   ������ frontend
��   ��   ��   ������ Code related to the stream frontend interface.
��   ��   ������ mutators
��   ��   ��   ������ Used to modify / optimise the Graph intermediate representation(Operator fusion, in place operations, etc.)
��   ��   ������ nodes
��   ��   ��   ������ The various nodes supported by the graph API
��   ��   ������ printers
��   ��   ��   ������ Debug printers
��   ��   ������ Graph objects ( INode, ITensorAccessor, Graph, etc.)
��   ������ runtime
��       ������ CL
��       ��   ������ CL objects & allocators (CLArray, CLImage, CLTensor, etc.)
��       ��   ������ functions --> Folder containing all the OpenCL functions
��       ��   ��   ������ CL*.h
��       ��   ������ CLScheduler.h --> Interface to enqueue OpenCL kernels and get/set the OpenCL CommandQueue and ICLTuner.
��       ��   ������ CLFunctions.h --> Includes all the OpenCL functions at once
��       ��   ������ tuners
��       ��       ������ Local workgroup size tuners for specific architectures / GPUs
��       ������ CPP
��       ��   ������ CPPKernels.h --> Includes all the CPP functions at once.
��       ��   ������ CPPScheduler.h --> Basic pool of threads to execute CPP/NEON code on several cores in parallel
��       ��   ������ functions --> Folder containing all the CPP functions
��       ��       ������ CPP*.h
��       ������ GLES_COMPUTE
��       ��   ������ GLES objects & allocators (GCArray, GCImage, GCTensor, etc.)
��       ��   ������ functions --> Folder containing all the GLES functions
��       ��   ��   ������ GC*.h
��       ��   ������ GCScheduler.h --> Interface to enqueue GLES kernels and get/set the GLES CommandQueue.
��       ��   ������ GCFunctions.h --> Includes all the GLES functions at once
��       ������ NEON
��       ��   ������ functions --> Folder containing all the NEON functions
��       ��   ��   ������ NE*.h
��       ��   ������ NEFunctions.h --> Includes all the NEON functions at once
��       ������ OMP
��       ��   ������ OMPScheduler.h --> OpenMP scheduler (Alternative to the CPPScheduler)
��       ������ Memory manager files (LifetimeManager, PoolManager, etc.)
��       ������ Basic implementations of the generic object interfaces (Array, Image, Tensor, etc.)
������ data -> Contains test images and reference data dumps used by validation tests
������ docs -> Contains Doxyfile and Doxygen sources used to generate the HTML pages in the documentation folder.
������ documentation
��   ������ index.xhtml
��   ������ ...
������ documentation.xhtml -> documentation/index.xhtml
������ examples
��   ������ cl_*.cpp --> OpenCL examples
��   ������ gc_*.cpp --> GLES compute shaders examples
��   ������ graph_*.cpp --> Graph examples
��   ������ neoncl_*.cpp --> NEON / OpenCL interoperability examples
��   ������ neon_*.cpp --> NEON examples
������ graph.h --> Includes all the Graph headers at once.
������ include
��   ������ CL
��   ��   ������ Khronos OpenCL C headers and C++ wrapper
��   ������ half --> FP16 library available from http://half.sourceforge.net
��   ������ libnpy --> Library to load / write npy buffers, available from https://github.com/llohse/libnpy
��   ������ linux --> Headers only needed for Linux builds
��       ������ Khronos EGL and OpenGLES headers
������ opencl-1.2-stubs
��   ������ opencl_stubs.c --> OpenCL stubs implementation
������ opengles-3.1-stubs
��   ������ EGL.c --> EGL stubs implementation
��   ������ GLESv2.c --> GLESv2 stubs implementation
������ scripts
��   ������ caffe_data_extractor.py --> Basic script to export weights from Caffe to npy files
��   ������ tensorflow_data_extractor.py --> Basic script to export weights from Tensor Flow to npy files
������ src
��   ������ core
��   ��   ������ ... (Same structure as headers)
��   ��       ������ CL
��   ��       ��   ������ cl_kernels --> All the OpenCL kernels
��   ��       ������ GLES_COMPUTE
��   ��           ������ cs_shaders --> All the OpenGL ES Compute Shaders
��   ������ graph
��   ��   ������ ... (Same structure as headers)
��   ������ runtime
��       ������ ... (Same structure as headers)
������ support
��   ������ Various headers to work around toolchains / platform issues.
������ tests
��   ������ All test related files shared between validation and benchmark
��   ������ benchmark --> Sources for benchmarking
��   ��   ������ Benchmark specific files
��   ��   ������ fixtures
��   ��   ��   ������ Backend agnostic fixtures to initialise and run the functions to test.
��   ��   ������ CL --> OpenCL benchmarking tests
��   ��   ������ GLES_COMPUTE --> GLES benchmarking tests
��   ��   ������ NEON --> NEON benchmarking tests
��   ������ CL --> OpenCL accessors
��   ������ GLES_COMPUTE --> GLES accessors
��   ������ NEON --> NEON accessors
��   ������ datasets
��   ��   ������ Datasets for all the validation / benchmark tests, layer configurations for various networks, etc.
��   ������ framework
��   ��   ������ Boiler plate code for both validation and benchmark test suites (Command line parsers, instruments, output loggers, etc.)
��   ������ networks
��   ��   ������ Examples of how to instantiate networks.
��   ������ validation --> Sources for validation
��       ������ Validation specific files
��       ������ fixtures
��       ��   ������ Backend agnostic fixtures to initialise and run the functions to test.
��       ������ reference
��       ��   ������ Reference implementation used to validate the results of the various backends.
��       ������ CL --> OpenCL validation tests
��       ������ GLES_COMPUTE --> GLES validation tests
��       ������ CPP --> C++ reference implementations
��       ������ NEON --> NEON validation tests
������ utils --> Boiler plate code used by examples
    ������ Various utilities to print types, load / store assets, etc.