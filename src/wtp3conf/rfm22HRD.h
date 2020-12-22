#ifndef RFM22_HRD_H_
#define RFM22_HRD_H_

/**************/
/*STM32L0 VERSION*/
/**************/

/** Interrupt request pin of transceiver */
#define RFM22_INT_PORT_ENABLE()     __GPIOC_CLK_ENABLE()
#define RFM22_INT_PORT              GPIOC
#define RFM22_INT_BIT               GPIO_PIN_4

/** Interrupt NVIC config*/
#define RFM22_IRQ                   EXTI4_15_IRQn

#define RFM22_SPI_HANDLE            hspi1

/** SDN pin */
#define RFM22_SDN_PORT_ENABLE()     __GPIOC_CLK_ENABLE()
#define RFM22_SDN_PORT              GPIOC
#define RFM22_SDN_BIT               GPIO_PIN_5

/** chip select pin */
#define RFM22_SPI_CS_PORT_ENABLE()  __GPIOA_CLK_ENABLE()
#define RFM22_SPI_CS_PORT           GPIOA
#define RFM22_SPI_CS_BIT            GPIO_PIN_4

#endif //RFM22_HRD_H_
