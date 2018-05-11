/*
 * color_eval.h
 *
 *  Created on: 2018. jan. 30.
 *      Author: Andras Pasztor
 */

#ifndef COLOR_EVAL_H_
#define COLOR_EVAL_H_

#include "rgb.h"
#include "GUI.h"

typedef struct {
	char     name[10];
	uint32_t color_show;
	double   r_ref;
	double   g_ref;
	double   b_ref;
	double   tolerance;
	uint8_t  selectable;
} colors_t;

void color_evaluation();
void init_colors();

#endif /* COLOR_EVAL_H_ */
