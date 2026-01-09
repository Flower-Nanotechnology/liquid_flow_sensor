/*
 ******************************************************************************
 * @file           : set_unit_screen.h
 * @brief          : Set unit screen creation, stylization and
 *                   load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_SCREENS_SET_UNIT_SCREEN_H_
#define INCLUDE_SCREENS_SET_UNIT_SCREEN_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"


/* Exported functions prototypes ---------------------------------------------*/
void set_unit_screen_create(void);
void set_unit_screen_load(int selected_channel);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_SET_UNIT_SCREEN_H_ */
