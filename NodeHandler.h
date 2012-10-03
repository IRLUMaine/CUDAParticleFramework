/*
 * NodeHandler.h
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#ifndef NODEHANDLER_H_
#define NODEHANDLER_H_

#include "Node.h"
#include <vector>

class NodeHandler {
public:
	NodeHandler(int sizeX, int sizeY, float startX, float startY, float endX, float endY, int nodeDataSize);
	virtual ~NodeHandler();

	Node* getNode(int i);
	int getNodeNum();

	void writeState();

private:
	std::vector<Node*> nodes;

};

#endif /* NODEHANDLER_H_ */
