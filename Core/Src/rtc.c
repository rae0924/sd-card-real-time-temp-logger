/*
 * rtc.c
 *
 *  Created on: Feb 13, 2021
 *      Author: rae384
 */

#include "rtc.h"

static uint8_t buffer[8];

void RTC_SetSecond(I2C_HandleTypeDef* hi2c, uint8_t second)
{
	uint8_t ones = second % 10;			// second
	uint8_t tens = (second / 10) << 4;	// 10 second

	if (second < 1 || second > 60) return;

	buffer[0] = RTC_REG_SEC;
	buffer[1] = tens + ones;
	HAL_I2C_Master_Transmit(hi2c, RTC_ADDR, buffer, 2, HAL_MAX_DELAY);
}

void RTC_SetMinute(I2C_HandleTypeDef* hi2c, uint8_t minute)
{
	uint8_t ones = minute % 10;			// minute
	uint8_t tens = (minute / 10) << 4;	// 10 minute

	if (minute < 1 || minute > 60) return;

	buffer[0] = RTC_REG_MIN;
	buffer[1] = tens + ones;
	HAL_I2C_Master_Transmit(hi2c, RTC_ADDR, buffer, 2, HAL_MAX_DELAY);
}


void RTC_SetHour(I2C_HandleTypeDef* hi2c, uint8_t hour)
{
	uint8_t ones = hour % 10;			// hour
	uint8_t tens = (hour / 10) << 4;	// 10 hour

	if (hour < 1 || hour > 24) return;

	buffer[0] = RTC_REG_HOUR;
	buffer[1] = tens + ones;
	HAL_I2C_Master_Transmit(hi2c, RTC_ADDR, buffer, 2, HAL_MAX_DELAY);
}

void RTC_SetDate(I2C_HandleTypeDef* hi2c, uint8_t date)
{
	uint8_t ones = date % 10;			// date
	uint8_t tens = (date / 10) << 4;	// 10 date

	if (date < 1 || date > 31) return;

	buffer[0] = RTC_REG_DATE;
	buffer[1] = tens + ones;
	HAL_I2C_Master_Transmit(hi2c, RTC_ADDR, buffer, 2, HAL_MAX_DELAY);
}

void RTC_SetMonth(I2C_HandleTypeDef* hi2c, uint8_t month)
{
	uint8_t ones = month % 10;			// month
	uint8_t tens = (month / 10) << 4;	// 10 month

	if (month < 1 || month > 12) return;

	buffer[0] = RTC_REG_MC;
	buffer[1] = tens + ones;
	HAL_I2C_Master_Transmit(hi2c, RTC_ADDR, buffer, 2, HAL_MAX_DELAY);
}

uint8_t RTC_Get(I2C_HandleTypeDef* hi2c, uint8_t reg)
{
	buffer[0] = reg;
	HAL_StatusTypeDef ret = HAL_I2C_Master_Transmit(hi2c, RTC_ADDR, buffer, 1, HAL_MAX_DELAY);
	if (ret == HAL_OK)
	{
		HAL_I2C_Master_Receive(hi2c, RTC_ADDR, buffer, 1, HAL_MAX_DELAY);
		return buffer[0];
	}
	return 0xff;
}
