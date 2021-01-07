/*
 * Driver.cpp
 *
 *  Created on: Mar 14, 2020
 *      Author: marcin
 */

#include "Driver.h"
#include "hardware.h"
#include "rfm22HRD.h"
#include "stdlib.h"
#include "wtp_address_gen.h"

const uint8_t Driver::MINUTE = 60;
const uint8_t Driver::TIME_UPDATE_MINUTES_EEPROM = 15;
const uint8_t Driver::TIME_UPDATE_HOURS_EEPROM = 60;

void Driver::init()
{
	lcd.init();
	lcd.clear();
	alarm.init(BUZZER_PORT, BUZZER_PIN);
	actualMotohours = controlerInfo.getMotohours();
	actualMotominutes = controlerInfo.getMotominutes();

	minuteTimer.start(MINUTE);
	screenManager.init(&lcd, screens[0], 3);
	initCommunication();
}

void Driver::update()
{
//	checkMotohours();
	updateMinutes();
	motohoursScreen.updateMotohours(actualMotohours);
	screenManager.update();
	wtp3Driver.update();
}

void Driver::checkMotohours()
{
	if (controlerInfo.getMaxMotohours() < controlerInfo.getMotohours())
	{
		alarm.on();
	}
	else
	{
		alarm.off();
	}
}

void Driver::updateMinutes()
{
	if (minuteTimer.isElapsed())
	{
		minuteTimer.start(MINUTE);
		actualMotominutes++;
		if (actualMotominutes % TIME_UPDATE_MINUTES_EEPROM == 0)
		{
			controlerInfo.setMotominutes(actualMotominutes);
		}
		if (actualMotominutes == TIME_UPDATE_HOURS_EEPROM)
		{
			actualMotominutes = 0;
			actualMotohours++;
			controlerInfo.setMotohours(actualMotohours);
		}
	}
}

void Driver::initCommunication(void)
{
	wtp3Devices[0] = &motoCounter;
	wtp_address_gen_init();
	uint32_t address = wtp_address_gen_get_address();
	initRadioSpi();
	wtp3Driver.init(wtp3Devices, 1, address, 1, RECEIVE_MODE_CONTINUOUS, 170);
}

void Driver::initRadioSpi(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	__SPI1_CLK_ENABLE();

	GPIO_InitStruct.Pin = SPI_1_SCK_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF0_SPI1;
	HAL_GPIO_Init(SPI_1_SCK_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = SPI_1_MISO_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF0_SPI1;
	HAL_GPIO_Init(SPI_1_MISO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = SPI_1_MOSI_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF0_SPI1;
	HAL_GPIO_Init(SPI_1_MOSI_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = RFM22_SPI_CS_BIT;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = 0;
	HAL_GPIO_Init(RFM22_SPI_CS_PORT, &GPIO_InitStruct);
}
