/*
 * ScreenManager.h
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#ifndef CLASSES_SCREENMANAGER_SCREENMANAGER_H_
#define CLASSES_SCREENMANAGER_SCREENMANAGER_H_

#include "Screen.h"
#include "Lcd.h"
#include "timer.h"

class ScreenManager
{
public:
	ScreenManager():
		screenArr(0),
		numberOfScreens(0),
		actualScreenIndex(0)
	{
	}
	virtual ~ScreenManager()
	{
	}
	void init(Lcd* lcd, Screen** scArr, uint8_t numberOfSc);
	void update(void);
private:
	Screen** screenArr;
	uint8_t numberOfScreens;
	uint8_t actualScreenIndex;
	CTimer screenTimer;
};

#endif /* CLASSES_SCREENMANAGER_SCREENMANAGER_H_ */
