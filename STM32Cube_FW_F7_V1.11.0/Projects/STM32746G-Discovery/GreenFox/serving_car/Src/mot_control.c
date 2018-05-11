/*
 * mot_control.c
 *
 *  Created on: 2018. jan. 7.
 *      Author: Whistleblower
 */


#include "mot_control.h"
#include "main.h"
#include "port_define.h"
#include "adc.h"
#include "aux_sensor.h"

#define MC_MIN_SPEED			1
#define MC_MAX_SPEED			50
#define MC_SPEEDING_TRIGGER		MC_MIN_SPEED + 10
#define MC_SPEED_DIFF			30
//#define MC_MAX_SPEEDING_PERIOD	25				// 25 ms
//#define MC_MIN_SPEEDING_PERIOD	5					// 5 ms
#define MC_SPEEDING_PERIOD		10000				// 1000 ms
#define MC_MAX_STOP_AID_PERIOD	2500				// 250 ms

#define MC_PWM_PERIOD			300					// period is 300 us long // frequency = 1 / 300 * 10^-6 = 3,3 kHz
#define MC_PWM_PRESCALER		108					// so 1.000.000 incrementation makes out 1 sec
extern State_struct_t st;
extern gen_speed;


/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef		gpio;
TIM_HandleTypeDef 		TimHandle_MC;
TIM_OC_InitTypeDef 		timpwm;

/* Static variables ---------------------------------------------------------*/


/* Static function prototypes -----------------------------------------------*/
static void set_motion(uint8_t speed);
void GPIO_Init();
static void MC_TIM3_PWM_Init();
static void MC_TIM6_Init();
static void set_forward();
static void set_backward();
static void set_break();
static void set_speeding_periode(uint8_t speed);

/*
 * Initialize the Motor Controller Module
 * param  None
 * retval None
 */
void MC_Init()
{
	/* Initialize and start timer 3 with PWM for motor control */
	MC_TIM3_PWM_Init();

	/* Initialize and start timer 6 for starting support */
	MC_TIM6_Init();

	NVIC_SetPriority(TIM6_DAC_IRQn,0x0f);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);

	/* Configure GPIOs for motor control */
	GPIO_Init();

	/* Setting state structure for motor control */
	st.state = NORMAL;
	st.command = BREAK;
	st.act_speed = 0;
	st.req_speed = 0;
}

/*
 * Control the Motor by given speed and command
 * param  None
 * retval None
 */
void MC_control(uint8_t speed, Command_t command)
{
	if (command != st.command || speed != st.act_speed) {
		switch (command) {
		case FORWARD:
			if (st.command == BACKWARD) {
				MC_control(100, BREAK);
				HAL_Delay(300);
				MC_control(speed, FORWARD);
			} else {
				st.command = FORWARD;
//				printf("forward\n");
				set_motion(speed);
			}
			break;
		case BACKWARD:
			if (st.command == FORWARD) {
				MC_control(100, BREAK);
				HAL_Delay(300);
				MC_control(speed, BACKWARD);
			} else {
				st.command = BACKWARD;
//				printf("backward\n");
				set_motion(speed);
			}
			break;
		case BREAK:
			st.command = BREAK;
//			printf("break\n");
			set_motion(100);
			break;
		default:
			break;
		}
	}
}

/*
 * This function sets the PWM ratio according to 'req_speed'
 * param  None
 * retval None
 */
void MC_set_pulse(uint8_t req_speed)
{
//	printf("speed: %d\n", req_speed);
	int pulse = MC_PWM_PERIOD * ADC_GetPwmMultiplier() * req_speed / 100;
	if (pulse > MC_PWM_PERIOD)
		pulse = MC_PWM_PERIOD;
	TIM3->CCR1 = pulse;
	st.act_speed = req_speed;
//	printf("pulse: %d\n", pulse);
}

/*
 * It chooses which accelerating / slowing pattern should be used according to 'speed'
 * and inner state-variable 'st.command'
 * param  speed
 * retval None
 */
static void set_motion(uint8_t speed)
{
	switch (st.command) {
	case FORWARD:
		if (speed > MC_MAX_SPEED)
			speed = MC_MAX_SPEED;
		if (speed < MC_MIN_SPEED)
			speed = MC_MIN_SPEED;
		set_forward();
		/* TODO: TEST CONDITION!!!  - to be reset!*/
		if ((st.act_speed == 0)) {
//			printf("forward: speeding: speed: 100\n");
			st.req_speed = speed;
			st.state = SPEEDING;
//			TIM3->CCR1 = MC_PWM_PERIOD;
			if (gen_speed == LOADED_SPEED)
				MC_set_pulse(speed + 50);
			else if (gen_speed == UNLOADED_SPEED)
				MC_set_pulse(speed + 40);
			else
				MC_set_pulse(speed + 3);
			set_speeding_periode(speed);
			HAL_TIM_Base_Stop_IT(&TimHandle_MC);
			HAL_TIM_Base_Start_IT(&TimHandle_MC);
		} else {
			MC_set_pulse(speed);
		}
		break;
	case BACKWARD:
		if (speed > MC_MAX_SPEED)
			speed = MC_MAX_SPEED;
		if (speed < MC_MIN_SPEED)
			speed = MC_MIN_SPEED;
		set_backward();
		if ((st.act_speed == 0)) {
//			printf("forward: speeding: speed: 100\n");
			st.req_speed = speed;
			st.state = SPEEDING;
			TIM3->CCR1 = MC_PWM_PERIOD;
			set_speeding_periode(speed);
			HAL_TIM_Base_Stop_IT(&TimHandle_MC);
			HAL_TIM_Base_Start_IT(&TimHandle_MC);
		} else {
			MC_set_pulse(speed);
		}
		break;
	case BREAK:
		if (speed > 100)
			speed = 100;
		if (speed < MC_MIN_SPEED)
			speed = MC_MIN_SPEED;
		set_break();
		TIM3->CCR1 = (MC_PWM_PERIOD / 100) * speed;
		st.act_speed = 0;
		st.req_speed = 0;
		break;
	default:
		break;
	}
//		printf("invalid speed value\n");
}

