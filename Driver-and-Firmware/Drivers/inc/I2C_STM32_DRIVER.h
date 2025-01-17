// /*
//  * I2C_STM32_DRIVER.h
//  *
//  *  Created on: Feb 15, 2021
//  *      Author: windows 10
//  */

// #ifndef INC_I2C_STM32_DRIVER_H_
// #define INC_I2C_STM32_DRIVER_H_

// #include "STM32F407DISC.h"

// /*
//  * Configuration structure for I2Cx peripheral
//  */
// typedef struct
// {
// 	uint32_t I2C_SCLSpeed;
// 	uint8_t  I2C_DeviceAddress;
// 	uint8_t  I2C_AckControl;
// 	uint8_t  I2C_FMDutyCycle;

// }I2C_Config_t;

// /*
//  *Handle structure for I2Cx peripheral
//  */
// typedef struct
// {
// 	I2C_RegDef_t 	*pI2Cx;
// 	I2C_Config_t 	I2C_Config;
// 	uint8_t 		*pTxBuffer; /* !< To store the app. Tx buffer address > */
// 	uint8_t 		*pRxBuffer;	/* !< To store the app. Rx buffer address > */
// 	uint32_t 		TxLen;		/* !< To store Tx len > */
// 	uint32_t 		RxLen;		/* !< To store Tx len > */
// 	uint8_t 		TxRxState;	/* !< To store Communication state > */
// 	uint8_t 		DevAddr;	/* !< To store slave/device address > */
//     uint32_t        RxSize;		/* !< To store Rx size  > */
//     uint8_t         Sr;			/* !< To store repeated start value  > */
// }I2C_Handle_t;

// /*
//  * I2C application states
//  */

// #define 	I2C_READY 					0
// #define 	I2C_BUSY_IN_RX 				1
// #define 	I2C_BUSY_IN_TX 				2

// /*
//  * @I2C_SCLSpeed
//  */

// #define 	I2C_SCL_SPEED_SM 	100000
// #define 	I2C_SCL_SPEED_FM4K 	400000
// #define 	I2C_SCL_SPEED_FM2K  200000

// /*
//  * @I2C_AckControl
//  */

// #define 	I2C_ACK_ENABLE        1
// #define 	I2C_ACK_DISABLE       0

// /*
//  * @I2C_FMDutyCycle
//  */

// #define 	I2C_FM_DUTY_2        0
// #define 	I2C_FM_DUTY_16_9     1

// /*
//  * I2C related status flags definitions
//  */



// #define 	I2C_DISABLE_SR  	RESET
// #define 	I2C_ENABLE_SR   	SET


// void I2C_PClKCTRL(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
// void I2C_Init(I2C_Handle_t *pI2CHandle);
// void I2C_DeInit(I2C_RegDef_t *pI2Cx);


// void I2C_MasterTxData(I2C_Handle_t *pI2CHandle,uint8_t *pTxbuffer, uint32_t Len, uint8_t SlaveAddr,uint8_t Sr);
// void I2C_MasterRxData(I2C_Handle_t *pI2CHandle,uint8_t *pRxBuffer, uint8_t Len, uint8_t SlaveAddr,uint8_t Sr);
// void I2C_CloseRxData(I2C_Handle_t *pI2CHandle);
// void I2C_CloseTxData(I2C_Handle_t *pI2CHandle);

// /*
//  * Other Peripheral Control APIs
//  */

// void I2Cx_PeriCtrl(I2C_RegDef_t *pI2Cx, uint8_t EnOrDi);
// uint8_t I2Cx_GetFlagStatus(I2C_RegDef_t *pI2Cx , uint32_t FlagName);
// void I2C_ManageAck(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
// void I2C_GenStopCon(I2C_RegDef_t *pI2Cx);


// #endif /* INC_I2C_STM32_DRIVER_H_ */
