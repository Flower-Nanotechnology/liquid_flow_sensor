/*
 ******************************************************************************
 * @file           : main_screen.h
 * @brief          : Main screen creation, stylization and load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */


#ifndef INCLUDE_SCREENS_MAIN_SCREEN_H_
#define INCLUDE_SCREENS_MAIN_SCREEN_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"


/* Exported functions prototypes ---------------------------------------------*/
void main_screen_create(void);
void main_screen_load(void);

// MODE/RATE BLOCK
void ui_update_mode_state_label(const char * mode_name);
void ui_update_ch1_value_label_rate(const char * flow);
void ui_update_ch1_unit_label_rate(const char * unit);
void ui_update_ch2_value_label_rate(const char * flow);
void ui_update_ch2_unit_label_rate(const char * unit);

// TARGET BLOCK
void ui_update_ch1_mode_label_target(const char * mode_name);
void ui_update_ch1_value_label_target(const char * flow);
void ui_update_ch1_unit_label_target(const char * unit);
void ui_update_ch2_mode_label_target(const char * mode_name);
void ui_update_ch2_value_label_target(const char * flow);
void ui_update_ch2_unit_label_target(const char * unit);

// SETTINGS BLOCK
void ui_update_ch1_run_btn_icon_settings(int state);
void ui_update_ch2_run_btn_icon_settings(int state);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_MAIN_SCREEN_H_ */
