#ifndef MULTIPLEXER_H_
#define MULTIPLEXER_H_

#include "main.h"
#include "port_define.h"

#define TCA9548_ADDRESS_ONE		0x70 << 1
#define TCA9548_ADDRESS_OTHER	0x71 << 1

extern I2C_HandleTypeDef I2C_Handle;
extern GPIO_InitTypeDef GPIO_Handle;

typedef enum {
	READ = 0,
	WRITE = 1
} read_write_t;

typedef enum {
	FIRST_8 = 0,
	SECOND_2 = 1
} to_be_addressed_t;

void I2C_init();
void address_multiplexer(uint8_t device, read_write_t rw, to_be_addressed_t addr);

#endif /* MULTIPLEXER_H_ */
