// /*
//  * ADC_STM32_DRIVER.c
//  *
//  *  Created on: Feb 23, 2021
//  *      Author: windows 10
//  */

// #include "STM32F407DISC.h"

// void ADC_Init(ADC_Handle_t *ADC_Handle)
// {
// 	ADC_Handle->pADCx->CR1  &= ~(0x00 << ADC_RES);
// 	ADC_Handle->pADCx->CR1  |= ((ADC_Handle->ADC_PinConfig.ADC_Resolution << ADC_RES)|(ENABLE << ADC_SCAN));
// 	ADC_Handle->pADCx->CR2  |= ((ENABLE << ADC_ADON)|(ADC_Handle->ADC_PinConfig.ADC_Cont << ADC_CONT)|(ADC_Handle->ADC_PinConfig.ADC_Align << ADC_ALIGN));
// 	ADC_Handle->pADCx->SQR1 |= (ADC_Handle->ADC_PinConfig.ADC_NoConversion << 20);
// 	ADC_Handle->pADCx->CR2  |= ( 1 << 0);
// 	ADC_Handle->pADCx->CR2  |= (ENABLE << ADC_SWSTART);
// }

// void ADC_ChInit(ADC_RegDef_t *pADCx,uint8_t Channel, uint8_t Priority, uint8_t ADC_SampleTime)
// {
// 	if(Channel > 9 )
// 	{
// 		pADCx->SMPR1 &= ~(SET << 3 *(Channel - 10));
// 		pADCx->SMPR1 |= (ADC_SampleTime << 3 *(Channel - 10));
// 	}
// 	else
// 	{
// 		pADCx->SMPR2 &= ~(SET << 3 *Channel);
// 		pADCx->SMPR2 |= (ADC_SampleTime << 3 *Channel);
// 	}
// 	if(Priority < 7)
// 	{
// 		pADCx->SQR3 &= ~(SET << 5 *(Priority - 1));
// 		pADCx->SQR3 |= (Channel << 5 *(Priority - 1));
// 	}
// 	else if(Priority < 13)
// 	{
// 		pADCx->SQR2 &= ~(SET << 5 *(Priority - 7));
// 		pADCx->SQR2 |= (Channel << 5 *(Priority - 7));
// 	}
// 	else
// 	{
// 		pADCx->SQR1 &= ~(SET << 5 *(Priority - 13));
// 		pADCx->SQR1 |= (Channel << 5 *(Priority - 13));
// 	}
// }
// uint32_t ADC_Read(ADC_RegDef_t *pADCx)
// {
// 	while((pADCx->SR) & (ADC_EOC_FLAG));
// 	int AnalogValue= pADCx->DR;
// 	pADCx->SR &= ~(SET << ADC_EOC);
// 	return AnalogValue;
// }
// void ADC_PClkCtrl(ADC_RegDef_t *pADCx, uint8_t EnorDi)
// {
// 	if(EnorDi == ENABLE)
// 	{
// 		if(pADCx == ADC1)
// 			ADC1_PCLK_EN();
// 		else if(pADCx == ADC2)
// 			ADC2_PCLK_EN();
// 		else if(pADCx == ADC3)
// 			ADC3_PCLK_EN();
// 	}
// 	else
// 	{
// 		if(pADCx == ADC1)
// 			ADC1_PCLK_DI();
// 		else if(pADCx == ADC2)
// 			ADC2_PCLK_DI();
// 		else if(pADCx == ADC3)
// 			ADC3_PCLK_DI();
// 	}
// }
// void ADC_Deinit(ADC_RegDef_t *pADCx)
// {
// 	if(pADCx == ADC1)
// 		ADC1_REG_RESET();
// 	else if(pADCx == ADC2)
// 		ADC2_REG_RESET();
// 	else if(pADCx == ADC3)
// 		ADC3_REG_RESET();

// }

// void ADC_TempSensor(uint8_t EnorDi)
// {
//   if (EnorDi == ENABLE)
//   {
//     ADC1->CCR |= ((uint32_t)0x00800000);
//   }
//   else
//   {
//     ADC1->CCR &= ~((uint32_t)(0x00800000));
//   }
// }
