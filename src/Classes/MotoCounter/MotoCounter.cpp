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

ERecFrameResult MotoCounter::receiveFrame(Wtp3Driver* driver)
{
	uint8_t command = 0;
	uint32_t data = 0;
	driver->readNextCmd(&command, (uint8_t*)&data);
	handlePackage(command, data);
	return REC_FRAME_NO_ANSWER;
}

void MotoCounter::handlePackage(uint8_t command, uint32_t data)
{
	command-=128;
	switch(command)
	{
	case 1:
	{
		MOTOHOUR actualMotohours = controlerInfo->getMotohours();
		controlerInfo->setMaxMotohours(actualMotohours + data);
		break;
	}
	case 2:
		controlerInfo->setMotohours(data);
		break;
	default:
		break;
	}
}
