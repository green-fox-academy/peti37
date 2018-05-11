/*
 * servo_pwm.h
 *
 *  Created on: 2018. jan. 4.
 *      Author: Felhasználó
 */

#ifndef SERVO_PWM_H_
#define SERVO_PWM_H_

#include "main.h"

void init_timer12();
void servo_init();
void draw_oval();
void servo_set_zero_pos();
void servo_set_zero_fast();
void servo_set_pwm(uint32_t pulse_length);
void servo_set_pos(int position);
int servo_get_pos();
void test_servo_steering();

#endif /* SERVO_PWM_H_ */
