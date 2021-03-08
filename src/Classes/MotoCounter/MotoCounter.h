/*
 * MotoCounter.h
 *
 *  Created on: Dec 22, 2020
 *      Author: marcin
 */

#ifndef CLASSES_MOTOCOUNTER_MOTOCOUNTER_H_
#define CLASSES_MOTOCOUNTER_MOTOCOUNTER_H_

#include "IWtp3Device.h"
#include "CControlerInfo.h"

class MotoCounter: public IWtp3Device
{
public:
	MotoCounter(): controlerInfo(0)
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
	void setControlerInfo(CControlerInfo* _controlerInfo);
private:
	CControlerInfo* controlerInfo;
	void handlePackage(uint8_t command, uint32_t data);
};

#endif /* CLASSES_MOTOCOUNTER_MOTOCOUNTER_H_ */
