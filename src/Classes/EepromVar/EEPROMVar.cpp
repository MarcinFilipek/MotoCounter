/*
 * EEPROMVar.cpp
 *
 *  Created on: 31 sty 2016
 *      Author: marcin
 */

#include "EEPROMVar.h"

uint32_t EEPROMVar::m_currentAddress = 0;

EEPROMVar::EEPROMVar(uint16_t size) {
	m_size = size;
	m_address = m_currentAddress;
	m_currentAddress += m_size;
}

void EEPROMVar::operator=(uint8_t data) {
	if(m_size > sizeof(uint8_t)){
		return;
	}
	HAL_DATA_EEPROMEx_Unlock();
//	HAL_DATA_EEPROMEx_Program(TYPEPROGRAM_BYTE, EEPROM_START + m_address, data);
	HAL_DATA_EEPROMEx_Program(FLASH_TYPEPROGRAMDATA_BYTE, EEPROM_START + m_address, data);
	HAL_DATA_EEPROMEx_Lock();
}

void EEPROMVar::operator=(uint16_t data) {
	if(m_size > sizeof(uint16_t)){
		return;
	}
	HAL_DATA_EEPROMEx_Unlock();
//	HAL_DATA_EEPROMEx_Program(TYPEPROGRAM_HALFWORD, EEPROM_START + m_address, data);
	HAL_DATA_EEPROMEx_Program(FLASH_TYPEPROGRAMDATA_HALFWORD, EEPROM_START + m_address, data);
	HAL_DATA_EEPROMEx_Lock();
}

void EEPROMVar::operator=(uint32_t data) {
	if(m_size > sizeof(uint32_t)){
		return;
	}
	HAL_DATA_EEPROMEx_Unlock();
//	HAL_DATA_EEPROMEx_Program(TYPEPROGRAM_WORD, EEPROM_START + m_address, data);
	HAL_DATA_EEPROMEx_Program(FLASH_TYPEPROGRAMDATA_WORD, EEPROM_START + m_address, data);
	HAL_DATA_EEPROMEx_Lock();
}

EEPROMVar::operator uint8_t() {
	uint8_t tmp = 0;
	tmp = *(__IO uint8_t*)(EEPROM_START+m_address);
	return tmp;
}

EEPROMVar::operator uint16_t() {
	uint16_t tmp = 0;
	tmp = *(uint16_t*)(EEPROM_START+m_address);
	return tmp;
}

EEPROMVar::operator uint32_t() {
	uint32_t tmp = 0;
	tmp = *(uint32_t*)(EEPROM_START+m_address);
	return tmp;
}
