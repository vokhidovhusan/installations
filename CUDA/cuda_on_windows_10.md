# CUDA on WINDOWS 10

## Prerequirements
1.NVIDIA GPU driver

## Download CUDA Toolkit 
Visit the CUDA download pr archive pages, then 
select cuda version according to your operating system

[CUDA last versions]: https://developer.nvidia.com/cuda-downloads

[CUDA Toolkit archives] https://developer.nvidia.com/cuda-toolkit-archive

![alt text](https://github.com/martianvenusian/installations/blob/master/CUDA/cuda_download_01.jpg?raw=true)

## Install CUDA Toolkit
After download CUDA.exe file install it

![alt text](https://github.com/martianvenusian/installations/blob/master/CUDA/install_01.jpg?raw=true)

## Download CUDNN library
Go to nvidia cudnn download page: https://developer.nvidia.com/cudnn-download-survey

You first have to crate account.

![alt text](https://github.com/martianvenusian/installations/blob/master/CUDA/cudnn_login_01.jpg?raw=true)

Then download cudnn library according to your operating system and CUDA version

![alt text](https://github.com/martianvenusian/installations/blob/master/CUDA/cudnn_download_01.jpg?raw=true)

## Install Visual Studio Community version 
Install Visual Studio Community version

![alt text](https://github.com/martianvenusian/installations/blob/master/CUDA/visual_studio_01.jpg?raw=true)

![alt text](https://github.com/martianvenusian/installations/blob/master/CUDA/visual_studio_02.jpg?raw=true)

## install CUDNN library
1. Extract the Cudnn zip file
2. Copy all files from cuda\bin\ folder to C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.0\bin\
3. Copy all files from cuda\include\ folder to C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.0\include\
4. Copy all files from cuda\lib\x64 folder to C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.0\lib\x64
### Done