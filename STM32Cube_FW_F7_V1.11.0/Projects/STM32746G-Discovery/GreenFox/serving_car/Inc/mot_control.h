/*
 * mot_control.h
 *
 *  Created on: 2018. jan. 7.
 *      Author: Whistleblower
 */
#include "main.h"
#ifndef MOT_CONTROL_H_
#define MOT_CONTROL_H_

/* DEFINING THE STATES OF THE MOTOR CONTROL */
typedef enum {FORWARD, BACKWARD, BREAK} Command_t;
typedef enum {NORMAL, SPEEDING, SLOWING} State_t;
typedef struct state_struct{
	State_t state;
	Command_t command;
	uint8_t act_speed;
	uint8_t req_speed;
} State_struct_t;
State_struct_t st;

void MC_Init();
void MC_control(uint8_t speed, Command_t command);
void MC_set_pulse(uint8_t req_speed);

#endif /* MOT_CONTROL_H_ */
