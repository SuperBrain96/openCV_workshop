#include <opencv2/opencv.hpp>                 //Includes all the openCV codes.
#include <highgui.h>
#include <stdio.h>

using namespace cv;

int main( int argc, char** argv )
{
  char* imageName = argv[1];                  //Storing the name of image.

  Mat image;
  image = imread( imageName, 1 );             //Reading the image, 1 is same as IMREAD_COLOR (enum).

  if( argc != 2 || !image.data )              //Checking for the conditions.
  {
    printf("No image data\n");
    return -1;
  }

  Mat gray_image;                             //Defining new gray image matrix.
  cvtColor( image, gray_image, CV_BGR2GRAY );   //Convert colors of first argument
                                                //and store it in second parameter according to the third parameter.
  imwrite( "Gray_Image.jpg", gray_image );       //Writing gray image in new file with name according to forst parameter.

  namedWindow( imageName, CV_WINDOW_AUTOSIZE );
  namedWindow( "Gray Image", CV_WINDOW_AUTOSIZE );

  imshow( imageName, image );
  imshow( "Gray Image", gray_image );

  waitKey(0);
  return 0;
}
