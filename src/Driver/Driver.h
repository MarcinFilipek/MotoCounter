/*
 * Driver.h
 *
 *  Created on: Mar 14, 2020
 *      Author: marcin
 */

#ifndef DRIVER_DRIVER_H_
#define DRIVER_DRIVER_H_

#include "EEPROMVar.h"
#include "Lcd.h"
#include "Alarm.h"
#include "CControlerInfo.h"
#include "timer.h"
#include "VersionScreen.h"
#include "AddresScreen.h"
#include "MotohoursScreen.h"
#include "wtp3driver.h"
#include "MotoCounter.h"
#include "ScreenManager.h"

class Driver
{
public:
	Driver() :
			actualMotohours(0), actualMotominutes(0), screens
			{ &versionScreen, &addressScreen, &motohoursScreen }
	{
	}
	virtual ~Driver()
	{
	}
	void init();
	void update();
private:
	static const uint8_t MINUTE;
	static const uint8_t TIME_UPDATE_MINUTES_EEPROM;
	static const uint8_t TIME_UPDATE_HOURS_EEPROM;
	MOTOHOUR actualMotohours;
	uint8_t actualMotominutes;
	CControlerInfo controlerInfo;
	Lcd lcd;
	Alarm alarm;
	CTimer minuteTimer;

	MotoCounter motoCounter;
	IWtp3Device* wtp3Devices[1];
	Wtp3Driver wtp3Driver;

	VersionScreen versionScreen;
	AddresScreen addressScreen;
	MotohoursScreen motohoursScreen;

	ScreenManager screenManager;
	Screen* screens[3];

	void initCommunication(void);
	void initRadioSpi(void);
	void checkMotohours();
	void updateMinutes();
	void updateScreen();
};

#endif /* DRIVER_DRIVER_H_ */
