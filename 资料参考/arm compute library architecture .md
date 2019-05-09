

.
©À©¤©¤ arm_compute --> All the arm_compute headers
©¦   ©À©¤©¤ core
©¦   ©¦   ©À©¤©¤ CL
©¦   ©¦   ©¦   ©À©¤©¤ CLKernelLibrary.h --> Manages all the OpenCL kernels compilation and caching, provides accessors for the OpenCL Context.
©¦   ©¦   ©¦   ©À©¤©¤ CLKernels.h --> Includes all the OpenCL kernels at once
©¦   ©¦   ©¦   ©À©¤©¤ CL specialisation of all the generic objects interfaces (ICLTensor, ICLImage, etc.)
©¦   ©¦   ©¦   ©À©¤©¤ kernels --> Folder containing all the OpenCL kernels
©¦   ©¦   ©¦   ©¦   ©¸©¤©¤ CL*Kernel.h
©¦   ©¦   ©¦   ©¸©¤©¤ OpenCL.h --> Wrapper to configure the Khronos OpenCL C++ header
©¦   ©¦   ©À©¤©¤ CPP
©¦   ©¦   ©¦   ©À©¤©¤ CPPKernels.h --> Includes all the CPP kernels at once
©¦   ©¦   ©¦   ©¸©¤©¤ kernels --> Folder containing all the CPP kernels
©¦   ©¦   ©¦       ©¸©¤©¤ CPP*Kernel.h
©¦   ©¦   ©À©¤©¤ GLES_COMPUTE
©¦   ©¦   ©¦   ©À©¤©¤ GCKernelLibrary.h --> Manages all the GLES kernels compilation and caching, provides accessors for the GLES Context.
©¦   ©¦   ©¦   ©À©¤©¤ GCKernels.h --> Includes all the GLES kernels at once
©¦   ©¦   ©¦   ©À©¤©¤ GLES specialisation of all the generic objects interfaces (IGCTensor, IGCImage, etc.)
©¦   ©¦   ©¦   ©À©¤©¤ kernels --> Folder containing all the GLES kernels
©¦   ©¦   ©¦   ©¦   ©¸©¤©¤ GC*Kernel.h
©¦   ©¦   ©¦   ©¸©¤©¤ OpenGLES.h --> Wrapper to configure the Khronos EGL and OpenGL ES C header
©¦   ©¦   ©À©¤©¤ NEON
©¦   ©¦   ©¦   ©À©¤©¤ kernels --> Folder containing all the NEON kernels
©¦   ©¦   ©¦   ©¦   ©À©¤©¤ assembly --> headers for assembly optimised NEON kernels.
©¦   ©¦   ©¦   ©¦   ©À©¤©¤ convolution --> headers for convolution assembly optimised NEON kernels.
©¦   ©¦   ©¦   ©¦   ©¦   ©À©¤©¤ common --> headers for code which is common to several convolution implementations.
©¦   ©¦   ©¦   ©¦   ©¦   ©À©¤©¤ depthwise --> headers for Depthwise convolultion assembly implementation
©¦   ©¦   ©¦   ©¦   ©¦   ©¸©¤©¤ winograd --> headers for Winograd convolution assembly implementation
©¦   ©¦   ©¦   ©¦   ©À©¤©¤ detail --> Common code for several intrinsics implementations.
©¦   ©¦   ©¦   ©¦   ©¸©¤©¤ NE*Kernel.h
©¦   ©¦   ©¦   ©¸©¤©¤ NEKernels.h --> Includes all the NEON kernels at once
©¦   ©¦   ©À©¤©¤ All common basic types (Types.h, Window, Coordinates, Iterator, etc.)
©¦   ©¦   ©À©¤©¤ All generic objects interfaces (ITensor, IImage, etc.)
©¦   ©¦   ©¸©¤©¤ Objects metadata classes (ImageInfo, TensorInfo, MultiImageInfo)
©¦   ©À©¤©¤ graph
©¦   ©¦   ©À©¤©¤ algorithms
©¦   ©¦   ©¦   ©¸©¤©¤ Generic algorithms used by the graph backend (e.g Order of traversal)
©¦   ©¦   ©À©¤©¤ backends --> The backend specific code
©¦   ©¦   ©¦   ©À©¤©¤ CL --> OpenCL specific operations
©¦   ©¦   ©¦   ©À©¤©¤ GLES  --> OpenGLES Compute Shaders specific operations
©¦   ©¦   ©¦   ©¸©¤©¤ NEON --> NEON specific operations
©¦   ©¦   ©À©¤©¤ detail
©¦   ©¦   ©¦   ©¸©¤©¤ Collection of internal utilities.
©¦   ©¦   ©À©¤©¤ frontend
©¦   ©¦   ©¦   ©¸©¤©¤ Code related to the stream frontend interface.
©¦   ©¦   ©À©¤©¤ mutators
©¦   ©¦   ©¦   ©¸©¤©¤ Used to modify / optimise the Graph intermediate representation(Operator fusion, in place operations, etc.)
©¦   ©¦   ©À©¤©¤ nodes
©¦   ©¦   ©¦   ©¸©¤©¤ The various nodes supported by the graph API
©¦   ©¦   ©À©¤©¤ printers
©¦   ©¦   ©¦   ©¸©¤©¤ Debug printers
©¦   ©¦   ©¸©¤©¤ Graph objects ( INode, ITensorAccessor, Graph, etc.)
©¦   ©¸©¤©¤ runtime
©¦       ©À©¤©¤ CL
©¦       ©¦   ©À©¤©¤ CL objects & allocators (CLArray, CLImage, CLTensor, etc.)
©¦       ©¦   ©À©¤©¤ functions --> Folder containing all the OpenCL functions
©¦       ©¦   ©¦   ©¸©¤©¤ CL*.h
©¦       ©¦   ©À©¤©¤ CLScheduler.h --> Interface to enqueue OpenCL kernels and get/set the OpenCL CommandQueue and ICLTuner.
©¦       ©¦   ©À©¤©¤ CLFunctions.h --> Includes all the OpenCL functions at once
©¦       ©¦   ©¸©¤©¤ tuners
©¦       ©¦       ©¸©¤©¤ Local workgroup size tuners for specific architectures / GPUs
©¦       ©À©¤©¤ CPP
©¦       ©¦   ©À©¤©¤ CPPKernels.h --> Includes all the CPP functions at once.
©¦       ©¦   ©À©¤©¤ CPPScheduler.h --> Basic pool of threads to execute CPP/NEON code on several cores in parallel
©¦       ©¦   ©¸©¤©¤ functions --> Folder containing all the CPP functions
©¦       ©¦       ©¸©¤©¤ CPP*.h
©¦       ©À©¤©¤ GLES_COMPUTE
©¦       ©¦   ©À©¤©¤ GLES objects & allocators (GCArray, GCImage, GCTensor, etc.)
©¦       ©¦   ©À©¤©¤ functions --> Folder containing all the GLES functions
©¦       ©¦   ©¦   ©¸©¤©¤ GC*.h
©¦       ©¦   ©À©¤©¤ GCScheduler.h --> Interface to enqueue GLES kernels and get/set the GLES CommandQueue.
©¦       ©¦   ©¸©¤©¤ GCFunctions.h --> Includes all the GLES functions at once
©¦       ©À©¤©¤ NEON
©¦       ©¦   ©À©¤©¤ functions --> Folder containing all the NEON functions
©¦       ©¦   ©¦   ©¸©¤©¤ NE*.h
©¦       ©¦   ©¸©¤©¤ NEFunctions.h --> Includes all the NEON functions at once
©¦       ©À©¤©¤ OMP
©¦       ©¦   ©¸©¤©¤ OMPScheduler.h --> OpenMP scheduler (Alternative to the CPPScheduler)
©¦       ©À©¤©¤ Memory manager files (LifetimeManager, PoolManager, etc.)
©¦       ©¸©¤©¤ Basic implementations of the generic object interfaces (Array, Image, Tensor, etc.)
©À©¤©¤ data -> Contains test images and reference data dumps used by validation tests
©À©¤©¤ docs -> Contains Doxyfile and Doxygen sources used to generate the HTML pages in the documentation folder.
©À©¤©¤ documentation
©¦   ©À©¤©¤ index.xhtml
©¦   ©¸©¤©¤ ...
©À©¤©¤ documentation.xhtml -> documentation/index.xhtml
©À©¤©¤ examples
©¦   ©À©¤©¤ cl_*.cpp --> OpenCL examples
©¦   ©À©¤©¤ gc_*.cpp --> GLES compute shaders examples
©¦   ©À©¤©¤ graph_*.cpp --> Graph examples
©¦   ©À©¤©¤ neoncl_*.cpp --> NEON / OpenCL interoperability examples
©¦   ©¸©¤©¤ neon_*.cpp --> NEON examples
©À©¤©¤ graph.h --> Includes all the Graph headers at once.
©À©¤©¤ include
©¦   ©À©¤©¤ CL
©¦   ©¦   ©¸©¤©¤ Khronos OpenCL C headers and C++ wrapper
©¦   ©À©¤©¤ half --> FP16 library available from http://half.sourceforge.net
©¦   ©À©¤©¤ libnpy --> Library to load / write npy buffers, available from https://github.com/llohse/libnpy
©¦   ©¸©¤©¤ linux --> Headers only needed for Linux builds
©¦       ©¸©¤©¤ Khronos EGL and OpenGLES headers
©À©¤©¤ opencl-1.2-stubs
©¦   ©¸©¤©¤ opencl_stubs.c --> OpenCL stubs implementation
©À©¤©¤ opengles-3.1-stubs
©¦   ©À©¤©¤ EGL.c --> EGL stubs implementation
©¦   ©¸©¤©¤ GLESv2.c --> GLESv2 stubs implementation
©À©¤©¤ scripts
©¦   ©À©¤©¤ caffe_data_extractor.py --> Basic script to export weights from Caffe to npy files
©¦   ©¸©¤©¤ tensorflow_data_extractor.py --> Basic script to export weights from Tensor Flow to npy files
©À©¤©¤ src
©¦   ©À©¤©¤ core
©¦   ©¦   ©¸©¤©¤ ... (Same structure as headers)
©¦   ©¦       ©À©¤©¤ CL
©¦   ©¦       ©¦   ©¸©¤©¤ cl_kernels --> All the OpenCL kernels
©¦   ©¦       ©¸©¤©¤ GLES_COMPUTE
©¦   ©¦           ©¸©¤©¤ cs_shaders --> All the OpenGL ES Compute Shaders
©¦   ©À©¤©¤ graph
©¦   ©¦   ©¸©¤©¤ ... (Same structure as headers)
©¦   ©¸©¤©¤ runtime
©¦       ©¸©¤©¤ ... (Same structure as headers)
©À©¤©¤ support
©¦   ©¸©¤©¤ Various headers to work around toolchains / platform issues.
©À©¤©¤ tests
©¦   ©À©¤©¤ All test related files shared between validation and benchmark
©¦   ©À©¤©¤ benchmark --> Sources for benchmarking
©¦   ©¦   ©À©¤©¤ Benchmark specific files
©¦   ©¦   ©À©¤©¤ fixtures
©¦   ©¦   ©¦   ©¸©¤©¤ Backend agnostic fixtures to initialise and run the functions to test.
©¦   ©¦   ©À©¤©¤ CL --> OpenCL benchmarking tests
©¦   ©¦   ©À©¤©¤ GLES_COMPUTE --> GLES benchmarking tests
©¦   ©¦   ©¸©¤©¤ NEON --> NEON benchmarking tests
©¦   ©À©¤©¤ CL --> OpenCL accessors
©¦   ©À©¤©¤ GLES_COMPUTE --> GLES accessors
©¦   ©À©¤©¤ NEON --> NEON accessors
©¦   ©À©¤©¤ datasets
©¦   ©¦   ©¸©¤©¤ Datasets for all the validation / benchmark tests, layer configurations for various networks, etc.
©¦   ©À©¤©¤ framework
©¦   ©¦   ©¸©¤©¤ Boiler plate code for both validation and benchmark test suites (Command line parsers, instruments, output loggers, etc.)
©¦   ©À©¤©¤ networks
©¦   ©¦   ©¸©¤©¤ Examples of how to instantiate networks.
©¦   ©¸©¤©¤ validation --> Sources for validation
©¦       ©À©¤©¤ Validation specific files
©¦       ©À©¤©¤ fixtures
©¦       ©¦   ©¸©¤©¤ Backend agnostic fixtures to initialise and run the functions to test.
©¦       ©À©¤©¤ reference
©¦       ©¦   ©¸©¤©¤ Reference implementation used to validate the results of the various backends.
©¦       ©À©¤©¤ CL --> OpenCL validation tests
©¦       ©À©¤©¤ GLES_COMPUTE --> GLES validation tests
©¦       ©À©¤©¤ CPP --> C++ reference implementations
©¦       ©¸©¤©¤ NEON --> NEON validation tests
©¸©¤©¤ utils --> Boiler plate code used by examples
    ©¸©¤©¤ Various utilities to print types, load / store assets, etc.