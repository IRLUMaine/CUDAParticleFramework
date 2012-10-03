/*
 * Node.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#include "Node.h"
#include <string.h>

Node::Node(float x, float y, float z, float* data, int dataSize) {
	this->x = x;
	this->y = y;
	this->z = z;
	if (dataSize > 0) {
		this->dataLength = dataSize;
		this->datas = new float[dataSize];
		for (int i = 0; i < dataSize; i++) {
			if (data != NULL) {
				this->datas[i] = data[i];
			} else {
				this->datas[i] = 0;
			}
		}
	}
}

Node::~Node() {
	delete[] this->datas;
}

float Node::getX() {
	return x;
}

float Node::getY() {
	return y;
}

float Node::getZ() {
	return z;
}

void Node::move(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
}

void Node::setX(float newX) {
	this->x = newX;
}

void Node::setY(float newY) {
	this->y = newY;
}

void Node::setZ(float newZ) {
	this->z = newZ;
}

float* Node::getData() {
	return datas;
}

float Node::getData(int index) {
	if (index < dataLength) {
		return datas[index];
	}
	return -1;
}

void Node::setData(int index, float value) {
	if (index < dataLength) {
		datas[index] = value;
	}
}
