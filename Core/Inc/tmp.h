/*
 * tmp.h
 *
 *  Created on: Feb 14, 2021
 *      Author: rae384
 */

#ifndef INC_TMP_H_
#define INC_TMP_H_

#include "stm32f4xx_hal.h"

#define TMP75B_ADDR  		(0x48u << 1)		// 7-bit address: 1001000
#define TMP_REG_TEMP		0x00u
#define TMP_REG_CONFIG		0x01u
#define TMP_REG_RESET		0x06u
#define TMP_SD_MODE			0x01u
#define TMP_OS_MODE 		0x80u

void TMP_Reset(I2C_HandleTypeDef* hi2c);
void TMP_ShutdownEnable(I2C_HandleTypeDef* hi2c);
void TMP_OneShotRead(I2C_HandleTypeDef* hi2c, uint8_t* data);
uint8_t TMP_ConfigRead(I2C_HandleTypeDef* hi2c);






#endif /* INC_TMP_H_ */
