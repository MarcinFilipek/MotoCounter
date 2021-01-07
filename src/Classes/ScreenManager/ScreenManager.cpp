/*
 * ScreenManager.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#include "ScreenManager.h"

void ScreenManager::init(Lcd* lcd, Screen* scArr, uint8_t numberOfSc)
{
	screenArr = scArr;
	numberOfScreens = numberOfSc;
	for(uint8_t i=0; i<numberOfScreens; i++)
	{
		screenArr[i].init(lcd);
	}
}

void ScreenManager::update()
{
	screenArr[actualScreenIndex].render();
}
