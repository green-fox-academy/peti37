/*
 * GUI.c
 *
 *  Created on: 2018. jan. 10.
 *      Author: Peter Jolankai and Agnes Gyurik
 */

#include "GUI.h"
#include "main.h"
#include "rgb.h"
#include "port_define.h"
#include "URM.h"
#include "adc.h"
#include "mot_control.h"
#include "servo_pwm.h"
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "color_eval.h"
#include <string.h>

// used variables for LCD and TS
static unsigned int buttonstate = 1;  // variable used for ts detected
static unsigned int x, y; // position of LCD
Color_t line;  //ENUm defined at GUI.h - used colors
Screen_t screen; //ENUm defined at GUI.h - prev screen for back button
extern color_t sensor_line_rgb_data[9];
extern Color_t sensor_line_evaluated_colors[9];
extern colors_t colors[7];
Screen_t prev_screen;
extern uint8_t no_line;
extern uint8_t obstacle;



// define button positions
#define bt_color1_xmin		60
#define bt_color1_xmax		120
#define bt_color2_xmin		160
#define bt_color2_xmax		220
#define bt_color3_xmin		260
#define bt_color3_xmax		320
#define bt_color4_xmin		360
#define bt_color4_xmax		420
#define bt_colors_ymin		170
#define bt_colors_ymax		230

#define bt_back_xmin		BSP_LCD_GetXSize() / 2 - 45
#define bt_back_xmax		BSP_LCD_GetXSize() / 2 + 45
#define bt_help_xmin		375
#define bt_help_xmax		465
#define bt_diagn_xmin		10
#define bt_diagn_xmax		100
#define bt_bt_upper_ymin	5
#define bt_bt_upper_ymax	25

#define bt_start_xmin		BSP_LCD_GetXSize() / 2 - 60
#define bt_start_xmax		BSP_LCD_GetXSize() / 2 + 60
#define bt_start_ymin		BSP_LCD_GetYSize() / 2 + 80 - 30
#define bt_start_ymax		BSP_LCD_GetYSize() / 2 + 80 + 30

TS_StateTypeDef TS_state;


uint32_t convert_color_code(color_t rgb_color);

/**
 * brief  make buttons on a screen
 * param  *button: a struct regarding to button property
 * param  length: length of *button
 * retval None
 */
void show_buttons(button_t *button, unsigned int length) {
	for (unsigned int i = 0; i < length; ++i) {
		// Button surface
		BSP_LCD_SetTextColor(button[i].bg_color);
		BSP_LCD_FillRect(button[i].x, button[i].y, button[i].width,
				button[i].height);

		// Frame (up. left)
		BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGRAY);
		BSP_LCD_DrawLine(button[i].x, button[i].y,
				button[i].x + button[i].width, button[i].y);
		BSP_LCD_DrawLine(button[i].x + 1, button[i].y + 1,
				button[i].x + button[i].width - 1, button[i].y + 1);
		BSP_LCD_DrawLine(button[i].x, button[i].y, button[i].x,
				button[i].y + button[i].height);
		BSP_LCD_DrawLine(button[i].x + 1, button[i].y + 1, button[i].x + 1,
				button[i].y + button[i].height - 1);

		// Frame (down. right)
		BSP_LCD_SetTextColor(LCD_COLOR_DARKGRAY);
		BSP_LCD_DrawLine(button[i].x + button[i].width,
				button[i].y + button[i].height, button[i].x,
				button[i].y + button[i].height);
		BSP_LCD_DrawLine(button[i].x + button[i].width - 1,
				button[i].y + button[i].height - 1, button[i].x + 1,
				button[i].y + button[i].height - 1);
		BSP_LCD_DrawLine(button[i].x + button[i].width,
				button[i].y + button[i].height, button[i].x + button[i].width,
				button[i].y);
		BSP_LCD_DrawLine(button[i].x + button[i].width - 1,
				button[i].y + button[i].height - 1,
				button[i].x + button[i].width - 1, button[i].y + 1);

		// Text
		BSP_LCD_SetTextColor(button[i].txt_color);
		BSP_LCD_SetBackColor(button[i].bg_color);
		BSP_LCD_SetFont(&Font20);
		BSP_LCD_DisplayStringAt(
				button[i].x + (button[i].width / 2)
						- (Font20.Width * strlen(button[i].title) / 2),
				(uint16_t) ((button[i].y
						+ (double) (button[i].height - Font20.Height) / 2) + 1),
				(uint8_t *) button[i].title, LEFT_MODE);
	}
}

