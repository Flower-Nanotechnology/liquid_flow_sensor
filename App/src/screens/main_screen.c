/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  *
  * Modified by: Thiago Oliveira
  * Date: December, 2025
  *
  ******************************************************************************
  */


/* Private includes ----------------------------------------------------------*/
#include "screens/main_screen.h"

#include "lvgl.h"

#include "screens/main_screen.h"
#include "styles/colors.h"


/* Private variables ---------------------------------------------------------*/

// Screen
static lv_obj_t *screen;

/* =========================================
 *    Mode/Rate block
 * ========================================= */

// Mode block
static lv_obj_t *mode_block_bg,
				*mode_title_bg, *mode_title_label,
				*mode_state_bg, *mode_state_label;

// Rate block
static lv_obj_t *channels_rate_params_block,

				*channel_1_title_bg_rate, *channel_1_title_label_rate,
				*channel_1_flow_bg_rate,  *channel_1_flow_label_rate,
				*channel_1_unit_bg_rate,  *channel_1_unit_label_rate,

				*channel_2_title_bg_rate, *channel_2_title_label_rate,
				*channel_2_flow_bg_rate,  *channel_2_flow_label_rate,
				*channel_2_unit_bg_rate,  *channel_2_unit_label_rate;

/* =========================================
 *    Target block
 * ========================================= */

// Target block
static lv_obj_t *channels_target_params_block,

				*channel_1_title_bg_target,       *channel_1_title_label_target,

				*channel_1_block_title_bg_target, *channel_1_block_title_label_target,
				*channel_1_target_mode_bg_target, *channel_1_target_mode_label_target,
				*channel_1_flow_bg_target,        *channel_1_flow_label_target,
				*channel_1_unit_bg_target,        *channel_1_unit_label_target,

				*channel_2_title_bg_target,       *channel_2_title_label_target,
				*channel_2_target_mode_bg_target, *channel_2_target_mode_label_target,
				*channel_2_flow_bg_target,        *channel_2_flow_label_target,
				*channel_2_unit_bg_target,        *channel_2_unit_label_target;

/* Private function prototypes -----------------------------------------------*/
static void mode_block_create(void);
static void target_block_create(void);


void main_screen_create(void)
{
	screen = lv_obj_create(NULL);

	// Mode/Rate block
	mode_block_create();

	// Target block
	target_block_create();
}


void main_screen_load(void)
{
	lv_screen_load(screen);
}



/* =========================================
 *    Mode/Rate block
 * ========================================= */

