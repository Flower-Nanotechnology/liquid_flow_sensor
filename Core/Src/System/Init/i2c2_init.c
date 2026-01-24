/**
  ******************************************************************************
  * @file           : i2c2_init.c
  * @brief          : I2C2 init function
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
  *        Date: January, 2026
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "error_handler.h"


/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c2;



/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{
	hi2c2.Instance = I2C2;
	hi2c2.Init.Timing = 0x00B03FDB;
	hi2c2.Init.OwnAddress1 = 0;
	hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c2.Init.OwnAddress2 = 0;
	hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

	if (HAL_I2C_Init(&hi2c2) != HAL_OK)
	{
		Error_Handler();
	}

	// Configure Analogue filter
	if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		Error_Handler();
	}

	// Configure Digital filter
	if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
	{
		Error_Handler();
	}
}


/**
 * @brief User-level wrapper for CubeMX-generated GPIO init.
 */
void i2c2_init_wrapper(void)
{
	return MX_I2C2_Init();
}

