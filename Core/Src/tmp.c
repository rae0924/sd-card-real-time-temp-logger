/*
 * tmp.c
 *
 *  Created on: Feb 14, 2021
 *      Author: rae384
 */


#include "tmp.h"


static uint8_t buffer[8];


void TMP_Reset(I2C_HandleTypeDef* hi2c)
{
	buffer[0] = TMP_REG_RESET;
	HAL_I2C_Master_Transmit(hi2c, 0x00, buffer, 1, HAL_MAX_DELAY);
}

void TMP_ShutdownEnable(I2C_HandleTypeDef* hi2c)
{
	buffer[0] = TMP_REG_CONFIG;
	buffer[1] = TMP_SD_MODE;
	HAL_I2C_Master_Transmit(hi2c, TMP75B_ADDR, buffer, 2, HAL_MAX_DELAY);
}

void TMP_OneShotRead(I2C_HandleTypeDef* hi2c, uint8_t* data)
{
	buffer[0] = TMP_REG_CONFIG;
	buffer[1] = TMP_OS_MODE | TMP_SD_MODE;
	HAL_I2C_Master_Transmit(hi2c, TMP75B_ADDR, buffer, 2, HAL_MAX_DELAY);

	HAL_Delay(50);	// allow time for conversion

	buffer[0] = TMP_REG_TEMP;
	HAL_I2C_Master_Transmit(hi2c, TMP75B_ADDR, buffer, 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(hi2c, TMP75B_ADDR, buffer, 2, HAL_MAX_DELAY);

	data[0] = buffer[0];
	data[1] = buffer[1];
}

uint8_t TMP_ConfigRead(I2C_HandleTypeDef* hi2c)
{
	buffer[0] = TMP_REG_CONFIG;
	HAL_I2C_Master_Transmit(hi2c, TMP75B_ADDR, buffer, 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(hi2c, TMP75B_ADDR, buffer, 1, HAL_MAX_DELAY);
	return buffer[0];
}
