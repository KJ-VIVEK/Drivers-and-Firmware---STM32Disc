// /*
//  * TIMER25_STM32_DRIVER.h
//  *
//  *  Created on: Feb 15, 2021
//  *      Author: windows 10
//  */

// #ifndef INC_TIMER25_STM32_DRIVER_H_
// #define INC_TIMER25_STM32_DRIVER_H_

// #include "STM32F407DISC.h"

// /*
//  * Prototype and structure Declaration
//  */
// /*****************************************************************
//  * @fn			-
//  *
//  * @brief		-initialization, di-initialization, delay prototype declared
//  *
//  * @param[in]	- None
//  * @param[in]	- None
//  *
//  * @return		- None
//  *
//  * @Note		- None
//  *
//  *****************************************************************/
// /*Delay Timer PIN CONFIGURATION
//  * Here we are using timer2 as dedicated timer for creating delay*/

// #define		UpCount	 				(0 << TIM25_DIR)
// #define		DownCount	 			(1 << TIM25_DIR)
// #define		PWMMode1	 			((uint16_t)0x06)
// #define		PWMMode2	 			((uint16_t)0x07)

// typedef struct{
// 	uint32_t TIM25_ClkFreq;				//This holds clock frequency of the MCU
// 	uint32_t TIM25_AutoReload;			//This holds AutoRelaod value of the MCU
// 	uint32_t TIM25_UpDown;				//This holds type of counter
// 	uint32_t TIM25_PSC;
// 	uint32_t TIM25_OCMode;				//Parameter used for TIM_PWM_modes
// 	uint32_t TIM25_OutputState;			//This holds TIM Output Compare state of the MCU
// 	uint32_t TIM25_Pulse;				//Specifies the pulse value
// 	uint32_t TIM25_OCPolarity;			//Specifies the output polarity
// 	uint32_t TIM25_mSec;
// }TIM25_PinConfig_t;

// typedef struct{
// 	TIM25_RegDef_t 		*pTIM25; 				// This holds BA of the GPIO port to which the pin belongs
// 	TIM25_PinConfig_t 	 TIM25_PinConfig;		//this holds GPIO pin configuration
// }TIM25_Handle_t;

// /*PROTOTYPE DECLARATION*/
// void Timer_PClkCtrl(TIM25_RegDef_t *pTIM25x, uint8_t EnorDi);

// void Timer_Init(TIM25_Handle_t *pTIM25Handle);
// void Timer_DeInit(TIM25_RegDef_t *pTIM25x);

// void Timer_Delay(TIM25_RegDef_t *pTIM25, TIM25_Handle_t *pTIM25Handle);

// void Timer_SetCmp2(TIM25_RegDef_t *pTIM25, uint32_t Cmp2);
// void Timer_SetCmp3(TIM25_RegDef_t *pTIM25, uint32_t Cmp3);
// void Timer_SetCmp4(TIM25_RegDef_t *pTIM25, uint32_t Cmp4);
// void Timer_SetCmp5(TIM25_RegDef_t *pTIM25, uint32_t Cmp5);

// void Timer_OCh1PreloadConfig(TIM25_RegDef_t *pTIM25, uint16_t TIM25_OCPreload);
// void Timer_OCh2PreloadConfig(TIM25_RegDef_t *pTIM25, uint16_t TIM25_OCPreload);
// void Timer_OCh3PreloadConfig(TIM25_RegDef_t *pTIM25, uint16_t TIM25_OCPreload);
// void Timer_OCh4PreloadConfig(TIM25_RegDef_t *pTIM25, uint16_t TIM25_OCPreload);

// #endif /* INC_TIMER25_STM32_DRIVER_H_ */
