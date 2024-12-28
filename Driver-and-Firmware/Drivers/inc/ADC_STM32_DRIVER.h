// /*
//  * ADC_STM32_DRIVER.h
//  *
//  *  Created on: Feb 23, 2021
//  *      Author: windows 10
//  */

// #ifndef INC_ADC_STM32_DRIVER_H_
// #define INC_ADC_STM32_DRIVER_H_

// #include "STM32F407DISC.h"
// #define		ResBit12	((uint8_t) 0x00)
// #define		ResBit10	((uint8_t) 0x01)
// #define		ResBit8		((uint8_t) 0x02)
// #define		ResBit6		((uint8_t) 0x03)

// #define		RightAlign	((uint8_t) 0x00)
// #define		LeftAlign	((uint8_t) 0x01)

// #define		SingleConv	((uint8_t) 0x00)
// #define		ContConv	((uint8_t) 0x01)

// #define 	cycles3		((uint8_t) 0x00)
// #define 	cycles15	((uint8_t) 0x01)
// #define 	cycles28	((uint8_t) 0x02)
// #define 	cycles56	((uint8_t) 0x03)
// #define 	cycles84	((uint8_t) 0x04)
// #define 	cycles112	((uint8_t) 0x05)
// #define 	cycles144	((uint8_t) 0x06)
// #define		cycles480	((uint8_t) 0x07)

// typedef struct{
// 	uint8_t ADC_Resolution;
// 	uint8_t ADC_Align;
// 	uint8_t ADC_Cont;
// 	uint8_t ADC_SampleTime;
// 	uint8_t ADC_NoConversion;

// }ADC_PinConfig_t;

// typedef struct{
// 	ADC_RegDef_t 		*pADCx; 				// This holds BA of the GPIO port to which the pin belongs
// 	ADC_PinConfig_t 	 ADC_PinConfig;		//this holds GPIO pin configuration
// }ADC_Handle_t;

// /*PROTOTYPE DECLARATION*/
// void ADC_Init(ADC_Handle_t *ADC_Handle);
// void ADC_ChInit(ADC_RegDef_t *pADCx, uint8_t Channel, uint8_t Priority, uint8_t ADC_SampleTime);
// void ADC_Deinit(ADC_RegDef_t *pADCx);

// void ADC_PClkCtrl(ADC_RegDef_t *pADCx, uint8_t EnorDi);

// uint32_t ADC_Read(ADC_RegDef_t *pADCx);

// void ADC_TempSensor(uint8_t EnorDi);
// #endif /* INC_ADC_STM32_DRIVER_H_ */
