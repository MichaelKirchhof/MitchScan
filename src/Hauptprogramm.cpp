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

void AktualisiereMainPage (int Prg, void*);
Hauptprogramm Aktuelle_Programmauswahl;

int main(int argc, char **argv) {

	std::string MainPageName = "Main Programm Selection";
	namedWindow( MainPageName, CV_WINDOW_KEEPRATIO );
	Aktuelle_Programmauswahl = MK_NoSelection;
	initTyps();
	//createButton( "Raster Images", ButtonClickRasterImage, NULL, CV_PUSH_BUTTON, false);
	//createButton( "OpenCvDemo", ButtonClickOpenCvDemo, NULL, CV_PUSH_BUTTON, false);
	int Prg = (int) Aktuelle_Programmauswahl;
	bool MainExit = false;
	while (!MainExit)
	{
		createTrackbar( "Wähle ein Unterprogramm und starte es mit ENTER:", MainPageName, &Prg, (int) Programmname.size()-1, AktualisiereMainPage );
		waitKey();
		destroyAllWindows();
		switch (Aktuelle_Programmauswahl)
		{
		case Main_MiaPRoject:
			ButtonClickRasterImage(0,NULL );
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			break;
		case Main_Rectivication:
			ButtonClickRasterImage(0,NULL );
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			break;

		case Main_GoodFeature:
			ButtonClickOpenCvDemo(0,NULL );
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			break;

		case Main_HomographyDemo:
			ButtonClickOpenHomoDecompDemo(0,NULL );
			Prg = Aktuelle_Programmauswahl = MK_NoSelection;
			break;

		case Main_ManualImageMatching:
			ButtonManualImageMatching(0,NULL);

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

void AktualisiereMainPage (int Prg, void*) {
	Aktuelle_Programmauswahl = (Hauptprogramm) Prg;
	std::cout << Programmname[Prg] << std::endl;
	//cv::addText()
}


