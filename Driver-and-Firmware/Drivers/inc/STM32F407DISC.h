/**
 * @file  STM32F407DISC.h
 * @brief Header file for STM32F407 Discovery board configurations and definitions
 *
 * This file contains pin mappings, peripheral configurations, and hardware-specific
 * definitions for the STM32F407 Discovery development board. It provides the necessary
 * declarations and macros to interface with the board's features and peripherals.
 *
 * @note This header is specifically designed for use with STM32F407 Discovery board
 *
 * @author Vivek K J
 * @date   2024-12-28
 */

#ifndef INC_STM32F407DISC_H_
#define INC_STM32F407DISC_H_

/*****************************************************************
 * INCLUDES
 *****************************************************************/
#include <stdint.h>

/*****************************************************************
 * MACRO DECLARATION
 *****************************************************************/

#define 	ENABLE				1
#define 	DISABLE				0
#define		SET					ENABLE
#define		RESET				DISABLE
#define		GPIO_PIN_SET		SET
#define		GPIO_PIN_RESET		RESET
#define		FLAG_SET			SET
#define 	FLAG_RESET			RESET

/*****************************************************************
 * BUS Address Declaration
 *****************************************************************/

#define		AHB1_BASEADDR 		0x40020000U
#define		AHB2_BASEADDR 		0x50000000U
#define		AHB3_BASEADDR 		0xA0000000U

#define		APB1_BASEADDR 		0x40000000U
#define		APB2_BASEADDR 		0x40010000U

/*****************************************************************
 * BASE ADDRESS DECLARATION OF PERIPHERALS
 *****************************************************************/

#define		RCC_BASEADDR		(AHB1_BASEADDR + 0x3800)			// RCC BASE ADDRESS, BA of AHB1_BUS + OFFSET

#define		GPIOA_BASEADDR 		(AHB1_BASEADDR + 0x0000)			// GPIO base address, BA of AHB1_BUS + OFFSET
#define		GPIOB_BASEADDR 		(AHB1_BASEADDR + 0x0400)
#define		GPIOC_BASEADDR 		(AHB1_BASEADDR + 0x0800)
#define		GPIOD_BASEADDR 		(AHB1_BASEADDR + 0x0C00)
#define		GPIOE_BASEADDR 		(AHB1_BASEADDR + 0x1000)
#define		GPIOH_BASEADDR 		(AHB1_BASEADDR + 0x1C00)			// GPIO base address, BA of AHB1_BUS + OFFSET

#define		SPI1_BASEADDR 		(APB2_BASEADDR + 0x3000)			// SPI1 base address, BA of APB2_BUS + OFFSET
#define		SPI2_BASEADDR 		(APB1_BASEADDR + 0x3800)			// SPI2/3 base address, BA of APB1_BUS + OFFSET
#define		SPI3_BASEADDR 		(APB1_BASEADDR + 0x3C00)

#define		I2C1_BASEADDR 		(APB1_BASEADDR + 0x5400)			// I2C1 TO 3 base address, BA of APB1_BUS + OFFSET
#define		I2C2_BASEADDR 		(APB1_BASEADDR + 0x5800)
#define		I2C3_BASEADDR 		(APB1_BASEADDR + 0x5C00)

#define		TIM2_BASEADDR 		(APB1_BASEADDR + 0x0000)			// TIMER 2 TO 5 base address, BA of APB1_BUS + OFFSET
#define		TIM3_BASEADDR 		(APB1_BASEADDR + 0x0400)
#define		TIM4_BASEADDR 		(APB1_BASEADDR + 0x0800)
#define		TIM5_BASEADDR 		(APB1_BASEADDR + 0x0C00)

#define		ADC1_BASEADDR 		(APB2_BASEADDR + 0x2000)			// ADC 1 TO 3 base address, BA of APB1_BUS + OFFSET
#define		ADC2_BASEADDR 		(APB2_BASEADDR + 0x2100)
#define		ADC3_BASEADDR 		(APB2_BASEADDR + 0x2200)

#define		EXTI_BASEADDR		(APB2_BASEADDR + 0x3C00)
#define		SYNCFG_BASEADDR		(APB2_BASEADDR + 0x3800)
#define 	NVIC_PR_BASE_ADDR	((volatile uint32_t*)0xE000E400)

/*****************************************************************
 * ARM CORTEX NVIC ISER BIT DEFINITION
 *****************************************************************/
#define 	NVIC_ISER0  		((volatile uint32_t*)0xE000E100)
#define 	NVIC_ISER1  		((volatile uint32_t*)0xE000E104)
#define 	NVIC_ISER2  		((volatile uint32_t*)0xE000E108)
#define 	NVIC_ISER3  		((volatile uint32_t*)0xE000E10C)

/*****************************************************************
 * ARM CORTEX NVIC ICER BIT DEFINITION
 *****************************************************************/
#define 	NVIC_ICER0  		((volatile uint32_t*)0xE000E180)
#define 	NVIC_ICER1  		((volatile uint32_t*)0xE000E184)
#define 	NVIC_ICER2  		((volatile uint32_t*)0xE000E188)
#define 	NVIC_ICER3  		((volatile uint32_t*)0xE000E18C)

/*****************************************************************
 * NVIC DECLARATION & PRIORITY BIT DEFINITION
 *****************************************************************/
#define 	IRQ_NO_EXTI0				6
#define 	IRQ_NO_EXTI1				7
#define 	IRQ_NO_EXTI2				8
#define 	IRQ_NO_EXTI3				9
#define 	IRQ_NO_EXTI4				10
#define 	IRQ_NO_EXTI9_5				23
#define 	IRQ_NO_EXTI5_10				40

#define 	NVIC_INTERRUPT_0			0
#define 	NVIC_INTERRUPT_1			1
#define 	NVIC_INTERRUPT_2			2
#define 	NVIC_INTERRUPT_3			3
#define 	NVIC_INTERRUPT_4			4
#define 	NVIC_INTERRUPT_5			5
#define 	NVIC_INTERRUPT_6			6
#define 	NVIC_INTERRUPT_7			7
#define 	NVIC_INTERRUPT_8			8
#define 	NVIC_INTERRUPT_9			9
#define 	NVIC_INTERRUPT_10			10
#define 	NVIC_INTERRUPT_11			11
#define 	NVIC_INTERRUPT_12			12
#define 	NVIC_INTERRUPT_13			13
#define 	NVIC_INTERRUPT_14			14
#define 	NVIC_INTERRUPT_15			15

#define 	NO_PR_BITS_IMPLEMENTED		4

/*****************************************************************
 *PERIPHERAL DEFINITION MACROS
 *****************************************************************/
#define		RCC 				((STRUCT_RCC_REG_DEF*)RCC_BASEADDR) 		// RCC BASE ADDRESS

