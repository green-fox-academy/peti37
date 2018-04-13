/**
 ******************************************************************************
 * @file    Templates/Src/main.c
 * @author  MCD Application Team
 * @version V1.0.3
 * @date    22-April-2016
 * @brief   STM32F7xx HAL API Template project
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
#include <string.h>
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"
#include "fonts.h"

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
/* RNG handler declaration */
RNG_HandleTypeDef RngHandle;
UART_HandleTypeDef uart_handle;
TS_StateTypeDef ts_state;

/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
#define  CIRCLE_RADIUS        30



static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);
static void Print_play_game(void);
static int Average_time(int*, int);
static void Touchscreen_DrawBackground (void);
static void overdraw_white_circle(int, int);
static int new_random(int, int);
static int start_button(int x, int y);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
	/* This project template calls firstly two functions in order to configure MPU feature
	 and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
	 These functions are provided as template implementation that User may integrate
	 in his application, to enhance the performance in case of use of AXI interface
	 with several masters. */

	/* Configure the MPU attributes as Write Through */
	MPU_Config();

	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	/* STM32F7xx HAL library initialization:
	 - Configure the Flash ART accelerator on ITCM interface
	 - Configure the Systick to generate an interrupt each 1 msec
	 - Set NVIC Group Priority to 4
	 - Low Level Initialization
	 */
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();
	RngHandle.Instance = RNG;
	uint32_t random_time;

	/* Add your application code here
	 */
	BSP_LED_Init(LED_GREEN);
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	/* Output a message using printf function */
	printf("\n------------------WELCOME------------------\r\n");
	printf("**********in MACROTIS reaction game**********\r\n\n");

	if (HAL_RNG_Init(&RngHandle) != HAL_OK) {
		/* Initialization Error */
		Error_Handler();
	}
	BSP_LCD_Init();
	// Initialize the LCD Layers
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetFont(&Font8);

	int rng_circle_posX = (HAL_RNG_GetRandomNumber(&RngHandle) % 5 + 1) * BSP_LCD_GetXSize() / 5 - 30;
	int rng_circle_posY = BSP_LCD_GetYSize() - 50 - CIRCLE_RADIUS;

	printf("xpos : %d\n", rng_circle_posX);
	printf("ypos : %d\n", rng_circle_posY);
	BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 30);

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(12, 9, (uint8_t *) "Hello", LEFT_MODE);

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(200, 9, (uint8_t *) "Start", LEFT_MODE);

	//BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	//BSP_LCD_FillCircle(rng_circle_posX, rng_circle_posY, CIRCLE_RADIUS);

	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());


	uint8_t  text[30];
	uint32_t start, end, status;
	uint32_t reaction_time = 0;
	int reaction_array[5];
	int counter = 0;
	int x, y;
	int game_on = 0;
	int sx = 200;
	int sy = 10;
	random_time = HAL_RNG_GetRandomNumber(&RngHandle) % 1000 + 200;
	printf("%d\n", random_time);

	while (1) {
		BSP_TS_GetState(&ts_state);
//		start = HAL_GetTick();
//		end = start + random_time;
		if (game_on == 0){
			if (ts_state.touchDetected){
				x = ts_state.touchX[0];
				y = ts_state.touchY[0];
				if (x < sx + 100 &&
					x > sx - 100 &&
					y < sy + CIRCLE_RADIUS &&
					y > sy - CIRCLE_RADIUS) {
					BSP_LCD_SetTextColor(LCD_COLOR_RED);
					BSP_LCD_SetFont(&Font12);
					BSP_LCD_DisplayStringAt(280, 9, (uint8_t *) "Starting...", LEFT_MODE);
					HAL_Delay(2000);
					BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
					BSP_LCD_SetFont(&Font12);
					BSP_LCD_DisplayStringAt(280, 9, (uint8_t *) "Starting...", LEFT_MODE);
					game_on = 1;
				}
			}
		}
		if (game_on == 1){
			BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
			BSP_LCD_FillCircle(rng_circle_posX, rng_circle_posY, CIRCLE_RADIUS);

			if (ts_state.touchDetected) {
				x = ts_state.touchX[0];
				y = ts_state.touchY[0];
				BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
				sprintf((char*)text, "[%d,%d]    ", x, y);
				BSP_LCD_DisplayStringAt(0, 9, (uint8_t *)&text, RIGHT_MODE);
				start = HAL_GetTick();
				end = start + random_time;
				game_on = 1;
		}

		if (x < rng_circle_posX + CIRCLE_RADIUS &&
			x > rng_circle_posX - CIRCLE_RADIUS &&
			y < rng_circle_posY + CIRCLE_RADIUS &&
			y > rng_circle_posY - CIRCLE_RADIUS && game_on == 1) {
			overdraw_white_circle(rng_circle_posX, rng_circle_posY);
			status = HAL_GetTick();
			sprintf((char*)text, "%dms", end - status);
			BSP_LCD_DisplayStringAt(0, 250, (uint8_t *)&text, RIGHT_MODE);

			HAL_Delay(random_time);


			rng_circle_posX = (HAL_RNG_GetRandomNumber(&RngHandle) % 5 + 1) * BSP_LCD_GetXSize() / 5;
			rng_circle_posY = (HAL_RNG_GetRandomNumber(&RngHandle) % 5 + 1) * BSP_LCD_GetYSize() / 5;
			while(new_random(rng_circle_posX, rng_circle_posY)){
				rng_circle_posX = (HAL_RNG_GetRandomNumber(&RngHandle) % 5 + 1) * BSP_LCD_GetXSize() / 5;
				rng_circle_posY = (HAL_RNG_GetRandomNumber(&RngHandle) % 5 + 1) * BSP_LCD_GetYSize() / 5;
			}
			//BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
			//BSP_LCD_FillCircle(rng_circle_posX, rng_circle_posY, CIRCLE_RADIUS);
			game_on = 1;
		}
	}
//		if (ts_state.touchDetected && game_on == 1){
//				game_on = 0;
//			}
	}
}

