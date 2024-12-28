/**
 * @file  GPIO_STM32_DRIVER.c
 * @brief GPIO driver implementation for STM32 microcontrollers
 * @details This file contains the implementation of GPIO (General Purpose Input/Output) 
 *          driver functions for STM32 microcontroller series. It provides APIs for
 *          configuring and controlling GPIO pins including initialization, pin mode
 *          settings, input/output operations, and interrupt configurations.
 * 
 * @author Vivek J K
 * @date   2024-12-28
 */

#include "STM32F407DISC.h"

/**
 * @brief 	- Enable or Disable peripheral clock for given GPIO port
 * @details This function is used to enable or disable peripheral clock for
 *          the given GPIO port.
 * @param 	pGPIOx - Base address of the GPIO port
 * @param 	EnorDi - ENABLE or DISABLE macros
 * @return 	- None
 */
void GPIO_PClkCtrl(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t EnorDi)
{
	//peripheral clock ENABLE AND DISABLE FOR GPIOx
	if(EnorDi == ENABLE)
	{
		//enable clock for GPIOx
		switch((uint32_t)pGPIOx)
		{
			case GPIOA_BASEADDR:
				//enable clock for GPIOA
				GPIOA_PCLK_EN();
				break;
			case GPIOB_BASEADDR:
				//enable clock for GPIOB
				GPIOB_PCLK_EN();
				break;
			case GPIOC_BASEADDR:
				//enable clock for GPIOC
				GPIOC_PCLK_EN();
				break;
			case GPIOD_BASEADDR:
				//enable clock for GPIOD
				GPIOD_PCLK_EN();
				break;
			case GPIOE_BASEADDR:
				//enable clock for GPIOE
				GPIOE_PCLK_EN();
				break;
			case GPIOH_BASEADDR:
				//enable clock for GPIOH
				GPIOH_PCLK_EN();
				break;
		}
	}
	else
	{
		//disable clock for GPIOx
		switch((uint32_t)pGPIOx)
		{
			case GPIOA_BASEADDR:
				//disable clock for GPIOA
				GPIOA_PCLK_DI();
				break;
			case GPIOB_BASEADDR:
				//disable clock for GPIOB
				GPIOB_PCLK_DI();
				break;
			case GPIOC_BASEADDR:
				//disable clock for GPIOC
				GPIOC_PCLK_DI();
				break;
			case GPIOD_BASEADDR:
				//disable clock for GPIOD
				GPIOD_PCLK_DI();
				break;
			case GPIOE_BASEADDR:
				//disable clock for GPIOE
				GPIOE_PCLK_DI();
				break;
			case GPIOH_BASEADDR:
				//disable clock for GPIOH
				GPIOH_PCLK_DI();
				break;
		}
	}
}

/**
 * @brief Initializes the specified GPIO port.
 * @details This function is used to initialize the specified GPIO port.
 * @param pGPIOHandle: Pointer to the GPIO handler structure.
 */
