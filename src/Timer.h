/*
 * Timer.h
 *
 *  Created on: 03.04.2017
 *      Author: michael
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"



class tTimer {
public:
	tTimer(int TimeInMS);
	virtual ~tTimer();
	void Reset();
	void Reset(int TimeInMS);
	void Start() {Reset();};
	bool Over();
	void Sleep();
	double GetElapsedTimeInSeconds();
private:
	double TickFrequence;
	int64 StartTick;
	int TimerDurration; // in ms;
};


