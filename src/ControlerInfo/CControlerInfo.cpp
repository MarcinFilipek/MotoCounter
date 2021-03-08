/*
 * CControlerInfo.cpp
 *
 *  Created on: 31 sty 2016
 *      Author: marcin
 */

#include "CControlerInfo.h"

uint32_t CControlerInfo::m_cpuid_1 = *(uint32_t *) 0x1FF80050;
uint32_t CControlerInfo::m_cpuid_2 = *(uint32_t *) 0x1FF80054;
uint32_t CControlerInfo::m_cpuid_3 = *(uint32_t *) 0x1FF80064;
EEPROMVar CControlerInfo::m_eepromInitialization = EEPROMVar(sizeof(uint16_t));
EEPROMVar CControlerInfo::m_eeppromMotominutes = EEPROMVar(sizeof(uint16_t));
EEPROMVar CControlerInfo::m_eeppromMotohours = EEPROMVar(sizeof(MOTOHOUR));
EEPROMVar CControlerInfo::m_eeppromMaxMotohours = EEPROMVar(sizeof(MOTOHOUR));

CControlerInfo::CControlerInfo() {
	if (getStatusInitialization() != INITIATED) {
		m_eepromInitialization = (uint16_t) INITIATED;
		m_eeppromMotohours = (MOTOHOUR)0;
		m_eeppromMotominutes = (uint16_t)0;
		m_eeppromMaxMotohours = (MOTOHOUR)400;
	}
}

CControlerInfo::TStatusInitialization CControlerInfo::getStatusInitialization() {
	uint8_t temp;
	temp = m_eepromInitialization;
	return (TStatusInitialization) temp;
}

void CControlerInfo::deinitialization() {
	m_eepromInitialization = (uint8_t) NO_INITIATED;
}

MOTOHOUR CControlerInfo::getMotohours() {
	MOTOHOUR temp;
	temp = m_eeppromMotohours;
	return temp;
}

void CControlerInfo::setMotohours(MOTOHOUR val) {
	m_eeppromMotohours = val;
}

uint8_t CControlerInfo::getMotominutes() {
	uint8_t temp;
	temp = m_eeppromMotominutes;
	return temp;
}

void CControlerInfo::setMotominutes(uint8_t val) {
	m_eeppromMotominutes = val;
}

MOTOHOUR CControlerInfo::getMaxMotohours() {
	MOTOHOUR temp;
	temp = m_eeppromMaxMotohours;
	return temp;
}

void CControlerInfo::setMaxMotohours(MOTOHOUR val) {
	m_eeppromMaxMotohours = val;
}

uint32_t CControlerInfo::getCpuId_1() {
	return m_cpuid_1;
}

uint32_t CControlerInfo::getCpuId_2() {
	return m_cpuid_2;
}

uint32_t CControlerInfo::getCpuId_3() {
	return m_cpuid_3;
}
