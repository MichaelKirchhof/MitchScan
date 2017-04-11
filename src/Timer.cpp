/*
 * Timer.cpp
 *
 *  Created on: 03.04.2017
 *      Author: michael
 */

#include "Timer.h"


using namespace std;


tTimer::tTimer(int TimeInMS) {
	TimerDurration = TimeInMS;
	TickFrequence = cv::getTickFrequency();
	StartTick = cv::getTickCount();
}

tTimer::~tTimer() {
	// TODO Auto-generated destructor stub
}

void tTimer::Reset() {
	StartTick = cv::getTickCount();
	cout << "Timer Reset" << endl;
}

void tTimer::Reset(int TimeInMS) {
	this->Reset();
	TimerDurration = TimeInMS;
}

double tTimer::GetElapsedTimeInSeconds() {
	int64 EndTick = cv::getTickCount();
	double ElapsedTime = ((double) EndTick - StartTick)/TickFrequence;
	cout << "Elapsed Time:" << ElapsedTime << endl;
	return ElapsedTime;
}

bool tTimer::Over() {
	return this->GetElapsedTimeInSeconds() > TimerDurration/1000.0; // Durration ist in ms angegeben.
}


