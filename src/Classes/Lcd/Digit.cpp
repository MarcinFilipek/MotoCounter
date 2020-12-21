/*
 * Digit.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: marcin
 */

#include <Digit.h>
#include "digitMap.h"

void Digit::init(uint8_t d1, uint8_t d2){
	this->d1 = d1;
	this->d2 = d2;
}

void Digit::setNumber(uint8_t num){
	this->num = num;
}

uint8_t Digit::getSegmentValue() {
	return digitMap[num];
}
