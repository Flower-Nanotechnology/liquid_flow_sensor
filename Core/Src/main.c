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
#include "spi1_init.h"
#include "spi3_init.h"
#include "dma_init.h"
#include "gpio_init.h"

// LVGL
#include "lvgl.h"
#include "drivers/display/ili9341/lv_ili9341.h"

#include "ili9341_driver_callbacks.h"

// Touch
// #include "xpt2046.h"

// Screens
#include "screens/main_screen.h"



/* Private variables ---------------------------------------------------------*/

extern SPI_HandleTypeDef hspi1; // Touch
extern SPI_HandleTypeDef hspi3; // LCD

// LVGL
lv_display_t *lcd_disp;
volatile int lcd_bus_busy = 0;


// RTOS
osThreadId_t lvgl_task_handle;
const osThreadAttr_t lvgl_task_attributes = {
	.name = "lvgl_task",
	.stack_size = 1024 * 4,
	.priority = (osPriority_t)osPriorityNormal
};

// Logic
lv_obj_t *ui_label_debug;
lv_obj_t *ui_touch_marker;

/* Private function prototypes -----------------------------------------------*/

// LVGL
void lvgl_task_callback(void *argument);
void ui_init(lv_display_t *disp);


// TOUCH
void touch_init(void);
void touchpad_read_cb(lv_display_t * disp, lv_indev_data_t * data);
// void touchpad_read_cb(lv_indev_t * indev, lv_indev_data_t * data);


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
	spi1_init_wrapper();
	spi3_init_wrapper();


	/* =========================================
	 *    LVGL
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
	lv_init();

	// Initiliaze LCD I/O
	if (lcd_io_init() != HAL_OK) return;

	// Create the LVGL display object with ILI9341 driver
	lcd_disp = lv_ili9341_create(LCD_H_RES, LCD_V_RES, LV_LCD_FLAG_NONE, lcd_send_cmd, lcd_send_color);
	lv_display_set_rotation(lcd_disp, LV_DISPLAY_ROTATION_90);



//	// Touch initialization
//	touch_init();
//
//	lv_indev_t * indev = lv_indev_create();
//	lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
//	lv_indev_set_read_cb(indev, (lv_indev_read_cb_t)touchpad_read_cb);




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

	ui_init(lcd_disp);

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
	ui_update_mode_label("Injection"); // Mode is "Injection" as default

	main_screen_load();
}



//void ui_init(lv_display_t *disp)
//{
//	/* set screen background to white */
//	lv_obj_t *scr = lv_screen_active();
//	lv_obj_set_style_bg_color(scr, lv_color_white(), 0);
//	lv_obj_set_style_bg_opa(scr, LV_OPA_100, 0);
//
//	/* create label */
//	ui_label_debug = lv_label_create(scr);
//	lv_obj_set_align(ui_label_debug, LV_ALIGN_CENTER);
//	lv_obj_set_height(ui_label_debug, LV_SIZE_CONTENT);
//	lv_obj_set_width(ui_label_debug, LV_SIZE_CONTENT);
//	lv_obj_set_style_text_font(ui_label_debug, &lv_font_montserrat_14, 0);
////	lv_obj_set_style_text_color(ui_label_debug, lv_palette_main(LV_PALETTE_RED), 0); // This is red background
//	lv_obj_set_style_text_color(ui_label_debug, lv_palette_main(LV_PALETTE_BLUE), 0); // This is red background
//	lv_label_set_text(ui_label_debug, "Aguardando toque...");
//}

////void ui_init(lv_display_t *disp)
////{
////    /* tela branca */
////    lv_obj_t *scr = lv_screen_active();
////    lv_obj_set_style_bg_color(scr, lv_color_white(), 0);
////    lv_obj_set_style_bg_opa(scr, LV_OPA_100, 0);
////
////    /* label debug */
////    ui_label_debug = lv_label_create(scr);
////    lv_obj_set_align(ui_label_debug, LV_ALIGN_CENTER);
////    lv_obj_set_style_text_font(ui_label_debug, &lv_font_montserrat_14, 0);
////    lv_obj_set_style_text_color(ui_label_debug,
////                                lv_palette_main(LV_PALETTE_BLUE), 0);
////    lv_label_set_text(ui_label_debug, "Aguardando toque...");
////
////    /* marcador do touch: quadrado 7x7 preto */
////    ui_touch_marker = lv_obj_create(scr);
////    lv_obj_set_size(ui_touch_marker, 7, 7);
////    lv_obj_set_style_bg_color(ui_touch_marker, lv_color_black(), 0);
////    lv_obj_set_style_bg_opa(ui_touch_marker, LV_OPA_100, 0);
////    lv_obj_set_style_border_width(ui_touch_marker, 0, 0);
////
////    /* começa invisível */
////    lv_obj_add_flag(ui_touch_marker, LV_OBJ_FLAG_HIDDEN);
////}
//
///* =========================================
// *    Touch callback
// * ========================================= */
//
//void touch_init(void)
//{
//	xpt2046_init();
//	xpt2046_bit_mode(XPT2046_12BIT_MODE);
//	xpt2046_set_size(LCD_H_RES, LCD_V_RES);
//	xpt2046_orientation(XPT2046_ORIENTATION_LANDSCAPE);
//	xpt2046_set_calibration(
//	    2447, 1680,   // x_max , x_min
//	    3811, 2121    // y_max , y_min
//	);
//
//	xpt2046_spi(&hspi1);
//}
//
//
///* Callback de leitura do Touchpad para a LVGL */
//void touchpad_read_cb(lv_display_t * disp, lv_indev_data_t * data)
//{
//    uint16_t x, y;
//
//    /* xpt2046_read_position retorna 0,0 se não estiver pressionado */
//    xpt2046_read_position(&x, &y);
//
//    if(xpt2046_pressed())
//    {
//        data->state = LV_INDEV_STATE_PRESSED;
//        data->point.x = x;
//        data->point.y = y;
//
//        /* Debug visual na tela */
//		if(ui_label_debug != NULL)
//		{
//			lv_label_set_text_fmt(ui_label_debug, "X: %d | Y: %d", x, y);
//		}
//    }
//    else
//    {
//        data->state = LV_INDEV_STATE_RELEASED;
//    }
//}
//
//
////void touchpad_read_cb(lv_indev_t * indev, lv_indev_data_t * data)
////{
////    uint16_t x, y;
////    xpt2046_read_position(&x, &y);
////
////    if(xpt2046_pressed()) {
////
////        data->state = LV_INDEV_STATE_PRESSED;
////        data->point.x = x;
////        data->point.y = y;
////
////        /* centraliza o quadrado */
////        lv_obj_clear_flag(ui_touch_marker, LV_OBJ_FLAG_HIDDEN);
////        lv_obj_set_pos(ui_touch_marker, x - 3, y - 3);
////
////        char buf[64];
////        sprintf(buf, "x=%u  y=%u", x, y);
////        lv_label_set_text(ui_label_debug, buf);
////    }
////    else {
////        data->state = LV_INDEV_STATE_RELEASED;
////        lv_obj_add_flag(ui_touch_marker, LV_OBJ_FLAG_HIDDEN);
////    }
////}
