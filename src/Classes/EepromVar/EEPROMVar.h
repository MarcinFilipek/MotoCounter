/*
 * EEPROMVar.h
 *
 *  Created on: 31 sty 2016
 *      Author: marcin
 */

#ifndef EEPROMVAR_H_
#define EEPROMVAR_H_

#include "hal.h"

class EEPROMVar {
public:
	EEPROMVar(uint16_t size);
	operator uint8_t();
	operator uint16_t();
	operator uint32_t();
	void operator=(uint8_t data);
	void operator=(uint16_t data);
	void operator=(uint32_t data);
private:
	static const uint32_t EEPROM_START = 0x08080000;
	static const uint32_t EEPROM_END = 0x080807FF;
	static uint32_t m_currentAddress;
	uint16_t m_size;
	uint32_t m_address;
protected:
};

#endif /* EEPROMVAR_H_ */
