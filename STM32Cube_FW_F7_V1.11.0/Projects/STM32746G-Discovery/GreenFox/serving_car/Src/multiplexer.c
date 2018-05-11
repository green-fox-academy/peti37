#include "multiplexer.h"
#include "main.h"

uint8_t first_8_channel = 0;
uint8_t second_2_channel = 0;

I2C_HandleTypeDef I2C_Handle;
GPIO_InitTypeDef GPIO_Handle;


/**
 * brief  Initialize I2C for RGB sensors
 * param  None
 * retval None
 */
void I2C_init()
{
	// INITIALIZING RESET PIN FOR MULTIPLEXERS
	GPIO_Handle.Mode		= GPIO_MODE_OUTPUT_OD;
	GPIO_Handle.Pin			= D12_PIN;
	GPIO_Handle.Pull		= GPIO_PULLUP;
	GPIO_Handle.Speed		= GPIO_SPEED_HIGH;
	HAL_GPIO_Init(D12_PORT, &GPIO_Handle);
	HAL_GPIO_WritePin(MUX, SET);

	// INITIALIZING CLOCK & PINS FOR I2C
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_Handle.Alternate	= GPIO_AF4_I2C1;
	GPIO_Handle.Mode		= GPIO_MODE_AF_OD;
	GPIO_Handle.Pin			= D15_PIN | D14_PIN;	// SCL | SDA
	GPIO_Handle.Pull		= GPIO_PULLUP;
	GPIO_Handle.Speed		= GPIO_SPEED_HIGH;
	HAL_GPIO_Init(D15_PORT, &GPIO_Handle); 			// the two pins are on the same port
	
	__HAL_RCC_I2C1_CLK_ENABLE();
	
	I2C_Handle.Instance				= I2C1;
	I2C_Handle.Init.Timing          = 0x40912732;
	I2C_Handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	HAL_I2C_Init(&I2C_Handle);

}


/**
 * brief  address multiplexer for RGB sensor
 * have 2 multiplexer for 10 sensor (one is gesture and 9 RGB sensore)
 * param  device which MUX you use
 * param rw using read or write I2C
 * param addr first 8 or last 2 sensor you using
 * retval None
 */
void address_multiplexer(uint8_t device, read_write_t rw, to_be_addressed_t addr)
{
	HAL_GPIO_WritePin(MUX, RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(MUX, SET);

	if (device > 7) {
		return;
	}
	uint8_t channel = 1 << device;
	
	if (addr == FIRST_8) {
		if (rw == READ) {
			HAL_I2C_Master_Receive(&I2C_Handle, (uint16_t)(TCA9548_ADDRESS_ONE), &first_8_channel, 1, 10000);
		} else if (rw == WRITE) {
			HAL_I2C_Master_Transmit(&I2C_Handle, (uint16_t)(TCA9548_ADDRESS_ONE), &channel, 1, 10000);
		}
	} else if (addr == SECOND_2) {
		if (rw == READ) {
			HAL_I2C_Master_Receive(&I2C_Handle, (uint16_t)TCA9548_ADDRESS_OTHER, &second_2_channel, 1, 10000);
		} else if (rw == WRITE) {
			HAL_I2C_Master_Transmit(&I2C_Handle, (uint16_t)TCA9548_ADDRESS_OTHER, &channel, 1, 10000);
		}
	}

}
