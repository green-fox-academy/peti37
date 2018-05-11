/*
 * adc.h
 *
 *  Created on: 2018. jan. 15.
 *      Author: Andras Pasztor
 */

#ifndef SERVING_CAR_USER_ADC_H_
#define SERVING_CAR_USER_ADC_H_

#include "main.h"

void ADC_Init();
double ADC_GetPwmMultiplier();
double ADC_GetBatteryVoltage();

#endif /* SERVING_CAR_USER_ADC_H_ */