#define 	GPIOA 				((STRUCT_GPIO_REG_DEF*)GPIOA_BASEADDR) 	// GPIO BASE ADDRESS
#define 	GPIOB 				((STRUCT_GPIO_REG_DEF*)GPIOB_BASEADDR)
#define 	GPIOC 				((STRUCT_GPIO_REG_DEF*)GPIOC_BASEADDR)
#define		GPIOD 				((STRUCT_GPIO_REG_DEF*)GPIOD_BASEADDR)
#define		GPIOE 				((STRUCT_GPIO_REG_DEF*)GPIOE_BASEADDR)
#define		GPIOH 				((STRUCT_GPIO_REG_DEF*)GPIOH_BASEADDR)

#define		SPI1 				((STRUCT_SPI_REG_DEF*)SPI1_BASEADDR) 		// SPI BASE ADDRESS
#define		SPI2 				((STRUCT_SPI_REG_DEF*)SPI2_BASEADDR)
#define		SPI3 				((STRUCT_SPI_REG_DEF*)SPI3_BASEADDR)

#define		I2C1 				((STRUCT_I2C_REG_DEF*)I2C1_BASEADDR) 		// I2C BASE ADDRESS
#define		I2C2 				((STRUCT_I2C_REG_DEF*)I2C2_BASEADDR)
#define		I2C3 				((STRUCT_I2C_REG_DEF*)I2C3_BASEADDR)

#define		TIM2 				((STRUCT_TIM25_REG_DEF*)TIM2_BASEADDR) 	// TIMER BASE ADDRESS
#define		TIM3 				((STRUCT_TIM25_REG_DEF*)TIM3_BASEADDR)
#define		TIM4 				((STRUCT_TIM25_REG_DEF*)TIM4_BASEADDR)
#define		TIM5 				((STRUCT_TIM25_REG_DEF*)TIM5_BASEADDR)

#define		ADC1 				((STRUCT_ADC_REG_DEF*)ADC1_BASEADDR) 		// ADC BASE ADDRESS
#define		ADC2 				((STRUCT_ADC_REG_DEF*)ADC2_BASEADDR)
#define		ADC3 				((STRUCT_ADC_REG_DEF*)ADC3_BASEADDR)

#define		EXTI				((STRUCT_EXTI_REG_DEF*)EXTI_BASEADDR) 	// EXTI BASE ADDRESS
#define		SYSCFG				((STRUCT_SYSCFG_REG_DEF*)SYNCFG_BASEADDR) // SYSCFG BASE ADDRESS

/*****************************************************************
 * CLOCK ENABLE BIT DEFINITION
 *****************************************************************/
#define		GPIOA_CLKEN 		((uint8_t)0x00)			// GPIO CLOCK ENABLE
#define		GPIOB_CLKEN 		((uint8_t)0x01)
#define		GPIOC_CLKEN 		((uint8_t)0x02)
#define		GPIOD_CLKEN 		((uint8_t)0x03)
#define		GPIOE_CLKEN 		((uint8_t)0x04)
#define		GPIOH_CLKEN 		((uint8_t)0x07)

#define		SPI1_CLKEN 			((uint8_t)0x0C)			// SPI CLOCK ENABLE
#define		SPI2_CLKEN 			((uint8_t)0x0E)
#define		SPI3_CLKEN 			((uint8_t)0x0F)

#define		I2C1_CLKEN 			((uint8_t)0x15)			// I2C CLOCK ENABLE
#define		I2C2_CLKEN 			((uint8_t)0x16)
#define		I2C3_CLKEN 			((uint8_t)0x17)

#define		TIM2_CLKEN 			((uint8_t)0x00)			// TIMER CLOCK ENABLE
#define		TIM3_CLKEN 			((uint8_t)0x01)
#define		TIM4_CLKEN 			((uint8_t)0x02)
#define		TIM5_CLKEN 			((uint8_t)0x03)

#define		ADC1_CLKEN 			((uint8_t)0x08)			// ADC CLOCK ENABLE
#define		ADC2_CLKEN 			((uint8_t)0x09)
#define		ADC3_CLKEN 			((uint8_t)0x0A)

#define		SYNCFG_CLKEN 		((uint8_t)0x0E)			// SYSCFG CLOCK ENABLE

/*****************************************************************
 * CLOCK DISABLE BIT DEFINITION
 *****************************************************************/
#define		GPIOA_CLKDIS 		((uint8_t)0x00) 		// GPIO CLOCK DISABLE
#define		GPIOB_CLKDIS 		((uint8_t)0x01)
#define		GPIOC_CLKDIS 		((uint8_t)0x02)
#define		GPIOD_CLKDIS 		((uint8_t)0x03)
#define		GPIOE_CLKDIS 		((uint8_t)0x04)
#define		GPIOH_CLKDIS 		((uint8_t)0x07)

#define		SPI1_CLKDIS 		((uint8_t)0x0C)			// SPI CLOCK DISABLE
#define		SPI2_CLKDIS 		((uint8_t)0x0E)
#define		SPI3_CLKDIS 		((uint8_t)0x0F)

#define		I2C1_CLKDIS 		((uint8_t)0x15)			// I2C CLOCK DISABLE
#define		I2C2_CLKDIS 		((uint8_t)0x16)
#define		I2C3_CLKDIS 		((uint8_t)0x17)

#define		TIM2_CLKDIS 		((uint8_t)0x00)			// TIMER CLOCK DISABLE
#define		TIM3_CLKDIS 		((uint8_t)0x01)
#define		TIM4_CLKDIS 		((uint8_t)0x02)
#define		TIM5_CLKDIS 		((uint8_t)0x03)

#define		ADC1_CLKDIS 		((uint8_t)0x08)			// ADC CLOCK DISABLE
#define		ADC2_CLKDIS 		((uint8_t)0x09)
#define		ADC3_CLKDIS 		((uint8_t)0x0A)

#define		SYNCFG_CLKDIS 		((uint8_t)0x0E)			// SYSCFG CLOCK DISABLE

/*****************************************************************
 * PERIPHERAL RESET BIT DEFINITION
 *****************************************************************/
#define		GPIOA_PRST	 		((uint8_t)0x00)			// GPIO PERIPHERAL RESET
#define		GPIOB_PRST 			((uint8_t)0x01)
#define		GPIOC_PRST 			((uint8_t)0x02)
#define		GPIOD_PRST 			((uint8_t)0x03)
#define		GPIOE_PRST 			((uint8_t)0x04)
#define		GPIOH_PRST	 		((uint8_t)0x07)

#define		SPI1_PRST 			((uint8_t)0x0C)			// SPI PERIPHERAL RESET
#define		SPI2_PRST 			((uint8_t)0x0E)
#define		SPI3_PRST 			((uint8_t)0x0F)

#define		I2C1_PRST 			((uint8_t)0x15)			// I2C PERIPHERAL RESET
#define		I2C2_PRST 			((uint8_t)0x16)
#define		I2C3_PRST 			((uint8_t)0x17)

#define		TIM2_PRST 			((uint8_t)0x00)			// TIMER PERIPHERAL RESET
#define		TIM3_PRST 			((uint8_t)0x01)
#define		TIM4_PRST 			((uint8_t)0x02)
#define		TIM5_PRST			((uint8_t)0x03)

