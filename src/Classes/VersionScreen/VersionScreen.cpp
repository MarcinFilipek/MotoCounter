/*
 * VersionScreen.cpp
 *
 *  Created on: Dec 21, 2020
 *      Author: marcin
 */

#include "VersionScreen.h"
#include "stdlib.h"

void VersionScreen::render()
{
	char buffer[Lcd::NUM_OF_DIG] =
	{ 0 };
	itoa(VERSION, buffer, 10);
	uint8_t i = 0;
	while (buffer[i])
	{
		lcd->writeChar((uint8_t*) &buffer[i], i + 5);
		i++;
	}
	lcd->print2ndColon(true);
	lcd->printDot(true);

}
