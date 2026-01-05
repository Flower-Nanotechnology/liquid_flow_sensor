/**
  ******************************************************************************
  * @file           : dma_init.c
  * @brief          : DMA init function
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
#include "stm32h7xx_hal.h"


/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  // DMA controller clock enable
  __HAL_RCC_DMA1_CLK_ENABLE();

  // DMA interrupt init
  // DMA1_Stream0_IRQn interrupt configuration
  HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);

}


/**
 * @brief User-level wrapper for CubeMX-generated DMA init.
 */
void dma_init_wrapper(void)
{
	return MX_DMA_Init();
}

