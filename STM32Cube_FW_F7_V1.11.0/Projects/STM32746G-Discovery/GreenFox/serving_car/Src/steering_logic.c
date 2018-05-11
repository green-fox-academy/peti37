/*
 * steering_logic.c
 *
 *  Created on: 2018. jan. 25.
 *      Author: Whistleblower
 */

#include "steering_logic.h"

#define STEER_DELAY	20
#define KP			7
#define KI			0.02
#define KD			7

static uint32_t steer_time = 0;
Controller_t act_controller = PID;
extern Color_t sensor_line_evaluated_colors[9];
extern Color_t line;

/**
 * brief  turns the raw value of the actual hits into a PID output
 * param  'diff_to_target' - comes as the return value of get_steering_param()
 * 			it is the difference from 0 on the -8...8 scale, which is the range of the
 * 			PID input
 * retval	It is a void function. However it calls the servo_set_pos() function and sets the
 * 			servo PWM of the steering to a number between -48...48
 */
static void servo_control_value(int diff_to_target)
{
	int mod_val = 0;
	switch (act_controller) {
	case P:
		mod_val = diff_to_target * KP;
		break;
	case PI:
		mod_val = diff_to_target * KP + circ_buf_sum(&cbuf) * KI;
		break;
	case PD:
		mod_val = diff_to_target * KP + circ_buf_differential(&cbuf) * KD;
		break;
	case PID:
		mod_val = diff_to_target * KP + circ_buf_sum(&cbuf) * KI + circ_buf_differential(&cbuf) * KD;
		break;
	default:
		break;
	}

	if (mod_val > 48) {
		mod_val = 48;
	} else if (mod_val < -48) {
		mod_val = -48;
	}

	servo_set_pos(mod_val);
}

/**
 * brief  	It is supposed to be called from the main() function. It is responsible for
 * 			the correction of the actual steering servo angle.
 * param  	'*signal' - It is a flag which is taken by its address in order to modify it.
 * 			It shows whether the RGB sensors are still sensing the color which has been chosen.
 * retval	It is a void function. It calls 'servo_control_value()' and sets 'steer_time'.
 */
void update_servo(int *signal)
{
	if (HAL_GetTick() > (steer_time + STEER_DELAY)) {
		servo_control_value(get_steering_param(line, sensor_line_evaluated_colors, signal));
		steer_time = HAL_GetTick();
	}
}

/**
 * brief  Turns the double type average of the actual hits which is received in a range of 0...8
 * 			to a value in a range of -8...8
 * param  'average' - It is the average position of the sensors which measured the chosen color.
 * retval	It returns an 'int' value in the range mentioned above.
 */
int average_to_st_param_conv(double average)
{
	double st_param = average * 2 - 8;
	st_param = round(st_param);
	return (int)st_param;

}

/**
 * brief  Converts the actual position of the hit into a value that is on the -8...8 range.
 * 			This function is used in 'close_prev_hit()' to make values comparable to the previous
 * 			ones already stored in the buffer.
 * param  'hit' - It is the position (ie. the number) of the RGB sensor which measured the chosen
 * 			color value.
 * retval	It returns an 'int' value in the range mentioned above.
 */
int hit_to_st_param_conv(int hit)
{
	int st_param = hit * 2 - 8;
	return st_param;

}

/**
 * brief  This function helps to decide whether the actual hit is close to the previous one.
 * 			If it is, that means the value can be accepted. If it is not, it is ignored.
 * param  'pos' - It is the actual position of the sensor which measured the chosen color.
 * 			'*signal' - this is a flag which is used for indicating whether there is a line
 * 			of the chosen color in front of the sensors or not? (If not, any hit is accepted)
 * retval	It returns a logical value (ie. '0' if false, '1' if true)
 */
int close_prev_hit(int8_t pos, int *signal)
{
	/* IF THE BUFFER IS EMPTY OR THERE IS NO SIGNAL WE CONSIDER ANY HIT AS APPROPRIATE */
	if (circ_buf_empty(&cbuf) || !*signal)
		return 1;

	int8_t data = 0;
	circ_buf_last(&cbuf, &data);

	if (hit_to_st_param_conv(pos) < data + 4 && hit_to_st_param_conv(pos) > data - 4)
		return 1;

	return 0;
}

