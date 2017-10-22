# README #

This is the rendering code used to generate random scene description textfiles used in the paper:

* **[SceneNet RGB-D: Can 5M Synthetic Images Beat Generic ImageNet Pre-training on Indoor Segmentation?](http://www.imperial.ac.uk/media/imperial-college/research-centres-and-groups/dyson-robotics-lab/jmccormac_etal_iccv2017.pdf)**, *John McCormac, Ankur Handa, Stefan Leutenegger, Andrew J Davison*, ICCV '17

It is a modified version of the Opposite Renderer available [here](https://github.com/apartridge/OppositeRenderer).  A GPU with 8GB of memory was used for rendering.

# 1. How to build it? #

The following instructions have been tested on Arch linux, with gcc 7.2.0, CUDA 8.0.  For the CVD dependency a compiler that supports C++14 is required.

Dependenices are:

* CMake
* OpenGL
* GLUT
* [CUDA >= 8.0](https://developer.nvidia.com/cuda-downloads)
* [CVD](https://github.com/edrosten/libcvd)
* [Pangolin](https://github.com/stevenlovegrove/Pangolin)
* [ASSIMP](http://assimp.sourceforge.net/)
* Eigen
* [Optix](https://developer.nvidia.com/optix)

* Download and install the Optix framework (NVIDIA-OptiX-SDK-4.1.1) from the Nvidia website (you probably have to register with them) - point towards the folder it is installed in CMakeModules/FindOptiX.cmake.

```
set(OptiX_INSTALL_DIR "/your/folder/containing/Optix" CACHE PATH "Path to OptiX installed location.")
```

by default it assumes the Optix folder (i.e. containing lib64 and include directories), is in the main renderer folder (alongside the src directory)

## Make a build directory and build the project

```
mkdir build
cd build
cmake ..
make
```

## Other things


You can set the image resolution in the same scenenet\_render.cpp by
editing the WIDTH and HEIGHT variables

```
unsigned int BaseScene::WIDTH  = 320u;
unsigned int BaseScene::HEIGHT = 240u;
```

You can also change the quality of the rendering with the following variables
(higher number means higher quality)

```
m_renderer->setNumIterations(4);
m_renderer->setNumPhotonMaps(5);
```

Finally you can also edit the ppmRadius for the photon mapping to reduce the
circular artifacts (at the cost of slower rendering) in ```src/Renderer/OptixRenderer.cpp line 372```

```
  const float initppmRadius = 0.05; //0.01 is the original scenenet parameter
```
