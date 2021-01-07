/*
 * AddresScreen.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#include "AddresScreen.h"
#include "stdlib.h"

void AddresScreen::init(Lcd* lcd) {
	this->lcd = lcd;
}

void AddresScreen::render(void)
{
	char buffer[Lcd::NUM_OF_DIG] = {0};
	itoa(99999999, buffer, 10);
	uint8_t i = 0;
	while(buffer[i]) {
		lcd->writeChar((uint8_t*)&buffer[i], i);
		i++;
	}
}
