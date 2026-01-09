/*
 ******************************************************************************
 * @file           : back_btn.h
 * @brief          : Back button create function with stylization
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */


#ifndef INCLUDE_SCREENS_BUTTONS_BACK_BTN_H_
#define INCLUDE_SCREENS_BUTTONS_BACK_BTN_H_


#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"


/* type definitions ----------------------------------------------------------*/
typedef void (* back_btn_cb_t)(int selected_setting_option);

typedef struct {
	back_btn_cb_t cb;     // pointer to callback function
    int op;               // selected setting option
} back_btn_cb_ctx_t;


/* Exported functions prototypes ---------------------------------------------*/
void back_btn_create(
		lv_obj_t * screen,
		back_btn_cb_t back_screen_load,
		int selected_setting_option);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_BUTTONS_BACK_BTN_H_ */
