/**
  ******************************************************************************
  * @file           : gpio_init.c
  * @brief          : GPIO init function
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
  *        Date: December, 2025
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	// GPIO Ports Clock Enable
	__HAL_RCC_GPIOC_CLK_ENABLE(); // C
	__HAL_RCC_GPIOD_CLK_ENABLE(); // D
	__HAL_RCC_GPIOE_CLK_ENABLE(); // E
	__HAL_RCC_GPIOG_CLK_ENABLE(); // G

	// ---------------------------------------
	//     LCD DISPLAY
	// ---------------------------------------

	// Configure GPIO pin Output Level
	HAL_GPIO_WritePin(GPIOD, LCD_DCX_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, LCD_RESET_Pin, GPIO_PIN_SET);

	// Configure GPIO pin Output Level
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);

	// Configure GPIO pin : LCD_DCX_Pin
	GPIO_InitStruct = (GPIO_InitTypeDef){
		.Pin = LCD_DCX_Pin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_NOPULL,
		.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
	};
	HAL_GPIO_Init(LCD_DCX_GPIO_Port, &GPIO_InitStruct);

	// Configure GPIO pin : LCD_RESET_Pin
	GPIO_InitStruct = (GPIO_InitTypeDef){
		.Pin = LCD_RESET_Pin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FREQ_LOW,
	};
	HAL_GPIO_Init(LCD_RESET_GPIO_Port, &GPIO_InitStruct);

	// Configure GPIO pin : LCD_CS_Pin
	GPIO_InitStruct = (GPIO_InitTypeDef){
		.Pin = LCD_CS_Pin,
		.Mode = GPIO_MODE_OUTPUT_PP,
		.Pull = GPIO_PULLUP,
		.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
	};
	HAL_GPIO_Init(LCD_CS_GPIO_Port, &GPIO_InitStruct);
}


/**
 * @brief User-level wrapper for CubeMX-generated GPIO init.
 */
void gpio_init_wrapper(void)
{
	return MX_GPIO_Init();
}

