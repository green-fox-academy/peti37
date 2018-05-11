/*
 * aux_sensor.c
 *
 *  Created on: 2018. jan. 25.
 *      Author: Whistleblower
 */

#include "aux_sensor.h"
#include "port_define.h"
#include "main.h"

#define	AS_DELAY	30

GPIO_InitTypeDef	gpio_aux;

static uint32_t update_time;
static uint32_t display_time;

void aux_sensor_init()
{
	GPIO_init_aux_sensor();
	display_time = update_time = HAL_GetTick();
	line_sensor_read();
}
void GPIO_init_aux_sensor()
{
	/* INIT CLOCKS */
	__HAL_RCC_GPIOF_CLK_ENABLE();


    /* INIT PINS */
	/* A2 - RIGHT*/
	gpio_aux.Pin = A2_PIN;
	gpio_aux.Mode = GPIO_MODE_INPUT;
	gpio_aux.Pull = GPIO_PULLDOWN;
	gpio_aux.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(A2_PORT, &gpio_aux);

	/* A3 - CENTER*/
	gpio_aux.Pin = A3_PIN;
	HAL_GPIO_Init(A3_PORT, &gpio_aux);

	/* A4 - LEFT*/
	gpio_aux.Pin =A4_PIN;
	HAL_GPIO_Init(A4_PORT, &gpio_aux);
}

static void line_sensor_read()
{
	if (HAL_GPIO_ReadPin(A2) == SET)
		ls.right = 1;
	else
		ls.right = 0;
	if (HAL_GPIO_ReadPin(A3) == SET)
		ls.center = 1;
	else
		ls.center = 0;
	if (HAL_GPIO_ReadPin(A4) == SET)
		ls.left = 1;
	else
		ls.left = 0;
}

void update_line_sensor_read()
{

	if (HAL_GetTick() > (update_time + AS_DELAY)) {
		line_sensor_read();
		update_time = HAL_GetTick();
	}
}

void test_uart_display() {

	if (HAL_GetTick() > (display_time + 2000)) {
		printf("left:   %u\n center: %u\n right:  %u\n\n", ls.left, ls.center, ls.right);
		display_time = HAL_GetTick();
	}
}
