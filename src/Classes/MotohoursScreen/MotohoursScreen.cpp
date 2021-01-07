/*
 * MotohoursScreen.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#include "MotohoursScreen.h"
#include "stdlib.h"

void MotohoursScreen::updateMotohours(uint16_t motohours)
{
	actualMotohours = motohours;
}

void MotohoursScreen::render()
{
	char buffer[Lcd::NUM_OF_DIG] =
	{ 0 };
	itoa(actualMotohours, buffer, 10);
	uint8_t i = 0;
	while (buffer[i])
	{
		lcd->writeChar((uint8_t*) &buffer[i], i);
		i++;
	}
}
