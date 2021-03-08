/*
 * MotohoursScreen.cpp
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#include "MotohoursScreen.h"
#include "stdlib.h"
#include "string.h"

void MotohoursScreen::updateMotohours(MOTOHOUR motohours)
{
	actualMotohours = motohours;
}

void MotohoursScreen::render()
{
	char buffer[Lcd::NUM_OF_DIG + 1] =
	{ 0 };
	itoa(actualMotohours, buffer, 10);
	uint8_t len = strlen(buffer);
	uint8_t i = 0, j = 0;
	uint8_t numberOfZero = Lcd::NUM_OF_DIG - len;
	while(i < numberOfZero)
	{
		char zero = '0';
		lcd->writeChar((uint8_t*) &zero, i);
		i++;
	}
	while(buffer[j])
	{
		lcd->writeChar((uint8_t*) &buffer[j], i + j);
		j++;
	}
}
