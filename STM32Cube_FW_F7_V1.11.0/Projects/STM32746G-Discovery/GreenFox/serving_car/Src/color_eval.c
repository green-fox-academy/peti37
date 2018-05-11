/*
 * color_eval.c
 *
 *  Created on: 2018. jan. 30.
 *      Author: Andras Pasztor
 */

#include "color_eval.h"
#include "rgb.h"
#include "GUI.h"
#include <string.h>

extern color_t sensor_line_rgb_data[9];

// The result of color_evaluation() is the determined colors
Color_t sensor_line_evaluated_colors[9];

// Specify the colors to identify by RGB sensors
colors_t colors[8] = {0};

static void add_color(Color_t i, char *name, uint32_t color_show, double r_ref, double g_ref, double b_ref, double tolerance, uint8_t selectable);

/**
  * brief  Evaluate the compensated colors of the sensors to determine exactly
  *        which color definition it fits.
  * param  None
  * retval None
  */
void color_evaluation()
{
	uint32_t color_sum = 0;

	// reset the value of the array of evaluated colors
	for (unsigned int i = 0; i < 9; ++i) {
		sensor_line_evaluated_colors[i] = UNKNOWN;
	}

	// check the colors of all sensors
	for (unsigned int i = 0; i < 9; ++i) {

		// check whether the color is too bright (white) or too dark (black)
		if (sensor_line_rgb_data[i].c > (0xFFFF * colors[WHITE].tolerance)) {
			sensor_line_evaluated_colors[i] = WHITE;
		} else if (sensor_line_rgb_data[i].c < (0xFFFF * colors[BLACK].tolerance)) {
			sensor_line_evaluated_colors[i] = BLACK;

		} else {
			color_sum = sensor_line_rgb_data[i].r + sensor_line_rgb_data[i].g + sensor_line_rgb_data[i].b;
			for (unsigned int j = 0; j < (sizeof(colors) / sizeof(colors[0])); ++j) {
				if (   sensor_line_rgb_data[i].r / (double)color_sum < colors[j].r_ref * (1 + colors[j].tolerance)
					&& sensor_line_rgb_data[i].r / (double)color_sum > colors[j].r_ref * (1 - colors[j].tolerance)

					&& sensor_line_rgb_data[i].g / (double)color_sum < colors[j].g_ref * (1 + colors[j].tolerance)
					&& sensor_line_rgb_data[i].g / (double)color_sum > colors[j].g_ref * (1 - colors[j].tolerance)

					&& sensor_line_rgb_data[i].b / (double)color_sum < colors[j].b_ref * (1 + colors[j].tolerance)
					&& sensor_line_rgb_data[i].b / (double)color_sum > colors[j].b_ref * (1 - colors[j].tolerance) ) {

						// if a color is found than continue the evaluation with the color of the next sensor
						sensor_line_evaluated_colors[i] = j;
						break;
				}
			}
		}
	}
}

/**
  * brief  Initialize colors to identify with RGB sensors
  * param  None
  * retval None
  */
void init_colors()
{
	// reset sensor_line_evaluated_colors array
	for (unsigned int i = 0; i < sizeof(sensor_line_evaluated_colors) / sizeof(sensor_line_evaluated_colors[0]); ++i)
		sensor_line_evaluated_colors[i] = UNKNOWN;

	add_color(UNKNOWN, "UNKNOWN", 0xFFFF00FF, 0,     0,     0,     0,     0);
	add_color(RED,     "RED",     0xFFFF0000, 0.489, 0.262, 0.249, 0.18,  1);
	add_color(BLUE,    "BLUE",    0xFF0000FF, 0.268, 0.312, 0.420, 0.17,  1);
	add_color(GREEN,   "GREEN",   0xFF00FF00, 0.268, 0.420, 0.312, 0.15,  1);
	add_color(YELLOW,  "YELLOW",  0xFFFFFF00, 0.423, 0.350, 0.227, 0.15,  1);
	add_color(GREY,    "GREY",    0xFF808080, 0.370, 0.330, 0.300, 0.06,  0);

	// BLACK and WHITE are special colors, reference values should be 0 and tolerance is the
	// clear color intensity compared to 0 and max value
	add_color(BLACK,   "BLACK",   0xFF000000, 0,     0,     0,     0.21,  0);
	add_color(WHITE,   "WHITE",   0xFFFFFFFF, 0,     0,     0,     0.96,  0);
}

/**
  * brief  Add a color definition to global variable colors to the i-th position
  * param  As in color_t struct definition
  * retval None
  */
static void add_color(Color_t i, char *name, uint32_t color_show, double r_ref, double g_ref, double b_ref, double tolerance, uint8_t selectable)
{
	strcpy(colors[i].name, name);
	colors[i].color_show = color_show;
	colors[i].r_ref = r_ref;
	colors[i].g_ref = g_ref;
	colors[i].b_ref = b_ref;
	colors[i].tolerance = tolerance;
	colors[i].selectable = selectable;
}

