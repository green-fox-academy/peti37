/*
 * servo_pwm.c
 *
 *  Created on: 2018. jan. 4.
 *      Author: Agnes
 */
// set min max position in servo - pwm pulse
#define	MIN_POS			123
#define ZERO_POS		142
#define	MAX_POS			161


#include "servo_pwm.h"
#include "main.h"
#include "port_define.h"

GPIO_InitTypeDef  Servo;
TIM_HandleTypeDef Servo_Timh;
TIM_OC_InitTypeDef sConfig;

int actual_servo_pos = 0;

/**
 * brief initialize timer for servo pwm
 * param  None
 * retval None
 */
void init_timer12()
{
	__HAL_RCC_TIM12_CLK_ENABLE();

	Servo_Timh.Instance = TIM12;
	Servo_Timh.Init.CounterMode = TIM_COUNTERMODE_UP;
	Servo_Timh.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Servo_Timh.Init.Period = (2000-1);
	Servo_Timh.Init.Prescaler = (1080-1);
	sConfig.Pulse = ZERO_POS;
	sConfig.OCMode = TIM_OCMODE_PWM1;

	HAL_TIM_PWM_Init(&Servo_Timh);
	HAL_TIM_PWM_ConfigChannel(&Servo_Timh, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&Servo_Timh, TIM_CHANNEL_1);
}

/**
  * brief initialize servo
  * param  None
  * retval None
  */
void servo_init()
{
	__HAL_RCC_GPIOH_CLK_ENABLE();

	Servo.Pin = GPIO_PIN_6;
	Servo.Mode = GPIO_MODE_AF_PP;
	Servo.Speed = GPIO_SPEED_FAST;
	Servo.Alternate = GPIO_AF9_TIM12;

	HAL_GPIO_Init(GPIOH, &Servo);
	init_timer12();
}


/**
  * brief set zero position on servo
  * param  None
  * retval None
  */
void servo_set_zero_pos() {
		int diff = TIM12->CCR1 - ZERO_POS;
		if (TIM12->CCR1 >= MIN_POS && TIM12->CCR1 <= MAX_POS) {
			for (unsigned int i = 0; i < (0 - diff); ++i) {
				TIM12->CCR1 -= 1;
				HAL_Delay(10);
			}

	} else {
		for (unsigned int i = 0; i < diff; ++i) {
			TIM12->CCR1 += 1;
			HAL_Delay(10);
		}
	}
}

/*
 * brief set servo zero pos ASAP - do not use
 * param  None
 * retval None
 */
void servo_set_zero_fast()
{
	TIM12->CCR1 = ZERO_POS;
}

/*
 * brief Set the PWM pulse length in ms
 * param  pulse_length set PWM
 * retval None
 */

void servo_set_pwm(uint32_t pulse_length)
{
	TIM12->CCR1 = pulse_length;
}

/*
 * brief Set the wheel position between most left and most rigth position. The position value is between -48 and +48.
 *       -48 is the most left, 0 is the center, +48 is the most right position.
 * param  position servo pos from -48 to 48
 * retval None
 */
void servo_set_pos(int position)
{
	if (position >= -48 && position <= 48)
	{
		servo_set_pwm(ZERO_POS + ((double)(MAX_POS - MIN_POS) / 96) * -position);
		actual_servo_pos = position;
	}
}

/**
 * brief get servo position for diagnostic screen from current servo pwm pulse between -48 and +48
 *        -48 is the most left, 0 is the center, +48 is the most right position
 * param  None
 * retval None
 */
int servo_get_pos()
{
	return actual_servo_pos;
}


/*
 * brief a test function for servo
 * param  None
 * retval None
 */
void test_servo_steering()
{
	RNG_HandleTypeDef rnd;
	uint32_t num_rnd;
	int num_rand;
	HAL_RNG_GenerateRandomNumber(&rnd, &num_rnd);
	num_rand = (num_rnd % 17 + 1) - 9;

	servo_set_pos(num_rand * 6);
}


