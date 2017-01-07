/*
 * OpenCvDemo.cpp
 *
 *  Created on: 02.09.2015
 *      Author: michael
 */

#include "OpenCvDemo.h"


OpenCvDemo MyDemo;




OpenCvDemo::OpenCvDemo() {
	maxCorners = 23;
	maxTrackbar = 2000;
	source_window = "Image";

}

OpenCvDemo::~OpenCvDemo() {
	// TODO Auto-generated destructor stub
}




void OpenCvDemo::runDemo( char** argv){

	VideoCapture CaptureClass;
	CaptureClass.open(argv[1]);

	CaptureClass.grab();
	CaptureClass.retrieve(src,3);

	//src = imread( argv[1], 1 );


	  cvtColor( src, src_gray, CV_BGR2GRAY );

	  /// Create Window
	  namedWindow( source_window, CV_WINDOW_AUTOSIZE );

	  /// Create Trackbar to set the number of corners
	  createTrackbar( "Max  corners:", source_window, &maxCorners, maxTrackbar, callback );

	  imshow( source_window, src );

	  goodFeaturesToTrack_Demo( 0, 0 );

	  waitKey(0);

	  destroyAllWindows();
	  return;

}

void callback( int, void* )
{
	MyDemo.goodFeaturesToTrack_Demo(0,0);
}

void OpenCvDemo::goodFeaturesToTrack_Demo(int, void *)
{
	RNG rng(12345);
	if( maxCorners < 1 ) { maxCorners = 1; }

	  /// Parameters for Shi-Tomasi algorithm
	  vector<Point2f> corners;
	  double qualityLevel = 0.01;
	  double minDistance = 10;
	  int blockSize = 3;
	  bool useHarrisDetector = false;
	  double k = 0.04;

	  /// Copy the source image
	  Mat copy;
	  copy = src.clone();

	  /// Apply corner detection
	  goodFeaturesToTrack( src_gray,
	               corners,
	               maxCorners,
	               qualityLevel,
	               minDistance,
	               Mat(),
	               blockSize,
	               useHarrisDetector,k );


	  /// Draw corners detected
	  cout<<"** Number of corners detected: "<<corners.size()<<endl;
	  int r = 4;
	  for( unsigned int i = 0; i < corners.size(); i++ )
	     { circle( copy, corners[i], r, Scalar(rng.uniform(0,255), rng.uniform(0,255),
	              rng.uniform(0,255)), -1, 8, 0 ); }

	  /// Show what you got
	  namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	  imshow( source_window, copy );
}