void GPIO_Init(STRUCT_GPIO_HANDLER *pGPIOHandle )
{
	uint32_t temp;
	/*
	 * 0. ENABLING THE CLOCK FOR RESPECTIVE REGISTER
	 */
	GPIO_PClkCtrl(pGPIOHandle->pGPIOx, ENABLE);
	/*
	 * 1. CONFIGURING GPIO MODE USING MDOER REGISTER
	 */
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		/*
		 * Set the bit in the MODER register of the GPIO port to configure the
		 * pin as input or output.
		 */
		temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 <<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER |=   temp;
		temp=0;
	}
	else
	{
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT )
		{
			/*
			 * Set the bit in the FTSR register of the EXTI peripheral to enable
			 * falling edge detection for the specified pin.
			 */
			EXTI->FTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->RTSR &= ~(1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT )
		{
			/*
			 * Set the bit in the RTSR register of the EXTI peripheral to enable
			 * rising edge detection for the specified pin.
			 */
			EXTI->RTSR |= (1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->FTSR &= ~(1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}

		uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
		uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYNCFG_PCLK_EN();
		SYSCFG->EXTICR[temp1]=portcode<<(temp2*4);

		/*
		 * Enable the EXTI interrupt for the specified pin.
		 */
		EXTI->IMR |= 1<<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
	}

	/*
	 * 2. CONFIGURING OUTPUT REGISTER AS PUSHPULL OR OPEN-DRAIN
	 */
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber );
	pGPIOHandle->pGPIOx->OTYPER &= ~( 0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	/*
	 * 3. CONFIGURING PIN SPEED USING OSPEEDR REGISTER
	 */
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 <<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |=  temp;
	temp=0;

	/*
	 * 4. CONFIGURING PULL UP/DOWN USINGPUPDR REGISTER
	 */
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR&= ~(0x3 <<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR|=temp;
	temp=0;

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTF)
	{
		uint8_t temp1, temp2;
		temp1=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
	 	temp2=pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8;
	 	/*
		 * Set the bits in the AFR register of the GPIO port to configure the
		 * pin as alternate function.
		 */
	 	pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF <<(4*temp2));
	 	pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle ->GPIO_PinConfig.GPIO_PinALTFunction <<(4*temp2));
	 	temp=0;
	}
}

/**
 * @brief Deinitializes the specified GPIO port.
 * @details This function is used to deinitialize the specified GPIO port.
 * @param pGPIOx: Pointer to the GPIO port base address.
 */
void GPIO_DeInit(STRUCT_GPIO_REG_DEF *pGPIOx)
{
	// Reset the GPIO port
	if(pGPIOx == GPIOA)			// GPIOA
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)		// GPIOB
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)		// GPIOC
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)		// GPIOD
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)		// GPIOE
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOH)		// GPIOH
	{
		GPIOH_REG_RESET();
	}
}

/**
 * @brief Reads the input data register bit for the specified GPIO pin.
 * @details This function is used to read the current state of a GPIO pin.
 * @param pGPIOx: Pointer to the GPIO port base address.
 * @param PinNumber: The GPIO pin number to be read.
 * @return uint8_t: The current state of the pin (0 or 1).
 */
uint8_t GPIO_ReadPin(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t PinNumber)
{
    // Variable to store the pin value
    uint8_t value;

    // Read the input data register, shift right by PinNumber, and mask with 0x01
    value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x01);
    
    // Return the pin state
    return value;
}

/**
 * @brief Toggles the output data register bit for the specified GPIO pin.
 * @details This function is used to toggle the output state of a GPIO pin.
 * @param pGPIOx: Pointer to the GPIO port base address.
 * @param PinNumber: The GPIO pin number to be toggled.
 */
void GPIO_Toggle(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t PinNumber)
{
	// Toggle the bit in the output data register corresponding to the PinNumber
	pGPIOx -> ODR ^= (1<<PinNumber);
}

/**
 * @brief Sets the output data register bit for the specified GPIO pin, setting it to high.
 * @param pGPIOx: Pointer to the GPIO port base address.
 * @param PinNumber: The GPIO pin number to be set to high.
 */
void GPIO_High(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t PinNumber)
{
	// Set the bit in the output data register corresponding to the PinNumber
	pGPIOx->ODR |= (1 << PinNumber);
}

/**
 * @brief Clears the output data register bit for the specified GPIO pin, setting it to low.
 * @param pGPIOx: Pointer to the GPIO port base address.
 * @param PinNumber: The GPIO pin number to be set to low.
 */
void GPIO_Low(STRUCT_GPIO_REG_DEF *pGPIOx, uint8_t PinNumber)
{
    // Reset the bit in the output data register corresponding to the PinNumber
    pGPIOx->ODR &= ~(1 << PinNumber);
}

