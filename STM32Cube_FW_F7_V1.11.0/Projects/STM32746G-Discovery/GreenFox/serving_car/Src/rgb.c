#include "rgb.h"
#include "color_eval.h"

struct {double r,g,b,c;}
rgb_sensor_color_correction_values[9] = {
		{1.45, 1.38, 1.21, 1.58},
		{1.04, 1.06, 1.09, 1.26},
		{0.92, 0.88, 0.89, 1.02},
//		{0.95, 0.90, 0.87, 0.99}, // LED OFF ON SENSOR
		{1.05, 1, 	 0.97, 1.2},
		{0.89, 0.92, 0.94, 0.99},
		{1.09, 1.09, 1.03, 1.01},
		{0.99, 0.98, 0.97, 1.00},
		{0.82, 0.85, 0.93, 0.99},
		{1.07, 1.13, 1.20, 1.20},
};

// global array for storing rgb datas from 9 rgb sensors
extern color_t sensor_line_rgb_data[9];


//low-layer functions (read and write)
//----------------------------------------------------------------------
void write_8_bit_reg(to_be_addressed_t addr, uint8_t device, uint8_t reg, uint8_t val)
{
	address_multiplexer(device, WRITE, addr);
	
	uint8_t data_to_send[2];
	data_to_send[0] = reg;
	data_to_send[1] = val;
	
	HAL_I2C_Master_Transmit(&I2C_Handle, (uint16_t)APDS9960_ADDRESS, &data_to_send[0], 2, 10000);

	return;
}

void read_8_bit_reg(to_be_addressed_t addr, uint8_t device, uint8_t reg, uint8_t* data)
{
	address_multiplexer(device, WRITE, addr);
	
	HAL_I2C_Master_Transmit(&I2C_Handle, (uint16_t)APDS9960_ADDRESS, &reg, 1, 10000);

	HAL_I2C_Master_Receive(&I2C_Handle, (uint16_t)APDS9960_ADDRESS, data, 1, 10000);

	return;
}

void read_16_bit_reg(to_be_addressed_t addr, uint8_t device, uint8_t reg, uint16_t* data)
{
	address_multiplexer(device, WRITE, addr);

	HAL_I2C_Master_Transmit(&I2C_Handle, (uint16_t)APDS9960_ADDRESS, &reg, 1, 10000);
	
	uint8_t temp[2];
	HAL_I2C_Master_Receive(&I2C_Handle, (uint16_t)APDS9960_ADDRESS, temp, 2, 10000);
	*data = (uint16_t)temp[0] | ((uint16_t)temp[1] << 8);

	return;
}

//setup functions
void enable_RGBA_sensor(to_be_addressed_t addr, uint8_t device)
{
	//TODO: getting the current settings, then setting the rgba enable bits, considering not to overwrite the actual bits in the register

	write_8_bit_reg(addr, device, ADDR_ENABLE, (VAL_PON | VAL_AEN | VAL_WEN));

	return;
}

// default values settings should be here (atime, wtime...)
void init_RGBA_sensor(to_be_addressed_t addr, uint8_t device)
{
	// disable all features
	write_8_bit_reg(addr, device, ADDR_ENABLE, 0x00);
	
    // Set default values for ambient light and proximity registers
	write_8_bit_reg(addr, device, ADDR_ATIME, 237);
	write_8_bit_reg(addr, device, ADDR_WTIME, DEFAULT_WTIME);
	write_8_bit_reg(addr, device, ADDR_AGAIN, DEFAULT_AGAIN);

	return;
}

//getting RGB data and make color correction
void read_color(to_be_addressed_t addr, uint8_t device, color_t* color_data)
{
	read_16_bit_reg(addr, device, ADDR_CDATAL, &(color_data->c));
	read_16_bit_reg(addr, device, ADDR_RDATAL, &(color_data->r));
	read_16_bit_reg(addr, device, ADDR_GDATAL, &(color_data->g));
	read_16_bit_reg(addr, device, ADDR_BDATAL, &(color_data->b));

	return;
}

