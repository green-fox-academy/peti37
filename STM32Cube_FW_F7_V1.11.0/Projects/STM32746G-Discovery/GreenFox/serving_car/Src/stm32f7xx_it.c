/**
  ******************************************************************************
  * @file    Templates/stm32f7xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016 
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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
#include "main.h"
#include "stm32f7xx_it.h"
#include "port_define.h"
#include "mot_control.h"
#include "URM.h"

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup Templates
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* variables for URM */
extern  TIM_HandleTypeDef TimHandle_URM_Trigger;
extern  TIM_HandleTypeDef TimHandle_URM_Echo;
uint8_t urm_echo_active_measuring = 0;				// 1 if the echo time measuring is in progress, else 0

/* variable for MC */
 extern TIM_HandleTypeDef TimHandle_MC;
 extern State_struct_t st;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M7 Processor Exceptions Handlers                         */
/******************************************************************************/

/*
 *  TIM1 interrupt for URM Trigger
 */
void TIM1_CC_IRQHandler()
{
	HAL_TIM_IRQHandler(&TimHandle_URM_Trigger);
}

/*
 *  TIM2 interrupt for URM Echo
 */
void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TimHandle_URM_Echo);
}

/*
 *  TIM6 interrupt for MC
 */
void TIM6_DAC_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TimHandle_MC);
}

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
	/* URM - If the trigger is ended in OC mode -> the echo measurement will be started */
	if (htim->Instance == URM_TRIGGER_TIM) {
		HAL_TIM_OC_Stop_IT(&TimHandle_URM_Trigger, TIM_CHANNEL_1);
		HAL_TIM_IC_Start_IT(&TimHandle_URM_Echo, TIM_CHANNEL_1);
		HAL_TIM_Base_Start_IT(&TimHandle_URM_Echo);
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/* URM - If no echo was measured until the timer period elapsed -> no object in focus */
	if (htim->Instance == URM_ECHO_TIM) {
		urm_echo_active_measuring = 0;
		HAL_TIM_IC_Stop_IT(&TimHandle_URM_Echo, TIM_CHANNEL_1);
		HAL_TIM_Base_Stop_IT(&TimHandle_URM_Echo);
		URM_AddNewValue(URM_ECHO_NOOBJECT_VALUE);
		if (URM_GetState() == URM_STATE_ACTIVE) {
			URM_Measure();
		}
	/* MC - if interrupt is thrown CCR1 of TIM3 must be overwritten (by MC_set_pulse()) and TIM6 shut down */
	} else if (htim->Instance == TIM6) {
		//MC_control(0, st.);
		printf("periode elapsed - speed support finished\n");
		st.state = NORMAL;
		MC_set_pulse(st.req_speed);
		switch (st.command) {
			case FORWARD:
				printf("forward: speed: %d\n", st.req_speed);
			break;
			case BACKWARD:
				printf("backward: speed: %d\n", st.req_speed);
			break;
			case BREAK:
				printf("break\n");
			break;
			default:
			break;
		}
		HAL_TIM_Base_Stop_IT(&TimHandle_MC);
	}
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	/* URM - If echo start or end has occured */
	if (htim->Instance == URM_ECHO_TIM) {
		if (!urm_echo_active_measuring) {
			urm_echo_active_measuring = 1;
			htim->Instance->CNT = 0;
		} else {
			urm_echo_active_measuring = 0;
			URM_AddNewValue(URM_ECHO_TIM->CCR1);
			HAL_TIM_IC_Stop_IT(&TimHandle_URM_Echo, TIM_CHANNEL_1);
			HAL_TIM_Base_Stop_IT(&TimHandle_URM_Echo);
			if (URM_GetState() == URM_STATE_ACTIVE) {
				URM_Measure();
			}
		}
	}
}


/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}
  

/******************************************************************************/
/*                 STM32F7xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f7xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/


/**
  * @}
  */ 

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
