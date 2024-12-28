/**
 * @file GPIO_STM32_DRIVER.h
 * @brief Header file containing GPIO driver implementations for STM32 microcontrollers
 * @details This file provides the interface definitions and function declarations for
 *          configuring and controlling General Purpose Input/Output (GPIO) pins on
 *          STM32 microcontrollers. It includes pin configurations, port operations,
 *          and interrupt handling capabilities.
 *
 * @author Vivek K J
 * @date   2024-12-28
 *
 * @note This driver supports various STM32 microcontroller families
 */

#ifndef INC_GPIO_STM32_DRIVER_H_
#define INC_GPIO_STM32_DRIVER_H_


/* macro declaration of various function of GPIO */
#define 	GPIO_MODE_IN	 	0	 	// Setting mode of GPIO
#define 	GPIO_MODE_OP	 	1
#define 	GPIO_MODE_ALTF	 	2
#define 	GPIO_MODE_ANALOG 	3
#define 	GPIO_MODE_IT_FT	 	4
#define 	GPIO_MODE_IT_RT	 	5

/* GPIO OUTPUT TYPE CONFIGURATION */
#define 	GPIO_OP_TYPE_PP		0		//Setting push pull for GPIO pin
#define 	GPIO_OP_TYPE_OD		1 

/* GPIO SPEED CONFIGURATION */
#define 	GPIO_SPEED_LOW		0
#define 	GPIO_SPEED_MEDIUM	1		// Setting speed of GPIO pin
#define 	GPIO_SPEED_FAST		2

/* GPIO PULL UP/DOWN CONFIGURATION */
#define		GPIO_NO_PUPD		0
#define		GPIO_PIN_PU			1		// Setting pull up/down for GPIO pin
#define		GPIO_PIN_PD			2

/* GPIO PIN NUMBER */
#define		GPIO_PIN_NO_0		0		// Setting for pin selection
#define		GPIO_PIN_NO_1		1
#define		GPIO_PIN_NO_2		2
#define		GPIO_PIN_NO_3		3
#define		GPIO_PIN_NO_4		4
#define		GPIO_PIN_NO_5		5
#define		GPIO_PIN_NO_6		6
#define		GPIO_PIN_NO_7		7
#define		GPIO_PIN_NO_8		8
#define		GPIO_PIN_NO_9		9
#define		GPIO_PIN_NO_10		10
#define		GPIO_PIN_NO_11		11
#define		GPIO_PIN_NO_12		12
#define		GPIO_PIN_NO_13		13
#define		GPIO_PIN_NO_14		14
#define		GPIO_PIN_NO_15		15

/* GPIO ALTERNATE FUNCTION CONFIGURATION */
#define		GPIO_ALTF0			((uint8_t)0x00)		//SYSTEM
#define		GPIO_ALTF1			((uint8_t)0x01)		//TIM1/2
#define		GPIO_ALTF2			((uint8_t)0x02)		//TIM3 TO 5
#define		GPIO_ALTF3			((uint8_t)0x03)		//TIM8 TO 11
#define		GPIO_ALTF4			((uint8_t)0x04)		//I2C1 TO 3
#define		GPIO_ALTF5			((uint8_t)0x05)		//SPI1/2
#define		GPIO_ALTF6			((uint8_t)0x06)		//SPI3
#define		GPIO_ALTF7			((uint8_t)0x07)		//USART1 TO 3
#define		GPIO_ALTF8			((uint8_t)0x08)		//USART4 TO 6
#define		GPIO_ALTF9			((uint8_t)0x09)		//CAN1/2, TIM12 TO 14
#define		GPIO_ALTF10			((uint8_t)0x0A)		//OTG_FS/HS
#define		GPIO_ALTF11			((uint8_t)0x0B)		//ETH
#define		GPIO_ALTF12			((uint8_t)0x0C)		//FSMC, SDIO, OTG_HS
#define		GPIO_ALTF13			((uint8_t)0x0D)		//DCMI
#define		GPIO_ALTF14			((uint8_t)0x0E)		//FPU
#define		GPIO_ALTF15			((uint8_t)0x0F)		//EVENTOUT 		//Setting pin for different alternate function

/*
 *  GPIO PIN CONFIGURATION
 */
typedef struct{
	uint8_t GPIO_PinNumber;			// GPIO pin number
	uint8_t GPIO_PinMode;			// GPIO pin mode
	uint8_t GPIO_PinSpeed;			// GPIO pin speed
	uint8_t GPIO_PinPuPdControl; 	// GPIO pin pull up/pull down control
	uint8_t GPIO_PinOPType; 		// GPIO pin output type
	uint8_t GPIO_PinALTFunction; 	// GPIO pin alternate function
} STRUCT_GPIO_PIN_CONFIG;

/*
 * GPIO HANDLER STRUCT
 */
typedef struct{
	STRUCT_GPIO_REG_DEF 	 *pGPIOx; 				// This holds BA of the GPIO port to which the pin belongs
	STRUCT_GPIO_PIN_CONFIG 	 GPIO_PinConfig;		// this holds GPIO pin configuration
} STRUCT_GPIO_HANDLER;

/*
 *  PROTOTYPE DECLARATION
 */
void GPIO_Init(STRUCT_GPIO_HANDLER *pGPIOHandle );									// initialization
void GPIO_DeInit(STRUCT_GPIO_REG_DEF *pGPIOx);										// de-initialization
void GPIO_PClkCtrl(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t EnorDi);					// peripheral clock
uint8_t GPIO_ReadPin(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t PinNumber);				// Read pin
void GPIO_Toggle(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t PinNumber);					// Toggling pin
void GPIO_High(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t PinNumber);						// led high pin
void GPIO_Low(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t PinNumber);						// led low pin

/*
 *  INTERRUPT PROTOTYPE DECLARATION
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi); 				// interrupt configuration
void GPIO_IRQPriorityconfig(uint8_t IRQNumber, uint32_t IRQPriority); 			// priority configuration
void GPIO_IRQHandling(uint8_t PinNumber); 										// interrupt handling


#endif /* INC_GPIO_STM32_DRIVER_H_ */
