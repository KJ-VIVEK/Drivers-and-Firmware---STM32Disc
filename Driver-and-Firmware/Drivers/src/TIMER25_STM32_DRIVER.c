// /*
//  * TIMER25_STM32_DRIVER.c
//  *
//  *  Created on: Feb 16, 2021
//  *      Author: windows 10
//  */

// #include "STM32F407DISC.h"
// uint8_t TIM25_GetFlagStatus(TIM25_RegDef_t *pTIM25, uint32_t FlagName);

// uint8_t TIM25_GetFlagStatus(TIM25_RegDef_t *pTIM25, uint32_t FlagName)
// {
// 		while((pTIM25->SR) & FlagName)
// 		{
// 			return FLAG_SET;
// 		}

// 		return FLAG_RESET;
// }

// /*************  ✨ Codeium Command ⭐  *************/
// /**
//  * @brief Initialize the Timer
//  *
//  * @param[in] pTIM25Handle This is structure of Timer Handle
//  *
//  * @return None
//  *
//  * @note This function is used to initialize the Timer

// void Timer_Init(TIM25_Handle_t *pTIM25Handle)
// {
// 	pTIM25Handle->pTIM25->CR1 	|= ( 1 << TIM25_CEN);
// 	pTIM25Handle->pTIM25->ARR 	 = (pTIM25Handle->TIM25_PinConfig.TIM25_AutoReload) - 1;
// 	pTIM25Handle->pTIM25->PSC 	 = pTIM25Handle->TIM25_PinConfig.TIM25_PSC - 1;
// 	pTIM25Handle->pTIM25->CR1 	|= pTIM25Handle->TIM25_PinConfig.TIM25_UpDown ;
// 	pTIM25Handle->pTIM25->CNT 	 = 0;
// }

// void Timer_Delay(TIM25_RegDef_t *pTIM25, TIM25_Handle_t *pTIM25Handle)
// {
// 	while(TIM25_GetFlagStatus(pTIM25, TIM25_UIF_FLAG) == FLAG_RESET);	//Checking status register for over flow
// 	pTIM25Handle->pTIM25->SR &= ~(SET << TIM25_UIF);
// }

// void Timer_PClkCtrl(TIM25_RegDef_t *pTIM25x, uint8_t EnorDi)
// {
// 	//peripheral clock ENABLE AND DISABLE FOR GPIOx
// 	if(EnorDi == ENABLE)
// 	{
// 		if(pTIM25x == TIM2)
// 			TIM2_PCLK_EN();

// 		else if(pTIM25x == TIM3)
// 			TIM3_PCLK_EN();

// 		else if(pTIM25x == TIM4)
// 			TIM4_PCLK_EN();

// 		else if(pTIM25x == TIM5)
// 			TIM5_PCLK_EN();
// 	}
// 	else
// 	{
// 		if(pTIM25x == TIM2)
// 			TIM2_PCLK_DI();

// 		else if(pTIM25x == TIM3)
// 			TIM3_PCLK_DI();

// 		else if(pTIM25x == TIM4)
// 			TIM4_PCLK_DI();

// 		else if(pTIM25x == TIM5)
// 			TIM5_PCLK_DI();
// 	}
// }

// void Timer_DeInit(TIM25_RegDef_t *pTIM25x)
// {
// 	if(pTIM25x == TIM2)
// 		TIM2_REG_RESET();

// 	else if(pTIM25x == TIM3)
// 		TIM3_REG_RESET();

// 	else if(pTIM25x == TIM4)
// 		TIM4_REG_RESET();

// 	else if(pTIM25x == TIM5)
// 		TIM5_REG_RESET();
// }

// void Timer_OCh1Init(TIM25_RegDef_t *pTIM25, TIM25_Handle_t *TIM_OCInitStruct)
// {
//   pTIM25->CCER &= ~(SET << TIM25_CC1E);
//   pTIM25->CCMR1 |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OCMode << TIM25_IC1F);
//   pTIM25->CCER  &= ~(SET << TIM25_CC1P);
//   pTIM25->CCER  |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OCPolarity << TIM25_CC1P);
//   pTIM25->CCER  |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OutputState << TIM25_CC1E);
//   pTIM25->CCMR1 |= (0x02 << TIM25_IC1PSC);
// }
// void Timer_OCh2Init(TIM25_RegDef_t *pTIM25, TIM25_Handle_t *TIM_OCInitStruct)
// {
//   pTIM25->CCER &= ~(SET << TIM25_CC2E);
//   pTIM25->CCMR1 |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OCMode << TIM25_IC2F);
//   pTIM25->CCER  &= ~(SET << TIM25_CC2P);
//   pTIM25->CCER  |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OCPolarity << TIM25_CC2P);
//   pTIM25->CCER  |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OutputState << TIM25_CC2E	);
//   pTIM25->CCMR1 |= (0x02 << TIM25_IC2PSC);
// }
// void Timer_OCh3Init(TIM25_RegDef_t *pTIM25, TIM25_Handle_t *TIM_OCInitStruct)
// {
//   pTIM25->CCER &= ~(SET << TIM25_CC3E);
//   pTIM25->CCMR2 |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OCMode << TIM25_IC3F);
//   pTIM25->CCER  &= ~(SET << TIM25_CC3P);
//   pTIM25->CCER  |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OCPolarity << TIM25_CC3P);
//   pTIM25->CCER  |= (uint16_t)(TIM_OCInitStruct->TIM25_PinConfig.TIM25_OutputState << TIM25_CC3E);
//   pTIM25->CCMR1 |= (0x02 << TIM25_IC3PSC);
// }
// void Timer_OCh4Init(TIM25_RegDef_t *pTIM25, TIM25_Handle_t *TIM_OCInitStruct)
// {
//   pTIM25->CCER &= ~(SET << TIM25_CC4E);
//   pTIM25->CCMR2 |= (TIM_OCInitStruct->TIM25_PinConfig.TIM25_OCMode << TIM25_IC4F);
//   pTIM25->CCER  &= ~(SET << TIM25_CC4P);
//   pTIM25->CCER  |= (TIM_OCInitStruct->TIM25_PinConfig.TIM25_OCPolarity << TIM25_CC4P);
//   pTIM25->CCER  |= (TIM_OCInitStruct->TIM25_PinConfig.TIM25_OutputState << TIM25_CC4E);
//   pTIM25->CCMR2 |= (0x02 << TIM25_IC4PSC);
// }

// void Timer_SetCmp1(TIM25_RegDef_t *pTIM25, uint32_t Cmp1)
// {
//     /* Set the Capture Compare4 Register value */
// 	pTIM25->CCR1 = Cmp1;
// }

// void Timer_SetCmp2(TIM25_RegDef_t *pTIM25, uint32_t Cmp2)
// {
//     /* Set the Capture Compare2 Register value */
// 	pTIM25->CCR2 = Cmp2;
// }
// void Timer_SetCmp3(TIM25_RegDef_t *pTIM25, uint32_t Cmp3)
// {
//     /* Set the Capture Compare2 Register value */
// 	pTIM25->CCR3 = Cmp3;
// }
// void Timer_SetCmp4(TIM25_RegDef_t *pTIM25, uint32_t Cmp4)
// {
//     /* Set the Capture Compare4 Register value */
// 	pTIM25->CCR4 = Cmp4;
// }


