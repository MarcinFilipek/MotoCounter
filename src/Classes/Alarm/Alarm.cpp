/*
 * Alarm.cpp
 *
 *  Created on: Feb 29, 2020
 *      Author: marcin
 */

#include "Alarm.h"

void Alarm::init(GPIO_TypeDef *port, uint16_t pin) {
	this->port = port;
	this->pin = pin;

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(port, &GPIO_InitStruct);
	off();
}

void Alarm::on() {
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void Alarm::off() {
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

