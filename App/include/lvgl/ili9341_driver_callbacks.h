/*
 ******************************************************************************
 * @file           : ili9341_driver_callbacks.h
 * @brief          : Prototype of two platform-dependent functions used by
 * 					 display controller support
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_LVGL_ILI9341_DRIVER_CALLBACKS_H_
#define INCLUDE_LVGL_ILI9341_DRIVER_CALLBACKS_H_


#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "lvgl.h"


/* Exported functions prototypes ---------------------------------------------*/

/* Initialize LCD I/O bus, reset LCD */
int32_t lcd_io_init(void);

// Send short command to the LCD
void lcd_send_cmd(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, const uint8_t *param, size_t param_size);

// Send large array of pixel data to the LCD
void lcd_send_color(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, uint8_t *param, size_t param_size);


#ifdef __cplusplus
}
#endif


#endif /* INCLUDE_LVGL_ILI9341_DRIVER_CALLBACKS_H_ */