/*
 * Sets GPIO pins on / off to drive forward
 * param  speed defined in main.c
 * retval None
 */
static void set_forward()
{
	HAL_GPIO_WritePin(D4, RESET);
	HAL_GPIO_WritePin(D5, SET);
}

/*
 * Sets GPIO pins on / off to drive backward
 * param  speed defined in main.c
 * retval None
 */
static void set_backward()
{
	HAL_GPIO_WritePin(D4, SET);
	HAL_GPIO_WritePin(D5, RESET);
}

/*
 * Sets GPIO pins on / off to break the vehicle
 * param  speed defined in main.c
 * retval None
 */
static void set_break()
{
	HAL_GPIO_WritePin(D4, RESET);
	HAL_GPIO_WritePin(D5, RESET);
}

/*
 * Calculates speeding periode according to speed difference 
 * (actual and required speeds)
 * param  speed defined in main.c
 * retval None
 */
static void set_speeding_periode(uint8_t speed)
{
	int period = MC_SPEEDING_PERIOD;
//	if (speed - st.act_speed >= MC_MAX_SPEED - MC_SPEEDING_TRIGGER) {
//		period = MC_MAX_SPEEDING_PERIOD - 1;
//	} else if (speed - st.act_speed <= MC_SPEEDING_TRIGGER- MC_MIN_SPEED) {
//		period = MC_MIN_SPEEDING_PERIOD - 1;
//	} else {
//		period = MC_MIN_SPEEDING_PERIOD + (MC_MAX_SPEEDING_PERIOD - MC_MIN_SPEEDING_PERIOD) * (speed - st.act_speed) / (MC_MAX_SPEED - MC_MIN_SPEED)- 1;
//	}
//	printf("speeding period: %d\n", period);
	TIM6->ARR = period;
}

/*
 * Initializes TIM3 for the PWM which is lead to the enable pin of the motor controller
 * param  None
 * retval None
 */
static void MC_TIM3_PWM_Init()
{
	__HAL_RCC_TIM3_CLK_ENABLE();              // enable TIM3 clock

	TimHandle_MC.Instance               = TIM3;
	TimHandle_MC.Init.Period            = MC_PWM_PERIOD - 1;
	TimHandle_MC.Init.Prescaler         = MC_PWM_PRESCALER - 1;
	TimHandle_MC.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle_MC.Init.CounterMode       = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TimHandle_MC);            //Configure the timer
	HAL_TIM_Base_Start(&TimHandle_MC);

	// PWM Mode
	HAL_TIM_PWM_Init(&TimHandle_MC);

	timpwm.OCMode     	= TIM_OCMODE_PWM1;
	timpwm.Pulse		= 0;
	HAL_TIM_PWM_ConfigChannel(&TimHandle_MC, &timpwm, TIM_CHANNEL_1);

//	HAL_TIM_PWM_Start_IT(&TimHandle_MC, TIM_CHANNEL_1);  // -> start it with interrupt

	HAL_TIM_PWM_Start(&TimHandle_MC, TIM_CHANNEL_1); // -> start it without interrupts
}

/*
 * Initializes TIM6 for measuring time while speeding.
 * param  None
 * retval None
 */
static void MC_TIM6_Init()
{
	__HAL_RCC_TIM6_CLK_ENABLE();              // enable TIM6 clock

	TimHandle_MC.Instance               = TIM6;
	TimHandle_MC.Init.Period            = 2000;	// period is 200 ms long
	TimHandle_MC.Init.Prescaler         = (10800 - 1); 	// so 10000 incrementation makes out 1 sec
	TimHandle_MC.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle_MC.Init.CounterMode       = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TimHandle_MC);            //Configure the timer
}

/*
 * Initializes GPIO pins.
 * param  None
 * retval None
 */
void GPIO_Init()
{
	/* INIT CLOCKS */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();

    /* INIT PINS */
	/* D5 */
	gpio.Pin = D5_PIN;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_PULLDOWN;
	gpio.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(D5_PORT, &gpio);

	/* D4 */
	gpio.Pin = D4_PIN;
	HAL_GPIO_Init(D4_PORT, &gpio);

	/* D3 */
	gpio.Pin = D3_PIN;
	gpio.Alternate = GPIO_AF2_TIM3;      // and the alternate function is to use TIM1 timer's second channel
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(D3_PORT, &gpio);

}
