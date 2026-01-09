/*
 ******************************************************************************
 * @file           : set_target_screen.h
 * @brief          : Set target screen creation, stylization and
 *                   load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_SCREENS_SET_TARGET_SCREEN_H_
#define INCLUDE_SCREENS_SET_TARGET_SCREEN_H_


#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"


/* Exported functions prototypes ---------------------------------------------*/
void set_target_screen_create(void);
void set_target_screen_load(int selected_channel);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_SET_TARGET_SCREEN_H_ */
