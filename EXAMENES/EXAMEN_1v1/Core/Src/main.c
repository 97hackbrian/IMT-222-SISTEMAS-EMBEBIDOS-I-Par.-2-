/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "liquidcrystal_i2c.h"
#include <string.h>
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
char read_keypad (void)
	{
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_3,0);  //Pull the R1 low
		HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, 1);  // Pull the R2 High
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_11, 1);  // Pull the R3 High
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, 1);  // Pull the R4 High

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_4)))   // if the Col 1 is low
		{
	return '1';
		}
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)))   // if the Col 1 is low
		{
	return '2';
		}

	if (!(HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_0)))   // if the Col 1 is low
		{
	return '3';
		}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12)))   // if the Col 1 is low
		{
	return 'A';
		}


		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_3,1);  //Pull the R1 high
		HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, 0);  // Pull the R2 LOW
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_11, 1);  // Pull the R3 High
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, 1);  // Pull the R4 High

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_4)))   // if the Col 1 is low
		{
	return '4';
		}
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)))   // if the Col 1 is low
		{
	return '5';
		}

	if (!(HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_0)))   // if the Col 1 is low
		{
	return '6';
		}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12)))   // if the Col 1 is low
		{
	return 'B';
		}


		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_3,1);  //Pull the R1 HIGH
		HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, 1);  // Pull the R2 High
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_11, 0);  // Pull the R3 LOW
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, 1);  // Pull the R4 High

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_4)))   // if the Col 1 is low
		{
	return '7';
		}
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)))   // if the Col 1 is low
		{
	return '8';
		}

	if (!(HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_0)))   // if the Col 1 is low
		{
	return '9';
		}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12)))   // if the Col 1 is low
		{
	return 'C';
		}


		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_3,1);  //Pull the R1 HIGH
		HAL_GPIO_WritePin (GPIOB, GPIO_PIN_1, 1);  // Pull the R2 High
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_11, 1);  // Pull the R3 High
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, 0);  // Pull the R4 LOW

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_4)))   // if the Col 1 is low
		{
	return '*';
		}
	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)))   // if the Col 1 is low
		{
	return '0';
		}

	if (!(HAL_GPIO_ReadPin (GPIOB, GPIO_PIN_0)))   // if the Col 1 is low
		{
	return '#';
		}

	if (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12)))   // if the Col 1 is low
		{
	return 'D';
		}
	}
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim16;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM16_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM16_Init();
  /* USER CODE BEGIN 2 */
  HD44780_Init(2);
  HD44780_Clear();
  HD44780_SetCursor(0,0);
  HD44780_PrintStr("INICIANDO...");
  HAL_Delay(5000);
  HD44780_SetCursor(10,1);
  HD44780_PrintStr("MAQUINA DISPENSADORA");
  HAL_Delay(2000);
  HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);

  HD44780_Clear();
  HD44780_SetCursor(0,0);
  HD44780_PrintStr("Ingrese las monedas");
  HAL_Delay(1000);
  int aux=0;
  float monedasT=0;
  while(aux==0){
	  if(read_keypad()=='A'){
		  HD44780_SetCursor(10,1);
		  HD44780_PrintStr("0.5Bs");
		  monedasT=monedasT+0.5;
		  HAL_Delay(500);
	  }
	  if(read_keypad ()=='B'){
		  HD44780_SetCursor(10,1);
		  HD44780_PrintStr("1Bs");
		  monedasT=monedasT+1;
		  HAL_Delay(500);
	  }
	  if(read_keypad ()=='C'){
		  HD44780_SetCursor(10,1);
		  HD44780_PrintStr("2Bs");
		  monedasT=monedasT+2;
		  HAL_Delay(500);
	  }
	  if(read_keypad ()=='D'){
		  HD44780_SetCursor(10,1);
		  HD44780_PrintStr("5Bs");
		  monedasT=monedasT+5;
		  HAL_Delay(500);
	  }
	  if(read_keypad ()=='*'){
		  HD44780_Clear();
		  HD44780_SetCursor(0,0);
		  char buf[100];
		  gcvt(monedasT, 6, buf);
		  HD44780_PrintStr(buf);
		  HAL_Delay(6000);

		  HD44780_Clear();
		  HD44780_SetCursor(0,0);
		  HD44780_PrintStr("seleccione el producto");
		  HAL_Delay(500);
		  aux=1;
	  }
  }
  int aux2=0;
  while(aux2==0){
	  if(read_keypad ()=='1'){
	  		  HD44780_SetCursor(10,1);
	  		  HD44780_PrintStr("Producto 1");
	  		  HAL_Delay(500);
	  }
	  if(read_keypad ()=='2'){
	  		  HD44780_SetCursor(10,1);
	  		  HD44780_PrintStr("Producto 2");
	  		  HAL_Delay(500);
	  }
	  if(read_keypad ()=='3'){
		  	  HD44780_SetCursor(10,1);
		  	  HD44780_PrintStr("Producto 3");
		  	  HAL_Delay(500);
	  }
	  if(read_keypad ()=='4'){
	  	  	  HD44780_SetCursor(10,1);
	  	  	  HD44780_PrintStr("Producto 4");
	  	  	  HAL_Delay(500);
	  }
	  if(read_keypad ()=='5'){
		  	  HD44780_SetCursor(10,1);
	  		  HD44780_PrintStr("Producto 5");
	  		  HAL_Delay(500);
	  }
	  if(read_keypad ()=='6'){
	  		  HD44780_SetCursor(10,1);
	  		  HD44780_PrintStr("Producto 6");
	  		  HAL_Delay(500);
	  }
	  if(read_keypad ()=='*'){
		  	  HD44780_Clear();
		  	  HD44780_SetCursor(0,0);
		  	  HD44780_PrintStr("dropeando el producto....");
		  	  HAL_Delay(500);
		  	  aux2=1;
	  }
  }
  int x;
  for(x=50;x<600;x++){
  		  __HAL_TIM_SET_COMPARE(&htim16,TIM_CHANNEL_1,x);
  		  HAL_Delay(2);
  }
  HD44780_Clear();
  HD44780_SetCursor(0,0);
  HD44780_PrintStr("RECOJA SU PRODUCTO");
  HAL_Delay(8000);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  int x;
	  for(x=50;x<600;x++){
		  __HAL_TIM_SET_COMPARE(&htim16,TIM_CHANNEL_1,x);
		  HAL_Delay(1);
	  }

	  for(x=600;x>50;x=x-1){
		  __HAL_TIM_SET_COMPARE(&htim16,TIM_CHANNEL_1,x);
		  HAL_Delay(1);
	  }

	  HD44780_Init(2);
	  HD44780_Clear();
	  HD44780_SetCursor(0,0);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 16;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00000E14;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 19;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 1000;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 500;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim16, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim16, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */
  HAL_TIM_MspPostInit(&htim16);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_8|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA3 PA8 PA11 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_8|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */



	char enteroACaracter(int numero){
	    return numero + '0';
	}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