/**
  * brief  Corrects color to eliminate color shift caused by the bluish led
  *        and RGB sensor sensitivity, corrects the differences of sensor
  *        sensitivity and add gain to increase brightness.
  *        The correction values are determined by real testing on white surface.
  * param  color_data: pointer of a color_t type color to be corrected
  *        i:          the place of the actual color in the array
  * retval None
  */
static void color_correction(color_t *color_data, unsigned int i)
{
	const double gain = 5;

	const double red_correction =    2.2 * rgb_sensor_color_correction_values[i].r * gain;
	const double green_correction = 1.33 * rgb_sensor_color_correction_values[i].g * gain;
	const double blue_correction =     1 * rgb_sensor_color_correction_values[i].b * gain;
	const double clear_correction = 0.68 * rgb_sensor_color_correction_values[i].c * gain;

	if (color_data->r > 0xFFFF / red_correction ) {
		color_data->r = 0xFFFF;
	} else {
		color_data->r *= red_correction;
	}

	if (color_data->g > 0xFFFF / green_correction ) {
		color_data->g = 0xFFFF;
	} else {
		color_data->g *= green_correction;
	}

	if (color_data->b > 0xFFFF / blue_correction ) {
		color_data->b = 0xFFFF;
	} else {
		color_data->b *= blue_correction;
	}

	if (color_data->c > 0xFFFF / clear_correction ) {
		color_data->c = 0xFFFF;
	} else {
		color_data->c *= clear_correction;
	}
}

//functions to be called from main
void setup_sensor_line()
{
	//initializing sensors on FIRST_8
	for (int i = 1; i < 8; i++) {
		init_RGBA_sensor(FIRST_8, i);
		enable_RGBA_sensor(FIRST_8, i);
	}

	//initializing sensors on SECOND_2
	init_RGBA_sensor(SECOND_2, 0);
	enable_RGBA_sensor(SECOND_2, 0);

	init_RGBA_sensor(SECOND_2, 1);
	enable_RGBA_sensor(SECOND_2, 1);

 	return;
}

void get_rgb_datas()
{
	//reading data from the FIRST_8 multiplexer
	read_color(FIRST_8, 3, &sensor_line_rgb_data[0]);
	read_color(FIRST_8, 2, &sensor_line_rgb_data[1]);
	read_color(FIRST_8, 1, &sensor_line_rgb_data[2]);
	read_color(FIRST_8, 4, &sensor_line_rgb_data[3]);
	read_color(FIRST_8, 5, &sensor_line_rgb_data[4]);
	read_color(FIRST_8, 7, &sensor_line_rgb_data[5]);
	read_color(FIRST_8, 6, &sensor_line_rgb_data[6]);
	
	//reading data from the SECOND_2 multoplexer
	read_color(SECOND_2, 0, &sensor_line_rgb_data[7]);
	read_color(SECOND_2, 1, &sensor_line_rgb_data[8]);

	// color correction due to the different sensor sensibility
	for (unsigned int i = 0; i < 9; ++i) {
		color_correction(&sensor_line_rgb_data[i], i);
	}

	color_evaluation();

	return;
}

#define LED_PWM_PERIOD			300					// period is 300 us long
#define LED_PWM_PRESCALER		108					// so 1.000.000 incrementation makes out 1 sec

GPIO_InitTypeDef		gpio;
TIM_HandleTypeDef		timh;
TIM_OC_InitTypeDef		timpwm;


/*
 * FUNCTIONS FOR INITIALIZING RGB DETECTION UTILITIES
 */
void GPIO_RGB_Init()
{
	/* INIT CLOCKS */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();

    /* INIT PINS */
	/* D11 */
	gpio.Pin = D11_PIN;
	gpio.Speed = GPIO_SPEED_FAST;
	/*gpio.Alternate = GPIO_AF9_TIM12;      // and the alternate function is to use TIM12
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pull = GPIO_NOPULL;*/
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(D11_PORT, &gpio);

	/* D1 */
	gpio.Pin = D1_PIN;
	HAL_GPIO_Init(D1_PORT, &gpio);
	/* D2 */
	gpio.Pin = D2_PIN;
	HAL_GPIO_Init(D2_PORT, &gpio);

}

