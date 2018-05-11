#ifndef RGB_H_
#define RGB_H_

#include "main.h"
#include "mot_control.h"
#include "port_define.h"
#include "multiplexer.h"
// rgba datas from sensor
typedef struct {
	uint16_t r;
	uint16_t g;
	uint16_t b;
	uint16_t c;
} color_t;

// global array for storing rgb datas from 9 rgb sensors
color_t sensor_line_rgb_data[9];

#define APDS9960_ADDRESS			(0x39 << 1)

//RGBA specific register addresses
//----------------------------------------------------------------------
//enable register
#define ADDR_ENABLE					0x80

#define ADDR_ATIME					0x81
#define ADDR_WTIME					0x83
#define ADDR_AGAIN					0x8F	//for AGAIN bits <1:0>
#define ADDR_AILTL					0x84	//ALS low threshold, lower byte
#define ADDR_AILTH					0x85	//ALS low threshold, upper byte
#define ADDR_AIHTL					0x86	//ALS high threshold, lower byte
#define ADDR_AIHTH					0x87	//ALS high threshold, upper byte
#define ADDR_WLONG					0x8D	//Wait Long Enable <1>
#define ADDR_CPSIEN					0x90	//Clear diode Saturation Interrupt Enable <6>
#define ADDR_CPSAT					0x93	//Clear Diode Saturation <7>
#define ADDR_AINT					0x93	//ALS Interrupt <4>
#define ADDR_AVALID					0x93	//ALS Valid <0>


#define ADDR_CDATAL					0x94
#define ADDR_CDATAH					0x95
#define ADDR_RDATAL					0x96
#define ADDR_RDATAH					0x97
#define ADDR_GDATAL					0x98
#define ADDR_GDATAH					0x99
#define ADDR_BDATAL					0x9A
#define ADDR_BDATAH					0x9B

//----------------------------------------------------------------------

//RGBA specific register values
//----------------------------------------------------------------------
//enable bits
#define VAL_PON		0b00000001
#define VAL_AEN		0b00000010
#define VAL_WEN		0b00001000

//gain
#define VAL_AGAIN_1X		0b00
#define VAL_AGAIN_4X		0b01
#define VAL_AGAIN_16X		0b10
#define VAL_AGAIN_64X		0b11

//atime
#define VAL_ATIME_712		0x00	//712 ms
#define VAL_ATIME_200		0xB6	//200 ms
#define VAL_ATIME_103		0xDB	//103 ms
#define VAL_ATIME_27_8		0xF6	//27.8 ms
#define VAL_ATIME_2_78		0xFF	//2.78 ms

//wtime
#define VAL_WTIME_712		0x00
#define VAL_WTIME_236		0xAB
#define VAL_WTIME_200		0xB8 //appr.
#define VAL_WTIME_100		0xDC //appr.
#define VAL_WTIME_2_78		0xFF


//----------------------------------------------------------------------

//default values
//----------------------------------------------------------------------
#define DEFAULT_ATIME				VAL_ATIME_103
#define DEFAULT_WTIME				VAL_WTIME_2_78
#define DEFAULT_AGAIN				VAL_AGAIN_64X
//----------------------------------------------------------------------

void write_8_bit_reg(to_be_addressed_t addr, uint8_t device, uint8_t reg, uint8_t val);
void read_8_bit_reg(to_be_addressed_t addr, uint8_t device, uint8_t reg, uint8_t* data);
void read_16_bit_reg(to_be_addressed_t addr, uint8_t device, uint8_t reg, uint16_t* data);

void enable_RGBA_sensor(to_be_addressed_t addr, uint8_t device);
void init_RGBA_sensor(to_be_addressed_t addr, uint8_t device);

void read_color(to_be_addressed_t addr, uint8_t device, color_t* color_data);
static void color_correction(color_t *color_data, unsigned int i);

void setup_sensor_line();
void GPIO_RGB_Init();
void LED_TIM12_PWM_Init();
void get_rgb_datas();


#endif /* RGB_H_ */
