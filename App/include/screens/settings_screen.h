/*
 ******************************************************************************
 * @file           : settings_screen.h
 * @brief          : Settings screen creation, stylization and load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */


#ifndef INCLUDE_SCREENS_SETTINGS_SCREEN_H_
#define INCLUDE_SCREENS_SETTINGS_SCREEN_H_


#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"


/* Exported functions prototypes ---------------------------------------------*/
void settings_screen_create(void);
void settings_screen_load(void);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_SETTINGS_SCREEN_H_ */
