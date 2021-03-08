/*
 * ScreenManager.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#include "ScreenManager.h"

void ScreenManager::init(Lcd* lcd, Screen** scArr, uint8_t numberOfSc)
{
	screenArr = scArr;
	numberOfScreens = numberOfSc;
	for(uint8_t i=0; i<numberOfScreens; i++)
	{
		screenArr[i]->init(lcd);
	}
	screenTimer.start(5);
}

void ScreenManager::update()
{
	screenArr[actualScreenIndex]->render();
	if(actualScreenIndex < numberOfScreens -1 )
	{
		if(screenTimer.isElapsed())
		{
			screenArr[actualScreenIndex]->exit();
			actualScreenIndex++;
			screenTimer.start(5);
		}
	}
}
