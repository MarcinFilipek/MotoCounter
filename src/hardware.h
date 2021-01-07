/*
 * hardware.h
 *
 *  Created on: Feb 29, 2020
 *      Author: marcin
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

#define BUZZER_PORT GPIOC
#define BUZZER_PIN GPIO_PIN_12

// radio defined in rfm22HRD.h
//spi
#define SPI_1_SCK_PORT GPIOA
#define SPI_1_SCK_PIN GPIO_PIN_5

#define SPI_1_MISO_PORT GPIOA
#define SPI_1_MISO_PIN GPIO_PIN_6

#define SPI_1_MOSI_PORT GPIOA
#define SPI_1_MOSI_PIN GPIO_PIN_7

//lcd
#define LCD_COM0_PORT GPIOA
#define LCD_COM0_PIN GPIO_PIN_8

#define LCD_COM1_PORT GPIOA
#define LCD_COM1_PIN GPIO_PIN_9

#define LCD_COM2_PORT GPIOA
#define LCD_COM2_PIN GPIO_PIN_10

#define LCD_COM3_PORT GPIOB
#define LCD_COM3_PIN GPIO_PIN_9

#define LCD_VLCD1_PORT GPIOB
#define LCD_VLCD1_PIN  GPIO_PIN_2

#define LCD_VLCD2_PORT GPIOB
#define LCD_VLCD2_PIN  GPIO_PIN_12

#define LCD_VLCD3_PORT GPIOB
#define LCD_VLCD3_PIN  GPIO_PIN_0

#define LCD_SEG0_PORT GPIOA
#define LCD_SEG0_PIN GPIO_PIN_1

#define LCD_SEG1_PORT GPIOA
#define LCD_SEG1_PIN GPIO_PIN_2

#define LCD_SEG2_PORT GPIOA
#define LCD_SEG2_PIN GPIO_PIN_3

#define LCD_SEG6_PORT GPIOB
#define LCD_SEG6_PIN GPIO_PIN_1

#define LCD_SEG11_PORT GPIOB
#define LCD_SEG11_PIN GPIO_PIN_11

#define LCD_SEG13_PORT GPIOB
#define LCD_SEG13_PIN GPIO_PIN_13

#define LCD_SEG14_PORT GPIOB
#define LCD_SEG14_PIN GPIO_PIN_14

#define LCD_SEG15_PORT GPIOB
#define LCD_SEG15_PIN GPIO_PIN_15

#define LCD_SEG18_PORT GPIOC
#define LCD_SEG18_PIN GPIO_PIN_0

#define LCD_SEG19_PORT GPIOC
#define LCD_SEG19_PIN GPIO_PIN_1

#define LCD_SEG20_PORT GPIOC
#define LCD_SEG20_PIN GPIO_PIN_2

#define LCD_SEG21_PORT GPIOC
#define LCD_SEG21_PIN GPIO_PIN_3

#define LCD_SEG24_PORT GPIOC
#define LCD_SEG24_PIN GPIO_PIN_6

#define LCD_SEG25_PORT GPIOC
#define LCD_SEG25_PIN GPIO_PIN_7

#define LCD_SEG26_PORT GPIOC
#define LCD_SEG26_PIN GPIO_PIN_8

#define LCD_SEG27_PORT GPIOC
#define LCD_SEG27_PIN GPIO_PIN_9

#endif /* HARDWARE_H_ */
