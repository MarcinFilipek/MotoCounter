/*
 * MotohoursScreen.h
 *
 *  Created on: Jan 5, 2021
 *      Author: marcin
 */

#ifndef CLASSES_MOTOHOURSSCREEN_MOTOHOURSSCREEN_H_
#define CLASSES_MOTOHOURSSCREEN_MOTOHOURSSCREEN_H_

#include "Screen.h"
#include "definition.h"

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
	void updateMotohours(MOTOHOUR motohours);
	void render(void);
	void exit(void){}
private:
	MOTOHOUR actualMotohours;
};

#endif /* CLASSES_MOTOHOURSSCREEN_MOTOHOURSSCREEN_H_ */
