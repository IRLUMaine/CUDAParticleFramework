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

#define frand() ((((float)rand()) / RAND_MAX) - .5f)

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
		float fy = -GRAVITY + frand() * RAND_AMOUNT;
//		float fz = 0;
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
							force = MAX_FORCE * ((MAX_RAD - dist) / (MAX_RAD - MIN_RAD));
//							printf("Collision %f\n", force);
							if (dist > ARB_SMALL) {
								fx += dx * force / dist;
								fy += dy * force / dist;
							} else {
								other->move(frand() * 2 * MAX_RAD, frand() * 2 * MAX_RAD, 0);
								printf("Too Small\n");
							}
						}
					}
				}
			}
		}
		current->setData(MXI, current->getData(MXI) + fx * dt);
		current->setData(MYI, current->getData(MYI) + fy * dt);
//		current->setData(MZI, current->getData(MZI) + fz * dt);
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
				0);
//				current->getData(MZI) * dt);
		float x = current->getX();
		float y = current->getY();
		if (isnan(x) || isnan(y)) {
			printf("NANTIME!!\n");
			exit(1);
		}
		if (x < WALL_MINX) {
			current->setData(MXI, -current->getData(MXI) * .9f);
			current->setX(WALL_MINX);
		} else if (x > WALL_MAXX) {
			current->setData(MXI, -current->getData(MXI) * .9f);
			current->setX(WALL_MAXX);
		}
		if (y < WALL_MINY) {
			current->setData(MYI, 0);
			current->setY(WALL_MINY);
		} else if (y > WALL_MAXY) {
			current->setData(MYI, 0);
			current->setY(WALL_MAXY);
		}
	}
}
