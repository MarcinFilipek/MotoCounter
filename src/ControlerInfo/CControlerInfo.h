/*
 * CControlerInfo.h
 *
 *  Created on: 31 sty 2016
 *      Author: marcin
 */

#ifndef CCONTROLERINFO_H_
#define CCONTROLERINFO_H_

#include "EEPROMVar.h"
typedef uint16_t MOTOHOUR;

class CControlerInfo {
public:
	typedef enum{
		NO_INITIATED = 0,
		INITIATED = 2
	}TStatusInitialization;
	CControlerInfo(void);
	void deinitialization(void);
	MOTOHOUR getMotohours();
	void setMotohours(MOTOHOUR val);
	uint8_t getMotominutes();
	void setMotominutes(uint8_t val);
	MOTOHOUR getMaxMotohours();
	void setMaxMotohours(MOTOHOUR val);
	TStatusInitialization getStatusInitialization(void);
	static uint32_t getCpuId_1(void);
	static uint32_t getCpuId_2(void);
	static uint32_t getCpuId_3(void);
private:
	static EEPROMVar m_eepromInitialization;
	static EEPROMVar m_eeppromMotohours;
	static EEPROMVar m_eeppromMotominutes;
	static EEPROMVar m_eeppromMaxMotohours;
	static uint32_t m_cpuid_1;
	static uint32_t m_cpuid_2;
	static uint32_t m_cpuid_3;
protected:
};

#endif /* CCONTROLERINFO_H_ */
