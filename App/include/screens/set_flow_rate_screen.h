/*
 ******************************************************************************
 * @file           : set_flow_rate_screen.h
 * @brief          : Set flow rate screen creation, stylization and
 *                   load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_SCREENS_SET_FLOW_RATE_SCREEN_H_
#define INCLUDE_SCREENS_SET_FLOW_RATE_SCREEN_H_


#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"


/* Exported functions prototypes ---------------------------------------------*/
void set_flow_rate_screen_create(void);
void set_flow_rate_screen_load(int selected_channel);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_SET_FLOW_RATE_SCREEN_H_ */
