/*
 * NodeHandler.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#include "NodeHandler.h"
#include <string.h>
#include <stdio.h>

NodeHandler::NodeHandler(int sizeX, int sizeY, float startX, float startY,
		float endX, float endY, int nodeDataSize) {
	float x = startX;
	float y = startY;
	float xSpace = (endX - startX) / (sizeX - 1);
	float ySpace = (endY - startY) / (sizeY - 1);
	for (int i = 0; i < sizeX; i++) {
		y = startY;
		for (int j = 0; j < sizeY; j++) {
			nodes.push_back(new Node(x, y, 0, NULL, nodeDataSize));

			y += ySpace;
		}
		x += xSpace;
	}
}

NodeHandler::~NodeHandler() {
	for (unsigned int i = 0; i < nodes.size(); i++) {
		delete nodes[i];
	}
}

Node* NodeHandler::getNode(int i) {
	return nodes[i];
}

int NodeHandler::getNodeNum() {
	return nodes.size();
}

void NodeHandler::writeState(TimeHandler timeHandler) {
	for (unsigned int i = 0; i < nodes.size(); i++) {
		printf("%d %f %f %f %f\n", i, nodes[i]->getX(), nodes[i]->getY(), nodes[i]->getZ(), timeHandler.getTime());
	}
}
