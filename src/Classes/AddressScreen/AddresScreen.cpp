/*
 * AddresScreen.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#include "AddresScreen.h"
#include "stdlib.h"
#include "string.h"

void AddresScreen::init(Lcd* lcd)
{
	this->lcd = lcd;
}

void AddresScreen::setAddress(uint32_t _address)
{
	address = _address;
}

void AddresScreen::render(void)
{
	char buffer[Lcd::NUM_OF_DIG + 1] =
	{ 0 };
	itoa(address, buffer, 10);
	uint8_t startPos = Lcd::NUM_OF_DIG - strlen(buffer);
	uint8_t i = 0;
	while (buffer[i])
	{
		lcd->writeChar((uint8_t*) &buffer[i], i + startPos);
		i++;
	}
}