#define		ADC1_PRST 			((uint8_t)0x08)			// ADC PERIPHERAL RESET
#define		ADC2_PRST 			((uint8_t)0x09)
#define		ADC3_PRST 			((uint8_t)0x0A)

#define		SYNCFG_PRST	 		((uint8_t)0x0E)			// SYSCFG PERIPHERAL RESET

/*****************************************************************
 * CLOCK ENABLE MACROS
 *****************************************************************/
#define		GPIOA_PCLK_EN()		(RCC -> AHB1ENR |= (ENABLE << GPIOA_CLKEN))
#define		GPIOB_PCLK_EN()		(RCC -> AHB1ENR |= (ENABLE << GPIOB_CLKEN))
#define		GPIOC_PCLK_EN()		(RCC -> AHB1ENR |= (ENABLE << GPIOC_CLKEN))
#define		GPIOD_PCLK_EN()		(RCC -> AHB1ENR |= (ENABLE << GPIOD_CLKEN))
#define		GPIOE_PCLK_EN()		(RCC -> AHB1ENR |= (ENABLE << GPIOE_CLKEN))
#define		GPIOH_PCLK_EN()		(RCC -> AHB1ENR |= (ENABLE << GPIOH_CLKEN))

#define		SYNCFG_PCLK_EN()	(RCC -> APB2ENR |= (ENABLE << SYNCFG_CLKEN))

#define		SPI1_PCLK_EN()		(RCC -> APB2ENR |= (ENABLE << SPI1_CLKEN))
#define		SPI2_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << SPI2_CLKEN))
#define		SPI3_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << SPI3_CLKEN))

#define		I2C1_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << I2C1_CLKEN))
#define		I2C2_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << I2C2_CLKEN))
#define		I2C3_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << I2C3_CLKEN))

#define		TIM2_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << TIM2_CLKEN))
#define		TIM3_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << TIM3_CLKEN))
#define		TIM4_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << TIM4_CLKEN))
#define		TIM5_PCLK_EN()		(RCC -> APB1ENR |= (ENABLE << TIM5_CLKEN))

#define		ADC1_PCLK_EN()		(RCC -> APB2ENR |= (ENABLE << ADC1_CLKEN))
#define		ADC2_PCLK_EN()		(RCC -> APB2ENR |= (ENABLE << ADC2_CLKEN))
#define		ADC3_PCLK_EN()		(RCC -> APB2ENR |= (ENABLE << ADC3_CLKEN))

/*****************************************************************
 * CLOCK DISABLING MACROS
 *****************************************************************/
#define		GPIOA_PCLK_DI()		(RCC -> AHB1ENR &= (DISABLE << GPIOA_CLKDIS))
#define		GPIOB_PCLK_DI()		(RCC -> AHB1ENR &= (DISABLE << GPIOB_CLKDIS))
#define		GPIOC_PCLK_DI()		(RCC -> AHB1ENR &= (DISABLE << GPIOC_CLKDIS))
#define		GPIOD_PCLK_DI()		(RCC -> AHB1ENR &= (DISABLE << GPIOD_CLKDIS))
#define		GPIOE_PCLK_DI()		(RCC -> AHB1ENR &= (DISABLE << GPIOE_CLKDIS))
#define		GPIOH_PCLK_DI()		(RCC -> AHB1ENR &= (DISABLE << GPIOH_CLKDIS))

#define		SYNCFG_PCLK_DI()	(RCC -> APB2ENR &= (DISABLE << SYNCFG_CLKDIS))

#define		SPI1_PCLK_DI()		(RCC -> APB2ENR &= (DISABLE << SPI1_CLKDIS))
#define		SPI2_PCLK_DI()		(RCC -> APB1ENR &= (DISABLE << SPI2_CLKDIS))
#define		SPI3_PCLK_DI()		(RCC -> APB1ENR &= (DISABLE << SPI3_CLKDIS))

#define		I2C1_PCLK_DI()		(RCC -> APB2ENR &= (DISABLE << I2C1_CLKDIS))
#define		I2C2_PCLK_DI()		(RCC -> APB1ENR &= (DISABLE << I2C2_CLKDIS))
#define		I2C3_PCLK_DI()		(RCC -> APB1ENR &= (DISABLE << I2C3_CLKDIS))

#define		TIM2_PCLK_DI()		(RCC -> APB1ENR &= (DISABLE << TIM2_CLKDIS))
#define		TIM3_PCLK_DI()		(RCC -> APB1ENR &= (DISABLE << TIM3_CLKDIS))
#define		TIM4_PCLK_DI()		(RCC -> APB1ENR &= (DISABLE << TIM4_CLKDIS))
#define		TIM5_PCLK_DI()		(RCC -> APB1ENR &= (DISABLE << TIM5_CLKDIS))

#define		ADC1_PCLK_DI()		(RCC -> APB2ENR |= (DISABLE << ADC1_CLKDIS))
#define		ADC2_PCLK_DI()		(RCC -> APB2ENR |= (DISABLE << ADC2_CLKDIS))
#define		ADC3_PCLK_DI()		(RCC -> APB2ENR |= (DISABLE << ADC3_CLKDIS))

/*****************************************************************
 * PERIPHERAL RESET MACROS
 * The Peripheral Reset Registers should cause the peripheral's entire register set and internal state to be reset to power-on defaults
 * not just the registers that are exposed to the user, but also any internal registers, counters, or flags should be set as they would
 * be when the device is initially powered on.
 *****************************************************************/
#define 	GPIOA_REG_RESET()	do{RCC -> AHB1RSTR |= ~(SET << GPIOA_PRST); RCC -> AHB1RSTR &= ~(SET << GPIOA_PRST);}while(0)
#define 	GPIOB_REG_RESET()	do{RCC -> AHB1RSTR |= ~(SET << GPIOB_PRST); RCC -> AHB1RSTR &= ~(SET << GPIOB_PRST);}while(0)
#define 	GPIOC_REG_RESET()	do{RCC -> AHB1RSTR |= ~(SET << GPIOC_PRST); RCC -> AHB1RSTR &= ~(SET << GPIOC_PRST);}while(0)
#define 	GPIOD_REG_RESET()	do{RCC -> AHB1RSTR |= ~(SET << GPIOD_PRST); RCC -> AHB1RSTR &= ~(SET << GPIOD_PRST);}while(0)
#define 	GPIOE_REG_RESET()	do{RCC -> AHB1RSTR |= ~(SET << GPIOE_PRST); RCC -> AHB1RSTR &= ~(SET << GPIOE_PRST);}while(0)
#define 	GPIOH_REG_RESET()	do{RCC -> AHB1RSTR |= ~(SET << GPIOH_PRST); RCC -> AHB1RSTR &= ~(SET << GPIOH_PRST);}while(0)