/**
 * brief  check button touch
 * param  *button: a struct regarding to button property
 * param  length: length of *button
 * retval None
 */
void check_button_touch(button_t *button, unsigned int length) {
	uint16_t x = 0;
	uint16_t y = 0;

	BSP_TS_GetState(&TS_state);
	if (TS_state.touchDetected) {
		// get cordinate where you tuoch the screen
		x = TS_state.touchX[0];
		y = TS_state.touchY[0];
	}

	for (unsigned int i = 0; i < length; ++i) {
		if (x >= button[i].x && x <= button[i].x + button[i].width
				&& y >= button[i].y && y <= button[i].y + button[i].height) {
			button[i].function();
			break;
		}
	}
}


/**
 * brief  Initialize GUI and touch screen
 * param  None
 * retval None
 */
void GUI_Init() {

	BSP_LCD_Init();
	// Initialize the LCD Layers
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, SDRAM_DEVICE_ADDR);
	BSP_LCD_LayerDefaultInit(2, SDRAM_DEVICE_ADDR);
	// Set LCD Foreground Layer
	BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
	BSP_LCD_SetFont(&LCD_DEFAULT_FONT);

	// Initialize touch screen
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
	BSP_LCD_Clear(LCD_COLOR_BLACK);
}

/*
 * brief  make a diagnostic button to the upper left screen
 * param  None
 * retval None
 */
