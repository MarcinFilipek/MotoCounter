/*
 * Alarm.h
 *
 *  Created on: Feb 29, 2020
 *      Author: marcin
 */

#ifndef CLASSES_ALARM_ALARM_H_
#define CLASSES_ALARM_ALARM_H_

#include "hal.h"

class Alarm {
public:
	void init(GPIO_TypeDef *port, uint16_t pin);
	void on();
	void off();
private:
	GPIO_TypeDef* port;
	uint16_t pin;
};

#endif /* CLASSES_ALARM_ALARM_H_ */
