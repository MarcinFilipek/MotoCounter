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

class Driver {
public:
	Driver(){}
	virtual ~Driver(){}
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

	void printMotohour();
	void checkMotohours();
	void updateMinutes();
};

#endif /* DRIVER_DRIVER_H_ */
