/*
 * tFeatureDetector.cpp
 *
 *  Created on: 02.09.2015
 *      Author: michael
 */

#include "tFeatureDetector.h"
#include "opencv2/features2d.hpp"


tFeatureDetector::tFeatureDetector() {
	//Corners.clear();
	//Corners.resize(2000);
	this->MaxCorners = 500;
	this->Quality = 0.05;
	this->QualityInt = 500;


}

tFeatureDetector::~tFeatureDetector() {
	// TODO Auto-generated destructor stub
}


void tFeatureDetector::SetQualityInteger(int _QualityInt) {
	this->QualityInt = _QualityInt;
	this->UpdateQuality();
}


/*
 * Die Grundidee ist, dass nur der totale Schrott über die mindest Qualität abgefischt wird. Ansosnten wird
 * eine gleichmäßige Verteilung erzwungen indem das Bild in 10x10 Teile aufgeteilt wird und dort, wenn möglich
 * eine maximale Anzahl detektiert.
 * Übergabe des Frames erfolgt hier als Referenz, da das Bild noch ein weiteres Mal übergeben wird.
 */
bool tFeatureDetector::DetectFeatureInFrame(cv::Mat &Frame, std::vector<cv::KeyPoint> &DetectedCorners) {
	DetectedCorners.clear();
	for (int Row =0; Row < 10; Row++) {
		for (int Col = 0; Col <10; Col++) {
			cv::Mat Mask;
			//TODO: Defininiere Maske, wie muss ich noch rausfinden.
			if (!DetectFeatureInSubFrame(Frame, DetectedCorners, MaxCorners / 100 )) {
				printf("No Corners in Section %d, %d\r\n", Row, Col);
			}
		}
	 }
	// Hier muss mindestens eine Fundamental-Matrix bestimmt werden können. Daher mehr als 8 Punkte!
	if (DetectedCorners.size()>7) return true;

	return false; // Zu wenig Punkte gefunden. Hier muss abgefangen werden, da sonst weiter unten alles in die Hose geht...
}

bool tFeatureDetector::DetectFeatureInSubFrame(cv::Mat Frame, std::vector<cv::KeyPoint> &DetectedCorners, int MaxNrOfPointsInSection ) {
	// Hier geht die aktion mit Harris-Detektor ab. Alle anderen Detektoren wie SIFT werden auf der Ebene obendrüber aufgerufen, da dort eine
	// Teilung des Bildes nicht ergforderlich ist...
	cv::Mat src_gray;
	src_gray = Frame.clone();

	cv::goodFeaturesToTrack( src_gray,
		               DetectedCorners, // prüfen ob hier ein Clear auf das arry erfolgt, sonst hier lokal verwalten und umkopieren.
		               MaxNrOfPointsInSection,
		               Quality,
		               10, // non Maximum-suression in 10x10 Fenster
		               cv::Mat(),
		               5, // 5x5 Matrix zur Ermittlung der Ableitung. Nicht so effektiv aber bei Bildern mit Rauschen sinnvoll
		               true);
	return false;
}
