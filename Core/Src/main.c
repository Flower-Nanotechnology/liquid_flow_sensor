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


/* Private includes ----------------------------------------------------------*/
#include "main.h"

#include <stdio.h>

// System
#include "error_handler.h"
#include "system_clock_config.h"
#include "mpu_config.h"
#include "period_elapsed_cb.h"

// Peripherals
#include "spi3_init.h"
#include "dma_init.h"
#include "gpio_init.h"

// LVGL
#include "lvgl.h"
#include "drivers/display/ili9341/lv_ili9341.h"

#include "ili9341_driver_callbacks.h"

// Screens
#include "screens/main_screen.h"

// Styles
#include "styles/styles.h"

// System
#include "system/type_definitions.h"


/* Public variables ----------------------------------------------------------*/
extern SPI_HandleTypeDef hspi3; // LCD


/* Private variables ---------------------------------------------------------*/

// LVGL
lv_display_t *lcd_disp;
volatile int lcd_bus_busy = 0;

// RTOS
osThreadId_t lvgl_task_handle;
const osThreadAttr_t lvgl_task_attributes = {
	.name       = "lvgl_task",
	.stack_size = 1024 * 4 * 2,
	.priority   = (osPriority_t)osPriorityNormal
};



/* Private function prototypes -----------------------------------------------*/

// LVGL
void lvgl_task_callback(void *argument);
void ui_init(lv_display_t *disp);


/* Debug private variables --------------------------------------------------*/

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
	mpu_config_wrapper();

	// Reset of all peripherals, Initializes the Flash interface and the Systick.
	HAL_Init();

  	// Configure the system clock
	system_clock_config_wrapper();

	// RTOS kernel initialize
	osKernelInitialize();


	/* =========================================
	 *    Peripherals
	 * ========================================= */

	// General GPIO
	gpio_init_wrapper();

	// DMA
	dma_init_wrapper();

	// SPI
	spi3_init_wrapper();


	/* =========================================
	 *    TOUCH
	 * ========================================= */


	/* =========================================
	 *    RTOS features
	 * ========================================= */

	lvgl_task_handle = osThreadNew(lvgl_task_callback, NULL, &lvgl_task_attributes);


	/* =========================================
	 *    Scheduler start
	 * ========================================= */

	 osKernelStart();
}


/* =========================================
 *    Tasks Callbacks
 * ========================================= */

void lvgl_task_callback(void *argument)
{
	// Initialize LVGL
	// XPT2046_InitTouch(&touch1, 20, &cnt_touch);
	lv_init();

	// Initiliaze LCD I/O
	if (lcd_io_init() != HAL_OK) return;

	// Create the LVGL display object with ILI9341 driver
	lcd_disp = lv_ili9341_create(LCD_H_RES, LCD_V_RES, LV_LCD_FLAG_NONE, lcd_send_cmd, lcd_send_color);
	lv_display_set_rotation(lcd_disp, LV_DISPLAY_ROTATION_90);


	// Allocate draw buffers on the heap. In this example we use two partial buffers of 1/10th size of the screen
	lv_color_t * buf1 = NULL;
	lv_color_t * buf2 = NULL;

	uint32_t buf_size = LCD_H_RES * LCD_V_RES / 10 * lv_color_format_get_size(lv_display_get_color_format(lcd_disp));

	buf1 = lv_malloc(buf_size);
	if(buf1 == NULL)
	{
		LV_LOG_ERROR("display draw buffer malloc failed");
		return;
	}

	buf2 = lv_malloc(buf_size);
	if(buf2 == NULL)
	{
		LV_LOG_ERROR("display buffer malloc failed");
		lv_free(buf1);
		return;
	}
	lv_display_set_buffers(lcd_disp, buf1, buf2, buf_size, LV_DISPLAY_RENDER_MODE_PARTIAL);


	// Styles init
	styles_init();


	ui_init(lcd_disp);
	//ui_init_test(lcd_disp);

	for(;;)
	{
		// The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
		lv_timer_handler();
		// raise the task priority of LVGL and/or reduce the handler period can improve the performance
		osDelay(10);
	}
}


/* =========================================
 *    Interfaces
 * ========================================= */

void ui_init(lv_display_t *disp)
{
	main_screen_create();
	main_screen_load();
}
