/*
 * GUI.h
 *
 *  Created on: 2018. jan. 10.
 *      Author: Peter Jolánkai & Ágnes Gyurik
 */

#ifndef GUI_H_
#define GUI_H_

#include "main.h"
#include "rgb.h"
#include <fonts.h>

typedef enum {RED, BLUE, GREEN, YELLOW, BLACK, WHITE, GREY, UNKNOWN} Color_t;

/* define buttons on touch screen */

typedef enum {JEAN, START, SELECTION, COLORWRITER, DIAGNOSTIC, RGB_DIAGN, URM_DIAGN} Screen_t;

typedef struct {
	char title[16];
	uint16_t x;
	uint16_t y;
	uint16_t width;
	uint16_t height;
	uint32_t bg_color;
	uint32_t txt_color;
	uint8_t	active;
	sFONT *font;
	void (*function)();
} button_t;

void GUI_Init();
void screen_welcome();
void screen_startpos();
void line_selecting_screen();
void write_selected_color(Color_t line);
void set_color();
void push_diagn_or_help();
void get_button_coordinate();
void screen_delivery();
void screen_help();
void screen_diagnostic();
void screen_alarm();
void screen_stopped();
void show_buttons(button_t *button, unsigned int length);
void check_button_touch(button_t *button, unsigned int length);
void play_welcome_screens();
void rgb_diagnostic();
void get_button_coordinate();
void screen_urm_diagn();
void screen_after_delivered();
uint32_t convert_color_code(color_t rgb_color);

// protype some function using only this .c file
static void button_diagnostic();
static void button_help();
static void button_start();
static void button_back();
static void place_diagn_help_back_button();
static void place_diagn_help_button();
static void push_start();
static void push_back();
static void push_start();
static void reset_ts_coord();
static int numb_of_start_sign();
void battery_alarm_message();
void color_lost_alarm_message();
void obstarctle_alarm_message();
void screen_prev();
static void button_yes();


#endif /* GUI_H_ */
