/**
  ******************************************************************************
  * @file    stm32f7xx_hal_msp.c
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016 
  * @brief   HAL MSP module.
  *          This file template is located in the HAL folder and should be copied 
  *          to the user folder.
  *         
  @verbatim
 ===============================================================================
                     ##### How to use this driver #####
 ===============================================================================
    [..]


  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include "stm32f7xx_hal_gpio.h"

/** @addtogroup STM32F7xx_HAL_Driver
  * @{
  */

/** @defgroup HAL_MSP
  * @brief HAL MSP module.
  * @{
  */

extern TIM_HandleTypeDef Timer_IT;
extern TIM_HandleTypeDef Timer_PWM;
extern TIM_IC_InitTypeDef IC_conf;
extern TIM_OC_InitTypeDef sConfig;
extern GPIO_InitTypeDef gpio_init_structure;
extern UART_HandleTypeDef uart_handle;
extern GPIO_InitTypeDef gpio_IC_init;
extern GPIO_InitTypeDef gpioA0;
extern ADC_HandleTypeDef adc_handle;
extern ADC_ChannelConfTypeDef adc_channel;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief  Initializes the Global MSP.
  * @param  None
  * @retval None
  */
void HAL_MspInit(void)
{

}

/**
  * @brief  DeInitializes the Global MSP.
  * @param  None  
  * @retval None
  */
void HAL_MspDeInit(void)
{
  /* NOTE : This function is generated automatically by STM32CubeMX and eventually  
            modified by the user
   */
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	//TODO
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim)
{
	//TODO
}

void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
	//TODO
}

void clock_enable_init(void)
{
	__HAL_RCC_TIM3_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_ADC3_CLK_ENABLE();
}

void timer_pwm_init(void)
{
	Timer_PWM.Instance = TIM3;
	Timer_PWM.Init.Period = 100;
	Timer_PWM.Init.Prescaler = 1;
	Timer_PWM.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Timer_PWM.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&Timer_PWM);
	HAL_TIM_Base_Start(&Timer_PWM);

	HAL_TIM_PWM_Init(&Timer_PWM);

	sConfig.Pulse = 50;
	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&Timer_PWM, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&Timer_PWM, TIM_CHANNEL_1);
}

void gpio_pwm_init(void)
{
	gpio_init_structure.Alternate = GPIO_AF2_TIM3;
	gpio_init_structure.Mode = GPIO_MODE_AF_PP;
	gpio_init_structure.Pin = GPIO_PIN_4;
	gpio_init_structure.Pull = GPIO_NOPULL;
	gpio_init_structure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOB, &gpio_init_structure);

}

void gpio_adc_init(void)
{
	gpioA0.Mode = GPIO_MODE_ANALOG;
	gpioA0.Speed = GPIO_SPEED_FAST;
	gpioA0.Pin = GPIO_PIN_0;
	HAL_GPIO_Init(GPIOA, &gpioA0);
}

void adc_handler(void)
{
	adc_handle.Instance          		 = ADC3;
	adc_handle.Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV4;
	adc_handle.Init.Resolution            = ADC_RESOLUTION_12B;
	adc_handle.Init.ScanConvMode          = DISABLE;                       // Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1)
	adc_handle.Init.ContinuousConvMode    = DISABLE;                       // Continuous mode enabled to have continuous conversion
	adc_handle.Init.DiscontinuousConvMode = DISABLE;                       // Parameter discarded because sequencer is disabled
	adc_handle.Init.NbrOfDiscConversion   = 0;
	adc_handle.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE; // Conversion start trigged at each external event
	adc_handle.Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T1_CC1;
	adc_handle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
	adc_handle.Init.NbrOfConversion       = 1;
	adc_handle.Init.DMAContinuousRequests = DISABLE;
	adc_handle.Init.EOCSelection          = DISABLE;

	HAL_ADC_Init(&adc_handle);

	adc_channel.Channel      = ADC_CHANNEL_0;
	adc_channel.Rank         = 1;
	adc_channel.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	adc_channel.Offset       = 0;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_channel);
}

void uart_init(void)
{
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

void TIM2_init(void)
{
	Timer_IT.Instance = TIM2;
	Timer_IT.Init.Period = 65535;
	Timer_IT.Init.Prescaler = 54;
	Timer_IT.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	Timer_IT.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&Timer_IT);
	HAL_TIM_Base_Start_IT(&Timer_IT);
}

void IC_config(void)
{
	IC_conf.ICSelection = TIM_ICSELECTION_DIRECTTI;
	IC_conf.ICPolarity = TIM_ICPOLARITY_RISING;
	IC_conf.ICPrescaler = TIM_ICPSC_DIV1;
	IC_conf.ICFilter = 0;
	HAL_TIM_IC_ConfigChannel(&Timer_IT, &IC_conf, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&Timer_IT, TIM_CHANNEL_1);
}

void gpioA15_init(void)
{
	gpio_IC_init.Pin = GPIO_PIN_15;
	gpio_IC_init.Speed = GPIO_SPEED_FAST;
	gpio_IC_init.Mode = GPIO_MODE_AF_OD;
	gpio_IC_init.Pull = GPIO_PULLUP;
	gpio_IC_init.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &gpio_IC_init);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
