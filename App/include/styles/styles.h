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

extern lv_style_t primary_blue_bg_style;
extern lv_style_t secondary_blue_bg_style;
extern lv_style_t primary_grey_bg_style;
extern lv_style_t green_bg_style;
extern lv_style_t red_bg_style;

extern lv_style_t primary_grey_with_stroke_bg_style;

extern lv_style_t white_text_style;
extern lv_style_t black_text_style;



/* Exported function prototypes ----------------------------------------------*/
void styles_init();


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_STYLES_STYLES_H_ */
