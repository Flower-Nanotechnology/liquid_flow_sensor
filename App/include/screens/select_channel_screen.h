/*
 ******************************************************************************
 * @file           : select_channel_screen.h
 * @brief          : Select channel screen creation, stylization and
 *                   load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_SCREENS_SELECT_CHANNEL_SCREEN_H_
#define INCLUDE_SCREENS_SELECT_CHANNEL_SCREEN_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"


/* Exported functions prototypes ---------------------------------------------*/
void select_channel_screen_create(void);
void select_channel_screen_load(int selected_setting_option);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_SELECT_CHANNEL_SCREEN_H_ */
