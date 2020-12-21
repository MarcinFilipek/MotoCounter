/*
 * Lcd.h
 *
 *  Created on: Mar 1, 2020
 *      Author: marcin
 */

#ifndef CLASSES_LCD_LCD_H_
#define CLASSES_LCD_LCD_H_

#include "hal.h"
#include "Digit.h"

class Lcd {
public:
	const static uint8_t NUM_OF_DIG = 8;
	void init();
	void clear();
	void writeChar(uint8_t* ch, uint8_t pos);
private:
	LCD_HandleTypeDef lcdHandler;
	Digit dig[NUM_OF_DIG];
	void pinInit();
	void test();
};

#endif /* CLASSES_LCD_LCD_H_ */
