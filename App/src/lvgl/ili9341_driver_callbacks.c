/*
 ******************************************************************************
 * @file           : ili9341_driver_callbacks.c
 * @brief          : Implementation of two platform-dependent functions used by
 * 					 display controller support
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */


/* Includes ------------------------------------------------------------------*/
#include "ili9341_driver_callbacks.h"


/* Private variables ---------------------------------------------------------*/

// SPI
extern SPI_HandleTypeDef hspi3;

// LVGL
extern lv_display_t *lcd_disp;
extern volatile int lcd_bus_busy;



/* Private functions ---------------------------------------------------------*/

void lcd_color_transfer_ready_cb(SPI_HandleTypeDef *hspi)
{
	// CS high
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
	lcd_bus_busy = 0;
	lv_display_flush_ready(lcd_disp);
}


/* Public functions ----------------------------------------------------------*/

// Initialize LCD I/O bus, reset LCD
int32_t lcd_io_init(void)
{
	// Register SPI Tx Complete Callback
	HAL_SPI_RegisterCallback(&hspi3, HAL_SPI_TX_COMPLETE_CB_ID, lcd_color_transfer_ready_cb);

	// reset LCD
	HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_RESET);
	osDelay(100);
	HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_SET);
	osDelay(100);

	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_DCX_GPIO_Port, LCD_DCX_Pin, GPIO_PIN_SET);

	return HAL_OK;
}


// Send short command to the LCD
void lcd_send_cmd(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, const uint8_t *param, size_t param_size)
{
	LV_UNUSED(disp);

	// Wait until previous transfer is finished
	while (lcd_bus_busy);

	// Set the SPI in 8-bit mode
	hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
	HAL_SPI_Init(&hspi3);

	// DCX low (command)
	HAL_GPIO_WritePin(LCD_DCX_GPIO_Port, LCD_DCX_Pin, GPIO_PIN_RESET);

	// CS low
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);

	// send command
	if (HAL_SPI_Transmit(&hspi3, cmd, cmd_size, BUS_SPI3_POLL_TIMEOUT) == HAL_OK)
	{
		// DCX high (data)
		HAL_GPIO_WritePin(LCD_DCX_GPIO_Port, LCD_DCX_Pin, GPIO_PIN_SET);

		// for short data blocks we use polling transfer
		HAL_SPI_Transmit(&hspi3, (uint8_t *)param, (uint16_t)param_size, BUS_SPI3_POLL_TIMEOUT);

		// CS high
		HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
	}
}


// Send large array of pixel data to the LCD
void lcd_send_color(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, uint8_t *param, size_t param_size)
{
	LV_UNUSED(disp);

	// Wait until previous transfer is finished
	while (lcd_bus_busy);

	// Set the SPI in 8-bit mode
	hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
	HAL_SPI_Init(&hspi3);

	// DCX low (command)
	HAL_GPIO_WritePin(LCD_DCX_GPIO_Port, LCD_DCX_Pin, GPIO_PIN_RESET);

	// CS low
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);

	// send command
	if (HAL_SPI_Transmit(&hspi3, cmd, cmd_size, BUS_SPI3_POLL_TIMEOUT) == HAL_OK)
	{
		// DCX high (data)
		HAL_GPIO_WritePin(LCD_DCX_GPIO_Port, LCD_DCX_Pin, GPIO_PIN_SET);

		// Clear cache
		// SCB_CleanDCache_by_Addr((uint32_t *)param, param_size);
		// No seu arquivo de callbacks:
//		if (param_size > 0 && param != NULL) {
//		    // Calcula o endereço inicial alinhado para baixo (múltiplo de 32)
//		    uint32_t aligned_addr = (uint32_t)param & ~0x1F;
//		    // Calcula o tamanho total cobrindo o resto do desalinhamento
//		    uint32_t aligned_size = (param_size + ((uint32_t)param & 0x1F) + 31) & ~0x1F;
//
//		    SCB_CleanDCache_by_Addr((uint32_t *)aligned_addr, aligned_size);
//		}

		// (for color data use DMA transfer)
		// Set the SPI in 16-bit mode to match endianess
		hspi3.Init.DataSize = SPI_DATASIZE_16BIT;
		HAL_SPI_Init(&hspi3);

		// Set transmition flag to 1
		lcd_bus_busy = 1;

		// Transmit
		HAL_SPI_Transmit_DMA(&hspi3, param, (uint16_t)param_size / 2);

		// NOTE: CS will be reset in the transfer ready callback
	}
}
