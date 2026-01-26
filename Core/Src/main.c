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
#include "i2c2_init.h"

// LVGL
#include "lvgl.h"
#include "drivers/display/ili9341/lv_ili9341.h"

// Liquid Flow Sensor
#include "sensirion_common.h"
#include "sensirion_i2c_hal.h"
#include "sf06_lf_i2c.h"

/* ----------------------------------------------------------*/

// APP

#include "ili9341_driver_callbacks.h"

// Screens
#include "screens/main_screen.h"

// Styles
#include "styles/styles.h"

// System
#include "system/type_definitions.h"



/* Private variables ---------------------------------------------------------*/

// LVGL
lv_display_t * lcd_disp;

// RTOS

// LVGL task
osThreadId_t lvgl_task_handle;
const osThreadAttr_t lvgl_task_attributes = {
	.name       = "lvgl_task",
	.stack_size = 1024 * 8, // 8 KB
	.priority   = (osPriority_t)osPriorityAboveNormal
};

osThreadId_t sensor_task_handle;
const osThreadAttr_t sensor_task_attributes = {
	.name = "sensor_task",
	.stack_size = 1024 * 4, // 4 KB
	.priority = (osPriority_t)osPriorityNormal
};

// LVGL queue
osMessageQueueId_t sensor_queue;

// Digital filter to sensor data
static int32_t flow_filt_ml_x1000 = 0;  // mL/min × 1000



/* Private definitions -------------------------------------------------------*/

#define sensirion_hal_sleep_us sensirion_i2c_hal_sleep_usec

#define SENSOR_QUEUE_LEN 4

#define ALPHA_NUM 1             // numerador de alpha (ex: 1/10)
#define ALPHA_DEN 10            // denominador de alpha
#define DEADBAND_ML_X1000 20    // 0.020 mL/min

#define FLAG_AIR_IN_LINE     (1U << 0)
#define FLAG_HIGH_FLOW       (1U << 1)



/* Private type definitions --------------------------------------------------*/
typedef struct {
    int32_t raw_flow;
    int16_t raw_temp;
    uint16_t flags;
} sensor_msg_t;



/* Private function prototypes -----------------------------------------------*/

// LVGL
void lvgl_task_callback(void * argument);
void sensor_task_callback(void * argument);



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

	// I2C
	i2c2_init_wrapper();


	/* =========================================
	 *    TOUCH
	 * ========================================= */


	/* =========================================
	 *    RTOS features
	 * ========================================= */

	/* QUEUES -------------------------------------------------------------------*/

	// Liquid flow sensor queue
	sensor_queue = osMessageQueueNew(SENSOR_QUEUE_LEN, sizeof(sensor_msg_t), NULL);
	if (sensor_queue == NULL)
	{
	    Error_Handler();
	}

	/* TASKS --------------------------------------------------------------------*/

	// LVGL task
	lvgl_task_handle = osThreadNew(lvgl_task_callback, NULL, &lvgl_task_attributes);

	// Liquid flow sensor task
	sensor_task_handle = osThreadNew(sensor_task_callback, NULL, &sensor_task_attributes);


	/* =========================================
	 *    Scheduler start
	 * ========================================= */

	 osKernelStart();
}



/* Task callbacks -----------------------------------------------------------*/

