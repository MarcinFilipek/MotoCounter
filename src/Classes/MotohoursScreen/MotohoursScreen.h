/*
 * MotohoursScreen.h
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#ifndef CLASSES_MOTOHOURSSCREEN_MOTOHOURSSCREEN_H_
#define CLASSES_MOTOHOURSSCREEN_MOTOHOURSSCREEN_H_

#include "Screen.h"

class MotohoursScreen: public Screen
{
public:
	MotohoursScreen() :
			actualMotohours(0)
	{
	}
	virtual ~MotohoursScreen()
	{
	}
	void updateMotohours(uint16_t motohours);
	void render(void);
private:
	uint16_t actualMotohours;
};

#endif /* CLASSES_MOTOHOURSSCREEN_MOTOHOURSSCREEN_H_ */
