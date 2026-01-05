/**
  ******************************************************************************
  * @file           : spi3_init.c
  * @brief          : SPI3 init function.
  * 				  SPI3 port is dedicated to LCD Display.
  * 				  This SPI port uses DMA.
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
#include "error_handler.h"


/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi3;
DMA_HandleTypeDef hdma_spi3_tx;


/**
  * @brief SPI3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI3_Init(void)
{
	// SPI3 parameter configuration
	hspi3.Instance = SPI3;
	hspi3.Init.Mode = SPI_MODE_MASTER;
	hspi3.Init.Direction = SPI_DIRECTION_2LINES_TXONLY;
	hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi3.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi3.Init.NSS = SPI_NSS_SOFT;
	hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
	hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi3.Init.CRCPolynomial = 0x0;
	hspi3.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
	hspi3.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
	hspi3.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
	hspi3.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
	hspi3.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
	hspi3.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
	hspi3.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
	hspi3.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
	hspi3.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
	hspi3.Init.IOSwap = SPI_IO_SWAP_DISABLE;

	if (HAL_SPI_Init(&hspi3) != HAL_OK)
	{
		Error_Handler();
	}
}


/**
 * @brief User-level wrapper for CubeMX-generated SPI3 init.
 */
void spi3_init_wrapper(void)
{
	return MX_SPI3_Init();
}

