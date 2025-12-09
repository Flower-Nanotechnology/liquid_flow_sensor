/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  *
  * Modified by: Thiago Oliveira
  * Date: December, 2025
  *
  ******************************************************************************
  */


// Includes
#include "main.h"
#include "cmsis_os.h"



/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

	/* =========================================
	 *    Initial configurations
	 * ========================================= */

	// MPU Configuration
	MPU_Config();

	// Reset of all peripherals, Initializes the Flash interface and the Systick.
	HAL_Init();

  	// Configure the system clock
	SystemClock_Config();

	// RTOS kernel initialize
	osKernelInitialize();


	/* =========================================
	 *    Peripherals
	 * ========================================= */

	// Create gpio init structure
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	// Set LED_PIN
	MX_GPIO_Init(
		GPIO_InitStruct,
		LED_PIN_Pin,
		LED_PIN_GPIO_Port,
		GPIO_MODE_OUTPUT_PP,
		GPIO_NOPULL,
		GPIO_SPEED_FREQ_LOW
	);


	/* =========================================
	 *    RTOS features
	 * ========================================= */

	// create tasks, lists, queues, semaphores, etc here


	/* =========================================
	 *    Scheduler start
	 * ========================================= */
	 osKernelStart();
}
