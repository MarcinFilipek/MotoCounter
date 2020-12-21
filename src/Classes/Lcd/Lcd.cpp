/*
 * Lcd.cpp
 *
 *  Created on: Mar 1, 2020
 *      Author: marcin
 */

#include "Lcd.h"
#include "hardware.h"

void Lcd::init(){
	dig[0].init(9, 16);
	dig[1].init(7, 8);
	dig[2].init(27, 17);
	dig[3].init(25, 26);
	dig[4].init(23, 22);
	dig[5].init(11, 10);
	dig[6].init(14, 13);
	dig[7].init(24, 15);

	__HAL_RCC_LCD_CLK_ENABLE();
	lcdHandler.Instance = LCD;
	lcdHandler.Init.Prescaler = LCD_PRESCALER_1;
	lcdHandler.Init.Divider = LCD_DIVIDER_16;
	lcdHandler.Init.Duty = LCD_DUTY_1_4;
	lcdHandler.Init.Bias = LCD_BIAS_1_4;
	lcdHandler.Init.VoltageSource = LCD_VOLTAGESOURCE_INTERNAL;
	lcdHandler.Init.Contrast = LCD_CONTRASTLEVEL_3;
	lcdHandler.Init.DeadTime = LCD_DEADTIME_0;
	lcdHandler.Init.PulseOnDuration = LCD_PULSEONDURATION_0;
	lcdHandler.Init.HighDrive = LCD_HIGHDRIVE_1;
	lcdHandler.Init.BlinkMode = LCD_BLINKMODE_OFF;
	lcdHandler.Init.BlinkFrequency = LCD_BLINKFREQUENCY_DIV8;
	lcdHandler.Init.MuxSegment = LCD_MUXSEGMENT_DISABLE;
	/* Initialize the LCD */
	HAL_LCD_Init(&lcdHandler);
	pinInit();
	//todo: poprawic bias i vlcd
	__HAL_SYSCFG_VLCD_CAPA_CONFIG(
			SYSCFG_VLCD_PB0_EXT_CAPA_ON | SYSCFG_VLCD_PB2_EXT_CAPA_ON |SYSCFG_VLCD_PB12_EXT_CAPA_ON );
//	test();
}

void Lcd::pinInit() {
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	GPIO_InitStruct.Pin = LCD_VLCD1_PIN;
	HAL_GPIO_Init(LCD_VLCD1_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_VLCD2_PIN;
	HAL_GPIO_Init(LCD_VLCD2_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_VLCD3_PIN;
	HAL_GPIO_Init(LCD_VLCD3_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = GPIO_AF1_LCD;

	GPIO_InitStruct.Pin = LCD_COM0_PIN;
	HAL_GPIO_Init(LCD_COM0_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_COM1_PIN;
	HAL_GPIO_Init(LCD_COM1_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_COM2_PIN;
	HAL_GPIO_Init(LCD_COM2_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_COM3_PIN;
	HAL_GPIO_Init(LCD_COM3_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG7_PIN;
	HAL_GPIO_Init(LCD_SEG7_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG8_PIN;
	HAL_GPIO_Init(LCD_SEG8_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG9_PIN;
	HAL_GPIO_Init(LCD_SEG9_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG10_PIN;
	HAL_GPIO_Init(LCD_SEG10_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG11_PIN;
	HAL_GPIO_Init(LCD_SEG11_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG13_PIN;
	HAL_GPIO_Init(LCD_SEG13_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG14_PIN;
	HAL_GPIO_Init(LCD_SEG14_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG15_PIN;
	HAL_GPIO_Init(LCD_SEG15_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG16_PIN;
	HAL_GPIO_Init(LCD_SEG16_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG17_PIN;
	HAL_GPIO_Init(LCD_SEG17_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG22_PIN;
	HAL_GPIO_Init(LCD_SEG22_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG23_PIN;
	HAL_GPIO_Init(LCD_SEG23_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG24_PIN;
	HAL_GPIO_Init(LCD_SEG24_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG25_PIN;
	HAL_GPIO_Init(LCD_SEG25_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG26_PIN;
	HAL_GPIO_Init(LCD_SEG26_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = LCD_SEG27_PIN;
	HAL_GPIO_Init(LCD_SEG27_PORT, &GPIO_InitStruct);
}

void Lcd::clear() {
	HAL_LCD_Clear (&lcdHandler);
}

void Lcd::writeChar(uint8_t* ch, uint8_t pos) {
	dig[pos].setNumber(*ch - 0x30);
	uint8_t segVal = dig[pos].getSegmentValue();

	uint32_t R0 = 0x00;
	uint32_t R2 = 0x00;
	uint32_t R4 = 0x00;
	uint32_t R6 = 0x00;

	R0 = ((segVal >> 5) & 0x1) << dig[pos].getD2() | (segVal & 0x1) << dig[pos].getD1();
	R2 = ((segVal >> 4) & 0x1) << dig[pos].getD2() | ((segVal >> 2) & 0x1) << dig[pos].getD1();
	R4 = ((segVal >> 6) & 0x1) << dig[pos].getD2() | ((segVal >> 1) & 0x1) << dig[pos].getD1();
	R6 = ((segVal >> 3) & 0x1) << dig[pos].getD2();

	uint32_t MASK = 0xFFFFFFFF;

	HAL_LCD_Write(&lcdHandler, LCD_RAM_REGISTER0, (MASK & ~(1 << dig[pos].getD2())) & ~(1 << dig[pos].getD1()), R0);
	HAL_LCD_Write(&lcdHandler, LCD_RAM_REGISTER2, (MASK & ~(1 << dig[pos].getD2())) & ~(1 << dig[pos].getD1()), R2);
	HAL_LCD_Write(&lcdHandler, LCD_RAM_REGISTER4, (MASK & ~(1 << dig[pos].getD2())) & ~(1 << dig[pos].getD1()), R4);
	HAL_LCD_Write(&lcdHandler, LCD_RAM_REGISTER6, MASK & ~(1 << dig[pos].getD2()), R6);

	HAL_LCD_UpdateDisplayRequest (&lcdHandler);
}

//todo: usunac funkcje testującą po zakończeniu implementacji lcd i digit
void Lcd::test() {
		for(int i=0; i<16; i++){
			lcdHandler.Instance->RAM[i] = 0xFFFFFFFF;
		}
		HAL_LCD_UpdateDisplayRequest (&lcdHandler);
		for(int i =0; i< 32; i++) {
			uint32_t data = 1 << i;
			HAL_LCD_Write(&lcdHandler, LCD_RAM_REGISTER2, 0 ,data);
			HAL_LCD_UpdateDisplayRequest (&lcdHandler);
			data = 0;	//only debug
		}
}