int get_steering_param(Color_t line, Color_t sensor_line_evaluated_colors[9], int *signal)
{
	double average = 0;
	int st_param = 0;
	int sum = 0;
	int hit = 0;

	for (int i = 0; i < 9; ++i) {
		if (sensor_line_evaluated_colors[i] == line && close_prev_hit(i, signal)) {
			sum += i;
			hit++;
		}
	}

	if (hit == 0) {
		average = NO_LINE;
		*signal = 0;
		circ_buf_last(&cbuf, &st_param);
	} else {
		average = (double)sum / hit;
		st_param = average_to_st_param_conv(average);
		circ_buf_put(&cbuf, st_param);
		*signal = 1;
	}
	circ_buf_print(&cbuf);
	return st_param;
}

///* CIRCULAR BUFFER */

int circ_buf_differential(Circ_buf_t *cbuf)
{
	int previous = (cbuf->head + TRACKED_SENSOR_STATES - 1) % cbuf->size;
	int beforeprevious = (cbuf->head + TRACKED_SENSOR_STATES - 2) % cbuf->size;

	return cbuf->buffer[previous] - cbuf->buffer[beforeprevious];
}

int circ_buf_sum(Circ_buf_t *cbuf)
{
    int position = 0;
    int sum = 0;

    for (int i = 0; i < TRACKED_SENSOR_STATES - 1; i++) {
    	position = (cbuf->tail + i) % cbuf->size;
    	if (position == cbuf->head)
    		break;
        sum += cbuf->buffer[position];
    }
    return sum;
}

void circ_buf_print(Circ_buf_t *cbuf)
{
    int real_place;

    for (int i = 0; i < TRACKED_SENSOR_STATES - 1; i++) {
    	real_place = (cbuf->tail + i) % cbuf->size;
//        printf("buf_data%d: %d\n", i, cbuf->buffer[real_place]);
    }
}

int circ_buf_reset(Circ_buf_t *cbuf)
{
    int r = -1;

    if (cbuf) {
        cbuf->head = 0;
        cbuf->tail = 0;
        r = 0;
    }

    return r;
}

int circ_buf_empty(Circ_buf_t *cbuf)
{
    // We define empty as head == tail
    return (cbuf->head == cbuf->tail);
}

int circ_buf_full(Circ_buf_t cbuf)
{
    // We determine "full" case by head being one position behind the tail
    // Note that this means we are wasting one space in the buffer!
    // Instead, you could have an "empty" flag and determine buffer full that way
    return ((cbuf.head + 1) % cbuf.size) == cbuf.tail;
}

int circ_buf_put(Circ_buf_t * cbuf, int8_t data)
{
    int r = -1;

    if (cbuf) {
        cbuf->buffer[cbuf->head] = data;
        cbuf->head = (cbuf->head + 1) % cbuf->size;

        if (cbuf->head == cbuf->tail) {
            cbuf->tail = (cbuf->tail + 1) % cbuf->size;
        }

        r = 0;
    }

    return r;
}

int circ_buf_get(Circ_buf_t * cbuf, int8_t * data)
{
    int r = -1;

    if(cbuf && data && !circ_buf_empty(cbuf))
    {
        *data = cbuf->buffer[cbuf->tail];
        cbuf->tail = (cbuf->tail + 1) % cbuf->size;

        r = 0;
    }

    return r;
}

int circ_buf_last(Circ_buf_t *cbuf, int *data)
{
    int r = -1;
    int prevstuff;

    prevstuff = (cbuf->head + TRACKED_SENSOR_STATES - 1) % cbuf->size;

//    printf("prevstuff: %d\n", cbuf->buffer[prevstuff]);

    if(cbuf && data && !circ_buf_empty(cbuf))
    {
        *data = cbuf->buffer[prevstuff];
        r = 0;
//        printf("Im here :) & the data is: %d\n", *data);
    }

    return r;
}

/* INITIALIZE CIRCULAR BUFFER */

void circ_buf_init(Circ_buf_t *cbuf)
{
    cbuf->size = TRACKED_SENSOR_STATES;
    cbuf->buffer = malloc(cbuf->size);
    circ_buf_reset(&cbuf);
}


