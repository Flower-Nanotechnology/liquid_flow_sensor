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
void main_screen_load();

void set_high_flow_state_on_display(int state);
void set_air_in_line_state_on_display(int state);
void set_flow_rate_on_display(char * value);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_MAIN_SCREEN_H_ */
