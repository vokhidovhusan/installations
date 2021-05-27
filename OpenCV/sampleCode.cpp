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