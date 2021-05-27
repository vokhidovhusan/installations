# OpenCV on WINDOWS 10
Installation by using the pre-build library

## Prerequirements
1. CMake
2. git-bash
3. Visual Studio Community

## Download OpenCV
1. Download opencv library [here](https://opencv.org/releases/).
2. Select "Windows" to download the package.
![alt text](https://github.com/martianvenusian/installations/blob/master/OpenCV/opencv_download_01.png?raw=true)


## Installation
1. Once you download the installer, double click on it to extract.
2. Choose the path where you want to extract.
![alt text](https://github.com/martianvenusian/installations/blob/master/OpenCV/installation_01.png?raw=true)


## CMake build configuration 

1. Create `CMakeLists.txt` file

2. Write a minimal cmake code as following:

```
# SPECIFY THE MINIMUM VERSION OF CMAKE REQUIRED
cmake_minimum_required(VERSION 2.8.12)

# SPECIFY YOUR PROJECT NAME
PROJECT(Project_Name)

# ENABLE C++11
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# MAKE SURE OPENCV IS INSTALLED CORRECTLY
find_package( OpenCV REQUIRED )

# INCLUDE OPENCV DIRECTORIES
include_directories( ${OpenCV_INCLUDE_DIRS})

# MACRO TO COMPILE CPP FILES
# Do Not Edit
MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )
ENDMACRO()

# COMPILE CPP FILES USING THIS LINE
######## EDIT THE FILE NAMES ########
add_example(sampleCode)
#add_example(sampleCode2) and so on
```

2. Write a sample c++ code 

```
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

using namespace cv;

int main( int argc, char** argv) {
	cout << "OpenCV version : " << CV_VERSION << endl;

	if( argc != 2)
    {
     cout <<" Usage: " << argv[0] << " ImageToLoadAndDisplay" << endl;
     return -1;
    }
    Mat image;
    image = imread(argv[1], IMREAD_COLOR); // Read the file
    if( image.empty() ) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image ); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    

	return 0;
}
```

## Build the application

```
> mkdir build
> cd build
> cmake -DCMAKE_PREFIX_PATH=\absolute\path\to\opencv ..
> cmake --build . --config Release
```

Where \absolute\path\to\opencv should be the absolute (!) path to the unzipped opencv library.

for example your cmake build will be like this: cmake -DCMAKE_PREFIX_PATH=C:\Users\Husan\opencv\build ..

## Exectute a sample code

```
> cd Release
> sampleCode.exe \path\to\image
```

Where \path\to\image should be the path to a image you want to test with

For example: D:\husan\projects\installation\OpenCV\image.jpg

and your result:

OpenCV version : 4.5.2

![alt text](https://github.com/martianvenusian/installations/blob/master/OpenCV/image.png?raw=true)