#define 	SPI1_REG_RESET()	do{RCC -> APB2RSTR |= ~(SET << SPI1_PRST); RCC -> APB2RSTR &= ~(SET << SPI1_PRST);}while(0)
#define 	SPI2_REG_RESET()	do{RCC -> APB1RSTR |= ~(SET << SPI2_PRST); RCC -> APB1RSTR &= ~(SET << SPI2_PRST);}while(0)
#define 	SPI3_REG_RESET()	do{RCC -> APB1RSTR |= ~(SET << SPI3_PRST); RCC -> APB1RSTR &= ~(SET << SPI3_PRST);}while(0)

#define 	I2C1_REG_RESET()	do{RCC -> APB2RSTR |= ~(SET << I2C1_PRST); RCC -> APB2RSTR &= ~(SET << I2C1_PRST);}while(0)
#define 	I2C2_REG_RESET()	do{RCC -> APB1RSTR |= ~(SET << I2C2_PRST); RCC -> APB1RSTR &= ~(SET << I2C2_PRST);}while(0)
#define 	I2C3_REG_RESET()	do{RCC -> APB1RSTR |= ~(SET << I2C3_PRST); RCC -> APB1RSTR &= ~(SET << I2C3_PRST);}while(0)

#define 	TIM2_REG_RESET()	do{RCC -> APB1RSTR |= ~(SET << TIM2_PRST); RCC -> APB1RSTR &= ~(SET << TIM2_PRST);}while(0)
#define 	TIM3_REG_RESET()	do{RCC -> APB1RSTR |= ~(SET << TIM3_PRST); RCC -> APB1RSTR &= ~(SET << TIM3_PRST);}while(0)
#define 	TIM4_REG_RESET()	do{RCC -> APB1RSTR |= ~(SET << TIM4_PRST); RCC -> APB1RSTR &= ~(SET << TIM4_PRST);}while(0)
#define 	TIM5_REG_RESET()	do{RCC -> APB1RSTR |= ~(SET << TIM5_PRST); RCC -> APB1RSTR &= ~(SET << TIM5_PRST);}while(0)

#define 	ADC1_REG_RESET()	do{RCC -> APB2RSTR |= ~(SET << ADC1_PRST); RCC -> APB2RSTR &= ~(SET << ADC1_PRST);}while(0)
#define 	ADC2_REG_RESET()	do{RCC -> APB2RSTR |= ~(SET << ADC2_PRST); RCC -> APB2RSTR &= ~(SET << ADC2_PRST);}while(0)
#define 	ADC3_REG_RESET()	do{RCC -> APB2RSTR |= ~(SET << ADC3_PRST); RCC -> APB2RSTR &= ~(SET << ADC3_PRST);}while(0)

/*****************************************************************
 * RCC CONTROL BIT DEFINITION
 ****************************************************************/
#define 	RCC_HSION				((uint8_t)0x00)
#define 	RCC_HSIRDY				((uint8_t)0x01)
#define 	RCC_HSITRIM				((uint8_t)0x03)
#define 	RCC_HSICAL				((uint8_t)0x08)
#define 	RCC_HSEON				((uint8_t)0x10)
#define 	RCC_HSERDY				((uint8_t)0x11)
#define 	RCC_HSEBYP				((uint8_t)0x12)
#define 	RCC_CSSON				((uint8_t)0x13)
#define 	RCC_PLLON				((uint8_t)0x18)
#define 	RCC_PLLRDY				((uint8_t)0x19)
#define 	RCC_PLLI2SON			((uint8_t)0x1B)
#define 	RCC_PLLSAION			((uint8_t)0x1C)
#define 	RCC_PLLSAIRDY			((uint8_t)0x1D)

/*****************************************************************
 * RCC CONFIGURATION BIT DEFINITION
 ****************************************************************/
#define 	RCC_SW0					((uint8_t)0x00)
#define 	RCC_SW1					((uint8_t)0x01)
#define 	RCC_SWS0				((uint8_t)0x02)
#define 	RCC_SWS1				((uint8_t)0x03)
#define 	RCC_HPRE				((uint8_t)0x04)
#define 	RCC_PPRE1				((uint8_t)0x0A)
#define 	RCC_PPRE2				((uint8_t)0x0D)
#define 	RCC_RTCPRE				((uint8_t)0x10)
#define 	RCC_MCO1				((uint8_t)0x15)
#define 	RCC_I2SSCR				((uint8_t)0x17)
#define 	RCC_MCO1_PRE			((uint8_t)0x18)
#define 	RCC_MCO2_PRE			((uint8_t)0x1B)
#define 	RCC_MCO2				((uint8_t)0x1E)

/*****************************************************************
 * PLL CONFIGURATION BIT DEFINITION
 ****************************************************************/
#define 	RCC_PLLM				((uint8_t)0x00)
#define 	RCC_PLLN				((uint8_t)0x06)
#define 	RCC_PLLP				((uint8_t)0x10)
#define 	RCC_PLLSRC				((uint8_t)0x16)
#define 	RCC_PLLQ0				((uint8_t)0x18)
#define 	RCC_PLLQ1				((uint8_t)0x19)
#define 	RCC_PLLQ2				((uint8_t)0x1A)
#define 	RCC_PLLQ3				((uint8_t)0x1B)

/*****************************************************************
 * SPI CONTROL REGISTER1 BIT DEFINITION
 ****************************************************************/
#define 	SPIx_BIDIMODE			((uint8_t)0x0F)
#define 	SPIx_BIDIOE				((uint8_t)0x0E)
#define 	SPIx_CRCEN				((uint8_t)0x0D)
#define 	SPIx_CRCNEXT			((uint8_t)0x0C)
#define 	SPIx_DFF				((uint8_t)0x0B)
#define 	SPIx_RXONLY				((uint8_t)0x0A)
#define 	SPIx_SSM				((uint8_t)0x09)
#define 	SPIx_SSI				((uint8_t)0x08)
#define 	SPIx_LSBFIRST			((uint8_t)0x07)
#define 	SPIx_SPE				((uint8_t)0x06)
#define 	SPIx_BR					((uint8_t)0x03)
#define 	SPIx_MSTR				((uint8_t)0x02)
#define 	SPIx_CPOL				((uint8_t)0x01)
#define 	SPIx_CPHA				((uint8_t)0x00)

/*****************************************************************
 * SPI CONTROL REGISTER2 BIT DEFINITION
 ****************************************************************/
#define 	SPIx_TXEIE				((uint8_t)0x07)
#define 	SPIx_RXNEIE				((uint8_t)0x06)
#define 	SPIx_ERRIE				((uint8_t)0x05)
#define 	SPIx_FRF				((uint8_t)0x04)
#define 	SPIx_SSOE				((uint8_t)0x02)
#define 	SPIx_TXDMAEN			((uint8_t)0x01)
#define 	SPIx_RXDMAEN			((uint8_t)0x00)

/*****************************************************************
 * SPI STATUS REGISTER BIT DEFINITION
 ****************************************************************/
