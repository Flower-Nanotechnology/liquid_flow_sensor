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


/* Exported functions prototypes ---------------------------------------------*/
void back_btn_create(
		lv_obj_t * screen,
		void (* back_screen_load)(void));


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_BUTTONS_BACK_BTN_H_ */
