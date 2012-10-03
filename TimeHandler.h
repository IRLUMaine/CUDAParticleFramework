/*
 * TimeHandler.h
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#ifndef TIMEHANDLER_H_
#define TIMEHANDLER_H_

class TimeHandler {
public:
	TimeHandler(float deltaTime, float length);
	virtual ~TimeHandler();

	float getTime();
	float getDeltaTime();
	void incrementTime();
	void setDeltaTime(float deltaTime);
	int isDone();

private:
	float time;
	float deltaTime;
	float length;
};

#endif /* TIMEHANDLER_H_ */