static void mode_block_create(void)
{
	/* =========================================
	 *    MODE
	 * ========================================= */

	/* MODE BLOCK BACKGROUND -----------------------------------------------------*/
	mode_block_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(mode_block_bg);

	lv_obj_set_size(mode_block_bg, 86, 77);
	lv_obj_set_pos(mode_block_bg, 3, 4);
	lv_obj_set_style_bg_color(mode_block_bg, lv_color_hex(MAIN_GREY), 0);
	lv_obj_set_style_bg_opa(mode_block_bg, LV_OPA_COVER, 0);

	/* MODE TITLE BACKGROUND -----------------------------------------------------*/
	mode_title_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(mode_title_bg);

	lv_obj_set_size(mode_title_bg, 82, 33);
	lv_obj_set_pos(mode_title_bg, 5, 8);
	lv_obj_set_style_bg_color(mode_title_bg, lv_color_hex(BLUE), 0);
	lv_obj_set_style_bg_opa(mode_title_bg, LV_OPA_COVER, 0);
	lv_obj_set_style_border_width(mode_title_bg, 3, 0);
	lv_obj_set_style_border_color(mode_title_bg, lv_color_black(), 0);

	/* MODE TITLE LABEL ----------------------------------------------------------*/
	mode_title_label = lv_label_create(mode_title_bg);
	lv_obj_remove_style_all(mode_title_label);

	lv_label_set_text(mode_title_label, "MODE");
	lv_obj_align(mode_title_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(mode_title_label, lv_color_white(), 0);
	lv_obj_set_style_text_opa(mode_title_label, LV_OPA_COVER, 0);


	/* MODE STATE BACKGROUND -----------------------------------------------------*/
	mode_state_bg= lv_obj_create(screen);
	lv_obj_remove_style_all(mode_state_bg);

	lv_obj_set_size(mode_state_bg, 82, 33);
	lv_obj_set_pos(mode_state_bg, 5, 44);
	lv_obj_set_style_bg_color(mode_state_bg, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(mode_state_bg, LV_OPA_COVER, 0);

	/* MODE STATE LABEL ----------------------------------------------------------*/
	mode_state_label = lv_label_create(mode_state_bg);
	lv_obj_remove_style_all(mode_state_label);

	lv_obj_align(mode_state_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(mode_state_label, lv_color_white(), 0);
	lv_obj_set_style_text_opa(mode_state_label, LV_OPA_COVER, 0);


	/* =========================================
	 *    RATE
	 * ========================================= */

	/* CHANNEL STATES BLOCK BACKGROUND -------------------------------------------*/
	channels_rate_params_block = lv_obj_create(screen);
	lv_obj_remove_style_all(channels_rate_params_block);

	lv_obj_set_size(channels_rate_params_block, 225, 77);
	lv_obj_set_pos(channels_rate_params_block, 92, 4);
	lv_obj_set_style_bg_color(channels_rate_params_block, lv_color_hex(MAIN_GREY), 0);
	lv_obj_set_style_bg_opa(channels_rate_params_block, LV_OPA_COVER, 0);

	/* CHANNEL 1 TITLE BACKGROUND ------------------------------------------------*/
	channel_1_title_bg_rate = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_1_title_bg_rate);

	lv_obj_set_size(channel_1_title_bg_rate, 50, 33);
	lv_obj_set_pos(channel_1_title_bg_rate, 94, 8);
	lv_obj_set_style_bg_color(channel_1_title_bg_rate, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_1_title_bg_rate, LV_OPA_COVER, 0);

	/* CHANNEL 1 TITLE LABEL -----------------------------------------------------*/
	channel_1_title_label_rate = lv_label_create(channel_1_title_bg_rate);
	lv_obj_remove_style_all(channel_1_title_label_rate);

	lv_label_set_text(channel_1_title_label_rate, "CH1");
	lv_obj_align(channel_1_title_label_rate, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_1_title_label_rate, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_1_title_label_rate, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_1_title_label_rate, &lv_font_montserrat_14, 0);

	/* CHANNEL 1 FLOW BACKGROUND -------------------------------------------------*/
	channel_1_flow_bg_rate = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_1_flow_bg_rate);

	lv_obj_set_size(channel_1_flow_bg_rate, 84, 33);
	lv_obj_set_pos(channel_1_flow_bg_rate, 147, 8);
	lv_obj_set_style_bg_color(channel_1_flow_bg_rate, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_1_flow_bg_rate, LV_OPA_COVER, 0);

	/* CHANNEL 1 FLOW LABEL ------------------------------------------------------*/
	channel_1_flow_label_rate = lv_label_create(channel_1_flow_bg_rate);
	lv_obj_remove_style_all(channel_1_flow_label_rate);

	lv_label_set_text(channel_1_flow_label_rate, "0.0");
	lv_obj_align(channel_1_flow_label_rate, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_1_flow_label_rate, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_1_flow_label_rate, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_1_flow_label_rate, &lv_font_montserrat_14, 0);

	/* CHANNEL 1 UNIT BACKGROUND -------------------------------------------------*/
	channel_1_unit_bg_rate = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_1_unit_bg_rate);

	lv_obj_set_size(channel_1_unit_bg_rate, 81, 33);
	lv_obj_set_pos(channel_1_unit_bg_rate, 234, 8);
	lv_obj_set_style_bg_color(channel_1_unit_bg_rate, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_1_unit_bg_rate, LV_OPA_COVER, 0);

	/* CHANNEL 1 UNIT LABEL ------------------------------------------------------*/
	channel_1_unit_label_rate = lv_label_create(channel_1_unit_bg_rate);
	lv_obj_remove_style_all(channel_1_unit_label_rate);

	lv_label_set_text(channel_1_unit_label_rate, "ml/min");
	lv_obj_align(channel_1_unit_label_rate, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_1_unit_label_rate, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_1_unit_label_rate, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_1_unit_label_rate, &lv_font_montserrat_14, 0);



	/* CHANNEL 2 TITLE BACKGROUND ------------------------------------------------*/
	channel_2_title_bg_rate = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_2_title_bg_rate);

	lv_obj_set_size(channel_2_title_bg_rate, 50, 33);
	lv_obj_set_pos(channel_2_title_bg_rate, 94, 44);
	lv_obj_set_style_bg_color(channel_2_title_bg_rate, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_2_title_bg_rate, LV_OPA_COVER, 0);

	/* CHANNEL 2 TITLE LABEL -----------------------------------------------------*/
	channel_2_title_label_rate = lv_label_create(channel_2_title_bg_rate);
	lv_obj_remove_style_all(channel_2_title_label_rate);

	lv_label_set_text(channel_2_title_label_rate, "CH2");
	lv_obj_align(channel_2_title_label_rate, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_2_title_label_rate, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_2_title_label_rate, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_2_title_label_rate, &lv_font_montserrat_14, 0);

	/* CHANNEL 2 FLOW BACKGROUND -------------------------------------------------*/
	channel_2_flow_bg_rate = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_2_flow_bg_rate);

	lv_obj_set_size(channel_2_flow_bg_rate, 84, 33);
	lv_obj_set_pos(channel_2_flow_bg_rate, 147, 44);
	lv_obj_set_style_bg_color(channel_2_flow_bg_rate, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_2_flow_bg_rate, LV_OPA_COVER, 0);

	/* CHANNEL 1 FLOW LABEL ------------------------------------------------------*/
	channel_2_flow_label_rate = lv_label_create(channel_2_flow_bg_rate);
	lv_obj_remove_style_all(channel_2_flow_label_rate);

	lv_label_set_text(channel_2_flow_label_rate, "0.0");
	lv_obj_align(channel_2_flow_label_rate, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_2_flow_label_rate, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_2_flow_label_rate, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_2_flow_label_rate, &lv_font_montserrat_14, 0);

	/* CHANNEL 2 UNIT BACKGROUND -------------------------------------------------*/
	channel_2_unit_bg_rate = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_2_unit_bg_rate);

	lv_obj_set_size(channel_2_unit_bg_rate, 81, 33);
	lv_obj_set_pos(channel_2_unit_bg_rate, 234, 44);
	lv_obj_set_style_bg_color(channel_2_unit_bg_rate, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_2_unit_bg_rate, LV_OPA_COVER, 0);

	/* CHANNEL 2 UNIT LABEL ------------------------------------------------------*/
	channel_2_unit_label_rate = lv_label_create(channel_2_unit_bg_rate);
	lv_obj_remove_style_all(channel_2_unit_label_rate);

	lv_label_set_text(channel_2_unit_label_rate, "ml/min");
	lv_obj_align(channel_2_unit_label_rate, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_2_unit_label_rate, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_2_unit_label_rate, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_2_unit_label_rate, &lv_font_montserrat_14, 0);
}


