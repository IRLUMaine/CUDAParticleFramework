/*
 * WaterFaker.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#include "WaterFaker.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ModelParams.h"

WaterFaker::WaterFaker() {
	// TODO Auto-generated constructor stub

}

WaterFaker::~WaterFaker() {
	// TODO Auto-generated destructor stub
}

void WaterFaker::generateElements(FEMUtil &femUtil, NodeHandler &nodeHandler,
		TimeHandler &timeHandler) {

}

void WaterFaker::solveStep(FEMUtil &femUtil, NodeHandler &nodeHandler,
		TimeHandler &timeHandler) {
	for (int i = 0; i < nodeHandler.getNodeNum(); i++) {
		Node* current = nodeHandler.getNode(i);
		Node* other;
		float fx = rand() * RAND_AMOUNT / RAND_MAX;
		float fy = -GRAVITY + rand() * RAND_AMOUNT / RAND_MAX;
		float fz = 0;
		float adx, dx;
		float ady, dy;
		float dist;
		float force;
		float dt = timeHandler.getDeltaTime();

		for (int j = 0; j < nodeHandler.getNodeNum(); j++) {
			if (j != i) {
				other = nodeHandler.getNode(j);
				dx = current->getX() - other->getX();
				adx = fabs(dx);
				if (adx < MAX_RAD) {
					dy = current->getY() - other->getY();
					ady = fabs(dy);
					if (ady < MAX_RAD) {
						dist = sqrt(dx*dx+dy*dy);
						if (dist < MAX_RAD) {
							force = (dist - MIN_RAD) / (MAX_RAD - MIN_RAD);
//							printf("Collision %f\n", force);
							fx += dx * force / dist;
							fy += dy * force / dist;
						}
					}
				}
			}
		}
		current->setData(MXI, current->getData(MXI) + fx * dt);
		current->setData(MYI, current->getData(MYI) + fy * dt);
		current->setData(MZI, current->getData(MZI) + fz * dt);
//		printf("Force %f %f %f - Momentum %f %f %f\n", fx, fy, fz, current->getData(MXI), current->getData(MYI), current->getData(MZI));
	}
}

void WaterFaker::postStepProc(FEMUtil &femUtil, NodeHandler &nodeHandler,
		TimeHandler &timeHandler) {
	for (int i = 0; i < nodeHandler.getNodeNum(); i++) {
		Node* current = nodeHandler.getNode(i);
		float dt = timeHandler.getDeltaTime() / current->getData(MASSI);

		current->move(current->getData(MXI) * dt,
				current->getData(MYI) * dt,
				current->getData(MZI) * dt);
		float x = current->getX();
		float y = current->getY();
		if (isnan(x) || isnan(y)) {
			printf("NANTIME!!\n");
			exit(1);
		}
		if (x < WALL_MINX) {
			current->setX(WALL_MINX);
		} else if (x > WALL_MAXX) {
			current->setX(WALL_MAXX);
		}
		if (y < WALL_MINY) {
			current->setY(WALL_MINY);
		} else if (y > WALL_MAXY) {
			current->setY(WALL_MAXY);
		}
	}
}
