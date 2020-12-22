/*
 * Driver.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: marcin
 */

#include "Driver.h"
#include "hardware.h"
#include "stdlib.h"
#include "wtp_address_gen.h"

const uint8_t Driver::MINUTE = 60;
const uint8_t Driver::TIME_UPDATE_MINUTES_EEPROM = 15;
const uint8_t Driver::TIME_UPDATE_HOURS_EEPROM = 60;

void Driver::init() {
	lcd.init();
	lcd.clear();
	alarm.init(BUZZER_PORT, BUZZER_PIN);
	actualScreen = MOTOHOURS;
	actualMotohours = controlerInfo.getMotohours();
	actualMotominutes = controlerInfo.getMotominutes();

	minuteTimer.start(MINUTE);

	versionScreen.init(&lcd);
	wtp_address_gen_init();
	wtp3Driver.init(0, 1, wtp_address_gen_get_address(), 1, RECEIVE_MODE_CONTINUOUS, 170);
}

void Driver::update() {
//	checkMotohours();
	updateMinutes();
	updateScreen();
}

void Driver::printMotohour() {
	char buffer[Lcd::NUM_OF_DIG] = {0};
	itoa(actualMotohours, buffer, 10);
	uint8_t i = 0;
	while(buffer[i]) {
		lcd.writeChar((uint8_t*)&buffer[i], i);
		i++;
	}
}

void Driver::checkMotohours() {
	if (controlerInfo.getMaxMotohours() < controlerInfo.getMotohours()) {
		alarm.on();
	} else {
		alarm.off();
	}
}

void Driver::updateMinutes() {
	if(minuteTimer.isElapsed()) {
		minuteTimer.start(MINUTE);
		actualMotominutes++;
		if (actualMotominutes % TIME_UPDATE_MINUTES_EEPROM == 0) {
			controlerInfo.setMotominutes(actualMotominutes);
		}
		if(actualMotominutes == TIME_UPDATE_HOURS_EEPROM) {
			actualMotominutes = 0;
			actualMotohours++;
			controlerInfo.setMotohours(actualMotohours);
		}
	}
}

void Driver::updateScreen() {
	switch(actualScreen){
	case VERSION:
		versionScreen.printVerison();
		break;
	case ADDRES:
	case MOTOHOURS:
		printMotohour();
		break;
	}
}
