/*
 * WaterFaker.h
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#ifndef WATERFAKER_H_
#define WATERFAKER_H_

#include "MeshLessHandler.h"

class WaterFaker : MeshLessHandler {
public:
	WaterFaker();
	virtual ~WaterFaker();

	/**
	 * This function will be called before each FEM step and should be used
	 * primarily for the purpose of generating the elements.
	 */
	virtual void generateElements(FEMUtil &femUtil, NodeHandler &nodeHandler, TimeHandler &timeHandler);

	/**
	 * Most FEM Solving will be handled by the FEM Util but this callback will
	 * allow for greater flexibility in solving.
	 */
	virtual void solveStep(FEMUtil &femUtil, NodeHandler &nodeHandler, TimeHandler &timeHandler);

	/**
	 * This is called to allow the solver to handle any of the results required
	 * such as moving of the nodes.
	 */
	virtual void postStepProc(FEMUtil &femUtil, NodeHandler &nodeHandler, TimeHandler &timeHandler);

};

#endif /* WATERFAKER_H_ */
