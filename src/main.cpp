#include <stddef.h>
#include "stm32l0xx.h"
#include "hal.h"
#include "hardware.h"
#include "button.h"
#include "timer.h"
#include "Driver.h"

void SystemClock_Config();
void TurnOnWorkingClock();
void initPinBuzzer();

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	TurnOnWorkingClock();
	CTimer::classInit1000(HAL_GetTick);
	CButton button1;
	CButton button2;
	CButton button3;
	CButton button4;
	Driver driver;

	button1.init(BUTTON_1_PORT, BUTTON_1_PIN);
	button2.init(BUTTON_2_PORT, BUTTON_2_PIN);
	button3.init(BUTTON_3_PORT, BUTTON_3_PIN);
	button4.init(BUTTON_4_PORT, BUTTON_4_PIN);

	driver.init();
	while(true){
		driver.update();
	}
}

void SystemClock_Config() {
	  RCC_ClkInitTypeDef RCC_ClkInitStruct;
	  RCC_OscInitTypeDef RCC_OscInitStruct;
	  RCC_PeriphCLKInitTypeDef PeriphClkInit;

	  __HAL_RCC_PWR_CLK_ENABLE();

	  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_MSI;
	  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
	  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
	  RCC_OscInitStruct.MSICalibrationValue=0x00;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	  HAL_RCC_OscConfig(&RCC_OscInitStruct);

	  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);

	  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
	  PeriphClkInit.RTCClockSelection = RCC_CSR_RTCSEL_LSI;
	  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);
}

void TurnOnWorkingClock(void) {
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();
}
