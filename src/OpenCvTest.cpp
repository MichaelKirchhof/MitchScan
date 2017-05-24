//============================================================================
// Name        : OpenCvTest.cpp
// Author      : Michael
// Version     :
// Copyright   : First test for OpenCv
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "tFeatureDetector.h"
#include "OpenCvDemo.h"
#include "MiaProject/MiaProject.h"
#include "Typdef.h"

using namespace std;
using namespace cv;
#define _BUILD_MARIA

void AktualisiereMainPage (int Prg, void*);
Hauptprogramm Aktuelle_Programmauswahl;

int main(int argc, char **argv) {

	char * MainPageName = "Main Programm Selection";
	namedWindow( MainPageName, CV_WINDOW_KEEPRATIO );
	Aktuelle_Programmauswahl = MK_NoSelection;
	initTyps();
	createButton( "Raster Images", ButtonClickRasterImage, NULL, CV_PUSH_BUTTON, false);
	//createButton( "OpenCvDemo", ButtonClickOpenCvDemo, NULL, CV_PUSH_BUTTON, false);
	int Prg = (int) Aktuelle_Programmauswahl;
	createTrackbar( "Max  corners:", MainPageName, &Prg, (int) Programmname.size(), AktualisiereMainPage );

	waitKey();
	destroyAllWindows();
	return 0;
}

void AktualisiereMainPage (int Prg, void*) {
	Aktuelle_Programmauswahl = (Hauptprogramm) Prg;
	std::cout << Programmname[Prg] << std::endl;
	//cv::addText()
}


