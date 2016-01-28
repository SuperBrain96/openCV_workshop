#include "opencv2/opencv.hpp"               //< > search only in library whereas " " search in current folder as well.

using namespace cv;

int main()
{
  VideoCapture cap(0);                      //Since default camera is at video0 in /dev folder.
  if(!cap.isOpened())                       //If video is successfully opened.
    return -1;

  Mat edges;                                //Unneccesary line in this case.
  namedWindow( "Video Stream 1", 1 );       //Defining videos for channel.
  namedWindow( "Video Stream 2", 1 );
  namedWindow( "Video Stream 3", 1 );
  namedWindow( "Video Stream 4", 1 );
  namedWindow( "Video Stream 5", 1 );
  namedWindow( "Video Stream 6", 1 );
  namedWindow( "Video Stream 7", 1 );
  namedWindow( "Video Stream 8", 1 );
  namedWindow( "Video Stream 9", 1 );

  for( ; ; )                                //Infinite loop.
  {
    Mat frame1, frame2, frame3, frame4[3], frame5[3];          //Creating 9 different matrix Frame.
    cap >> frame1;                                             //capturing from camera.
    cvtColor( frame1, frame2, CV_BGR2RGB );
    cvtColor( frame1, frame3, CV_BGR2HSV );
    split( frame1, frame4 );                            //Splitting values into channel.
    split( frame3, frame5 );
    imshow( "Video Stream 1", frame1 );                     //Putting feed from camera to the frame.
    imshow( "Video Stream 2", frame2 );
    imshow( "Video Stream 3", frame3 );
    imshow( "Video Stream 4", frame4[0] );
    imshow( "Video Stream 5", frame4[1] );
    imshow( "Video Stream 6", frame4[2] );
    imshow( "Video Stream 7", frame5[0] );
    imshow( "Video Stream 8", frame5[1] );
    imshow( "Video Stream 9", frame5[2] );        //Showing frame in a window.

    if( waitKey(30) >= 0 )                  //If no key is pressed in t millisecond(t being parameter)
      break;                                //-1 is returned else ASCII value is returned.
  }

//The camera will be deinitialized automatically in VideoCature destructor.
  return 0;
}
