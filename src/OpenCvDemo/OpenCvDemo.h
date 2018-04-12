/*
 * OpenCvDemo.h
 *
 *  Created on: 02.09.2015
 *      Author: michael
 */

#ifndef OPENCVDEMO_H_
#define OPENCVDEMO_H_

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

class OpenCvDemo {
public:
	OpenCvDemo();
	virtual ~OpenCvDemo();
	void runDemo( string argv);
	void goodFeaturesToTrack_Demo( int, void* );
	Mat src, src_gray;

	int maxCorners;
	int maxTrackbar;
	int IQualityLevel;
	double qualityLevel;
	std::string source_window;
	VideoCapture CaptureClass;
};


void callback_KLTDemo( int, void* );
void ButtonClickOpenCvDemo( int, void* );

extern OpenCvDemo MyDemo;

#endif /* OPENCVDEMO_H_ */