#define 	SPIx_FRE				((uint8_t)0x08)
#define 	SPIx_BSY				((uint8_t)0x07)
#define 	SPIx_OVR				((uint8_t)0x06)
#define 	SPIx_MODE				((uint8_t)0x05)
#define 	SPIx_CRCERR				((uint8_t)0x04)
#define 	SPIx_UDR				((uint8_t)0x03)
#define 	SPIx_CHSIDE				((uint8_t)0x02)
#define 	SPIx_TXE				((uint8_t)0x01)
#define 	SPIx_RXN				((uint8_t)0x00)

#define 	SPIx_FRE_FLAG			(1<< SPIx_FRE)
#define 	SPIx_BSY_FLAG			(1<< SPIx_BSY)
#define 	SPIx_OVR_FLAG			(1<< SPIx_OVR)
#define 	SPIx_MODE_FLAG			(1<< SPIx_MODE)
#define 	SPIx_CRCERR_FLAG		(1<< SPIx_CRCERR)
#define 	SPIx_UDR_FLAG			(1<< SPIx_UDR)
#define 	SPIx_CHSIDE_FLAG		(1<< SPIx_CHSIDE)
#define 	SPIx_TXE_FLAG			(1<< SPIx_TXE)
#define 	SPIx_RXN_FLAG			(1<< SPIx_RXN)

/*****************************************************************
 * I2S REGISTER BIT DEFINITION
 ****************************************************************/
#define 	SPIx_I2SMOD				((uint8_t)0x0B)
#define 	SPIx_I2SE				((uint8_t)0x0A)
#define 	SPIx_I2SCFG_1			((uint8_t)0x09)
#define 	SPIx_I2SCFG_0			((uint8_t)0x08)
#define 	SPIx_PCMSYNC			((uint8_t)0x07)
#define 	SPIx_I2SSTD_1			((uint8_t)0x05)
#define 	SPIx_I2SSTD_0			((uint8_t)0x04)
#define 	SPIx_CKPOL				((uint8_t)0x03)
#define 	SPIx_DATLEN_1			((uint8_t)0x02)
#define 	SPIx_DATLEN_0			((uint8_t)0x01)
#define 	SPIx_CHLEN				((uint8_t)0x00)

/*****************************************************************
 * I2S PRESCALAR BIT DEFINITION
 ****************************************************************/
#define 	SPIx_MCKOE				((uint8_t)0x09)
#define 	SPIx_ODD				((uint8_t)0x08)

//I2C CR1 CONFIGURATION DECLARATIONS
#define 	I2Cx_SWRST				((uint8_t)0x0F)
#define 	I2Cx_ALERT				((uint8_t)0x0D)
#define 	I2Cx_PEC				((uint8_t)0x0C)
#define 	I2Cx_POS				((uint8_t)0x0B)
#define 	I2Cx_ACK				((uint8_t)0x0A)
#define 	I2Cx_STOP				((uint8_t)0x09)
#define 	I2Cx_START				((uint8_t)0x08)
#define 	I2Cx_NOSTRETCH			((uint8_t)0x07)
#define 	I2Cx_ENGC				((uint8_t)0x06)
#define 	I2Cx_ENPEC				((uint8_t)0x05)
#define 	I2Cx_ENARP				((uint8_t)0x04)
#define 	I2Cx_SMBTYPE			((uint8_t)0x03)
#define 	I2Cx_SMBUS				((uint8_t)0x01)
#define 	I2Cx_PE					((uint8_t)0x00)

//I2C CR2 CONFIGURATION DECLARATIONS
#define 	I2Cx_LAST				((uint8_t)0x0C)
#define 	I2Cx_DMAEN				((uint8_t)0x0B)
#define 	I2Cx_ITBUFEN			((uint8_t)0x0A)
#define 	I2Cx_ITEVTEN			((uint8_t)0x09)
#define 	I2Cx_ITERREN			((uint8_t)0x08)
#define 	I2Cx_FREQ				((uint8_t)0x00)

//I2C OAR1 CONFIGURATION DECLARATIONS
#define 	I2Cx_ADDMODE			((uint8_t)0x0F)
#define 	I2Cx_ADDRE9_8			((uint8_t)0x08)
#define 	I2Cx_ADDR1_7			((uint8_t)0x01)
#define 	I2Cx_ADDR0				((uint8_t)0x00)

//I2C OAR2 CONFIGURATION DECLARATIONS
#define 	I2Cx_ADDR2				((uint8_t)0x01)
#define 	I2Cx_ENDUAL				((uint8_t)0x00)

//I2C SR1 CONFIGURATION DECLARATIONS
#define 	I2Cx_SMBALERT			((uint8_t)0x0F)
#define 	I2Cx_TIMEOUT			((uint8_t)0x0E)
#define 	I2Cx_PECERR				((uint8_t)0x0C)
#define 	I2Cx_OVR				((uint8_t)0x0B)
#define 	I2Cx_AF					((uint8_t)0x0A)
#define 	I2Cx_ARLO				((uint8_t)0x09)
#define 	I2Cx_BERR				((uint8_t)0x08)
#define 	I2Cx_TxE				((uint8_t)0x07)
#define 	I2Cx_RxNE				((uint8_t)0x06)
#define 	I2Cx_STOPF				((uint8_t)0x04)
#define 	I2Cx_ADD10				((uint8_t)0x03)
#define 	I2Cx_BTF				((uint8_t)0x02)
#define 	I2Cx_ADDR				((uint8_t)0x01)
#define 	I2Cx_SB					((uint8_t)0x00)

//I2C SR1 Flag CONFIGURATION DECLARATIONS
#define 	I2Cx_SMBALERT_FLAG		(1<< I2Cx_SMBALERT)
#define 	I2Cx_TIMEOUT_FLAG		(1<< I2Cx_TIMEOUT)
#define 	I2Cx_PECERR_FLAG		(1<< I2Cx_PECERR)
#define 	I2Cx_OVR_FLAG			(1<< I2Cx_OVR)
#define 	I2Cx_AF_FLAG			(1<< I2Cx_AF)
#define 	I2Cx_ARLO_FLAG			(1<< I2Cx_ARLO)
#define 	I2Cx_BERR_FLAG			(1<< I2Cx_BERR)
#define 	I2Cx_TxE_FLAG			(1<< I2Cx_TxE)
#define 	I2Cx_RxNE_FLAG			(1<< I2Cx_RxNE)
#define 	I2Cx_STOPF_FLAG			(1<< I2Cx_STOPF)
#define 	I2Cx_ADD10_FLAG			(1<< I2Cx_ADD10)
#define 	I2Cx_BTF_FLAG			(1<< I2Cx_BTF)
#define 	I2Cx_ADDR_FLAG			(1<< I2Cx_ADDR)
#define 	I2Cx_SB_FLAG			(1<< I2Cx_SB)

//I2C SR2 CONFIGURATION DECLARATIONS
#define 	I2Cx_PEC0_7				((uint8_t)0x08)
#define 	I2Cx_DUALF				((uint8_t)0x07)
#define 	I2Cx_SMBHOST			((uint8_t)0x06)
#define 	I2Cx_SMBDEFAULT			((uint8_t)0x05)
#define 	I2Cx_GENCALL			((uint8_t)0x04)
#define 	I2Cx_TRA				((uint8_t)0x02)
#define 	I2Cx_BUSY				((uint8_t)0x01)
#define 	I2Cx_MSL				((uint8_t)0x00)

