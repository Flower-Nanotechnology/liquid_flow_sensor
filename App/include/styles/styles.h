/*
 ******************************************************************************
 * @file           : styles.h
 * @brief          : Pre-defined style init function
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_STYLES_STYLES_H_
#define INCLUDE_STYLES_STYLES_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "lvgl.h"

/* Private variables ---------------------------------------------------------*/
extern lv_style_t panel_block_bg_style;
extern lv_style_t panel_title_bg_style;
extern lv_style_t panel_title_label_style;
extern lv_style_t panel_channel_param_bg_style;
extern lv_style_t panel_channel_param_label_style;

extern lv_style_t settings_btn_icon_style;
extern lv_style_t settings_op_btn_label_style;

extern lv_style_t settings_panel_bg_style;
extern lv_style_t settings_panel_label_style;

extern lv_style_t blue_btn_bg_style;
extern lv_style_t red_btn_bg_style;
extern lv_style_t green_btn_bg_style;

extern lv_style_t general_btn_icon_style;

extern lv_style_t back_btn_icon_bg_style;
extern lv_style_t back_btn_icon_style;
extern lv_style_t back_btn_text_style;

extern lv_style_t simple_page_title_label_style;
extern lv_style_t red_page_title_label_style;


/* Exported function prototypes ----------------------------------------------*/
void styles_init();


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_STYLES_STYLES_H_ */
