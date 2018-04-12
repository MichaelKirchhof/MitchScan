/*
 * Typdef.cpp
 *
 *  Created on: 12.05.2017
 *      Author: michael
 */
#include "Typdef.h"

std::vector<std::string> Programmname;


void initTyps() {

	// Die Reihenfolge muss mit den Enums abgestimmt sein!
	Programmname.push_back("MiaProject");
	Programmname.push_back("Image Rectivication");
	Programmname.push_back("Single Camera Calibration");
	Programmname.push_back("Homography Demo");
	Programmname.push_back("GoodFeature to track Demo");
	Programmname.push_back("Basic Reconstruction");
	Programmname.push_back("Bundle-Adjustment");
	Programmname.push_back("Manual Image Matching");
	Programmname.push_back("Exit");


}
