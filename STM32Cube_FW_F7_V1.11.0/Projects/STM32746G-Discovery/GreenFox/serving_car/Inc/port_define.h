/*
 * port_define.h
 *
 *  Created on: 2018. jan. 4.
 *      Author: user
 */

#ifndef PORT_DEFINE_H_
#define PORT_DEFINE_H_

// CN 5
#define A0_PIN			GPIO_PIN_0
#define A0_PORT			GPIOA
#define A0				A0_PORT, A0_PIN		// ADC3_IN0
#define A1_PIN			GPIO_PIN_10
#define A1_PORT			GPIOF
#define A1				A1_PORT, A1_PIN
#define A2_PIN			GPIO_PIN_9
#define A2_PORT			GPIOF
#define A2				A2_PORT, A2_PIN
#define A3_PIN			GPIO_PIN_8
#define A3_PORT			GPIOF
#define A3				A3_PORT, A3_PIN
#define A4_PIN			GPIO_PIN_7
#define A4_PORT			GPIOF
#define A4				A4_PORT, A4_PIN

// CN4

#define D1_PIN			GPIO_PIN_6
#define D1_PORT			GPIOC
#define	D1				D1_PORT, D1_PIN		// INTERRUPT FOR RGB
#define D2_PIN			GPIO_PIN_6
#define D2_PORT			GPIOG
#define	D2				D2_PORT, D2_PIN		// INTERRUPT FOR RGB
#define D3_PIN			GPIO_PIN_4
#define D3_PORT			GPIOB
#define	D3				D3_PORT, D3_PIN		// AF2: TIM3_CH1
#define D4_PIN			GPIO_PIN_7
#define D4_PORT			GPIOG
#define	D4				D4_PORT, D4_PIN
#define D5_PIN			GPIO_PIN_0
#define D5_PORT			GPIOI
#define	D5				D5_PORT, D5_PIN
#define D6_PIN			GPIO_PIN_6
#define D6_PORT			GPIOH
#define	D6				D6_PORT, D6_PIN		// AF9: TIM12_CH1
#define D7_PIN			GPIO_PIN_3
#define D7_PORT			GPIOI
#define	D7				D7_PORT, D7_PIN

// CN7
#define D9_PIN			GPIO_PIN_15
#define D9_PORT			GPIOA
#define	D9				D9_PORT, D9_PIN
#define D10_PIN			GPIO_PIN_8
#define D10_PORT		GPIOA
#define	D10				D10_PORT, D10_PIN	// AF1: TIM1_CH1
#define D11_PIN			GPIO_PIN_15
#define D11_PORT		GPIOB
#define D11				D11_PORT, D11_PIN
#define D12_PIN			GPIO_PIN_14
#define D12_PORT		GPIOB
#define D12				D12_PORT, D12_PIN
#define D14_PIN			GPIO_PIN_9			// AF1: TIM2_CH1
#define D14_PORT		GPIOB
#define D14				D14_PORT, D14_PIN
#define D15_PIN			GPIO_PIN_8
#define D15_PORT		GPIOB
#define D15				D15_PORT, D15_PIN

/* Ultraconic Ranging Module (URM) */
#define URM_TRIGGER		D10
#define URM_TRIGGER_TIM TIM1				// in case of changing, IRQn and timer prescaler should be updated
#define URM_TRIGGER_IRQ	TIM1_CC_IRQn

#define URM_ECHO		D9
#define URM_ECHO_TIM	TIM2				// in case of changing, IRQn and timer prescaler should be updated
#define URM_ECHO_IRQ	TIM2_IRQn

/* I2C - RGB sensors */
#define I2C_SCL			D15
#define I2C_SDA			D14
#define SENSOR_LIGHTS	D11
#define MUX				D12					// MUX RESET PIN

/* Motor control */
#define MOTOR_PWM		D3
#define MOTOR_DIR1		D4
#define MOTOR_DIR2		D5

/* Steering servo control */
#define SERVO_PWM		D6

/* ADC input for battery voltage */
#define ADC_IN			A0

#endif /* PORT_DEFINE_H_ */
