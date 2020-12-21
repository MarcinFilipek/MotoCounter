/*
 * HardwareInterrupt.h
 *
 *  Created on: 16.07.2019
 *      Author: marcin
 */

#ifndef HARDWAREINTERRUPT_HARDWAREINTERRUPT_H_
#define HARDWAREINTERRUPT_HARDWAREINTERRUPT_H_


#ifdef __cplusplus
extern "C"
{
#endif

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* HARDWAREINTERRUPT_HARDWAREINTERRUPT_H_ */
