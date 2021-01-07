/*
 * AddresScreen.h
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#ifndef CLASSES_ADDRESSSCREEN_ADDRESSCREEN_H_
#define CLASSES_ADDRESSSCREEN_ADDRESSCREEN_H_

#include "Screen.h"
#include "Lcd.h"

class AddresScreen: public Screen
{
public:
	AddresScreen()
	{
	}
	virtual ~AddresScreen()
	{
	}
	void init(Lcd* lcd);
	void render(void);
};

#endif /* CLASSES_ADDRESSSCREEN_ADDRESSCREEN_H_ */
