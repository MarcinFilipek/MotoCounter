/*
 * MotoCounter.cpp
 *
 *  Created on: Dec 22, 2020
 *      Author: marcin
 */

#include "MotoCounter.h"

void MotoCounter::setControlerInfo(CControlerInfo* _controlerInfo)
{
	controlerInfo = _controlerInfo;
}

void MotoCounter::update()
{
	nextInspection.setData(controlerInfo->getMaxMotohours(), false);
	currentCounter.setData(controlerInfo->getMotohours(), false);
}

void MotoCounter::createFrame(Wtp3Driver* driver)
{
	driver->startFrame(COUNTER_CONTROLER_ADDRESS, 0x01, 0x01);
	for (uint8_t i = 0; i < NUM_OF_PARAMS; i++)
	{
		if (parameters[i]->isNewValue())
		{
			uint8_t command = parameters[i]->getCommand();
			uint8_t size = parameters[i]->getSize();
			uint8_t* dataPtr = parameters[i]->getDataPtr();
			driver->addLongCommand(command, size, dataPtr);
			parameters[i]->clear();
		}
	}
	driver->endFrame();
}

ERecFrameResult MotoCounter::receiveFrame(Wtp3Driver* driver)
{
	uint8_t command = 0;
	uint32_t data = 0;
	driver->readNextCmd(&command, (uint8_t*)&data);
	handlePackage(command, data);
	bool needAnswer = sendNeeded();
	if(needAnswer)
	{
		createFrame(driver);
		return REC_FRAME_ANSWER;
	}
	return REC_FRAME_NO_ANSWER;
}

void MotoCounter::handlePackage(uint8_t command, uint32_t data)
{
	command-=128;
	switch(command)
	{
	case CounterCommand::INITIALIZATION:
		nextInspection.forceSend();
		currentCounter.forceSend();
		break;
	case CounterCommand::SET_NEXT_INSPECTION:
	{
		MOTOHOUR actualMotohours = controlerInfo->getMotohours();
		setMaxMotohours(actualMotohours + data);
		break;
	}
	case CounterCommand::SET_CURRENT_COUNTER:
		controlerInfo->setMotohours(data);
		break;
	default:
		break;
	}

}

void MotoCounter::setMaxMotohours(MOTOHOUR val)
{
	controlerInfo->setMaxMotohours(val);
	nextInspection.setData(val);
}
