/*
 * ManualImageMatching.h
 *
 *  Created on: 12.04.2018
 *      Author: michael
 */


#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#ifndef MANUALIMAGEMATCHING_H_
#define MANUALIMAGEMATCHING_H_


class tManualImageMatching {
public:
	tManualImageMatching();
	virtual ~tManualImageMatching();
	void Start();
};



void onMouse(int event, int i, int j, int flags, void* param);
void ButtonManualImageMatching ( int, void* );
#endif /* MANUALIMAGEMATCHING_H_ */


struct ClickedPoint {
public:
	ClickedPoint(): newPoint(false) {}; // Mit false Initialisiert!
	cv::Point2f PointCoords;
	bool newPoint;
};
