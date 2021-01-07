/*
 * MotoCounter.h
 *
 *  Created on: Dec 22, 2020
 *      Author: marcin
 */

#ifndef CLASSES_MOTOCOUNTER_MOTOCOUNTER_H_
#define CLASSES_MOTOCOUNTER_MOTOCOUNTER_H_

#include "IWtp3Device.h"

class MotoCounter: public IWtp3Device
{
public:
	MotoCounter()
	{
	}
	virtual ~MotoCounter()
	{
	}
	void init()
	{
	}
	void update()
	{
	}
	uint16_t getDeviceNumber()
	{
		return 1;
	}
	bool sendNeeded()
	{
		return false;
	}
	void createFrame(Wtp3Driver* driver)
	{
	}
	ERecFrameResult receiveFrame(Wtp3Driver* driver);
};

#endif /* CLASSES_MOTOCOUNTER_MOTOCOUNTER_H_ */
