/*
 * digitMap.h
 *
 *  Created on: Mar 9, 2020
 *      Author: marcin
 */

#ifndef CLASSES_LCD_DIGITMAP_H_
#define CLASSES_LCD_DIGITMAP_H_

//		  0
//		 ---
//	5	| 6	|	1
//		 ---
//	4	| 3	|	2
//		 ---
//

static const uint8_t digitMap[10] = {
		0b00111111,						//0
		0b00000110,						//1
		0b01011011,						//2
		0b01001111,						//3
		0b01100110,						//4
		0b01101101,						//5
		0b01111101,						//6
		0b00000111,						//7
		0b01111111,						//8
		0b01101111,						//9
};


#endif /* CLASSES_LCD_DIGITMAP_H_ */
