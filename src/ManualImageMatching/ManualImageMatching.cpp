/*
 * ManualImageMatching.cpp
 *
 *  Created on: 12.04.2018
 *      Author: michael
 */

#include "ManualImageMatching.h"
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

tManualImageMatching::tManualImageMatching() {
	// TODO Auto-generated constructor stub

}

tManualImageMatching::~tManualImageMatching() {
	// TODO Auto-generated destructor stub
}



// Hauptrutine für das Matching der Punkte!
void tManualImageMatching::Start()
{
	Mat img, img2;
	FILE *in;
	if (!(in = popen( "zenity  --title=\"Select an reference image\" --file-selection",	"r"))) {
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

	if (!(in = popen( "zenity  --title=\"Select an image to match\" --file-selection",	"r"))) {
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
	img2 = imread(selectFile,CV_LOAD_IMAGE_UNCHANGED);

	// Wir haben zwei Bilder im Speicher.
	// Ablauf:
	//1. Zeige Bild 1 und Wähle Punkt und bestätige mit "b"
	//2. Zeige Bild 2 und wähle den gleichen Punkt. Bestätige mit "b"
	// Wiederholen, bis der "e" nach dem zweiten Bild geklickt wird.
	// Prüfen ob genug Daten da sind
	// Homographie berechnen.
	// Residuen bestimmen. Ab größe xy User fragen wie es weiter gehen soll...
	// Transformation und Transformiertes Bild in Datei speichern.

}




void ButtonManualImageMatching ( int, void* )
{
	tManualImageMatching ManImageMatching;
	ManImageMatching.Start();
}
