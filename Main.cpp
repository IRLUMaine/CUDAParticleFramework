/*
 * Main.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#include "ModelParams.h"
#include <stdio.h>
#include "NodeHandler.h"
#include "TimeHandler.h"
#include "FEMUtil.h"
#include "MeshLessHandler.h"
#include "WaterFaker.h"

int main(int argc, char* argv[]) {
	NodeHandler nodeHandler(NUMX, NUMY, STARTX, STARTY, ENDX, ENDY, 4);
	TimeHandler timeHandler(DELTA_TIME, LENGTH);
	FEMUtil femUtil;
	WaterFaker waterFaker;

	for (int i = 0; i < nodeHandler.getNodeNum(); i++) {
		nodeHandler.getNode(i)->setData(MASSI, MASS);
	}

	while (!timeHandler.isDone()) {
		waterFaker.generateElements(femUtil, nodeHandler, timeHandler);
		waterFaker.solveStep(femUtil, nodeHandler, timeHandler);
		waterFaker.postStepProc(femUtil, nodeHandler, timeHandler);

		nodeHandler.writeState();

		timeHandler.incrementTime();
	}

	printf("Done\n");

	return 0;
}

