/*
 * rtc.h
 *
 *  Created on: Feb 13, 2021
 *      Author: rae384
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_

#include "stm32f4xx_hal.h"

#define RTC_ADDR		(0x68u << 1)  // 7-bit address: 1101000
#define RTC_REG_SEC 	0x00u		 // Second
#define RTC_REG_MIN 	0x01u		 // Minute
#define RTC_REG_HOUR 	0x02u		 // Hour
#define RTC_REG_DAY 	0x03u		 // Day
#define RTC_REG_DATE 	0x04u		 // Date
#define RTC_REG_MC 		0x05u		 // Month/Century

void RTC_SetSecond(I2C_HandleTypeDef* hi2c, uint8_t second);
void RTC_SetMinute(I2C_HandleTypeDef* hi2c, uint8_t minute);
void RTC_SetHour(I2C_HandleTypeDef* hi2c, uint8_t hour);
void RTC_SetDate(I2C_HandleTypeDef* hi2c, uint8_t date);
void RTC_SetMonth(I2C_HandleTypeDef* hi2c, uint8_t month);
uint8_t RTC_Get(I2C_HandleTypeDef* hi2c, uint8_t reg);


#endif /* INC_RTC_H_ */
