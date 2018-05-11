/*
 * steering_logic.h
 *
 *  Created on: 2018. jan. 25.
 *      Author: Whistleblower
 */

#ifndef STEERING_LOGIC_H_
#define STEERING_LOGIC_H_
#include "main.h"
#include "GUI.h"
#include "color_eval.h"
#include <math.h>

#define TRACKED_SENSOR_STATES	22
#define NO_LINE					33


typedef struct {
    int8_t *buffer;
    size_t head;
    size_t tail;
    size_t size; //of the buffer
} Circ_buf_t;

typedef enum {
	P, PI, PD, PID
}Controller_t;

Circ_buf_t cbuf;

void update_servo(int *signal);
int close_prev_hit(int8_t pos, int *signal);
static int get_steering_param(Color_t line, Color_t sensor_line_evaluated_colors[9], int *signal);
static int circ_buf_reset(Circ_buf_t *cbuf);
int circ_buf_empty(Circ_buf_t *cbuf);
static int circ_buf_full(Circ_buf_t cbuf);
int circ_buf_put(Circ_buf_t *cbuf, int8_t data);
int circ_buf_get(Circ_buf_t *cbuf, int8_t *data);
int circ_buf_last(Circ_buf_t *cbuf, int *data);
int circ_buf_sum(Circ_buf_t *cbuf);
void circ_buf_init(Circ_buf_t *cbuf);
int average_to_st_param_conv(double average);
int hit_to_st_param_conv(int hit);

#endif /* STEERING_LOGIC_H_ */
