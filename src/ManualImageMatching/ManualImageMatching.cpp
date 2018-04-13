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
	Mat ReferenzFrame, MatchingFrame, ReferenzFrameWithFeature, MatchingFrameWithFeature, TransformedFrame;
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
	string RefFrame = "Referenz Frame";
	string MatchFrame = "Matching Frame";
	string FinalFrame = "Transformated Frame";
	namedWindow(RefFrame, WINDOW_NORMAL);
	resizeWindow(RefFrame, 600,600);
	namedWindow(MatchFrame, WINDOW_NORMAL);
	resizeWindow(MatchFrame, 600,600);
	namedWindow(FinalFrame, WINDOW_NORMAL);
	resizeWindow(FinalFrame, 600,600);


	bool ready = false;
	vector<Point2f> ListOfPointsInReferenzFrame, ListOfPointsInMatchingFrame;

	while (!ready) {
		ReferenzFrameWithFeature = ReferenzFrame.clone();
		MatchingFrameWithFeature = MatchingFrame.clone();
		this->DrawMatches(RefFrame, ReferenzFrameWithFeature, ListOfPointsInReferenzFrame);
		this->DrawMatches(MatchFrame, MatchingFrameWithFeature, ListOfPointsInMatchingFrame);
		imshow(RefFrame, ReferenzFrameWithFeature);// Später durch die neue Methode draw Feature ersetzen!!
		imshow(MatchFrame, MatchingFrameWithFeature);// Später durch die neue Methode draw Feature ersetzen!!
		// Clicken Einfügen!
		this->AddClickedPoint(RefFrame, ListOfPointsInReferenzFrame, ReferenzFrameWithFeature);
		ready = this->AddClickedPoint(MatchFrame, ListOfPointsInMatchingFrame, MatchingFrameWithFeature);

		if (ListOfPointsInMatchingFrame.size() >4) {
			// Es liegen genug Punkte vor um eine Homographie zu berechnen. Also geht es los:
			Mat H = findHomography( ListOfPointsInMatchingFrame, ListOfPointsInReferenzFrame);
			warpPerspective(MatchingFrame, TransformedFrame, H, ReferenzFrame.size());
			imshow(FinalFrame, TransformedFrame);
			resizeWindow(FinalFrame, 600,600);
		}
	}
	std:string SaveName = selectFile;
	SaveName.resize(SaveName.size()-4);
	SaveName.append("_transformed.jpg");
	imwrite(SaveName, TransformedFrame);

	destroyWindow(MatchFrame);
	destroyWindow(RefFrame);
	destroyWindow(FinalFrame);
}

// Die Mehtode gibt ready zurück, falls sie mit 'e' beendet wird. Ansonsten wird gewartet bis erst ein Punkt geklickt wurde und anschließend mit 'c' bestätigt wird.
bool tManualImageMatching::AddClickedPoint(std::string WindowName, vector<Point2f> &ListOfPoints, const Mat SourceImage)
{
	bool ready = false;
	ClickedPoint NewPoint;
	setMouseCallback(WindowName, onMouse, &NewPoint);
	while (1)
	{
		Mat Image = SourceImage.clone();
		char HotKey= waitKey(30);

		if (NewPoint.newPoint) {
			circle(Image,cvPoint(NewPoint.PointCoords.x,NewPoint.PointCoords.y),20,Scalar(255,0,0),2);
			imshow(WindowName, Image);
		}
		if (HotKey == 'e'){
			ready = true;
		}
		if (HotKey == 'c' || HotKey == 'e') {
		// Hier passiert die Action der Punkt wurde bestätigt. Also rechnen was das zeug hält.
			if (NewPoint.newPoint) {
				ListOfPoints.push_back(NewPoint.PointCoords);
				break;
			}
		}
	}
	return ready;
}

void tManualImageMatching::DrawMatches(std::string WindowName, cv::Mat &Image, std::vector<cv::Point2f> &ListOfPoints)
{
	for (int i=0; i < ListOfPoints.size(); i++) {
		circle(Image,cvPoint(ListOfPoints[i].x,ListOfPoints[i].y),20,Scalar(0,0,0),2);//draw circle in point 100,100
	}
	imshow(WindowName, Image);
	resizeWindow(WindowName, 600,600);
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