void button_diagnostic()
{
	BSP_LCD_SetBackColor(LCD_COLOR_GRAY);
	BSP_LCD_SetTextColor(LCD_COLOR_GRAY);
	BSP_LCD_FillRect(10, 5, 90, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawRect(10, 5, 90, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAt(12, 9, (uint8_t *) " DIAGNOSTIC", LEFT_MODE);
	BSP_LCD_SetFont(&Font20);
}

/**
  * brief make a help button to the upper right screen
  * param  None
  * retval None
  */
void button_help()
{
	BSP_LCD_SetBackColor(LCD_COLOR_GRAY);
	BSP_LCD_SetTextColor(LCD_COLOR_GRAY);
	BSP_LCD_FillRect(375, 5, 90, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawRect(375, 5, 90, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAt(12, 9, (uint8_t *) "HELP    ", RIGHT_MODE);
	BSP_LCD_SetFont(&Font20);
}

/*
 * brief make a help button to the upper center screen
 * param  None
 * retval None
 */
void button_back()
{
	BSP_LCD_SetBackColor(LCD_COLOR_GRAY);
	BSP_LCD_SetTextColor(LCD_COLOR_GRAY);
	BSP_LCD_FillRect(BSP_LCD_GetXSize() / 2 - 45, 5, 90, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawRect(BSP_LCD_GetXSize() / 2 - 45, 5, 90, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAt(12, 9, (uint8_t *) "BACK    ", CENTER_MODE);
	BSP_LCD_SetFont(&Font20);
}

/**
  * brief make start button center mode to the "selected color screen
  * param  None
  * retval None
  */
void button_start()
{
	BSP_LCD_SetBackColor(LCD_COLOR_LIGHTMAGENTA);
	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTMAGENTA);
	BSP_LCD_FillEllipse(bt_start_xmin + 60, bt_start_ymax - 30, 60, 30);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(0, (BSP_LCD_GetYSize() / 2 + 70), (uint8_t *) "START", CENTER_MODE);
	BSP_LCD_SetFont(&Font20);
}

/**
  * brief a function to place diagnostic, help and back buttons to the screen at the same time
  * param  None
  * retval None
  */
void place_diagn_help_back_button()
{
button_diagnostic();
button_help();
button_back();
}


/**
  * brief a function to place diagnostic and help buttons to the screen at the same time
  * param  None
  * retval None
  */
void place_diagn_help_button()
{
button_diagnostic();
button_help();
}

/**
  * brief Screen, where write short introduction about Jean, the serving car
  * param  None
  * retval None
  */
void screen_welcome()  // Jean short introduce
{
	screen = JEAN;
	// Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	// write out the text
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 90, (uint8_t *) "Hello I am Jean,", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 110, (uint8_t *) "the serving car",	CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 130, (uint8_t *) "of the Kryptonite team", CENTER_MODE);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAt(0, 165, (uint8_t *) "was born in 2018 at Static class", CENTER_MODE);
}

/**
  * brief A screen with instruction: place the car to the start position
  * param  None
  * retval None
  */
void screen_startpos()
{	
	screen = START;
	HAL_GPIO_WritePin(SENSOR_LIGHTS, SET);
	buttonstate = 0;
	// Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	// write out the text
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 100, (uint8_t *) "Please place me", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 120, (uint8_t *) "to the start position",
			CENTER_MODE);

	// color lines at the end of screen -red, blue, green, yellow
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_FillRect(0, 180, 480, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_FillRect(0, 200, 480, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_FillRect(0, 220, 480, 20);
	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_FillRect(0, 240, 480, 20);

	// place help and diagnostic buttons of this screen
	place_diagn_help_button();
	while (TS_state.touchDetected) {
			BSP_TS_GetState(&TS_state);
		}
	reset_ts_coord();
	// examination of touch screen detected
	while (buttonstate != 1) {
		get_button_coordinate();
		push_diagn_or_help();
		if (numb_of_start_sign() > 6) {
			buttonstate = 1;
			write_selected_color(line);
		}
	}
}


/**
  * brief color selecting screen to select which color will be followed, when stand on the lines
  * param  None
  * retval None
  */
void line_selecting_screen() {
	screen = SELECTION;
	//Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_Clear(LCD_COLOR_BLACK);

	// Set the the object's Color
	BSP_LCD_SetTextColor(LCD_COLOR_DARKGREEN);
	// Set the place of object
	BSP_LCD_FillRect(0, 30, 480, 70);

	// Display LCD messages
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 39, (uint8_t *) "Please select", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 55, (uint8_t *) "the color of line to follow",
			CENTER_MODE);

	// circles and text tags
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_DisplayStringAt(66, 135, (uint8_t *) "RED", LEFT_MODE); // right, down,
	BSP_LCD_FillCircle(90, 200, 30); //left, down, radius
	// blue circle
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_DisplayStringAt(159, 135, (uint8_t *) "BLUE", LEFT_MODE); // right, down,
	BSP_LCD_FillCircle(190, 200, 30);
	// green circle
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_DisplayStringAt(250, 135, (uint8_t *) "GREEN", LEFT_MODE); // right, down,
	BSP_LCD_FillCircle(290, 200, 30);
	// yellow circle
	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_DisplayStringAt(345, 135, (uint8_t *) "YELLOW", LEFT_MODE); // right, down,
	BSP_LCD_FillCircle(390, 200, 30);
	// place needed buttons to the screen
	place_diagn_help_button();
	buttonstate = 0;
	reset_ts_coord();
	while (TS_state.touchDetected) {
		BSP_TS_GetState(&TS_state);
	}
	// examination of touch screen detected
	reset_ts_coord();
	while (buttonstate != 1) {
		get_button_coordinate();
		push_diagn_or_help();
		push_back();
		set_color();
		//push_start();
	}
}


/*
 * brief A screen which write the selected color
 * param Color_t line is an ENUM, which is the selected color
 * retval None
 */
void write_selected_color(Color_t line) 
{
	screen = COLORWRITER;
	// Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_Clear(LCD_COLOR_BLACK);

	// Display LCD messages
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(0, 45, (uint8_t *) "The selected color is", CENTER_MODE);

	switch (line) {
	case RED:
		BSP_LCD_DisplayStringAt(0, 65, (uint8_t *) "RED",  CENTER_MODE);
		// Set the LCD Text Color
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
		BSP_LCD_FillRect(0, 110, 480, 60);
		break;
	case BLUE:
		BSP_LCD_DisplayStringAt(0, 65, (uint8_t *) "BLUE", CENTER_MODE);
		// Set the LCD Text Color
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
		BSP_LCD_FillRect(0, 110, 480, 60);
		break;
	case GREEN:
		BSP_LCD_DisplayStringAt(0, 65, (uint8_t *) "GREEN", CENTER_MODE);
		// Set the LCD Text Color
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		BSP_LCD_FillRect(0, 110, 480, 60);
		break;
	case YELLOW:
		BSP_LCD_DisplayStringAt(0, 65, (uint8_t *) "YELLOW", CENTER_MODE);
		// Set the LCD Text Color
		BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
		BSP_LCD_FillRect(0, 110, 480, 60);
		break;
	case WHITE:
		break;
	case BLACK:
		break;
	case GREY:
		break;
	case UNKNOWN:
		break;
	}
	// place buttons to the screen
	place_diagn_help_back_button();
	button_start();
	// reset buttonstate and ts coordinate
	buttonstate = 0;
	reset_ts_coord();
	// a short delay to avoid fast touching on the next screen
	while (TS_state.touchDetected) {
			BSP_TS_GetState(&TS_state);
		}
	//examine touch
	while (buttonstate !=1){
		get_button_coordinate();
		push_diagn_or_help();
		push_back();
		push_start();
	}
}

/**
  * brief examine touch screen detection for color selecting
  * param line = selected color defined as ENUM in GUI.h file
  * retval None
  */
void set_color()
{
	if ((x >= 60 && x <= 120) && ( y >= 170 && y <= 230)){  // COLOR1 selected
		line = RED;
		screen_startpos();
	} else if ((x >= 160 && x <= 220) && ( y >= 170 && y <= 230)){  //COLOR2 selected
		line = BLUE;
		screen_startpos();
	} else if ((x >= 260 && x <= 320) && (y >= 170 && y <= 230)) { //COLOR3 selected
		line = GREEN;
		screen_startpos();
	} else if ((x >= 360 && x <= 420) && (y >= 170 && y <= 230)) { //COLOR4 selected
		line = YELLOW;
		screen_startpos();
	}
}

/**
  * brief examine touch screen, when push diagnostic or help button
  * param  None
  * retval None
  */
void push_diagn_or_help() {
	if ((x >= bt_diagn_xmin && x <= bt_diagn_xmax) && (y >= bt_bt_upper_ymin && y <= bt_bt_upper_ymax)) {  // DIAGNOSTIC button
		screen_diagnostic();
		buttonstate = 1;
	}
	if ((x >= 375 && x <= 465) && (y >= 5 && y <= 35)) {  // coordinates of HELP button
		screen_help();
		buttonstate = 1;
	}
}

/**
 * brief Create touch screen to back button in upper central of screen
 * param  None
 * retval None
 */
void push_back() {
	if ((x >= (bt_back_xmin) && x <= (bt_back_xmax)) && (y >= bt_bt_upper_ymin && y <= bt_bt_upper_ymax)) {
		screen_prev();
		buttonstate = 1;
	}
}


/**
 * brief If touch back button, step back to the prev screen
 * param  None
 * retval None
 */
void screen_prev() {
	switch (screen){
	case START:
		screen_startpos();
		break;
	case COLORWRITER :
		write_selected_color(line);
		break;
	case JEAN:
		screen_welcome();
		break;
	case SELECTION :
		line_selecting_screen();
		break;
	}
}

/**
 * brief Create touch screen to start button in upper central of screen
 * param  None
 * retval None
 */
void push_start()
{
	if ((x >= bt_start_xmin && x <= bt_start_xmax) && (y >= bt_start_ymin && y <= bt_start_ymax )) {
		// todo : make external variable for status and off LCD
		buttonstate = 1;
	//	BSP_LCD_DisplayOff();
		BSP_LCD_Clear(LCD_COLOR_BLACK);
	}
}

/**
 * brief Set ts coordinates when you touch the screen
 * param  None
 * retval None
 */
void get_button_coordinate() {

	BSP_TS_GetState(&TS_state);
	if (TS_state.touchDetected) {

		// get cordinate where you tuoch the screen
		x = TS_state.touchX[0];
		y = TS_state.touchY[0];
	}
}

/**
  * brief reset touch screen coordiantes to 0
 * param  None
 * retval None
 */
void reset_ts_coord()
{
			x = 0;		//reset coordinate x
			y = 0;		//reset coordinate y
}


/**
 * brief play screens in first time when you start Jean
 * param  None
 * retval None
 */
void play_welcome_screens()
{
	screen_welcome();
	// wait 5 s or if you touch the screen, change slide
	while (buttonstate != 0) {
		uint32_t tickstart = HAL_GetTick();
		BSP_TS_GetState(&TS_state);
		if (TS_state.touchDetected || tickstart > 5000) {
			buttonstate = 0;
		}
	}
	line_selecting_screen();
	//screen_startpos();
	buttonstate = 0;

}
/*
 * Yes button for delivery screen
 * param  None
 * retval None
 */
void button_yes()
{
	BSP_LCD_SetBackColor(LCD_COLOR_LIGHTMAGENTA);
	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTMAGENTA);
	BSP_LCD_FillEllipse(bt_start_xmin + 60, bt_start_ymax - 30, 60, 30);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(0, (BSP_LCD_GetYSize() / 2 + 70), (uint8_t *) "YES", CENTER_MODE);
	BSP_LCD_SetFont(&Font20);
}

/**
 * brief When feel an obstacle less than 60s
 * param  None
 * retval None
 */
void screen_delivery()
{
	// Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Set the the object's Color
	BSP_LCD_SetTextColor(LCD_COLOR_DARKGREEN);
	/* Set the place of object */
	BSP_LCD_FillRect(0, 30, 480, 100);

	// write out the text
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 45, (uint8_t *) "Are you ordered me?",
			CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 75, (uint8_t *) "If no, do nothing",
			CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 105, (uint8_t *) "If yes, push the button",
			CENTER_MODE);

	button_yes();
	buttonstate = 0;
	reset_ts_coord();
	uint32_t tickstart = HAL_GetTick();
	while (buttonstate != 1) {
		get_button_coordinate();
		if ((x >= bt_start_xmin && x <= bt_start_xmax) && (y >= bt_start_ymin && y <= bt_start_ymax )) {
				// todo : what to do???
				screen_after_delivered();
				buttonstate = 1;
		} if (HAL_GetTick() - tickstart > 5000) {
			buttonstate = 1;
		}
	}
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	//BSP_LCD_DisplayOff();
}

void screen_after_delivered()
{
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Set the the object's Color
	BSP_LCD_SetTextColor(LCD_COLOR_DARKGREEN);
	/* Set the place of object */
	BSP_LCD_FillRect(0, 30, 480, 100);

	// write out the text
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 45,
			(uint8_t *) "Push start, if you take your order ", CENTER_MODE);
	button_start();
	while (TS_state.touchDetected) {
		BSP_TS_GetState(&TS_state);
	}
	reset_ts_coord();
	buttonstate = 0;
	while (buttonstate != 1) {
		get_button_coordinate();
		if ((x >= bt_start_xmin && x <= bt_start_xmax)	&& (y >= bt_start_ymin && y <= bt_start_ymax)) {
			buttonstate = 1;
		}
	}
	HAL_Delay(1000);
}

/**
 * brief short introduction of Jean and the serving car
 * param  None
 * retval None
 */
void screen_help() {
	// todo: write some lines
	//Clear the LCD */
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_Clear(LCD_COLOR_BLACK); // possible to remove
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Set the the object's Color
	BSP_LCD_SetTextColor(LCD_COLOR_DARKGREEN);
	// Set the place of object
	BSP_LCD_FillRect(0, 30, 480, 50);

	// write out the text
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 45, (uint8_t *) "HELP screen", CENTER_MODE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(0, 80, (uint8_t *) "When you place me to the start position ",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 95, (uint8_t *) "(black line) and select, which colored ",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 110, (uint8_t *) "of line to follow, and after that push ",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 125, (uint8_t *) "'Start' I will serve you. ",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 145, (uint8_t *) "When you see'ALARM screen, something ",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 160, (uint8_t *) "happened, but you can see on the screen,",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 175, (uint8_t *) "what would you to do to solve the problem.",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 195, (uint8_t *) "When you push 'Back', you can  ",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 210, (uint8_t *) "choose the color. ",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 230, (uint8_t *) "When you push 'Diagnostic', you can see",LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 245, (uint8_t *) "some technical details about me ",LEFT_MODE);
	buttonstate = 0;
	button_back();
	button_diagnostic();
	buttonstate = 0;
	while (TS_state.touchDetected) {
			BSP_TS_GetState(&TS_state);
		}
	reset_ts_coord();
	while (buttonstate != 1) {
		get_button_coordinate();
		if ((x >= bt_diagn_xmin  && x <= bt_diagn_xmax) && (y >= bt_bt_upper_ymin && y <= bt_bt_upper_ymax + 5)) {  // DIAGNOSTIC button
			screen_diagnostic();
			buttonstate = 1;
				}
			push_back();
		}
}

/**
 * brief A diagnostic screen, where you can see some data about working, measuring
 * param  None
 * retval None
 */
void screen_diagnostic() 
{
while (TS_state.touchDetected) {
BSP_TS_GetState(&TS_state);
				}
HAL_GPIO_WritePin(SENSOR_LIGHTS, SET);


while(1){

		get_rgb_datas();
	/*while (TS_state.touchDetected) {
				BSP_TS_GetState(&TS_state);
			}
	static uint32_t timestamp = 0;
	BSP_TS_GetState(&TS_state);
	reset_ts_coord();
	if (TS_state.touchDetected) {
				// get cordinate where you tuoch the screen
				x = TS_state.touchX[0];
				y = TS_state.touchY[0];

				if (x > 0 && x < 34) {
					screen = RGB_DIAGN;
					prev_screen = DIAGNOSTIC;
					BSP_LCD_Clear(LCD_COLOR_BLACK);
				} else if ((x > 34) /*&& (x < 120) && (y> 140) && (y < 215)*/ /*) {
					screen = URM_DIAGN;
					prev_screen = DIAGNOSTIC;
					BSP_LCD_Clear(LCD_COLOR_BLACK);
				}
			}

	if (screen == RGB_DIAGN) {
		rgb_diagnostic();
	} else if (screen == URM_DIAGN) {
		screen_urm_diagn();
	} else if (HAL_GetTick() - timestamp > 200){
		timestamp = HAL_GetTick();

		screen = DIAGNOSTIC;
*/
		// Clear the LCD
		BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
		BSP_LCD_Clear(LCD_COLOR_BLACK); // possible to remove
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

		/* values to write*/
		char us_sensor_val[10];
		sprintf(us_sensor_val, "%d", URM_GetDistance());
		char drive_state[20];

			if (st.command == 0){
				sprintf(drive_state, "Forward  speed:%d", st.act_speed);
			}else if(st.command == 1){
				sprintf(drive_state, "Backward speed:%d", st.act_speed);
			}else if(st.command == 2){
				sprintf(drive_state, "Break    speed:%d", st.act_speed);
			}else{
				sprintf(drive_state, "              speed:%d", st.act_speed);
		}

		char serv_dir[20];
		sprintf(serv_dir, "%d", servo_get_pos());
		char batt_voltage[20];
		sprintf(batt_voltage, "%dmV ", (int) (ADC_GetBatteryVoltage() * 1000));
		char PWM_multiplier[20];
		sprintf(PWM_multiplier, "%d%%", (int) (ADC_GetPwmMultiplier() * 100));


		/*	9 squares */
		int b = 24; // square size

		for (int i = 0; i < 9; i++)
		{
			BSP_LCD_SetTextColor(colors[sensor_line_evaluated_colors[i]].color_show);
			BSP_LCD_FillRect(5, (10 - i) * b - i, b, b); //x pos, y pos, width, height
		}
			// write out the text
		BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_SetFont(&Font20);
		BSP_LCD_DisplayStringAt(0, 25, (uint8_t *) "Diagnostic screen", CENTER_MODE);
		BSP_LCD_DisplayStringAt(40, 60, (uint8_t *) "<- RGB values", LEFT_MODE);
		BSP_LCD_DisplayStringAt(40, 120, (uint8_t *) "ultrasonic value   drive state", LEFT_MODE);
		BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
		BSP_LCD_DisplayStringAt(40, 150, (uint8_t *) us_sensor_val, LEFT_MODE);
		BSP_LCD_DisplayStringAt(230, 150, (uint8_t *) drive_state, LEFT_MODE);
		BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
		BSP_LCD_DisplayStringAt(40, 180, (uint8_t *) "servo direction battery mV,PWM", LEFT_MODE);
		BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
		BSP_LCD_DisplayStringAt(40, 210, (uint8_t *) serv_dir, LEFT_MODE);
		BSP_LCD_DisplayStringAt(290, 210, (uint8_t *) batt_voltage, LEFT_MODE);
		BSP_LCD_DisplayStringAt(380, 210, (uint8_t *) PWM_multiplier, LEFT_MODE);


		BSP_TS_GetState(&TS_state);
		if(TS_state.touchDetected)
			break;

		HAL_Delay(100);
	}
}

/**
 * brief Make an alarm, when lost the line, or battery is too low
 * param  None
 * retval None
 */
void screen_alarm() {

	// place buttons to the screen
	buttonstate = 0;
	place_diagn_help_button();

	//todo: make flags in correct way - modify name

	if (no_line == 1 && obstacle == 1) {
		 color_lost_alarm_message();
		 obstarctle_alarm_message();
	 } else if (no_line == 1) {
		 color_lost_alarm_message();
	 } else if (obstacle == 1) {
		 obstarctle_alarm_message();
	 }

	while(buttonstate !=1){
		get_button_coordinate();
		push_diagn_or_help(); // todo: modify help screen because back button
	}
}



void battery_alarm_message()
{
	// Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_Clear(LCD_COLOR_RED);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Set the the object's Color
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	// Set the place of object
	BSP_LCD_FillRect(0, 30, 480, 70);

	// write out the text
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 45, (uint8_t *) "Alarm!", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 70, (uint8_t *) "Something happend!",
			CENTER_MODE);
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(0, 110, (uint8_t *) "LOW BATTERY!", CENTER_MODE);
}

