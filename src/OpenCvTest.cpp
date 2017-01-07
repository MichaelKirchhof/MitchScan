//============================================================================
// Name        : OpenCvTest.cpp
// Author      : Michael
// Version     :
// Copyright   : First test for OpenCv
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <cmath>
using namespace std;
using namespace cv;
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "tFeatureDetector.h"
#include "OpenCvDemo.h"


#define _BUILD_MARIA

int main(int argc, char **argv) {

#ifdef BUILD_MARIA

	Mat img = imread(argv[1],CV_LOAD_IMAGE_UNCHANGED);

	if (img.empty())
	{
		cout << "Error image:"<< argv[1]<< "can not be found" << endl;
		waitKey(1000);
		//system("pause");
		return -1;
	}
	Mat img_out;
	int NrOfLines;
	sscanf(argv[2], "%d",&NrOfLines);
	//cout << "Nr of lines selected:"<< argv[2]<< "or" << NrOfLines << endl;

	if (argv[3][0]!='r')
	{
	// Gleichmässiger Teilungsmodus!
		bool ready = false;
		while (!ready)
		{
			img_out = img.clone();

			namedWindow("Test fuer Maria", CV_WINDOW_AUTOSIZE);
			Point StartPoint, EndPoint;

			for (int count=1;count<NrOfLines+1; count++)
			{
				StartPoint.x = 0;
				EndPoint.x = img.cols;
				StartPoint.y = EndPoint.y = img.rows*count/(NrOfLines+1);
				line( img_out,StartPoint, EndPoint, Scalar(255,255,255), 1, CV_AA, 0);
			}

			for (int count=1;count<NrOfLines+1; count++)
			{
				StartPoint.y = 0;
				EndPoint.y = img.rows;
				StartPoint.x = EndPoint.x = img.cols*count/(NrOfLines+1);
				line( img_out,StartPoint, EndPoint, Scalar(255,255,255), 1, CV_AA, 0);
			}
			imshow("Test fuer Maria", img_out);
			char HotKey= waitKey(0);
			switch (HotKey)
			{
			case 'p':
				NrOfLines++;
				break;
			case 'm':
				NrOfLines--;
				break;
			default:
				ready = true;
				break;

			}
		}
	}
	else
	{
	// Quadratischer Teilungsmodus!

		// NrOfLines entspricht hier der Anzahl der linien auf der kürzesten Seite

		bool ready = false;
		while (!ready)
		{
			int Distance = min(img.rows/(NrOfLines+1), img.cols/(NrOfLines+1));
			img_out = img.clone();

			namedWindow("Test fuer Maria", CV_WINDOW_AUTOSIZE);
			Point StartPoint, EndPoint;

			for (int count=1;count*Distance<img.rows; count++)
			{
				StartPoint.x = 0;
				EndPoint.x = img.cols;
				StartPoint.y = EndPoint.y = count*Distance;
				line( img_out,StartPoint, EndPoint, Scalar(255,255,255), 1, CV_AA, 0);
			}

			for (int count=1; count*Distance<img.cols; count++)
			{
				StartPoint.y = 0;
				EndPoint.y = img.rows;
				StartPoint.x = EndPoint.x = count*Distance;
				line( img_out,StartPoint, EndPoint, Scalar(255,255,255), 1, CV_AA, 0);
			}
			imshow("Test fuer Maria", img_out);
			char HotKey= waitKey(0);
			switch (HotKey)
			{
			case 'p':
				NrOfLines++;
				break;
			case 'm':
				NrOfLines--;
				break;
			default:
				ready = true;
				break;

			}
		}
	}

	imwrite("/home/michael/Share/RasteredImage.jpg",img_out);

	destroyAllWindows();

#endif
	MyDemo.runDemo(argv);
	return 0;
}

