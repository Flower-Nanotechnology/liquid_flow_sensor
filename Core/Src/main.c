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
#include "xpt2046.h"
#include "calibrate_touch.h"
#include "demo.h"

// Screens
#include "screens/main_screen.h"
#include "screens/settings_screen.h"
#include "screens/select_channel_screen.h"
#include "screens/set_unit_screen.h"
#include "screens/set_target_screen.h"
#include "screens/set_flow_rate_screen.h"

// Styles
#include "styles/styles.h"

// System
#include "system/type_definitions.h"


/* Public variables ----------------------------------------------------------*/
extern SPI_HandleTypeDef hspi1; // Touch
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

// XPT2046
XPT2046_Handler touch_handler;
XPT2046_ConnectionData cnt_touch = {
    .hspi     = &hspi1,
    .cs_port  = TOUCH_CS_GPIO_Port,
    .cs_pin   = TOUCH_CS_Pin,
    .irq_port = TOUCH_IRQ_GPIO_Port,
    .irq_pin  = TOUCH_IRQ_Pin,
    .exti_irq = TOUCH_IRQ_EXTI_IRQn
};





/* Private function prototypes -----------------------------------------------*/

// LVGL
void lvgl_task_callback(void *argument);
void ui_init(lv_display_t *disp);


// TOUCH
void touchpad_read_cb(lv_indev_t * indev, lv_indev_data_t * data);


/* Debug private variables --------------------------------------------------*/

// Touch
#if DEBUG_TOUCH
lv_obj_t *ui_touch_marker;
#endif // DEBUG_TOUCH


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


	XPT2046_InitTouch(&touch_handler, 20, &cnt_touch);  // 20ms
	//XPT2046_CalibrateTouch(&touch1);

	// DISPLAY 1
//	touch1.coef.Dx1 = 0xFFFFD12A2E400000LL;
//	touch1.coef.Dx2 = 0x0000001C58400000LL;
//	touch1.coef.Dx3 = 0x02A41CEE3A000000LL;
//	touch1.coef.Dy1 = 0x0000000060400000LL;
//	touch1.coef.Dy2 = 0X00001FEA6D600000LL;
//	touch1.coef.Dy3 = 0xFFF5E47E1D800000LL;
//	touch1.coef.D   = 0x0001E35E90000000LL;

	// DISPLAY 2
	touch_handler.coef.Dx1 = 0xFFFFD1A61B400000LL;
	touch_handler.coef.Dx2 = 0x000000206F520000LL;
	touch_handler.coef.Dx3 = 0x0299EC6347B80000LL;
	touch_handler.coef.Dy1 = 0xFFFFFFFCE2800000LL;
	touch_handler.coef.Dy2 = 0X00001F42D73A0000LL;
	touch_handler.coef.Dy3 = 0xFFF63560CF180000LL;
	touch_handler.coef.D   = 0x0001D9744B000000LL;

	touch_handler.fl_interrupt = 1;

	lv_indev_t * indev = lv_indev_create();
	lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
	lv_indev_set_read_cb(indev, (lv_indev_read_cb_t)touchpad_read_cb);

	// Styles init
	styles_init();


	ui_init(lcd_disp);
	//ui_init_test(lcd_disp);

	//LVGL_Draw_TouchPenDemo(&touch1);

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
	settings_screen_create();
	select_channel_screen_create();
	set_unit_screen_create();
	set_target_screen_create();
	set_flow_rate_screen_create();

	// Set default values on display

	// MODE
	ui_update_mode_state_label("Injection");   // Mode is Injection as default
	ui_update_ch1_value_label_rate("0.0");     // CH1 flow is 0.0 as default
	ui_update_ch1_unit_label_rate("ml/min");   // CH1 unit is ml/min as deafult
	ui_update_ch2_value_label_rate("0.0");     // CH2 flow is 0.0 as default
	ui_update_ch2_unit_label_rate("ml/min");   // CH2 unit is ml/min as deafult

	// TARGET
	ui_update_ch1_mode_label_target("Vol.");   // CH1 target mode is volume as default
	ui_update_ch1_value_label_target("0.0");   // CH1 target value is 0.0 as default
	ui_update_ch1_unit_label_target("ml");     // CH1 target unit is ml as default
	ui_update_ch2_mode_label_target("Vol.");   // CH1 target mode is volume as default
	ui_update_ch2_value_label_target("0.0");   // CH1 target value is 0.0 as default
	ui_update_ch2_unit_label_target("ml");     // CH1 target unit is ml as default

	ui_update_ch1_run_btn_icon_settings(CHANNEL_STATE__STOPPED); // CH1 start stopped as default
	ui_update_ch2_run_btn_icon_settings(CHANNEL_STATE__STOPPED); // CH2 start stopped as default

	main_screen_load(SETTING_OPTION__NO_OPTION);


#if DEBUG_TOUCH
	ui_touch_marker = lv_canvas_create(lv_screen_active());
	lv_obj_set_size(ui_touch_marker, 10, 10);
	lv_obj_set_style_bg_color(ui_touch_marker, lv_palette_main(LV_PALETTE_RED), 0);
	lv_obj_set_style_bg_opa(ui_touch_marker, LV_OPA_COVER, 0);
	lv_obj_set_style_radius(ui_touch_marker, LV_RADIUS_CIRCLE, 0);
	lv_obj_remove_flag(ui_touch_marker, LV_OBJ_FLAG_CLICKABLE); // Do not interter touch
#endif
}


///* =========================================
// *    Touch callback
// * ========================================= */


void touchpad_read_cb(lv_indev_t * indev, lv_indev_data_t * data)
{
    if (touch_handler.click)
    {
        tPoint display_point;
        XPT2046_ConvertPoint(&display_point, &touch_handler.point, &touch_handler.coef);

        data->point.x = (int16_t)display_point.y;
        data->point.y = LCD_V_RES - (int16_t)display_point.x;
        data->state = LV_INDEV_STATE_PRESSED;

#if DEBUG_TOUCH
        if(ui_touch_marker != NULL)
        {
            lv_obj_set_pos(ui_touch_marker, (int16_t)display_point.x - 5, (int16_t)display_point.y - 5);
        }
#endif // DEBUG_TOUCH

        touch_handler.click = 0;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}


