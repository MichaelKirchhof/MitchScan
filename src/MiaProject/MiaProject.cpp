/*
 * MiaProject.cpp
 *
 *  Created on: 10.05.2017
 *      Author: michael
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <cv.h>
#include <highgui.h>
#include "opencv2/imgcodecs.hpp"
#include <cmath>
using namespace std;
using namespace cv;

void ButtonClickRasterImage( int, void* )
{
	Mat img;

	FILE *in;
	if (!(in = popen( "zenity  --title=\"Select an image\" --file-selection",	"r"))) {
		// Hier sollte auf dem BasisFrame noch ein Text generiert werden, dass das File nicht geöffnet werden konnte.
		cout << "Es wurde keine Datei ausgewählt." << endl;
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

	// path + filename + format
	img = imread(selectFile,CV_LOAD_IMAGE_UNCHANGED);


	Mat img_out;
	int NrOfLines;
	NrOfLines = 4;
	//cout << "Nr of lines selected:"<< argv[2]<< "or" << NrOfLines << endl;

	cout << "Select Rastertype: Press q for quadric raster and any other key for equal nr of lines in columns and rows. " << endl;
	char SelectedType= waitKey(0);
	if (SelectedType!= 'q')
	{
	// Gleichmässiger Teilungsmodus!
		bool ready = false;
		while (!ready)
		{
			img_out = img.clone();

			namedWindow("Raster mit gleicher Verteilung", CV_WINDOW_AUTOSIZE);
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
			imshow("Raster mit gleicher Verteilung", img_out);
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

			namedWindow("Quadratisches Raster", CV_WINDOW_AUTOSIZE);
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
			imshow("Quadratisches Raster", img_out);
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

	destroyWindow("Quadratisches Raster");
	destroyWindow("Raster mit gleicher Verteilung");
	return ;
}


