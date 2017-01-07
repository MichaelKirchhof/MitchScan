/*
 * tFeatureDetector.cpp
 *
 *  Created on: 02.09.2015
 *      Author: michael
 */

#include "tFeatureDetector.h"

tFeatureDetector::tFeatureDetector() {
	//Corners.clear();
	//Corners.resize(2000);
	MaxCorners=500;
	Quality = 0.05;
	QualityInt = 500;


}

tFeatureDetector::~tFeatureDetector() {
	// TODO Auto-generated destructor stub
}

