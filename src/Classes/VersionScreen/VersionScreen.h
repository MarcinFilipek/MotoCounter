/*
 * VersionScreen.h
 *
 *  Created on: Dec 21, 2020
 *      Author: marcin
 */

#ifndef CLASSES_VERSIONSCREEN_VERSIONSCREEN_H_
#define CLASSES_VERSIONSCREEN_VERSIONSCREEN_H_

#include "Lcd.h"

class VersionScreen {
public:
	static const uint16_t VERSION = 100;
	void init(Lcd* lcd);
	void printVerison();
private:
	Lcd* lcd;
};

#endif /* CLASSES_VERSIONSCREEN_VERSIONSCREEN_H_ */