//I2C SR2 Flag CONFIGURATION DECLARATIONS
#define 	I2Cx_PEC0_7_FLAG		(1<< I2Cx_PEC0_7)
#define 	I2Cx_DUALF_FLAG			(1<< I2Cx_DUALF)
#define 	I2Cx_SMBHOST_FLAG		(1<< I2Cx_SMBHOST)
#define 	I2Cx_SMBDEFAULT_FLAG	(1<< I2Cx_SMBDEFAULT)
#define 	I2Cx_GENCALL_FLAG		(1<< I2Cx_I2Cx_GENCALL)
#define 	I2Cx_TRA_FLAG			(1<< I2Cx_TRA)
#define 	I2Cx_BUSY_FLAG			(1<< I2Cx_BUSY)
#define 	I2Cx_MSL_FLAG			(1<< I2Cx_MSL)

//I2C CLOCK CONTROL CONFIGURATION DECLARATIONS
#define 	I2Cx_FS					((uint8_t)0x0F)
#define 	I2Cx_DUTY				((uint8_t)0x0E)
#define 	I2Cx_CCR0_11			((uint8_t)0x00)

//I2C CLOCK RISE DECLARATIONS
#define 	I2Cx_TRISE0_5			((uint8_t)0x00)

//I2C FILTER DECLARATIONS
#define 	I2Cx_ANOFF				((uint8_t)0x04)
#define 	I2Cx_DNF0_3				((uint8_t)0x00)

/*****************************************************************
 * TIMER2 TO 5 CONTROL REGISTER1 BIT DEFINITION
 ****************************************************************/
#define 	TIM25_CKD				((uint8_t)0x08)
#define 	TIM25_ARPE				((uint8_t)0x07)
#define 	TIM25_CMS				((uint8_t)0x05)
#define 	TIM25_DIR				((uint8_t)0x04)
#define 	TIM25_OPM				((uint8_t)0x03)
#define 	TIM25_URS				((uint8_t)0x02)
#define 	TIM25_UDIS				((uint8_t)0x01)
#define 	TIM25_CEN				((uint8_t)0x00)

/*****************************************************************
 * TIMER2 TO 5 CONTROL REGISTER2 BIT DEFINITION
 ****************************************************************/
#define 	TIM25_TI1S				((uint8_t)0x07)
#define 	TIM25_MMS				((uint8_t)0x04)
#define 	TIM25_CCDS				((uint8_t)0x03)

/*****************************************************************
 * TIMER2 TO 5 SLAVE MODE CONTROL REGISTER BIT DEFINITION
 ****************************************************************/
#define 	TIM25_ETP				((uint8_t)0x0F)
#define 	TIM25_ECE				((uint8_t)0x0E)
#define 	TIM25_ETPS				((uint8_t)0x0C)
#define 	TIM25_ETF				((uint8_t)0x08)
#define 	TIM25_MSM				((uint8_t)0x07)
#define 	TIM25_TS				((uint8_t)0x04)
#define 	TIM25_SMS				((uint8_t)0x00)

/*****************************************************************
 * TIMER2 TO 5 COUNTER CONTROL REGISTER BIT DEFINITION
 ****************************************************************/
#define 	TIM25_CNT0_15			((uint8_t)0x00)
#define 	TIM25_CNT16_31			((uint8_t)0x10)

/*****************************************************************
 * TIMER 2 TO 5 STATUS REGISTER BIT DEFINITION
 ****************************************************************/
#define 	TIM25_CC4OF				((uint8_t)0x0C)
#define 	TIM25_CC3OF				((uint8_t)0x0B)
#define 	TIM25_CC2OF				((uint8_t)0x0A)
#define 	TIM25_CC1OF				((uint8_t)0x09)
#define 	TIM25_TIF				((uint8_t)0x06)
#define 	TIM25_CC4IF				((uint8_t)0x04)
#define 	TIM25_CC3IF				((uint8_t)0x03)
#define 	TIM25_CC2IF				((uint8_t)0x02)
#define 	TIM25_CC1IF				((uint8_t)0x01)
#define 	TIM25_UIF				((uint8_t)0x00)

#define 	TIM25_CC4OF_FLAG		(1 << TIM25_CC4OF)
#define 	TIM25_CC3OF_FLAG		(1 << TIM25_CC3OF)
#define 	TIM25_CC2OF_FLAG		(1 << TIM25_CC2OF)
#define 	TIM25_CC1OF_FLAG		(1 << TIM25_CC1OF)
#define 	TIM25_TIF_FLAG			(1 << TIM25_TIF)
#define 	TIM25_CC4IF_FLAG		(1 << TIM25_CC4IF)
#define 	TIM25_CC3IF_FLAG		(1 << TIM25_CC3IF)
#define 	TIM25_CC2IF_FLAG		(1 << TIM25_CC2IF)
#define 	TIM25_CC1IF_FLAG		(1 << TIM25_CC1IF)
#define 	TIM25_UIF_FLAG			(1 << TIM25_UIF)

/*****************************************************************
 * TIMER2 TO 5 CAPTURE COMPARE MODE REGISTER BIT DEFINITION
 ****************************************************************/
#define 	TIM25_CC1S				((uint8_t)0x00)
#define 	TIM25_IC1PSC			((uint8_t)0x02)
#define 	TIM25_IC1F				((uint8_t)0x04)
#define 	TIM25_CC2S				((uint8_t)0x08)
#define 	TIM25_IC2PSC			((uint8_t)0x0A)
#define 	TIM25_IC2F				((uint8_t)0x0C)
#define 	TIM25_CC3S				((uint8_t)0x00)
#define 	TIM25_IC3PSC			((uint8_t)0x02)
#define 	TIM25_IC3F				((uint8_t)0x03)
#define 	TIM25_CC4S				((uint8_t)0x08)
#define 	TIM25_IC4PSC			((uint8_t)0x0A)
#define 	TIM25_IC4F				((uint8_t)0x0C)

/*****************************************************************
 * TIMER2 TO 5 CAPTURE COMPARE ENABLE REGISTER BIT DEFINITION
 ****************************************************************/
#define 	TIM25_CC1E				((uint8_t)0x00)
#define 	TIM25_CC1P				((uint8_t)0x01)
#define 	TIM25_CC1NP				((uint8_t)0x03)
#define 	TIM25_CC2E				((uint8_t)0x04)
#define 	TIM25_CC2P				((uint8_t)0x05)
#define 	TIM25_CC2NP				((uint8_t)0x07)
#define 	TIM25_CC3E				((uint8_t)0x08)
#define 	TIM25_CC3P				((uint8_t)0x09)
#define 	TIM25_CC3NP				((uint8_t)0x0B)
#define 	TIM25_CC4E				((uint8_t)0x0C)
#define 	TIM25_CC4P				((uint8_t)0x0D)
#define 	TIM25_CC4NP				((uint8_t)0x0F)

