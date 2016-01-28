#include "opencv2/opencv.hpp"               //< > search only in library whereas " " search in current folder as well.

using namespace cv;

int main()
{
  VideoCapture cap(0);                      //Since default camera is at video0 in /dev folder.
  if(!cap.isOpened())                       //If video is successfully opened.
    return -1;

  Mat edges;                                //Unneccesary line in this case.
  namedWindow( "Video Stream", 1 );
  for( ; ; )                                //Infinite loop.
  {
    Mat frame;                              //Creating a matrix Frame.
    cap >> frame;                           //Putting feed from camera to the frame.
    imshow( "Video Stream", frame );        //Showing frame in a window.
    if( waitKey(30) >= 0 )                  //If no key is pressed in t millisecond(t being parameter)
      break;                                //-1 is returned else ASCII value is returned.
  }

//The camera will be deinitialized automatically in VideoCature destructor.
  return 0;
}
