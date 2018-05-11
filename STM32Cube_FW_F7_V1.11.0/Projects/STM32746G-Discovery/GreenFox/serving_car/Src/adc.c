/*
 * adc.c
 *
 *  Created on: 2018. jan. 15.
 *      Author: Andras Pasztor
 */

#include "adc.h"
#include "port_define.h"
#include "main.h"

#define ADC_NORMAL_VOLTAGE		8.2	// The voltage of the fully recharged battery
#define ADC_VOLTAGE_DIVIDER		4   // The value of the voltage divider (1/x)
#define ADC_MAX_PWM_MULTIPLIER	1.5 // The maximum value of the PWM multiplier

/* Private variables ---------------------------------------------------------*/
/* Static variables ----------------------------------------------------------*/
static ADC_HandleTypeDef    AdcHandle;

/* Static function prototypes ------------------------------------------------*/
static uint16_t ADC_Measure();
static void GPIO_ADC_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_PIN_x);

/* Private functions ---------------------------------------------------------*/

/**
  * brief  Initialize ADC port for measuring battery voltage.
  * param  None
  * retval None
  */
void ADC_Init()
{
	ADC_ChannelConfTypeDef sConfig;

	// Enable clock for ADC3
	__HAL_RCC_ADC3_CLK_ENABLE();

	// Initialize GPIO port for ADC
	GPIO_ADC_Init(ADC_IN);

	AdcHandle.Instance          		 = ADC3;
	AdcHandle.Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV4;
	AdcHandle.Init.Resolution            = ADC_RESOLUTION_12B;
	AdcHandle.Init.ScanConvMode          = DISABLE;                       // Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1)
	AdcHandle.Init.ContinuousConvMode    = DISABLE;                       // Continuous mode enabled to have continuous conversion
	AdcHandle.Init.DiscontinuousConvMode = DISABLE;                       // Parameter discarded because sequencer is disabled
	AdcHandle.Init.NbrOfDiscConversion   = 0;
	AdcHandle.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE; // Conversion start trigged at each external event
	AdcHandle.Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T1_CC1;
	AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
	AdcHandle.Init.NbrOfConversion       = 1;
	AdcHandle.Init.DMAContinuousRequests = DISABLE;
	AdcHandle.Init.EOCSelection          = DISABLE;
	HAL_ADC_Init(&AdcHandle);

	sConfig.Channel      = ADC_CHANNEL_0;
	sConfig.Rank         = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	sConfig.Offset       = 0;
	HAL_ADC_ConfigChannel(&AdcHandle, &sConfig);
}

/**
  * brief  Calculates a multiplier for PWM duty cycle to grant average voltage
  *        as a fully charged battery.
  * param  None
  * retval PWM multiplier value bigger than 1
  */
double ADC_GetPwmMultiplier()
{
	double m = ADC_NORMAL_VOLTAGE / ADC_GetBatteryVoltage();
	if (m < 1) {
		m = 1;
	} else if (m > ADC_MAX_PWM_MULTIPLIER) {
		m = ADC_MAX_PWM_MULTIPLIER;
	}
//	printf("Battery multiplier: %d.%d\n", (int)m, ((int)(m * 100)) % 100);
	return m;
}

/**
  * brief  Measure the actual voltage of the battery
  * param  None
  * retval Actual battery voltage
  */
double ADC_GetBatteryVoltage()
{
	return (3.3 / 4095) * (double)ADC_Measure() * ADC_VOLTAGE_DIVIDER;
}

/**
  * brief  Measure the ADC value of battery voltage.
  * param  None
  * retval The value of one measure. Maximum is 4095 (3.3V).
  *        If there is an error it returns the normal value (will be no effect to PWM)
  */
static uint16_t ADC_Measure()
{
	HAL_ADC_Start(&AdcHandle);
	if (HAL_ADC_PollForConversion(&AdcHandle, 10) == HAL_OK)
	  {
	    // ADC conversion completed
	    return HAL_ADC_GetValue(&AdcHandle);
	  }

	return (uint16_t)(ADC_NORMAL_VOLTAGE / ADC_VOLTAGE_DIVIDER) * 4095 / 3.3;
}

/**
  * brief  Initialize GPIO port for ADC (input)
  * param  GPIOx:      GPIO port
  * param  GPIO_PIN_x: GPIO pin
  * retval None
  */
static void GPIO_ADC_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_PIN_x)
{
	GPIO_InitTypeDef GPIO_InitHandle;

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitHandle.Mode		= GPIO_MODE_ANALOG;
	GPIO_InitHandle.Pin			= GPIO_PIN_x;
	GPIO_InitHandle.Pull		= GPIO_NOPULL;
	GPIO_InitHandle.Speed		= GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitHandle);
}
