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

#include "Core/tFeatureDetector.h"
#include "OpenCvDemo/OpenCvDemo.h"
#include "HomoGraphieZerlegung/HomographyDecompDemo.h"
#include "MiaProject/MiaProject.h"
#include "Core/Typdef.h"
#include "ManualImageMatching/ManualImageMatching.h"


using namespace std;
using namespace cv;

void AktualisiereMainPage (int Prg, void* );
void InitMainPage();
Hauptprogramm Aktuelle_Programmauswahl;

std::string MainPageName = "Main Programm Selection";

int main(int argc, char **argv) {


	namedWindow( MainPageName, CV_WINDOW_KEEPRATIO );
	Aktuelle_Programmauswahl = MK_NoSelection;
	initTyps();
	InitMainPage();
	//createButton( "Raster Images", ButtonClickRasterImage, NULL, CV_PUSH_BUTTON, false);
	//createButton( "OpenCvDemo", ButtonClickOpenCvDemo, NULL, CV_PUSH_BUTTON, false);
	int Prg = (int) Aktuelle_Programmauswahl;
	bool MainExit = false;
	while (!MainExit)
	{
		createTrackbar( "Wähle ein Unterprogramm und starte es mit ENTER:", MainPageName, &Prg, (int) Programmname.size()-1, AktualisiereMainPage);
		waitKey();
		destroyAllWindows();
		switch (Aktuelle_Programmauswahl)
		{
		case Main_MiaPRoject:
			ButtonClickRasterImage(0,NULL );
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			InitMainPage();
			break;
		case Main_Rectivication:
			ButtonClickRasterImage(0,NULL );
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			InitMainPage();
			break;

		case Main_GoodFeature:
			ButtonClickOpenCvDemo(0,NULL );
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			InitMainPage();
			break;

		case Main_HomographyDemo:
			ButtonClickOpenHomoDecompDemo(0,NULL );
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			InitMainPage();
			break;

		case Main_ManualImageMatching:
			ButtonManualImageMatching(0,NULL);
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			InitMainPage();
			break;

		case Main_Exit:
			MainExit = true;
			break;
		default:
			namedWindow( MainPageName, CV_WINDOW_KEEPRATIO );
			break;
		}

	}

	std::cout << "Get out of here" <<std::endl;
	return 0;
}

void AktualisiereMainPage (int Prg, void* ) {
	Aktuelle_Programmauswahl = (Hauptprogramm) Prg;
	std::cout << Programmname[Prg] << std::endl;
	Mat MainPage(300,600, CV_8UC3);
	MainPage.zeros(300,600, CV_8UC3);
	cv::putText(MainPage, Programmname[Prg], Point2f(150,30) , FONT_HERSHEY_COMPLEX, 0.8,  cvScalar(200,200,250), 1, CV_AA);
	cv::putText(MainPage, "Confirm with [ENTER]", Point2f(150,80) , FONT_HERSHEY_COMPLEX, 0.8,  cvScalar(200,200,250), 1, CV_AA);
	imshow(MainPageName, MainPage);

}

void InitMainPage()
{
	Mat MainPage(300,600, CV_8UC3);
	MainPage.zeros(300,600, CV_8UC3);
	cv::putText(MainPage, "Please select an option", Point2f(150,30) , FONT_HERSHEY_COMPLEX, 0.8,  cvScalar(200,200,250), 1, CV_AA);
	imshow(MainPageName, MainPage);

}