static int new_random(int x, int y)
{
	if(x <= 450 && x >= 30 && y <= 252 && y >= 60)
		return 0;
	else
		return 1;
}

static int start_button(int x, int y){
	if (x < 200 + CIRCLE_RADIUS &&
		x > 200 - CIRCLE_RADIUS &&
		y < 10 + CIRCLE_RADIUS &&
		y > 10 - CIRCLE_RADIUS) {
		return 0;
	}
	else
		return 1;
}

static void overdraw_white_circle(int x, int y)
{
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillCircle(x, y, CIRCLE_RADIUS);
}



static void Touchscreen_DrawBackground (void)
{
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 50);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
	BSP_LCD_DisplayStringAt(12, 9, (uint8_t *) " Hello embedded!", LEFT_MODE);
}
/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
	/* Place your implementation of fputc here */
	/* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
	HAL_UART_Transmit(&uart_handle, (uint8_t *) &ch, 1, 0xFFFF);

	return ch;
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 216000000
 *            HCLK(Hz)                       = 216000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 432
 *            PLL_P                          = 2
 *            PLL_Q                          = 9
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 7
 * @param  None
 * @retval None
 */

static int Average_time(int *times, int counter)
{
	int sum = 0;
	int average;
	for (int i = 0; i < counter; i++) {
		sum += times[i];
	}
	average = sum / counter;
	return average;
}


static void Print_play_game(void) {
	printf("Let's play a game! Are you ready?\n");
}

static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 432;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
	MPU_Region_InitTypeDef MPU_InitStruct;

	/* Disable the MPU */
	HAL_MPU_Disable();

	/* Configure the MPU attributes as WT for SRAM */
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress = 0x20010000;
	MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
	MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable = 0x00;
	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);

	/* Enable the MPU */
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
