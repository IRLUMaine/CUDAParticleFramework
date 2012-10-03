/*
 * Node.h
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node(float x, float y, float z, float* data, int dataSize);
	virtual ~Node();

	float getX();
	float getY();
	float getZ();

	void move(float x, float y, float z);

	void setX(float newX);
	void setY(float newY);
	void setZ(float newZ);

	float* getData();
	float getData(int index);
	void setData(int index, float value);

private:
	float x,y,z;
	float* datas;
	float dataLength;
};

#endif /* NODE_H_ */