void color_lost_alarm_message()
{
	// Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_Clear(LCD_COLOR_RED);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Set the the object's Color
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	// Set the place of object
	BSP_LCD_FillRect(0, 30, 480, 70);

	// write out the text
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 45, (uint8_t *) "Alarm!", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 70, (uint8_t *) "Something happend!",
			CENTER_MODE);
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(0, 140, (uint8_t *) "I HAVE LOST THE LINE!", CENTER_MODE);
}

void obstarctle_alarm_message()
{		// Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_Clear(LCD_COLOR_RED);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Set the the object's Color
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	// Set the place of object
	BSP_LCD_FillRect(0, 30, 480, 70);

	// write out the text
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 45, (uint8_t *) "Alarm!", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 70, (uint8_t *) "Something happend!",
			CENTER_MODE);
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(0, 170, (uint8_t *) "THERE IS AN OBSTACLE!", CENTER_MODE);
}

/**
 * brief when the car stopped, you will see this screen
 * param  None
 * retval None
 */
void screen_stopped()
{
	// Clear the LCD
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_Clear(LCD_COLOR_BLACK); // possible to remove
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	// Set the the object's Color
	BSP_LCD_SetTextColor(LCD_COLOR_DARKGREEN);
	// Set the place of object
	BSP_LCD_FillRect(0, 30, 480, 70);

	// write out the text
	BSP_LCD_SetBackColor(LCD_COLOR_DARKGREEN);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(0, 45,
			(uint8_t *) "Stopped! Whats's going on?", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 70, (uint8_t *) "Let me go!",
			CENTER_MODE);

	// place buttons to the screen
	place_diagn_help_button();
}