// LVGL
void lvgl_task_callback(void *argument)
{
	// Initialize LVGL
	// XPT2046_InitTouch(&touch1, 20, &cnt_touch);
	lv_init();

	// Initiliaze LCD I/O
	if (lcd_io_init() != HAL_OK) return;

	// Create the LVGL display object with ILI9341 driver
	lcd_disp = lv_ili9341_create(LCD_H_RES, LCD_V_RES, LV_LCD_FLAG_NONE, lcd_send_cmd, lcd_send_color);
	lv_display_set_rotation(lcd_disp, LV_DISPLAY_ROTATION_180);


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

	// Screens create
	main_screen_create();

	// Main screen load
	main_screen_load();

	for(;;)
	{
		sensor_msg_t msg;
		int got = 0;
		while (osMessageQueueGet(sensor_queue, &msg, NULL, 0) == osOK)
		{
		    // fica com o último msg recebido
			got = 1;
		}

		if(got == 1)
		{
		    // =========================
		    //     FLOW RATE
		    // =========================

			int32_t i = msg.raw_flow / 1000;
			int32_t f = (msg.raw_flow % 1000 + 50) / 100; // arredondado e truncado em uma casa decimal apenas
			if (f < 0) f = -f;

			char buf[32];
			snprintf(buf, sizeof(buf), "%ld.%01ld", (long)i, (long)f);

			set_flow_rate_on_display(buf);


		    // =========================
		    //    WARNING FLAGS
		    // =========================

			if(msg.flags & FLAG_HIGH_FLOW)
				set_high_flow_state_on_display(WARNING_FLAG__HIGH_FLOW_YES);
			else
				set_high_flow_state_on_display(WARNING_FLAG__HIGH_FLOW_NO);


			if(msg.flags & FLAG_AIR_IN_LINE)
				set_air_in_line_state_on_display(WARNING_FLAG__AIR_YES);
			else
				set_air_in_line_state_on_display(WARNING_FLAG__AIR_NO);

		}

		// The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
		lv_timer_handler();
		// raise the task priority of LVGL and/or reduce the handler period can improve the performance
		osDelay(10);
	}
}


// LIQUID FLOW SENSOR
void sensor_task_callback(void * argument)
{
    int16_t error = NO_ERROR;

    sensirion_i2c_hal_init();
    sf06_lf_init(SLF3C_1300F_I2C_ADDR_08);

    sf06_lf_stop_continuous_measurement();
    sensirion_hal_sleep_us(150000);

    uint32_t product_identifier = 0;
    uint8_t serial_number[8] = {0};

    error = sf06_lf_read_product_identifier(&product_identifier, serial_number, 8);
    if (error != NO_ERROR) osThreadExit();

    error = sf06_lf_start_h2o_continuous_measurement();
    if (error != NO_ERROR) osThreadExit();

    int16_t raw_flow = 0;
    int16_t raw_temperature = 0;
    uint16_t signaling_flags = 0u;

    sensirion_hal_sleep_us(50000); // warm-up

    for (;;)
    {
        sensirion_hal_sleep_us(105000);

        error = sf06_lf_read_measurement_data_raw(
        		&raw_flow,
				&raw_temperature,
                &signaling_flags
			);

        if (error != NO_ERROR) // error executing read_measurement_data_raw()
        	continue;

        // raw_flow -> mL/min × 1000
        // 1 count = 2 uL/min = 0.002 mL/min
        int32_t flow_ml_x1000 = (int32_t)raw_flow * 2;

        // deadband (elimina ruído e falsos negativos)
        if (flow_ml_x1000 > -DEADBAND_ML_X1000 &&
            flow_ml_x1000 <  DEADBAND_ML_X1000)
        {
            flow_ml_x1000 = 0;
        }

        // filtro IIR em fix-point
        flow_filt_ml_x1000 =
            flow_filt_ml_x1000 +
            (ALPHA_NUM * (flow_ml_x1000 - flow_filt_ml_x1000)) / ALPHA_DEN;

        sensor_msg_t msg = {
            .raw_flow = flow_filt_ml_x1000,
            .raw_temp = raw_temperature,
			.flags = signaling_flags
        };

        osStatus_t st = osMessageQueuePut(sensor_queue, &msg, 0, 0);

        if (st == osErrorResource)
        {
        	// Full queue. Remove the oldest and try again (keeps always the newest)
            sensor_msg_t junk;
            osMessageQueueGet(sensor_queue, &junk, NULL, 0);
            osMessageQueuePut(sensor_queue, &msg, 0, 0);
        }

    }
}
