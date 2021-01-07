/*
 * VersionScreen.h
 *
 *  Created on: Dec 21, 2020
 *      Author: marcin
 */

#ifndef CLASSES_VERSIONSCREEN_VERSIONSCREEN_H_
#define CLASSES_VERSIONSCREEN_VERSIONSCREEN_H_

#include "Screen.h"

class VersionScreen: public Screen
{
public:
	static const uint16_t VERSION = 100;
	void render(void);
};

#endif /* CLASSES_VERSIONSCREEN_VERSIONSCREEN_H_ */
