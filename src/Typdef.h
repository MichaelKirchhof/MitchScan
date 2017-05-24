/*
 * Typdef.h
 *
 *  Created on: 12.05.2017
 *      Author: michael
 */

#include <vector>
#include <iostream>
#include <string.h>

#ifndef TYPDEF_H_
#define TYPDEF_H_


enum Hauptprogramm{
	Main_MiaPRoject,
	Main_ChessBoardCalibration,
	Main_HomographyDemo,
	Main_GoodFeature,
	Main_Basic_Reconstruction,
	Main_Adjustment,
	MK_NoSelection
};
extern std::vector<char *> Programmname;

void initTyps();



#endif /* TYPDEF_H_ */
