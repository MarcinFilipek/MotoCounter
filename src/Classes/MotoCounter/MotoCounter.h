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
#include "ICommVar.h"
#include "CommVar.h"

class MotoCounter: public IWtp3Device
{
public:
	MotoCounter() :
			controlerInfo(0)
	{
		nextInspection.setCommand(CounterCommand::SET_NEXT_INSPECTION);
		currentCounter.setCommand(CounterCommand::SET_CURRENT_COUNTER);
		parameters[0] = &nextInspection;
		parameters[1] = &currentCounter;
	}
	virtual ~MotoCounter()
	{
	}
	void init()
	{
	}
	void update();
	uint16_t getDeviceNumber()
	{
		return 1;
	}
	bool sendNeeded()
	{
		for(uint8_t i =0; i<NUM_OF_PARAMS; i++)
		{
			if(parameters[i]->isNewValue())
			{
				return true;
			}
		}
		return false;
	}
	void createFrame(Wtp3Driver* driver);
	ERecFrameResult receiveFrame(Wtp3Driver* driver);
	void setControlerInfo(CControlerInfo* _controlerInfo);
	static const uint32_t COUNTER_CONTROLER_ADDRESS = 1;
private:
	static const uint8_t NUM_OF_PARAMS = 2;
	ICommVar* parameters[NUM_OF_PARAMS];
	CommVar<uint32_t> nextInspection;
	CommVar<uint32_t> currentCounter;

	CControlerInfo* controlerInfo;
	void handlePackage(uint8_t command, uint32_t data);

	void setMaxMotohours(MOTOHOUR val);
};

#endif /* CLASSES_MOTOCOUNTER_MOTOCOUNTER_H_ */