/* =========================================
 *    Target block
 * ========================================= */

static void target_block_create(void)
{
	/* =========================================
	 *    TARGET
	 * ========================================= */

	/* CHANNEL STATES BLOCK BACKGROUND -------------------------------------------*/
	channels_target_params_block = lv_obj_create(screen);
	lv_obj_remove_style_all(channels_target_params_block);

	lv_obj_set_size(channels_target_params_block, 314, 74);
	lv_obj_set_pos(channels_target_params_block, 3, 85);
	lv_obj_set_style_bg_color(channels_target_params_block, lv_color_hex(MAIN_GREY), 0);
	lv_obj_set_style_bg_opa(channels_target_params_block, LV_OPA_COVER, 0);

	/* CHANNEL 1 BLOCK TITLE BACKGROUND -------------------------------------------*/
	channel_1_block_title_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_1_block_title_bg_target);

	lv_obj_set_size(channel_1_block_title_bg_target, 104, 68);
	lv_obj_set_pos(channel_1_block_title_bg_target, 5, 88);
	lv_obj_set_style_bg_color(channel_1_block_title_bg_target, lv_color_hex(BLUE), 0);
	lv_obj_set_style_bg_opa(channel_1_block_title_bg_target, LV_OPA_COVER, 0);
	lv_obj_set_style_border_width(channel_1_block_title_bg_target, 3, 0);
	lv_obj_set_style_border_color(channel_1_block_title_bg_target, lv_color_black(), 0);

	/* CHANNEL 1 BLOCK TITLE LABEL ------------------------------------------------*/
	channel_1_block_title_label_target = lv_label_create(channel_1_block_title_bg_target);
	lv_obj_remove_style_all(channel_1_block_title_label_target);

	lv_label_set_text(channel_1_block_title_label_target, "TARGET");
	lv_obj_align(channel_1_block_title_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_1_block_title_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_1_block_title_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_1_block_title_label_target, &lv_font_montserrat_22, 0);

	/* CHANNEL 1 TITLE BACKGROUND ------------------------------------------------*/
	channel_1_title_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_1_title_bg_target);

	lv_obj_set_size(channel_1_title_bg_target, 51, 33);
	lv_obj_set_pos(channel_1_title_bg_target, 111, 88);
	lv_obj_set_style_bg_color(channel_1_title_bg_target, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_1_title_bg_target, LV_OPA_COVER, 0);

	/* CHANNEL 1 TITLE LABEL -----------------------------------------------------*/
	channel_1_title_label_target = lv_label_create(channel_1_title_bg_target);
	lv_obj_remove_style_all(channel_1_title_label_target);

	lv_label_set_text(channel_1_title_label_target, "CH1");
	lv_obj_align(channel_1_title_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_1_title_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_1_title_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_1_title_label_target, &lv_font_montserrat_14, 0);

	/* CHANNEL 1 TARGET MODE BACKGROUND ------------------------------------------*/
	channel_1_target_mode_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_1_target_mode_bg_target);

	lv_obj_set_size(channel_1_target_mode_bg_target, 46, 33);
	lv_obj_set_pos(channel_1_target_mode_bg_target, 164, 88);
	lv_obj_set_style_bg_color(channel_1_target_mode_bg_target, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_1_target_mode_bg_target, LV_OPA_COVER, 0);

	/* CHANNEL 1 TARGET MODE LABEL -----------------------------------------------*/
	channel_1_target_mode_label_target = lv_label_create(channel_1_target_mode_bg_target);
	lv_obj_remove_style_all(channel_1_target_mode_label_target);

	lv_label_set_text(channel_1_target_mode_label_target, "Vol.");
	lv_obj_align(channel_1_target_mode_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_1_target_mode_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_1_target_mode_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_1_target_mode_label_target, &lv_font_montserrat_14, 0);

	/* CHANNEL 1 FLOW BACKGROUND -------------------------------------------------*/
	channel_1_flow_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_1_flow_bg_target);

	lv_obj_set_size(channel_1_flow_bg_target, 68, 33);
	lv_obj_set_pos(channel_1_flow_bg_target, 212, 88);
	lv_obj_set_style_bg_color(channel_1_flow_bg_target, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_1_flow_bg_target, LV_OPA_COVER, 0);

	/* CHANNEL 1 FLOW LABEL ------------------------------------------------------*/
	channel_1_flow_label_target = lv_label_create(channel_1_flow_bg_target);
	lv_obj_remove_style_all(channel_1_flow_label_target);

	lv_label_set_text(channel_1_flow_label_target, "0.0");
	lv_obj_align(channel_1_flow_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_1_flow_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_1_flow_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_1_flow_label_target, &lv_font_montserrat_14, 0);

	/* CHANNEL 1 UNIT BACKGROUND -------------------------------------------------*/
	channel_1_unit_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_1_unit_bg_target);

	lv_obj_set_size(channel_1_unit_bg_target, 33, 33);
	lv_obj_set_pos(channel_1_unit_bg_target, 282, 88);
	lv_obj_set_style_bg_color(channel_1_unit_bg_target, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_1_unit_bg_target, LV_OPA_COVER, 0);

	/* CHANNEL 1 UNIT LABEL ------------------------------------------------------*/
	channel_1_unit_label_target = lv_label_create(channel_1_unit_bg_target);
	lv_obj_remove_style_all(channel_1_unit_label_target);

	lv_label_set_text(channel_1_unit_label_target, "ml");
	lv_obj_align(channel_1_unit_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_1_unit_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_1_unit_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_1_unit_label_target, &lv_font_montserrat_14, 0);



	/* CHANNEL 2 TITLE BACKGROUND ------------------------------------------------*/
	channel_2_title_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_2_title_bg_target);

	lv_obj_set_size(channel_2_title_bg_target, 51, 33);
	lv_obj_set_pos(channel_2_title_bg_target, 111, 123);
	lv_obj_set_style_bg_color(channel_2_title_bg_target, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_2_title_bg_target, LV_OPA_COVER, 0);

	/* CHANNEL 2 TITLE LABEL -----------------------------------------------------*/
	channel_2_title_label_target = lv_label_create(channel_2_title_bg_target);
	lv_obj_remove_style_all(channel_2_title_label_target);

	lv_label_set_text(channel_2_title_label_target, "CH2");
	lv_obj_align(channel_2_title_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_2_title_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_2_title_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_2_title_label_target, &lv_font_montserrat_14, 0);

	/* CHANNEL 2 TARGET MODE BACKGROUND ------------------------------------------*/
	channel_2_target_mode_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_2_target_mode_bg_target);

	lv_obj_set_size(channel_2_target_mode_bg_target, 46, 33);
	lv_obj_set_pos(channel_2_target_mode_bg_target, 164, 123);
	lv_obj_set_style_bg_color(channel_2_target_mode_bg_target, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_2_target_mode_bg_target, LV_OPA_COVER, 0);

	/* CHANNEL 2 TARGET MODE LABEL -----------------------------------------------*/
	channel_2_target_mode_label_target = lv_label_create(channel_2_target_mode_bg_target);
	lv_obj_remove_style_all(channel_2_target_mode_label_target);

	lv_label_set_text(channel_2_target_mode_label_target, "Time");
	lv_obj_align(channel_2_target_mode_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_2_target_mode_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_2_target_mode_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_2_target_mode_label_target, &lv_font_montserrat_14, 0);


	/* CHANNEL 2 FLOW BACKGROUND -------------------------------------------------*/
	channel_2_flow_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_2_flow_bg_target);

	lv_obj_set_size(channel_2_flow_bg_target, 68, 33);
	lv_obj_set_pos(channel_2_flow_bg_target, 212, 123);
	lv_obj_set_style_bg_color(channel_2_flow_bg_target, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_2_flow_bg_target, LV_OPA_COVER, 0);

	/* CHANNEL 1 FLOW LABEL ------------------------------------------------------*/
	channel_2_flow_label_target = lv_label_create(channel_2_flow_bg_target);
	lv_obj_remove_style_all(channel_2_flow_label_target);

	lv_label_set_text(channel_2_flow_label_target, "0.0");
	lv_obj_align(channel_2_flow_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_2_flow_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_2_flow_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_2_flow_label_target, &lv_font_montserrat_14, 0);

	/* CHANNEL 2 UNIT BACKGROUND -------------------------------------------------*/
	channel_2_unit_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(channel_2_unit_bg_target);

	lv_obj_set_size(channel_2_unit_bg_target, 33, 33);
	lv_obj_set_pos(channel_2_unit_bg_target, 282, 123);
	lv_obj_set_style_bg_color(channel_2_unit_bg_target, lv_color_black(), 0);
	lv_obj_set_style_bg_opa(channel_2_unit_bg_target, LV_OPA_COVER, 0);

	/* CHANNEL 2 UNIT LABEL ------------------------------------------------------*/
	channel_2_unit_label_target = lv_label_create(channel_2_unit_bg_target);
	lv_obj_remove_style_all(channel_2_unit_label_target);

	lv_label_set_text(channel_2_unit_label_target, "sec");
	lv_obj_align(channel_2_unit_label_target, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_text_color(channel_2_unit_label_target, lv_color_white(), 0);
	lv_obj_set_style_text_opa(channel_2_unit_label_target, LV_OPA_COVER, 0);
	lv_obj_set_style_text_font(channel_2_unit_label_target, &lv_font_montserrat_14, 0);
}


void ui_update_mode_label(const char * mode_name)
{
	// Check if mode_state_label obj has been initialized
    if(mode_state_label != NULL)
    {
        lv_label_set_text(mode_state_label, mode_name); // Change the text
    }
}










