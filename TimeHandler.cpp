/*
 * TimeHandler.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#include "TimeHandler.h"

TimeHandler::TimeHandler(float deltaTime, float length) {
	this->time = 0;
	this->deltaTime = deltaTime;
	this->length = length;
}

TimeHandler::~TimeHandler() {
	// TODO Auto-generated destructor stub
}

float TimeHandler::getTime() {
	return time;
}

float TimeHandler::getDeltaTime() {
	return this->deltaTime;
}

void TimeHandler::incrementTime() {
	time += deltaTime;
}

void TimeHandler::setDeltaTime(float deltaTime) {
	this->time += this->deltaTime;
}

int TimeHandler::isDone() {
	return (time >= length);
}