void rgb_diagnostic()
{
	prev_screen = screen;
	screen = RGB_DIAGN;
	/*	9 squares */
	int b = 24; // big square size
	char string[50];

	for (int i = 0; i < 9; i++) {
		// show measured and corrected colors
		BSP_LCD_SetTextColor(convert_color_code(sensor_line_rgb_data[i]));
		BSP_LCD_FillRect(0, (10 - i) * b - i, b, b); //x pos, y pos, width, height

		// show evaluated colors
		BSP_LCD_SetTextColor(
				colors[sensor_line_evaluated_colors[i]].color_show);
		BSP_LCD_FillRect(b + 5 + 32 + 5, (10 - i) * b - i, b, b); //x pos, y pos, width, height

		for (int j = 0; j < 5; j++) {
			// Clear background of color candles
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			BSP_LCD_FillRect(b + 5, (((10 - i) * b) + b / 4 * 0) - i, 32, b);

			// Draw color candles
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			BSP_LCD_FillRect(b + 5, (((10 - i) * b) + b / 4 * 0) - i,
					sensor_line_rgb_data[i].r * 32 / 0xFFFF, b / 4); //x pos, y pos, width, height

			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
			BSP_LCD_FillRect(b + 5, (((10 - i) * b) + b / 4 * 1) - i,
					sensor_line_rgb_data[i].g * 32 / 0xFFFF, b / 4); //x pos, y pos, width, height

			BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
			BSP_LCD_FillRect(b + 5, (((10 - i) * b) + b / 4 * 2) - i,
					sensor_line_rgb_data[i].b * 32 / 0xFFFF, b / 4); //x pos, y pos, width, height

			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_FillRect(b + 5, (((10 - i) * b) + b / 4 * 3) - i,
					sensor_line_rgb_data[i].c * 32 / 0xFFFF, b / 4); //x pos, y pos, width, height

			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_SetBackColor(LCD_COLOR_BLACK);

			// Text
			BSP_LCD_SetFont(&Font20);
			sprintf(string, "R:%.3u G:%.3u B:%.3u C:%.3u",
					sensor_line_rgb_data[i].r / 256,
					sensor_line_rgb_data[i].g / 256,
					sensor_line_rgb_data[i].b / 256,
					sensor_line_rgb_data[i].c / 256);
			BSP_LCD_DisplayStringAt(b + 5 + 32 + 40, (10 - i) * b - i,
					(uint8_t *) string, LEFT_MODE);
		}
	}
	button_back();
	buttonstate = 0;
	while (buttonstate != 1) {
		get_button_coordinate();
		if ((x >= (bt_back_xmin) && x <= (bt_back_xmax)) && (y >= bt_bt_upper_ymin && y <= bt_bt_upper_ymax)) {
			screen_diagnostic();
		/*	switch (prev_screen) {
			case DIAGNOSTIC:
				screen_diagnostic();
				break;
			case URM_DIAGN:
				prev_screen = RGB_DIAGN;
				screen = URM_DIAGN;
				screen_urm_diagn();
				break;
			case RGB_DIAGN:
				rgb_diagnostic();
				break;
			} */
			buttonstate = 1;
		}
	}
}

