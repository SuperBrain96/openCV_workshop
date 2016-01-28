#include <opencv2/core/core.hpp>                                //Include openCV functions.
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;                             //Specify namespaces.
using namespace std;

int main( int argc, char** argv )
{
  if( argc != 2)                                  //Check for required no of arguments.
  {
    cout << "Usage: display_image ImageToLoadAndDisplay" << endl;
    return -1;
  }

  Mat image;                                  //Mat is an openCV object, image is matrix.
  image = imread( argv[1], IMREAD_COLOR );    //Takes a file name, reads it and store it in mat object.
                                              //IMREAD_COLOR specifies in RGB color, other like IMREAD_GRAYSCALE can be used.
  if( image.empty() )                         //Check whether file is empty or not.
  {
    cout << "Could not open or find the image" << std::endl;
    return -1;
  }

  namedWindow( "Display window", WINDOW_NORMAL );       //Creates a window according to second parameter.
  imshow( "Display window", image );                      //Load image on the window created.
                                                          //Good practice is using WINDOW_NORMAL.
  waitKey(0);                                  //Wait for specified time in parameter in millisecond. Zero means forever.
  return 0;
}
