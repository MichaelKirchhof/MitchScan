/*
 * OpenCvDemo.cpp
 *
 *  Created on: 02.09.2015
 *      Author: michael
 */

#include "OpenCvDemo.h"
#include "../Core/Timer.h"
#include <unistd.h>


OpenCvDemo MyDemo;




OpenCvDemo::OpenCvDemo() {
	maxCorners = 50;
	maxTrackbar = 2000;
	IQualityLevel = 10;
	qualityLevel = IQualityLevel / 1000.0;
	source_window = "Image MK";

}

OpenCvDemo::~OpenCvDemo() {
	// TODO Auto-generated destructor stub
}




void OpenCvDemo::runDemo( string argv){

	CaptureClass.open(argv);
	//CaptureClass.open(0);

	CaptureClass >> src;
	cvtColor( src, src_gray, CV_BGR2GRAY );

	/// Create Window
	namedWindow( source_window, CV_WINDOW_KEEPRATIO );

	/// Create Trackbar to set the number of corners
	createTrackbar( "Max  corners:", source_window, &maxCorners, maxTrackbar, callback_KLTDemo );
	createTrackbar( "Quality:", source_window, &IQualityLevel, maxTrackbar, callback_KLTDemo );

	imshow( source_window, src );

	waitKey(0);
	tTimer DrawTimer(1000);
	int FrameCounter =0;
	while (not src.empty()){
		FrameCounter ++;
		cout << "Current Frame Number: " << FrameCounter << endl;
		goodFeaturesToTrack_Demo( 0, 0 );
		waitKey(50);
		/*if (DrawTimer.Over()){
			waitKey(1);
			DrawTimer.Reset(1000);
		} else {
			usleep (20);
		}*/
		// if (FrameCounter % 50 ==0) waitKey(1);

		CaptureClass >> src;
		cvtColor( src, src_gray, CV_BGR2GRAY );
	}

	waitKey(0);

	destroyAllWindows();
	return;
}


void OpenCvDemo::goodFeaturesToTrack_Demo(int, void *)
{

	if (IQualityLevel >2)
		qualityLevel = IQualityLevel / 1000.0;

	RNG rng(12345);
	if( maxCorners < 1 ) { maxCorners = 1; }

	  /// Parameters for Shi-Tomasi algorithm
	  vector<Point2f> corners;
	  double minDistance = 10;
	  int blockSize = 3;
	  bool useHarrisDetector = true;
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

void callback_KLTDemo( int, void* )
{
	MyDemo.goodFeaturesToTrack_Demo(0,0);
}
void ButtonClickOpenCvDemo ( int, void* ) {
	FILE *in;
	if (!(in = popen(
			"zenity  --title=\"Select a video\" --file-selection",
			"r"))) {
		return;
	}

	char buff[512];
	string selectFile = "";
	while (fgets(buff, sizeof(buff), in) != NULL) {
		selectFile += buff;
	}
	pclose(in);

	//remove the "\n"
	selectFile.erase(std::remove(selectFile.begin(), selectFile.end(), '\n'),
				selectFile.end());
	MyDemo.runDemo(selectFile);
	return;
}

