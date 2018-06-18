#include "main.h"
#include "WM.h"
#include "BUTTON.h"
#include "DIALOG.h"

#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_sdram.h"
#include "stm32746g_discovery_ts.h"


uint8_t pushed = 0;

uint8_t GUI_Initialized = 0;
TIM_HandleTypeDef TimHandle;
uint32_t uwPrescalerValue = 0;

void BSP_Touch_Update(void);


#define ID_WINDOW_0    (GUI_ID_USER + 0x00)
#define ID_DROPDOWN_0    (GUI_ID_USER + 0x01)
#define ID_TEXT_0    (GUI_ID_USER + 0x02)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
  { DROPDOWN_CreateIndirect, "Dropdown", ID_DROPDOWN_0, 0, 0, 175, 74, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 250, 0, 229, 24, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

WM_HWIN mode;
WM_HWIN drop;

static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Window'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, GUI_MAKE_COLOR(0x00FF0000));
    //
    // Initialization of 'Dropdown'
    //
    drop = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
    DROPDOWN_SetFont(drop, GUI_FONT_24B_ASCII);
    DROPDOWN_AddString(drop, "Line following");
    DROPDOWN_AddString(drop, "RC");
    DROPDOWN_AddString(drop, "Settings");
    //
    // Initialization of 'Text'
    //
    mode = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(mode, "");
    TEXT_SetTextColor(mode, GUI_MAKE_COLOR(0x000000FF));
    TEXT_SetTextAlign(mode, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(mode, GUI_FONT_24B_ASCII);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_DROPDOWN_0: // Notifications sent by 'Dropdown'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
    	  switch(DROPDOWN_GetSelExp(drop)) {
    	  	case 0:
    	  		TEXT_SetText(mode, "Line follow");
    	  		break;
    	  	case 1:
    	  		TEXT_SetText(mode, "RC");
    	  		break;
    	  	case 2:
    	  		TEXT_SetText(mode, "Settings");
    	  		break;
    	  	}
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

WM_HWIN CreateWindow(void)
{
	WM_HWIN hWin;
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
void BSP_Background(void);

extern void MainTask(void);
static void CPU_CACHE_Enable(void);


int main(void)
{
	/* Enable the CPU Cache */
	//CPU_CACHE_Enable();

	HAL_Init();

	/* Configure the system clock to 200 MHz */
	SystemClock_Config();

	/* Configure LED1 */
	BSP_LED_Init(LED_GREEN);

	BSP_SDRAM_Init();
	BSP_TS_Init(480, 272);

	/* Enable CRC to Unlock GUI */
	__HAL_RCC_CRC_CLK_ENABLE();

	/* Enable Back up SRAM */
	__HAL_RCC_BKPSRAM_CLK_ENABLE();


	/***********************************************************/
	/* Compute the prescaler value to have TIM3 counter clock equal to 10 KHz */
	uwPrescalerValue = (uint32_t) ((SystemCoreClock /2) / 10000) - 1;

	/* Set TIMx instance */
	TimHandle.Instance = TIM3;
	TimHandle.Init.Period = 500 - 1;
	TimHandle.Init.Prescaler = uwPrescalerValue;
	TimHandle.Init.ClockDivision = 0;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	if (HAL_TIM_Base_Init(&TimHandle) != HAL_OK) {
		while (1) {
		}
	}


	if(HAL_TIM_Base_Start_IT(&TimHandle) != HAL_OK)
	{
		while (1) {
		}
	}

	/***********************************************************/

	/* Init the STemWin GUI Library */
	BSP_SDRAM_Init(); /* Initializes the SDRAM device */
	__HAL_RCC_CRC_CLK_ENABLE(); /* Enable the CRC Module */


	GUI_Init();
	GUI_DispStringAt("Starting...", 0, 0);
	HAL_Delay(1000);
	//GUI_Initialized = 1;


//	/* Activate the use of memory device feature */
//	WM_SetCreateFlags(WM_CF_MEMDEV);
//	CreateWindow();
//	MainTask();
//
//	/* Infinite loop */
//	for(;;);

	//WM_SetCreateFlags(WM_CF_MEMDEV);

	CreateWindow();

	while (1) {
		BSP_Touch_Update();
		GUI_Exec();
		//GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
		GUI_Delay(1);
		if (pushed % 2 == 0) {
			BSP_LED_On(LED_GREEN);
		} else if (pushed % 2 == 1) {
			BSP_LED_Off(LED_GREEN);
		}
	}
}

void BSP_Touch_Update(void)
{
	GUI_PID_STATE TS_State;
	static TS_StateTypeDef prev_state;
	TS_StateTypeDef ts;
	uint16_t xDiff, yDiff;

	BSP_TS_GetState(&ts);
	if (ts.touchDetected > 0)
		ts.touchDetected = 1;
	TS_State.Pressed = ts.touchDetected;

	xDiff = (prev_state.touchX[0] > ts.touchX[0]) ?
			(prev_state.touchX[0] - ts.touchX[0]) :
			(ts.touchX[0] - prev_state.touchX[0]);
	yDiff = (prev_state.touchY[0] > ts.touchY[0]) ?
			(prev_state.touchY[0] - ts.touchY[0]) :
			(ts.touchY[0] - prev_state.touchY[0]);

	if ((prev_state.touchDetected != ts.touchDetected)
			&& ((xDiff > 3) || (yDiff > 3))) {
		if (ts.touchDetected > 0)
			ts.touchDetected = 1;
		TS_State.Layer = 0;
		TS_State.x = ts.touchX[0];
		TS_State.y = ts.touchY[0];

		GUI_TOUCH_StoreStateEx(&TS_State);
	}
	prev_state = ts;

}

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//	BSP_Background();
//}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	/*##-1- Enable peripherals and GPIO Clocks #################################*/
	/* TIMx Peripheral clock enable */
	__HAL_RCC_TIM3_CLK_ENABLE();

	/*##-2- Configure the NVIC for TIMx ########################################*/
	/* Set the TIMx priority */
	HAL_NVIC_SetPriority(TIM3_IRQn, 0, 1);

	/* Enable the TIMx global Interrupt */
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void BSP_Background(void)
{
	BSP_LED_Toggle(LED1);
}

static void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;
	HAL_StatusTypeDef ret = HAL_OK;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 400;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 8;

	ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
	if (ret != HAL_OK) {
		while (1) {
			;
		}
	}

	/* Activate the OverDrive to reach the 200 MHz Frequency */
	ret = HAL_PWREx_EnableOverDrive();
	if (ret != HAL_OK) {
		while (1) {
			;
		}
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6);
	if (ret != HAL_OK) {
		while (1) {
			;
		}
	}
}

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
	{}
}
#endif
