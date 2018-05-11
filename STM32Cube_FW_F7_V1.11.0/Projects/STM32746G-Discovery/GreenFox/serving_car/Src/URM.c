/*
 * URM.c
 *
 *  Created on: 2018. jan. 4.
 *      Author: Andras Pasztor
 */

#include "URM.h"
#include "main.h"
#include "port_define.h"

// TODO: Test
/* URM test screen */
#include "stm32746g_discovery_lcd.h"
#include "stdlib.h"

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef 	TimHandle_URM_Trigger;
TIM_HandleTypeDef 	TimHandle_URM_Echo;

/* Static variables ---------------------------------------------------------*/
static GPIO_InitTypeDef 	GPIO_InitHandle;
static TIM_OC_InitTypeDef 	ocConfig_URM_Trigger;
static TIM_IC_InitTypeDef 	icConfig_URM_Echo;
static URM_State_t	state = URM_STATE_INACTIVE;		// 1 if the measuring is active else 0
static uint16_t     actual_echo = URM_ECHO_NOOBJECT_VALUE;				// The actual (average) distance of an object in micro seconds.

// Buffer array for the last measured echo time period values in micro seconds (us)
static uint16_t measuredValues[URM_NUMBER_OF_THE_BUFFERED_VALUES] = {URM_ECHO_NOOBJECT_VALUE};

// The start value of the measuredValues buffer array
static uint16_t	measuredValues_end = URM_NUMBER_OF_THE_BUFFERED_VALUES - 1;

/* Static function prototypes -----------------------------------------------*/
static void URM_AddIfLower(uint16_t *lowest_values, uint16_t length, uint16_t newValue);
static uint16_t URM_EchoToDistance(uint32_t echoPeriod);
static void GPIO_URM_Trigger_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_PIN_x);
static void GPIO_URM_Echo_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_PIN_x);
static void URM_Trigger_TIM_Init();
static void URM_Echo_TIM_Init();

/**
  * brief  Initialize the Ultrasonic Ranging Module (URM)
  * param  None
  * retval None
  */
void URM_Init()
{
	// Enable clock for port used by URM, and initialize GPIO ports
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_URM_Trigger_Init(URM_TRIGGER);
	GPIO_URM_Echo_Init(URM_ECHO);

	// Configure timers for URM with interrupts enabled
	URM_Trigger_TIM_Init();
	URM_Echo_TIM_Init();

	//TODO: Test
	//URM testscreen
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, SDRAM_DEVICE_ADDR);
	BSP_LCD_LayerDefaultInit(2, SDRAM_DEVICE_ADDR);
	BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
	BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGRAY);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
}

/**
  * brief  Gets the actual testing data of URM sensor.
  * param  None
  * retval None
  */
void URM_GetTestScreenData(uint16_t *_measuredValues, unsigned int *_number_of_values, uint16_t *_measuredValues_end, uint16_t *_actual_echo)
{
	*_number_of_values = sizeof(measuredValues) / sizeof(measuredValues[0]);
	*_measuredValues_end = measuredValues_end;
	*_actual_echo = actual_echo;
	for (unsigned int i = 0; i < *_number_of_values; ++i) {
		_measuredValues[i] = measuredValues[i];
	}
}

/**
  * brief  Start the continuous measuring of URM.
  * param  None
  * retval None
  */
void URM_Start()
{
	state = URM_STATE_ACTIVE;
	URM_Measure();
}

/**
  * brief  Stop the continuous measuring of URM.
  *        The ongoing actual measuring won't be stopped it will finish normally.
  * param  None
  * retval None
  */
void URM_Stop()
{
	state = URM_STATE_INACTIVE;
}

/**
  * brief  Gets the actual object distance in cm.
  * param  None
  * retval The actual object distance in cm
  */
uint16_t URM_GetDistance()
{
	return URM_EchoToDistance(actual_echo);
}

/**
  * brief  Gets the actual state whether the continuous measuring is active or not.
  * param  None
  * retval The actual state of URM measuring
  */
