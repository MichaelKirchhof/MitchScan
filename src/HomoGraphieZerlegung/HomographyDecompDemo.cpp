/*
 * HomographyDecompDemo.cpp
 *
 *  Created on: 09.05.2017
 *      Author: michael
 */

#include "HomographyDecompDemo.h"
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <vector>


using namespace cv;
using namespace std;

HomographyDecompDemo::HomographyDecompDemo() {
	// TODO Auto-generated constructor stub

}

HomographyDecompDemo::~HomographyDecompDemo() {
	// TODO Auto-generated destructor stub
}


int HomographyDecompDemo::runDemo() {

// set up a virtual camera
  float f = 100, w = 640, h = 480;

  Mat1f K = (cv::Mat1f(3, 3) <<
	  f, 0, w/2,
	  0, f, h/2,
	  0, 0,   1);

  // set transformation from 1st to 2nd camera (assume K is unchanged)
  Mat1f rvecDeg = (cv::Mat1f(3, 1) << 45, 12, 66);
  Mat1f t = (cv::Mat1f(3, 1) << 100, 200, 300);

  cout << "-------------------------------------------\n";
  cout << "Ground truth:\n";

  cout << "K = \n" << K << endl << endl;
  cout << "rvec = \n" << rvecDeg << endl << endl;
  cout << "t = \n" << t << endl << endl;

  // set up points on a plane
  vector<cv::Point3f> p3d;/*{{0, 0, 10},
							   {100, 0, 10},
							   {0, 100, 10},
							   {100, 100, 10}};*/
  p3d.push_back({ 0,0,10});
  p3d.push_back({ 100,0,10});
  p3d.push_back({ 0,100,10});
  p3d.push_back({ 100,100,10});
  // project on both cameras
  vector<cv::Point2f> Q, P, S;

  projectPoints(p3d,
					Mat1d::zeros(3, 1),
					Mat1d::zeros(3, 1),
					K,
					Mat(),
					Q);

  cv::projectPoints(p3d,
					rvecDeg*CV_PI/180,
					t,
					K,
					Mat(),
					P);

  // find homography
  Mat H = findHomography(Q, P);

  cout << "-------------------------------------------\n";
  cout << "Estimated H = \n" << H << endl << endl;


  // check by reprojection
  vector<cv::Point2f> P_(P.size());
  perspectiveTransform(Q, P_, H);

  float sumError = 0;

  for (size_t i = 0; i < P.size(); i++) {
	sumError += cv::norm(P[i] - P_[i]);
  }

  cout << "-------------------------------------------\n";
  cout << "Average reprojection error = "
	  << sumError/P.size() << endl << endl;


  // decompose using identity as internal parameters matrix
  // TODO:Decompose ist nicht verfügbar-> Implementierung ala Faugeras wie in Matlab!
  // TODO:ObjektTyp "auto" funktioniert hier nicht. -> Prüfen!!

  vector<cv::Mat> Rs, Ts;
  decomposeHomographyMat(H,
							 K,
							 Rs, Ts,
							 noArray());

  cout << "-------------------------------------------\n";
  cout << "Estimated decomposition:\n\n";
  cout << "rvec = " << std::endl;
  for (size_t i = 0;  i < Rs.size();i++) {
	Mat1d rvec;
	Rodrigues(Rs[i], rvec);
	cout << rvec*180/CV_PI << endl << endl;
  }

  cout << endl;

  cout << "t = " << endl;
  for (size_t i = 0;  i < Ts.size();i++) {
	cout << Ts[i] << endl << endl;
  }

  return 0;
}



void ButtonClickOpenHomoDecompDemo ( int, void* ) {
	HomographyDecompDemo MyDemo;
	MyDemo.runDemo();
	return;
}

