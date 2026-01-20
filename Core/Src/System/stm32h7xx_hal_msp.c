/**
  ******************************************************************************
  * @file         stm32h7xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
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
#include "error_handler.h"


/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_spi3_tx;


/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
	__HAL_RCC_SYSCFG_CLK_ENABLE();

	/* System interrupt init*/
	/* PendSV_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(PendSV_IRQn, 15, 0);
}


/**
  * @brief SPI MSP Initialization
  * This function configures the hardware resources
  * @param hspi: SPI handle pointer
  * @retval None
  */
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

	if(hspi->Instance==SPI3)
	{
		// Initializes the peripherals clock
		PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPI3;
		PeriphClkInitStruct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL;

		if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
		{
			Error_Handler();
		}

		// Peripheral clock enable
		__HAL_RCC_SPI3_CLK_ENABLE();
		__HAL_RCC_GPIOC_CLK_ENABLE();


		// SPI3 GPIO Configuration
		//     PC10 ------> SPI3_SCK
		GPIO_InitStruct = (GPIO_InitTypeDef) {
			.Pin = LCD_SCK_Pin,
			.Mode = GPIO_MODE_AF_PP,
			.Pull = GPIO_PULLDOWN,
			.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
			.Alternate = GPIO_AF6_SPI3
		};
		HAL_GPIO_Init(LCD_SCK_Port, &GPIO_InitStruct);

		// SPI3 GPIO Configuration
		//     PC12 ------> SPI3_MOSI
		GPIO_InitStruct = (GPIO_InitTypeDef) {
			.Pin = LCD_SDI_Pin,
			.Mode = GPIO_MODE_AF_PP,
			.Pull = GPIO_PULLUP,
			.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
			.Alternate = GPIO_AF6_SPI3
		};
		HAL_GPIO_Init(LCD_SDI_Port, &GPIO_InitStruct);


		// SPI3 DMA Init: SPI3_TX Init
		hdma_spi3_tx.Instance = DMA1_Stream0;
		hdma_spi3_tx.Init.Request = DMA_REQUEST_SPI3_TX;
		hdma_spi3_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
		hdma_spi3_tx.Init.PeriphInc = DMA_PINC_DISABLE;
		hdma_spi3_tx.Init.MemInc = DMA_MINC_ENABLE;
		hdma_spi3_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
		hdma_spi3_tx.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
		hdma_spi3_tx.Init.Mode = DMA_NORMAL;
		hdma_spi3_tx.Init.Priority = DMA_PRIORITY_MEDIUM;
		hdma_spi3_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;

		if (HAL_DMA_Init(&hdma_spi3_tx) != HAL_OK)
		{
			Error_Handler();
		}

		__HAL_LINKDMA(hspi,hdmatx,hdma_spi3_tx);

		// SPI3 interrupt Init
		HAL_NVIC_SetPriority(SPI3_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(SPI3_IRQn);
	}
}

/**
  * @brief SPI MSP De-Initialization
  * This function freeze the hardware resources used
  * @param hspi: SPI handle pointer
  * @retval None
  */
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi)
{
	if(hspi->Instance==SPI3)
	{
		// Peripheral clock disable
		__HAL_RCC_SPI3_CLK_DISABLE();

		//	PC12  ------> SPI3_MOSI
		HAL_GPIO_DeInit(LCD_SDI_Port, LCD_SDI_Pin);

		//	PC10 ------> SPI3_SCK
		HAL_GPIO_DeInit(LCD_SCK_Port, LCD_SCK_Pin);

	    // SPI3 DMA DeInit
	    HAL_DMA_DeInit(hspi->hdmatx);

	    // SPI3 interrupt DeInit
	    HAL_NVIC_DisableIRQ(SPI3_IRQn);

	}
}
