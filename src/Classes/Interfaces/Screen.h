/*
 * Screen.h
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#ifndef CLASSES_INTERFACES_SCREEN_H_
#define CLASSES_INTERFACES_SCREEN_H_

#include "Lcd.h"

class Screen
{
public:
	void init(Lcd* l)
	{
		lcd = l;
	}
	virtual void render(void) = 0;
protected:
	Lcd* lcd;
};

#endif /* CLASSES_INTERFACES_SCREEN_H_ */
