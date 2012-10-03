/*
 * WaterFaker.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#include "WaterFaker.h"
#include <stdio.h>

WaterFaker::WaterFaker() {
	// TODO Auto-generated constructor stub

}

WaterFaker::~WaterFaker() {
	// TODO Auto-generated destructor stub
}

void WaterFaker::generateElements(FEMUtil &femUtil, NodeHandler &nodeHandler,
		TimeHandler &timeHandler) {
	printf("Generate\n");
}

void WaterFaker::solveStep(FEMUtil &femUtil, NodeHandler &nodeHandler,
		TimeHandler &timeHandler) {
	printf("Solve\n");
}

void WaterFaker::postStepProc(FEMUtil &femUtil, NodeHandler &nodeHandler,
		TimeHandler &timeHandler) {
	printf("Post\n");
}
