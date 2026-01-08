/*
 ******************************************************************************
 * @file           : title_panel.h
 * @brief          : Title panel create function with stylization
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_SCREENS_PANELS_TITLE_PANEL_H_
#define INCLUDE_SCREENS_PANELS_TITLE_PANEL_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"

/* Exported function prototypes ----------------------------------------------*/
void title_panel_create(lv_obj_t * screen);
void ui_update_page_title_label(char * text);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_PANELS_TITLE_PANEL_H_ */
