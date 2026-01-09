/*
 ******************************************************************************
 * @file           : channel_panel.h
 * @brief          : Channel panel create function with stylization
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_SCREENS_PANELS_TITLE_PANEL_WITH_CHANNEL_H_
#define INCLUDE_SCREENS_PANELS_TITLE_PANEL_WITH_CHANNEL_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "lvgl.h"


/* Type definitions ----------------------------------------------------------*/
typedef struct {
    lv_obj_t * bg;
    lv_obj_t * label;
} channel_panel_t;


/* Exported function prototypes ----------------------------------------------*/
void channel_panel_create(channel_panel_t * panel, lv_obj_t * parent);
void channel_panel_set_text(channel_panel_t * panel, const char * text);


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SCREENS_PANELS_TITLE_PANEL_WITH_CHANNEL_H_ */
