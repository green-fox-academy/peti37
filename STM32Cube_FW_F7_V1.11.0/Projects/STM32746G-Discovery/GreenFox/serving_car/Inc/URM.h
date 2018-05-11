/*
 * URM.h
 *
 *  Created on: 2018. jan. 4.
 *      Author: user
 */

#ifndef URM_H_
#define URM_H_

#include "main.h"

/* The Period value of Echo timer in micro seconds.
 * HC-SR04 Ultrasonic Ranging Module's max measuring distance is 4m.
 * Due to that over 5m is an invalid measurement. 500cm = 29070 us */
#define URM_ECHO_TIM_PERIOD 					8700		// 150cm = 8700 us
#define URM_ECHO_NOOBJECT_VALUE					URM_ECHO_TIM_PERIOD

#define URM_ECHO_LAST_VALUES_FOR_AVERAGE		50			// number of the last values to calculate average
#define URM_ECHO_LOWEST_VALUES_FOR_AVERAGE		5			// number of the lowest values of last values to calculate average
#define URM_NUMBER_OF_THE_BUFFERED_VALUES		480  		// set to one value for one pixel

typedef enum{URM_STATE_INACTIVE, URM_STATE_ACTIVE} URM_State_t;

void URM_Init();
void URM_Start();
void URM_Stop();
uint16_t URM_GetDistance();
void URM_GetTestScreenData(uint16_t *_measuredValues, unsigned int *_number_of_values, uint16_t *_measuredValues_end, uint16_t *_actual_echo);

// Functions for interrupts
void URM_AddNewValue(uint16_t newValue);
void URM_Measure();
URM_State_t  URM_GetState();

//TODO: Test
// void URM_ShowTestScreen();

#endif /* URM_H_ */
