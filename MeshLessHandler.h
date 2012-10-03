/*
 * MeshLessHandler.h
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#ifndef MESHLESSHANDLER_H_
#define MESHLESSHANDLER_H_

#include "FEMUtil.h"
#include "NodeHandler.h"
#include "TimeHandler.h"

class MeshLessHandler {
public:
	MeshLessHandler();
	virtual ~MeshLessHandler();

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

#endif /* MESHLESSHANDLER_H_ */
