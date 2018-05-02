/*
 * tFeatureDetector.h
 *
 *  Created on: 02.09.2015
 *      Author: michael
 */

#ifndef TFEATUREDETECTOR_H_
#define TFEATUREDETECTOR_H_

#include <iostream>
#include "opencv2/opencv.hpp"
#include <cmath>
#include <vector>


class tFeatureDetector {
public:
	tFeatureDetector();
	virtual ~tFeatureDetector();
	void SetQualityInteger(int _QualityInt);
	bool DetectFeatureInFrame(cv::Mat &Frame, std::vector<cv::KeyPoint> &DetectedCorners );
private:
	void UpdateQuality() {this->Quality = (double) (this->QualityInt+1.0)/10000;};
	bool DetectFeatureInSubFrame(cv::Mat Frame, std::vector<cv::KeyPoint> &DetectedCorners, int MaxNrOfPointsInSection );
	std::vector<cv::Point2f> Corners;
	int MaxCorners, QualityInt;
	double Quality;
};

#endif /* TFEATUREDETECTOR_H_ */