URM_State_t URM_GetState()
{
	return state;
}

/**
  * brief  Adds a new value to the array of last measured echo values and sets the end position to this value.
  *        The last element will be overwritten. Also sets the actual distance.
  * param  newValue: The newly measured echo value to be added
  * retval None
  */
void URM_AddNewValue(uint16_t newValue)
{
	int sum = 0;	// summary of the lowest values of the last values
	// the n lowest values in the last URM_ECHO_LAST_VALUES_FOR_AVERAGE number of values
	uint16_t lowest_values[URM_ECHO_LOWEST_VALUES_FOR_AVERAGE];

	// reset array of lowest values
	for (unsigned int i = 0; i < URM_ECHO_LOWEST_VALUES_FOR_AVERAGE; ++i) {
		lowest_values[i] = URM_ECHO_NOOBJECT_VALUE ;
	}

	// Add the new value to the array of last values
	++measuredValues_end;
	if (measuredValues_end == sizeof(measuredValues) / sizeof(measuredValues[0]))
		measuredValues_end = 0;
	measuredValues[measuredValues_end] = newValue;

	// Build up the array of the lowest values
	int pos = 0;
	for (unsigned int i = 0; i < URM_ECHO_LAST_VALUES_FOR_AVERAGE; ++i) {
		pos = measuredValues_end - i;
		if (pos < 0)
			pos = URM_NUMBER_OF_THE_BUFFERED_VALUES + (measuredValues_end - i);
		URM_AddIfLower(lowest_values, URM_ECHO_LOWEST_VALUES_FOR_AVERAGE, measuredValues[pos]);
	}

	// Sum up the lowest values for average calculation
	for (unsigned int i = 0; i < URM_ECHO_LOWEST_VALUES_FOR_AVERAGE; ++i) {
		sum += lowest_values[i];
	}

	actual_echo = sum / URM_ECHO_LOWEST_VALUES_FOR_AVERAGE;
}

/**
  * brief  Add the new value to the array when it is smaller than a value in the array.
  * param  lowest_values: Array for collects the lowest values
  *        length:        The length of the array
  *        newValue:      The new value to be checked whether it is lower than a value in the array.
  * retval None
  */
static void URM_AddIfLower(uint16_t *lowest_values, uint16_t length, uint16_t newValue)
{
	for (unsigned int i = 0; i < length; ++i) {
		if (newValue < lowest_values[i]) {
			lowest_values[i] = newValue;
			break;
		}
	}
}

/**
  * brief  Start a new measuring sequence by enabling the Trigger TIM.
  * note   After an invalid measure (object is too far) you have to wait for
  *        at least 200ms for the next measure. If you start measure in this period,
  *        the measured value will be invalid as well, but the 200ms will not start again.
  * param  None
  * retval None
  */
void URM_Measure()
{
	URM_TRIGGER_TIM->CNT = 0;
	HAL_TIM_OC_Start_IT(&TimHandle_URM_Trigger, TIM_CHANNEL_1);
}

/**
  * brief  Calculates distance in cm from echo time in us.
  * note   sound speed: 344 m/s on +21C
  *        distance in cm = uS / ~58;
  *        or
  *        distance in cm = echo period in us * ( sound speed (344 m/s) / 2 / 10,000 ) = 0,0172
  * param  echoPeriod: The measured time between sending the sound and receiving the echo in us (micro seconds).
  * retval Distance in cm
  */
static uint16_t URM_EchoToDistance(uint32_t echoPeriod)
{
	return (int)(echoPeriod * 0.0172);
}

/**
  * brief  Initialize GPIO port for URM Trigger (output)
  * param  GPIOx:      GPIO port
  * param  GPIO_PIN_x: GPIO pin
  * retval None
  */
static void GPIO_URM_Trigger_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_PIN_x)
{
	GPIO_InitHandle.Alternate	= GPIO_AF1_TIM1;
	GPIO_InitHandle.Mode		= GPIO_MODE_AF_PP;
	GPIO_InitHandle.Pin			= GPIO_PIN_x;
	GPIO_InitHandle.Pull		= GPIO_PULLDOWN;
	GPIO_InitHandle.Speed		= GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOx, &GPIO_InitHandle);
}

