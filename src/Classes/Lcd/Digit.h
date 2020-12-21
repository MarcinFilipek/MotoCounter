/*
 * Digit.h
 *
 *  Created on: Mar 9, 2020
 *      Author: marcin
 */

#ifndef CLASSES_LCD_DIGIT_H_
#define CLASSES_LCD_DIGIT_H_

#include "hal.h"

/*
 * Shift bit on the digit
 *
 *		  d1
 * 		 ---
 * 	d2	|d2	|d1
 * 		 ---
 * 	d2	|d2	|d1
 * 		 ---
 *
 *
 */
class Digit {
public:
	const static uint8_t NUMBER_OF_SEGMENTS = 7;
	void init(uint8_t d1, uint8_t d2);
	void setNumber(uint8_t num);
	uint8_t getSegmentValue();
	inline uint8_t getD1() { return d1; }
	inline uint8_t getD2() { return d2; }
private:
	uint8_t d1;
	uint8_t d2;
	uint8_t num;
};

#endif /* CLASSES_LCD_DIGIT_H_ */