/**
  * brief  Convert color_t type color into 32 bit color
  * param  rgb_color: color in color_t struct format
  * retval Color in 32 bit ARGB(8-8-8-8)
  */
uint32_t convert_color_code(color_t rgb_color) {
	uint32_t color = 0xFF000000;

	color += (rgb_color.r / 256) << 16;
	color += (rgb_color.g / 256) << 8;
	color += (rgb_color.b / 256);

	return color;
}

int numb_of_start_sign()
{
	int start_sign = 0;
	get_rgb_datas();
	for (uint i = 0; i < 9; i++){
		if (sensor_line_evaluated_colors[i] == WHITE)
			start_sign++;
	}
	return start_sign;
}

/**
  * brief  Show test screen with actual values for Ultrasonic Ranging Module (URM).
  *        Call this function after every new measure to refresh the screen
  * param  None
  * retval None
  */
void screen_urm_diagn()
{
	static uint32_t timestamp = 0;
	button_back();
	if (HAL_GetTick() - timestamp > 100) {
		timestamp = HAL_GetTick();

		char cm[10] = "";
		uint16_t x = 0;
		uint16_t y = 0;

		unsigned int number_of_values;
		uint16_t *measuredValues = NULL;
		uint16_t measuredValues_end = 0;
		uint16_t actual_echo = 0;
		URM_GetTestScreenData(measuredValues, &number_of_values,
				&measuredValues_end, &actual_echo);

		// show actual distance value in cm
		sprintf(cm, "%d cm  ", URM_GetDistance());
		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		BSP_LCD_DisplayStringAt(12, 9, (uint8_t *) cm, LEFT_MODE);

		// show graph of last measured values
		int pos = 0;
		for (unsigned int i = 0; i < number_of_values; ++i) {
			pos = measuredValues_end - i;
			if (pos < 0)
				pos = URM_NUMBER_OF_THE_BUFFERED_VALUES
						+ (measuredValues_end - i);
			;
			BSP_LCD_SetTextColor(LCD_COLOR_GRAY);
			x = RK043FN48H_WIDTH
					- i * ((double) RK043FN48H_WIDTH / number_of_values) - 1;
			y = measuredValues[pos]
					* ((double) (RK043FN48H_HEIGHT - 70)
							/ URM_ECHO_NOOBJECT_VALUE);
			BSP_LCD_DrawLine(x, RK043FN48H_HEIGHT, x, RK043FN48H_HEIGHT - y);

			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			BSP_LCD_DrawLine(x, RK043FN48H_HEIGHT - y, x, 70);
		}

		// show line for average
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
		x = RK043FN48H_WIDTH
				- URM_ECHO_LAST_VALUES_FOR_AVERAGE
						* ((double) RK043FN48H_WIDTH / number_of_values) - 1;
		y = actual_echo
				* ((double) (RK043FN48H_HEIGHT - 70) / URM_ECHO_NOOBJECT_VALUE);
		BSP_LCD_DrawLine(x, RK043FN48H_HEIGHT - y, RK043FN48H_WIDTH - 1,
				RK043FN48H_HEIGHT - y);
	}
	button_back();
	buttonstate = 0;
	while (buttonstate != 1) {
		get_button_coordinate();
		if ((x >= (bt_back_xmin) && x <= (bt_back_xmax))
				&& (y >= bt_bt_upper_ymin && y <= bt_bt_upper_ymax)) {
			screen = DIAGNOSTIC;
			prev_screen = DIAGNOSTIC;
			screen_diagnostic();
			buttonstate = 1;
		}
	}
}