/**
  * brief  Initialize GPIO port for URM Echo (input)
  * param  GPIOx:      GPIO port
  * param  GPIO_PIN_x: GPIO pin
  * retval None
  */
static void GPIO_URM_Echo_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_PIN_x)
{
	GPIO_InitHandle.Alternate	= GPIO_AF1_TIM2;
	GPIO_InitHandle.Mode		= GPIO_MODE_AF_PP;
	GPIO_InitHandle.Pin			= GPIO_PIN_x;
	GPIO_InitHandle.Pull		= GPIO_NOPULL;
	GPIO_InitHandle.Speed		= GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOx, &GPIO_InitHandle);
}

/**
  * brief  Initialize timer for URM Trigger (output) in PWM mode
  * param  none
  * retval None
  */
static void URM_Trigger_TIM_Init()
{
	__HAL_RCC_TIM1_CLK_ENABLE();
	TimHandle_URM_Trigger.Instance				= URM_TRIGGER_TIM;
	// Set the timer to step 1 period until 10 us
	TimHandle_URM_Trigger.Init.Period			= 20000 - 1;				// 200 ms
	TimHandle_URM_Trigger.Init.Prescaler		= 2160 - 1;
	TimHandle_URM_Trigger.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
	TimHandle_URM_Trigger.Init.CounterMode		= TIM_COUNTERMODE_UP;
	HAL_TIM_OC_Init(&TimHandle_URM_Trigger);

	ocConfig_URM_Trigger.OCMode	= TIM_OCMODE_ACTIVE;
	// Set Pulse value to (1 * 10us) 12us to have the URM measure distance
	ocConfig_URM_Trigger.Pulse	= 1;
	HAL_TIM_OC_ConfigChannel(&TimHandle_URM_Trigger, &ocConfig_URM_Trigger, TIM_CHANNEL_1);

	HAL_NVIC_SetPriority(URM_TRIGGER_IRQ, 0x0E, 0x00);
	HAL_NVIC_EnableIRQ(URM_TRIGGER_IRQ);

	// Set SR register to 0 to avoid IT at start
	URM_TRIGGER_TIM->SR &= ~1;
}

/**
  * brief  Initialize timer for URM Echo (input) in IC mode
  * param  none
  * retval None
  */
static void URM_Echo_TIM_Init()
{
	__HAL_RCC_TIM2_CLK_ENABLE();
	TimHandle_URM_Echo.Instance               = URM_ECHO_TIM;
	TimHandle_URM_Echo.Init.Period            = URM_ECHO_TIM_PERIOD;
	// Set the timer to have 1 Period unit == 1 us
	TimHandle_URM_Echo.Init.Prescaler         = 108 - 1;
	TimHandle_URM_Echo.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle_URM_Echo.Init.CounterMode       = TIM_COUNTERMODE_UP;
	HAL_TIM_IC_Init(&TimHandle_URM_Echo);
	HAL_TIM_Base_Init(&TimHandle_URM_Echo);

	icConfig_URM_Echo.ICFilter 				= 0;
	icConfig_URM_Echo.ICPolarity 			= TIM_ICPOLARITY_BOTHEDGE;
	icConfig_URM_Echo.ICPrescaler 			= TIM_ICPSC_DIV1;
	icConfig_URM_Echo.ICSelection			= TIM_ICSELECTION_DIRECTTI;
	HAL_TIM_IC_ConfigChannel(&TimHandle_URM_Echo, &icConfig_URM_Echo, TIM_CHANNEL_1);
	// Don't start the timer at this time. Start function will start it

	HAL_NVIC_SetPriority(URM_ECHO_IRQ, 0x0E, 0x00);
	HAL_NVIC_EnableIRQ(URM_ECHO_IRQ);

	// Set SR register to 0 to avoid IT at start
	URM_ECHO_TIM->SR &= ~1;
}