/**
 * @brief Configures the interrupt for the given IRQ number
 * @param IRQNumber: The IRQ number to be configured
 * @param EnorDi: ENABLE to enable the interrupt, DISABLE to disable it
 *                 When ENABLE is specified, the corresponding NVIC ISER register is programmed
 *                 When DISABLE is specified, the corresponding NVIC ICER register is programmed
 * This function handles the enabling or disabling of interrupts by configuring
 * the NVIC ISER/ICER registers based on the IRQ number
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	//IRQ ISR handling
	if(EnorDi == ENABLE)
	{
		/**
		 * Check if the IRQ number is between 0 and 31
		 * If yes, program the ISER0 register
		 */
		if(IRQNumber <= 31)	*NVIC_ISER0 |= (1 << IRQNumber); //program ISER0

		/**
		 * Check if the IRQ number is between 32 and 63
		 * If yes, program the ISER1 register
		 */
		else if (IRQNumber > 31 && IRQNumber < 64 )	*NVIC_ISER1 |= (1 << (IRQNumber % 32));	//Program ISER1 register


		/**
		 * Check if the IRQ number is between 64 and 95
		 * If yes, program the ISER3 register
		 */
		else if (IRQNumber >= 64 && IRQNumber < 96 )	*NVIC_ISER3 |= (1 << (IRQNumber % 64)); //Program ISER2 register
	}
	else
	{
		/**
		 * Check if the IRQ number is between 0 and 31
		 * If yes, program the ICER0 register
		 */
		if(IRQNumber <= 31)	*NVIC_ICER0 |= (1 << IRQNumber); //program ISER0

		/**
		 * Check if the IRQ number is between 32 and 63
		 * If yes, program the ICER1 register
		 */
		else if (IRQNumber > 31 && IRQNumber < 64 )	*NVIC_ICER1 |= ( 1 << (IRQNumber % 32)); //Program ISER1 register

		/**
		 * Check if the IRQ number is between 64 and 95
		 * If yes, program the ICER3 register
		 */
		else if (IRQNumber >= 64 && IRQNumber < 96 )	*NVIC_ICER3 |= (1 << (IRQNumber % 64)); //Program ISER2 register

	}
}

/**
 * @brief Handles the interrupt for a given GPIO pin
 * @param PinNumber: The number of the GPIO pin for which the interrupt needs to be handled
 */
void GPIO_IRQHandling(uint8_t PinNumber)
{
	/**
	 * Clear the PR (Pending Register) bit for the given pin number
	 * This is necessary because the EXTI library does not clear the pending register bit
	 * by itself
	 */
	if(EXTI->PR &(1 << PinNumber))
		EXTI->PR |=(1 << PinNumber);
}

/**
 * @brief Sets the priority of the given IRQ number
 * @param IRQNumber: The number of the IRQ for which the priority needs to be set
 * @param IRQPriority: The priority of the IRQ. The lower the number, the higher the priority
 * */
void GPIO_IRQPriorityconfig (uint8_t IRQNumber, uint32_t IRQPriority)
{
	/**
	 * Find out the IPR address. The IPR (Interrupt Priority Register) is a set of 8 registers
	 * (IPR0 to IPR7) which specify the priority of each interrupt
	 * The IPR address is calculated as NVIC_PR_BASE_ADDR + (iprx)
	 */
	uint8_t iprx = IRQNumber / 4;
	
	/**
	 * Calculate the shift amount for the priority field in the IPR register
	 * The priority field is 8 bits wide and is located at a different position in each IPR register
	 * The position of the priority field is calculated as (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED)
	 */
	uint8_t iprx_section = IRQNumber % 4;
	uint8_t shift_amount =(8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
	
	/**
	 * Set the priority of the IRQ
	 * The priority is set by shifting the IRQPriority by the calculated shift amount and then ORing it with the IPR register
	 */
	*(NVIC_PR_BASE_ADDR + (iprx)) |= (IRQPriority <<(8 *  shift_amount));
}
