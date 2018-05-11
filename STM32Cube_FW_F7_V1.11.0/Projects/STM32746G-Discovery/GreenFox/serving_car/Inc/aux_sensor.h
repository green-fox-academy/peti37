/*
 * aux_sensor.h
 *
 *  Created on: 2018. jan. 25.
 *      Author: Whistleblower
 */

#ifndef AUX_SENSOR_H_
#define AUX_SENSOR_H_

#include "main.h"

#define LOADED_SPEED	16
#define UNLOADED_SPEED	14

typedef struct linsig {
	uint8_t left;
	uint8_t center;
	uint8_t right;
}Linsig_t;

Linsig_t ls;

void aux_sensor_init();
void update_line_sensor_read();
void test_uart_display();
void update_left_sensor_beer();

static void GPIO_init_aux_sensor();
static void line_sensor_read();


#endif /* AUX_SENSOR_H_ */
