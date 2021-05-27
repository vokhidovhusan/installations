# LibTorch on WINDOWS 10
This instruction only for GPU-enabled libtorch installation.

### Prerequirements
1. CMake
2. Visual Studio

### Download and unzip LibTorch

1. Go to pytorch's homepage: https://pytorch.org/

2. Select `LibTorch` > `C++/Java` > `CUDA XX.X`

![alt text](https://github.com/martianvenusian/installations/blob/master/PyTorch/libtorch_download_01.png?raw=true)

3. Copy the link and download LibTorch's release version. You can use command prompt to download it. For example:
```
https://download.pytorch.org/libtorch/cu111/libtorch-win-shared-with-deps-1.8.1%2Bcu111.zip
```
4. Unzip the downloaded file. Go to the folder where you downloaded libtorch archive file and unzip it. Or you can just use `Command Prompt`. For example:

```
unzip libtorch-win-shared-with-deps-1.8.1+cu111
```

### CMake build configuration 

1. Create `CMakeLists.txt` file

2. Write a minimal cmake code as following:

```
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(example-app)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(example-app example-app.cpp)
target_link_libraries(example-app "${TORCH_LIBRARIES}")
set_property(TARGET example-app PROPERTY CXX_STANDARD 14)

# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET example-app
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:example-app>)
endif (MSVC)
```

2. Write implementation c++ code

```
#include <torch/torch.h>
#include <iostream>

int main() {
  torch::Tensor tensor = torch::rand({2, 3});
  std::cout << tensor << std::endl;
}
```

### Build the application

1. Your directory could look like this:

```
example-app/
  CMakeLists.txt
  example-app.cpp
```

2. Run build command:

```
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=\absolute\path\to\libtorch ..
cmake --build . --config Release
```

Where \absolute\path\to\libtorch should be the absolute (!) path to the unzipped LibTorch distribution.

for example: `cmake -DCMAKE_PREFIX_PATH=C:\Users\Husan\libtorch-win-shared-with-deps-1.8.1+cu111\libtorch ..`

If all goes well, it will look something like this:

```
-- Building for: Visual Studio 16 2019
-- Selecting Windows SDK version 10.0.19041.0 to target Windows 10.0.19043
-- The C compiler identification is MSVC 19.29.30037.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done 
...
-- Generating done
-- Build files have been written to: D:/husan/projects/installations/PyTorch/build  
```

![alt text](https://github.com/martianvenusian/installations/blob/master/PyTorch/libtorch_build_01.png?raw=true)

### Executing the resulting example-app 
```
cd Release
example-app.ext
```
Your result: 
```
0.0355 0.3252 0.3173
0.2431 0.1775 0.2966
```