/*****************************************************************
 * ADC STATUS REGISTER BIT DEFINITION
 ****************************************************************/
#define 	ADC_OVR					((uint8_t)0x05)
#define 	ADC_STRT				((uint8_t)0x04)
#define 	ADC_JSTRT				((uint8_t)0x03)
#define 	ADC_JEOC				((uint8_t)0x02)
#define 	ADC_EOC					((uint8_t)0x01)
#define 	ADC_AWD					((uint8_t)0x00)

#define 	ADC_OVR_FLAG			(1 << ADC_OVR)
#define 	ADC_STRT_FLAG			(1 << ADC_STRT)
#define 	ADC_JSTRT_FLAG			(1 << ADC_JSTRT)
#define 	ADC_JEOC_FLAG			(1 << ADC_JEOC)
#define 	ADC_EOC_FLAG			(1 << ADC_EOC)
#define 	ADC_AWD_FLAG			(1 << ADC_AWD)

/*****************************************************************
 * ADC CONTROL REGISTER1 BIT DEFINITION
 ****************************************************************/
#define 	ADC_OVRIE				((uint8_t)0x01A)
#define 	ADC_RES					((uint8_t)0x018)
#define 	ADC_AWDEN				((uint8_t)0x017)
#define 	ADC_JAWDEN				((uint8_t)0x016)
#define 	ADC_DISCNUM				((uint8_t)0x0D)
#define 	ADC_JDISCEN				((uint8_t)0x0C)
#define 	ADC_DISCEN				((uint8_t)0x0B)
#define 	ADC_JAUTO				((uint8_t)0x0A)
#define 	ADC_AWDSGL				((uint8_t)0x09)
#define 	ADC_SCAN				((uint8_t)0x08)
#define 	ADC_JEOCIE				((uint8_t)0x07)
#define 	ADC_AWDIE				((uint8_t)0x06)
#define 	ADC_EOCIE				((uint8_t)0x05)
#define 	ADC_AWDCH				((uint8_t)0x00)

/*****************************************************************
 * ADC CONTROL REGISTER2 BIT DEFINITION
 ****************************************************************/

#define 	ADC_SWSTART				((uint8_t)0x01E)
#define 	ADC_EXTEN				((uint8_t)0x01C)
#define 	ADC_EXTSEL				((uint8_t)0x018)
#define 	ADC_JSWSTART			((uint8_t)0x016)
#define 	ADC_JEXTEN				((uint8_t)0x014)
#define 	ADC_JEXTSEL				((uint8_t)0x010)
#define 	ADC_ALIGN				((uint8_t)0x0B)
#define 	ADC_EOCS				((uint8_t)0x0A)
#define 	ADC_DDS					((uint8_t)0x09)
#define 	ADC_DMA					((uint8_t)0x08)
#define 	ADC_CONT				((uint8_t)0x01)
#define 	ADC_ADON				((uint8_t)0x00)

/*****************************************************************
 * ADC SAMPLE REGISTER BIT DEFINITION
 ****************************************************************/
#define 	ADC_SMP0				((uint8_t)0x00)
#define 	ADC_SMP1				((uint8_t)0x03)
#define 	ADC_SMP2				((uint8_t)0x06)
#define 	ADC_SMP3				((uint8_t)0x09)
#define 	ADC_SMP4				((uint8_t)0x0C)
#define 	ADC_SMP5				((uint8_t)0x0D)
#define 	ADC_SMP6				((uint8_t)0x012)
#define 	ADC_SMP7				((uint8_t)0x015)
#define 	ADC_SMP8				((uint8_t)0x018)
#define 	ADC_SMP9				((uint8_t)0x01B)
#define 	ADC_SMP10				((uint8_t)0x00)
#define 	ADC_SMP11				((uint8_t)0x03)
#define 	ADC_SMP12				((uint8_t)0x06)
#define 	ADC_SMP13				((uint8_t)0x09)
#define 	ADC_SMP14				((uint8_t)0x0C)
#define 	ADC_SMP15				((uint8_t)0x0D)
#define 	ADC_SMP16				((uint8_t)0x012)
#define 	ADC_SMP17				((uint8_t)0x018)
#define 	ADC_SMP18				((uint8_t)0x01B)

/*****************************************************************
 *@brief		- GPIO REGISTER DECLARATION STRUCTURE
 *****************************************************************/
typedef struct{
	volatile uint32_t MODER;			// port mode register
	volatile uint32_t OTYPER;			// port output type register
	volatile uint32_t OSPEEDR;			// port output speed register
	volatile uint32_t PUPDR;			// port pull-up/pull-down register
	volatile uint32_t IDR;				// port input data register
	volatile uint32_t ODR;				// port output data register
	volatile uint32_t BSRR;				// port bit set/reset register
	volatile uint32_t LCKR;				// port configuration lock register
	volatile uint32_t AFR[2];			// alternate function low/high register
} STRUCT_GPIO_REG_DEF;

/*****************************************************************
 *@brief		- INTERRUPT REGISTER DECLARATION STRUCTURE
 *****************************************************************/
typedef struct{
	volatile uint32_t IMR;				// interrupt mask register
	volatile uint32_t EMR;				// event mask register
	volatile uint32_t RTSR; 			// rising trigger selection register
	volatile uint32_t FTSR; 			// falling trigger selection register
	volatile uint32_t SWIER; 			// software interrupt event register
	volatile uint32_t PR; 				// pending register
} STRUCT_EXTI_REG_DEF;

/*****************************************************************
 *@brief		- SYSCFG REGISTER DECLARATION STRUCTURE
 *****************************************************************/
typedef struct{
	volatile uint32_t MEMRMP;			// memory remap register
	volatile uint32_t PMC; 				// peripheral mode configuration
	volatile uint32_t EXTICR[4]; 		// external interrupt configuration
	volatile uint32_t CMPCR;			// Compensation cell control register
} STRUCT_SYSCFG_REG_DEF;

//GPIO PORT BASE ADDRESS
# define	GPIO_BASEADDR_TO_CODE(x)	((x==GPIOA)?0:\
										 (x==GPIOB)?1:\
										 (x==GPIOC)?2:\
										 (x==GPIOD)?3:\
										 (x==GPIOE)?4:\
										 (x==GPIOH)?7:0);

/*****************************************************************
 *@brief		- RCC REGISTER DECLARATION STRUCTURE
 *****************************************************************/
