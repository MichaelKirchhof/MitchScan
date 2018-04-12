/*
 * ManualImageMatching.cpp
 *
 *  Created on: 12.04.2018
 *      Author: michael
 */

#include "ManualImageMatching.h"

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
	Mat ReferenzFrame, MatchingFrame, ReferenzFrameWithFeature, MatchingFrameWithFeature;
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
	ReferenzFrame = imread(selectFile,CV_LOAD_IMAGE_UNCHANGED);

	if (!(in = popen( "zenity  --title=\"Select an image to match\" --file-selection",	"r"))) {
		// Hier sollte auf dem BasisFrame noch ein Text generiert werden, dass das File nicht geöffnet werden konnte.
		cout << "Es wurde keine Datei ausgewählt." << endl;
		return;
	}


	selectFile = "";
	while (fgets(buff, sizeof(buff), in) != NULL) {
		selectFile += buff;
	}
	pclose(in);

	//remove the "\n"
	selectFile.erase(std::remove(selectFile.begin(), selectFile.end(), '\n'),
				selectFile.end());

	// path + filename + format
	MatchingFrame = imread(selectFile,CV_LOAD_IMAGE_UNCHANGED);

	// Wir haben zwei Bilder im Speicher.
	// Ablauf:
	//1. Zeige Bild 1 und Wähle Punkt und bestätige mit "c"
	//2. Zeige Bild 2 und wähle den gleichen Punkt. Bestätige mit "c"
	// Wiederholen, bis der "e" nach dem zweiten Bild geklickt wird.
	// Prüfen ob genug Daten da sind
	// Homographie berechnen.
	// Residuen bestimmen. Ab größe xy User fragen wie es weiter gehen soll...
	// Transformation und Transformiertes Bild in Datei speichern.

	namedWindow("Referenz Frame", WINDOW_NORMAL);
	namedWindow("Matching Frame", WINDOW_NORMAL);
	namedWindow("Transformated Frame", WINDOW_NORMAL);


	bool ready = false;
	ClickedPoint PointInRef, PointMatch;
	vector<Point2f> ListOfPointsInReferenzFrame, ListOfPointsInMatchingFrame;
	ReferenzFrameWithFeature = ReferenzFrame.clone();
	MatchingFrameWithFeature = MatchingFrame.clone();
	while (!ready) {

		imshow("Referenz Frame", ReferenzFrameWithFeature);
		resizeWindow("Referenz Frame", 600,600);
		// Clicken Einfügen!
		setMouseCallback("Referenz Frame", onMouse, &PointInRef);
		char HotKey= waitKey(0);
		if (HotKey == 'e'){
			ready = true;
		} else if (HotKey == 'c') {
			// Hier passiert die Action der Punkt wurde bestätigt. Also rechnen was das zeug hält.
			if (PointInRef.newPoint) {
				ListOfPointsInReferenzFrame.push_back(PointInRef.PointCoords);
			}
		} else {
			// Es wurde irgendwas gedrückt. Wir machen einfach nix und warten weiter.
		}
	}

}

void onMouse(int event, int i, int j, int flags, void* param)
{

    ClickedPoint* PointCoords = (ClickedPoint*) param;
    if (event == CV_EVENT_LBUTTONDOWN || event == EVENT_LBUTTONDOWN)
    {
    	PointCoords->PointCoords.x = i;
    	PointCoords->PointCoords.y = j;
    	PointCoords->newPoint = true;
        cout << "x= " << i << " y= " << j << endl;
    }
}




void ButtonManualImageMatching ( int, void* )
{
	tManualImageMatching ManImageMatching;
	ManImageMatching.Start();
}