typedef struct{
	volatile uint32_t CR;				// clock control register
	volatile uint32_t PLLCFGR;			// PLL configuration register
	volatile uint32_t CFGR;				// clock configuration register
	volatile uint32_t CIR;				// clock interrupt register
	volatile uint32_t AHB1RSTR;			// AHB1 peripheral reset register
	volatile uint32_t AHB2RSTR;			// AHB2 peripheral reset register
	volatile uint32_t AHB3RSTR;			// AHB3 peripheral reset register
	uint32_t RCC_RESERVED1;				// RESERVED
	volatile uint32_t APB1RSTR;			// APB1 peripheral reset register
	volatile uint32_t APB2RSTR;			// APB2 peripheral reset register
	uint32_t RCC_RESERVED2;				// RESERVED
	uint32_t RCC_RESERVED3;				// RESERVED
	volatile uint32_t AHB1ENR;			// AHB1 peripheral clock enable register
	volatile uint32_t AHB2ENR;			// AHB2 peripheral clock enable register
	volatile uint32_t AHB3ENR;			// AHB3 peripheral clock enable register
	uint32_t RCC_RESERVED4;				// RESERVED
	volatile uint32_t APB1ENR;			// APB1 peripheral clock enable register
	volatile uint32_t APB2ENR;			// APB2 peripheral clock enable register
	uint32_t RCC_RESERVED5;				// RESERVED
	uint32_t RCC_RESERVED6;				// RESERVED
	volatile uint32_t AHB1LPENR;		// AHB1 peripheral clock enable in low power mode register
	volatile uint32_t AHB2LPENR;		// AHB2 peripheral clock enable in low power mode register
	volatile uint32_t AHB3LPENR;		// AHB3 peripheral clock enable in low power mode register
	uint32_t RCC_RESERVED7;				// RESERVED
	volatile uint32_t APB1LPENR;		// APB1 peripheral clock enable in low power mode register
	volatile uint32_t APB2LPENR;		// APB2 peripheral clock enable in low power mode register
	uint32_t RCC_RESERVED8;				// RESERVED
	uint32_t RCC_RESERVED9;				// RESERVED
	volatile uint32_t BDCR;				// Backup domain control register
	volatile uint32_t CSR;				// clock control & status register
	uint32_t RCC_RESERVED10;			// RESERVED
	uint32_t RCC_RESERVED11;			// RESERVED
	volatile uint32_t SSCGR;			// spread spectrum clock generation register
	volatile uint32_t PLLI2SCFGR;		// PLLI2S configuration register
} STRUCT_RCC_REG_DEF;

/*****************************************************************
 *@brief		- SPI REGISTER DECLARATION STRUCTURE
 *****************************************************************/
typedef struct{
	volatile uint32_t SPI_CR1;			// SPI control register 1
	volatile uint32_t SPI_CR2;			// SPI control register 2
	volatile uint32_t SPI_SR;			// SPI status register
	volatile uint32_t SPI_DR;			// SPI data register
	volatile uint32_t SPI_CRCPR;		// SPI CRC polynomial register
	volatile uint32_t SPI_RXCRCR;		// SPI RX CRC register
	volatile uint32_t SPI_TXCRCR;		// SPI TX CRC register
	volatile uint32_t SPI_I2SCFGR;		// SPI_I2S configuration register
	volatile uint32_t SPI_I2SPR;		// SPI_I2S prescaler register
} STRUCT_SPI_REG_DEF;

/*****************************************************************
 *@brief		- I2C  REGISTER DECLARATION STRUCTURE
 *****************************************************************/
typedef struct{
	volatile uint32_t I2C_CR1;			// I2C control register 1
	volatile uint32_t I2C_CR2;			// I2C control register 2
	volatile uint32_t I2C_OAR1;			// I2C Own Address register
	volatile uint32_t I2C_OAR2;			// I2C Own Address register
	volatile uint32_t I2C_DR;			// I2C data register
	volatile uint32_t I2C_SR1;			// I2C status register
	volatile uint32_t I2C_SR2;			// I2C status register
	volatile uint32_t I2C_CCR;			// I2C Clock control register
	volatile uint32_t I2C_TRISE;		// I2C Rise time register
	volatile uint32_t I2C_FLTR;			// I2C Filter register
} STRUCT_I2C_REG_DEF;

/*****************************************************************
 * @brief		- TIMER2-5 REGISTER DECLARATION STRUCTURE
 *****************************************************************/
typedef struct{
	volatile uint32_t CR1;				// Control Register1
	volatile uint32_t CR2;				// Control Register2
	volatile uint32_t SMCR;				// Slave Mode Control Register
	volatile uint32_t DIER;				// DMA/Interrupt Enable Register
	volatile uint32_t SR;				// Status Register
	volatile uint32_t EGR;				// Event Generation Register
	volatile uint32_t CCMR1;			// Capture/Compare Mode Register
	volatile uint32_t CCMR2;			// Capture/Compare Mode Register
	volatile uint32_t CCER;				// Capture/Compare Enable Register
	volatile uint32_t CNT;				// Counter Register
	volatile uint32_t PSC;				// Pre-scalar Register
	volatile uint32_t ARR;				// Auto Reload Register
	uint32_t gTIM2_RESERVED1;			// Reserved
	volatile uint32_t CCR1;				// Capture/Compare Register1
	volatile uint32_t CCR2;				// Capture/Compare Register2
	volatile uint32_t CCR3;				// Capture/Compare Register3
	volatile uint32_t CCR4;				// Capture/Compare Register4
	uint32_t gTIM2_RESERVED2;			// Reserved
	volatile uint32_t DCR;				// DMA Control Register
	volatile uint32_t DMAR;				// DMA Address Register
	volatile uint32_t OR_2;				// Option Register 2
	volatile uint32_t OR_5;				// Option Register 5
} STRUCT_TIM25_REG_DEF;

/*****************************************************************
 * @brief		- ADC REGISTER DECLARATION STRUCTURE
 * *****************************************************************/
typedef struct{
	volatile uint32_t SR;				// Status register
	volatile uint32_t CR1;				// Control1 register
	volatile uint32_t CR2;				// Control2 register
	volatile uint32_t SMPR1;			// Sample time register 1
	volatile uint32_t SMPR2; 			// Sample time register 2
	volatile uint32_t JOFR[4];			// ADC Injected channel data offset register
	volatile uint32_t HTR;				// Watchdog higher threshold register
	volatile uint32_t LTR;				// Watchdog lower threshold register
	volatile uint32_t SQR1; 			// regular sequence register 1
	volatile uint32_t SQR2; 			// regular sequence register 2
	volatile uint32_t SQR3;				// regular sequence register 3
	volatile uint32_t JSQR; 			// Injected sequence register
	volatile uint32_t JDR[4];			// Injected data register
	volatile uint32_t DR;				// Data register
	volatile uint32_t CSR;				// common status register
	volatile uint32_t CCR; 				// common control register
	volatile uint32_t CDR; 				// common regular data register
} STRUCT_ADC_REG_DEF;

/*****************************************************************
 *@brief		- FIRMWARE HEADER DECLARATION
 *****************************************************************/
//#include "SPI_STM32_DRIVER.h" 		//SPI
#include "GPIO_STM32_DRIVER.h"			//GPIO
//#include "I2C_STM32_DRIVER.h"			//I2C
#include "TIMER25_STM32_DRIVER.h"		//TIMER2-5
#include "ADC_STM32_DRIVER.h"			//ADC
//#include "RCC_STM32_DRIVER.h"			//RCC

#endif /* INC_STM32F407DISC_H_ */
