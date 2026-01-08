/*
 ******************************************************************************
 * @file           : main_screen.h
 * @brief          : Main screen creation, stylization and load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */



/* Private includes ----------------------------------------------------------*/
#include "screens/main_screen.h"

#include <string.h>

#include "styles/colors.h"
#include "styles/styles.h"
#include "system/type_definitions.h"

// Screens
#include "screens/settings_screen.h"

/* Private variables ---------------------------------------------------------*/

// Screen
static lv_obj_t * screen;

/* =========================================
 *    Mode/Rate block
 * ========================================= */

// Mode block
static lv_obj_t * mode_block_bg,
				* mode_title_bg, * mode_title_label,
				* mode_state_bg, * mode_state_label;

// Rate block
static lv_obj_t * channels_rate_params_block_bg,

				* ch1_name_bg_rate,   * ch1_name_label_rate,
				* ch1_value_bg_rate,  * ch1_value_label_rate,
				* ch1_unit_bg_rate,   * ch1_unit_label_rate,

				* ch2_name_bg_rate,   * ch2_name_label_rate,
				* ch2_value_bg_rate,  * ch2_value_label_rate,
				* ch2_unit_bg_rate,   * ch2_unit_label_rate;

/* =========================================
 *    Target block
 * ========================================= */

// Target block
static lv_obj_t * channels_target_params_block,

				* target_title_bg, * target_title_label,

				* ch1_name_bg_target,   * ch1_name_label_target,
				* ch1_mode_bg_target,   * ch1_mode_label_target,
				* ch1_value_bg_target,  * ch1_value_label_target,
				* ch1_unit_bg_target,   * ch1_unit_label_target,

				* ch2_name_bg_target,   * ch2_name_label_target,
				* ch2_mode_bg_target,   * ch2_mode_label_target,
				* ch2_value_bg_target,  * ch2_value_label_target,
				* ch2_unit_bg_target,   * ch2_unit_label_target;

/* =========================================
 *    Settings block
 * ========================================= */

// Target block
static lv_obj_t * settings_btn, * settings_btn_icon,

				* ch1_name_bg_settings,   * ch1_name_label_settings,
				* ch1_run_btn,            * ch1_run_btn_icon,
				* ch1_back_btn,           * ch1_back_btn_icon,
				* ch1_forward_btn,        * ch1_forward_btn_icon,

				* ch2_name_bg_settings,   * ch2_name_label_settings,
				* ch2_run_btn,            * ch2_run_btn_icon,
				* ch2_back_btn,           * ch2_back_btn_icon,
				* ch2_forward_btn,        * ch2_forward_btn_icon;



/* Private function prototypes -----------------------------------------------*/
static void mode_block_create(void);
static void target_block_create(void);
static void settings_block_create(void);

// Button callbacks
static void settings_btn_event_cb(lv_event_t * e);
static void ch1_run_btn_event_cb(lv_event_t * e);
static void ch1_back_btn_event_cb(lv_event_t * e);
static void ch1_forward_btn_event_cb(lv_event_t * e);
static void ch2_run_btn_event_cb(lv_event_t * e);
static void ch2_back_btn_event_cb(lv_event_t * e);
static void ch2_forward_btn_event_cb(lv_event_t * e);



void main_screen_create(void)
{
	screen = lv_obj_create(NULL);

	mode_block_create();     // Mode/Rate block
	target_block_create();   // Target block
	settings_block_create(); // Settings block
}


void main_screen_load(void)
{
	lv_screen_load(screen);
}


/* BLOCKS CREATE FUNCTIONS -------------------------------------------------------*/

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
	lv_obj_add_style(mode_block_bg, &panel_block_bg_style, 0);

	lv_obj_set_size(mode_block_bg, 86, 77);
	lv_obj_set_pos(mode_block_bg, 3, 4);


	/* MODE TITLE BACKGROUND -----------------------------------------------------*/
	mode_title_bg = lv_obj_create(screen);

	lv_obj_remove_style_all(mode_title_bg);
	lv_obj_add_style(mode_title_bg, &panel_title_bg_style, 0);

	lv_obj_set_size(mode_title_bg, 82, 33);
	lv_obj_set_pos(mode_title_bg, 5, 8);


	/* MODE TITLE LABEL ----------------------------------------------------------*/
	mode_title_label = lv_label_create(mode_title_bg);

	lv_obj_remove_style_all(mode_title_label);
	lv_obj_add_style(mode_title_label, &panel_title_label_style, 0);
	lv_obj_set_style_text_font(mode_title_label, &lv_font_montserrat_14, 0);

	lv_label_set_text(mode_title_label, "MODE");
	lv_obj_align(mode_title_label, LV_ALIGN_CENTER, 0, 0);


	/* MODE STATE BACKGROUND -----------------------------------------------------*/
	mode_state_bg= lv_obj_create(screen);

	lv_obj_remove_style_all(mode_state_bg);
	lv_obj_add_style(mode_state_bg, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(mode_state_bg, 82, 33);
	lv_obj_set_pos(mode_state_bg, 5, 44);


	/* MODE STATE LABEL ----------------------------------------------------------*/
	mode_state_label = lv_label_create(mode_state_bg);

	lv_obj_remove_style_all(mode_state_label);
	lv_obj_add_style(mode_state_label, &panel_title_label_style, 0);
	lv_obj_set_style_text_font(mode_title_label, &lv_font_montserrat_14, 0);

	lv_obj_align(mode_state_label, LV_ALIGN_CENTER, 0, 0);



	/* =========================================
	 *    RATE
	 * ========================================= */

	/* CHANNEL STATES BLOCK BACKGROUND -------------------------------------------*/
	channels_rate_params_block_bg = lv_obj_create(screen);

	lv_obj_remove_style_all(channels_rate_params_block_bg);
	lv_obj_add_style(channels_rate_params_block_bg, &panel_block_bg_style, 0);

	lv_obj_set_size(channels_rate_params_block_bg, 225, 77);
	lv_obj_set_pos(channels_rate_params_block_bg, 92, 4);


	/* CHANNEL 1 NAME BACKGROUND -------------------------------------------------*/
	ch1_name_bg_rate = lv_obj_create(screen);

	lv_obj_remove_style_all(ch1_name_bg_rate);
	lv_obj_add_style(ch1_name_bg_rate, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch1_name_bg_rate, 50, 33);
	lv_obj_set_pos(ch1_name_bg_rate, 94, 8);


	/* CHANNEL 1 NAME LABEL ------------------------------------------------------*/
	ch1_name_label_rate = lv_label_create(ch1_name_bg_rate);

	lv_obj_remove_style_all(ch1_name_label_rate);
	lv_obj_add_style(ch1_name_label_rate, &panel_channel_param_label_style, 0);

	lv_label_set_text(ch1_name_label_rate, "CH1");

	lv_obj_align(ch1_name_label_rate, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 1 VALUE BACKGROUND ------------------------------------------------*/
	ch1_value_bg_rate = lv_obj_create(screen);
	lv_obj_remove_style_all(ch1_value_bg_rate);
	lv_obj_add_style(ch1_value_bg_rate, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch1_value_bg_rate, 84, 33);
	lv_obj_set_pos(ch1_value_bg_rate, 147, 8);


	/* CHANNEL 1 VALUE LABEL -----------------------------------------------------*/
	ch1_value_label_rate = lv_label_create(ch1_value_bg_rate);

	lv_obj_remove_style_all(ch1_value_label_rate);
	lv_obj_add_style(ch1_value_label_rate, &panel_channel_param_label_style, 0);

	lv_obj_align(ch1_value_label_rate, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 1 UNIT BACKGROUND -------------------------------------------------*/
	ch1_unit_bg_rate = lv_obj_create(screen);

	lv_obj_remove_style_all(ch1_unit_bg_rate);
	lv_obj_add_style(ch1_unit_bg_rate, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch1_unit_bg_rate, 81, 33);
	lv_obj_set_pos(ch1_unit_bg_rate, 234, 8);


	/* CHANNEL 1 UNIT LABEL ------------------------------------------------------*/
	ch1_unit_label_rate = lv_label_create(ch1_unit_bg_rate);

	lv_obj_remove_style_all(ch1_unit_label_rate);
	lv_obj_add_style(ch1_unit_label_rate, &panel_channel_param_label_style, 0);

	lv_obj_align(ch1_unit_label_rate, LV_ALIGN_CENTER, 0, 0);




	/* CHANNEL 2 NAME BACKGROUND -------------------------------------------------*/
	ch2_name_bg_rate = lv_obj_create(screen);

	lv_obj_remove_style_all(ch2_name_bg_rate);
	lv_obj_add_style(ch2_name_bg_rate, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch2_name_bg_rate, 50, 33);
	lv_obj_set_pos(ch2_name_bg_rate, 94, 44);


	/* CHANNEL 2 NAME LABEL ------------------------------------------------------*/
	ch2_name_label_rate = lv_label_create(ch2_name_bg_rate);

	lv_obj_remove_style_all(ch2_name_label_rate);
	lv_obj_add_style(ch2_name_label_rate, &panel_channel_param_label_style, 0);

	lv_label_set_text(ch2_name_label_rate, "CH2");

	lv_obj_align(ch2_name_label_rate, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 2 VALUE BACKGROUND ------------------------------------------------*/
	ch2_value_bg_rate = lv_obj_create(screen);

	lv_obj_remove_style_all(ch2_value_bg_rate);
	lv_obj_add_style(ch2_value_bg_rate, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch2_value_bg_rate, 84, 33);
	lv_obj_set_pos(ch2_value_bg_rate, 147, 44);


	/* CHANNEL 1 VALUE LABEL -----------------------------------------------------*/
	ch2_value_label_rate = lv_label_create(ch2_value_bg_rate);
	lv_obj_remove_style_all(ch2_value_label_rate);
	lv_obj_add_style(ch2_value_label_rate, &panel_channel_param_label_style, 0);

	lv_obj_align(ch2_value_label_rate, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 2 UNIT BACKGROUND -------------------------------------------------*/
	ch2_unit_bg_rate = lv_obj_create(screen);
	lv_obj_remove_style_all(ch2_unit_bg_rate);
	lv_obj_add_style(ch2_unit_bg_rate, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch2_unit_bg_rate, 81, 33);
	lv_obj_set_pos(ch2_unit_bg_rate, 234, 44);


	/* CHANNEL 2 UNIT LABEL ------------------------------------------------------*/
	ch2_unit_label_rate = lv_label_create(ch2_unit_bg_rate);

	lv_obj_remove_style_all(ch2_unit_label_rate);
	lv_obj_add_style(ch2_unit_label_rate, &panel_channel_param_label_style, 0);

	lv_obj_align(ch2_unit_label_rate, LV_ALIGN_CENTER, 0, 0);
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
	lv_obj_add_style(channels_target_params_block, &panel_block_bg_style, 0);

	lv_obj_set_size(channels_target_params_block, 314, 74);
	lv_obj_set_pos(channels_target_params_block, 3, 85);


	/* CHANNEL 1 BLOCK TITLE BACKGROUND -------------------------------------------*/
	target_title_bg = lv_obj_create(screen);

	lv_obj_remove_style_all(target_title_bg);
	lv_obj_add_style(target_title_bg, &panel_title_bg_style, 0);

	lv_obj_set_size(target_title_bg, 104, 68);
	lv_obj_set_pos(target_title_bg, 5, 88);


	/* CHANNEL 1 BLOCK TITLE LABEL ------------------------------------------------*/
	target_title_label = lv_label_create(target_title_bg);

	lv_obj_remove_style_all(target_title_label);
	lv_obj_add_style(target_title_label, &panel_title_label_style, 0);

	lv_label_set_text(target_title_label, "TARGET");
	lv_obj_set_style_text_font(target_title_label, &lv_font_montserrat_22, 0);

	lv_obj_align(target_title_label, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 1 TITLE BACKGROUND ------------------------------------------------*/
	ch1_name_bg_target = lv_obj_create(screen);

	lv_obj_remove_style_all(ch1_name_bg_target);
	lv_obj_add_style(ch1_name_bg_target, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch1_name_bg_target, 51, 33);
	lv_obj_set_pos(ch1_name_bg_target, 111, 88);


	/* CHANNEL 1 TITLE LABEL -----------------------------------------------------*/
	ch1_name_label_target = lv_label_create(ch1_name_bg_target);

	lv_obj_remove_style_all(ch1_name_label_target);
	lv_obj_add_style(ch1_name_label_target, &panel_channel_param_label_style, 0);

	lv_label_set_text(ch1_name_label_target, "CH1");
	lv_obj_align(ch1_name_label_target, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 1 TARGET MODE BACKGROUND ------------------------------------------*/
	ch1_mode_bg_target = lv_obj_create(screen);
	lv_obj_remove_style_all(ch1_mode_bg_target);
	lv_obj_add_style(ch1_mode_bg_target, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch1_mode_bg_target, 46, 33);
	lv_obj_set_pos(ch1_mode_bg_target, 164, 88);


	/* CHANNEL 1 TARGET MODE LABEL -----------------------------------------------*/
	ch1_mode_label_target = lv_label_create(ch1_mode_bg_target);

	lv_obj_remove_style_all(ch1_mode_label_target);
	lv_obj_add_style(ch1_mode_label_target, &panel_channel_param_label_style, 0);

	lv_obj_align(ch1_mode_label_target, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 1 FLOW BACKGROUND -------------------------------------------------*/
	ch1_value_bg_target = lv_obj_create(screen);

	lv_obj_remove_style_all(ch1_value_bg_target);
	lv_obj_add_style(ch1_value_bg_target, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch1_value_bg_target, 68, 33);
	lv_obj_set_pos(ch1_value_bg_target, 212, 88);


	/* CHANNEL 1 FLOW LABEL ------------------------------------------------------*/
	ch1_value_label_target = lv_label_create(ch1_value_bg_target);

	lv_obj_remove_style_all(ch1_value_label_target);
	lv_obj_add_style(ch1_value_label_target, &panel_channel_param_label_style, 0);

	lv_obj_align(ch1_value_label_target, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 1 UNIT BACKGROUND -------------------------------------------------*/
	ch1_unit_bg_target = lv_obj_create(screen);

	lv_obj_remove_style_all(ch1_unit_bg_target);
	lv_obj_add_style(ch1_unit_bg_target, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch1_unit_bg_target, 33, 33);
	lv_obj_set_pos(ch1_unit_bg_target, 282, 88);


	/* CHANNEL 1 UNIT LABEL ------------------------------------------------------*/
	ch1_unit_label_target = lv_label_create(ch1_unit_bg_target);

	lv_obj_remove_style_all(ch1_unit_label_target);
	lv_obj_add_style(ch1_unit_label_target, &panel_channel_param_label_style, 0);

	lv_obj_align(ch1_unit_label_target, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 2 TITLE BACKGROUND ------------------------------------------------*/
	ch2_name_bg_target = lv_obj_create(screen);

	lv_obj_remove_style_all(ch2_name_bg_target);
	lv_obj_add_style(ch2_name_bg_target, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch2_name_bg_target, 51, 33);
	lv_obj_set_pos(ch2_name_bg_target, 111, 123);


	/* CHANNEL 2 TITLE LABEL ----------------------------------------------------	*/
	ch2_name_label_target = lv_label_create(ch2_name_bg_target);

	lv_obj_remove_style_all(ch2_name_label_target);
	lv_obj_add_style(ch2_name_label_target, &panel_channel_param_label_style, 0);

	lv_label_set_text(ch2_name_label_target, "CH2");
	lv_obj_align(ch2_name_label_target, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 2 TARGET MODE BACKGROUND ------------------------------------------*/
	ch2_mode_bg_target = lv_obj_create(screen);

	lv_obj_remove_style_all(ch2_mode_bg_target);
	lv_obj_add_style(ch2_mode_bg_target, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch2_mode_bg_target, 46, 33);
	lv_obj_set_pos(ch2_mode_bg_target, 164, 123);


	/* CHANNEL 2 TARGET MODE LABEL -----------------------------------------------*/
	ch2_mode_label_target = lv_label_create(ch2_mode_bg_target);

	lv_obj_remove_style_all(ch2_mode_label_target);
	lv_obj_add_style(ch2_mode_label_target, &panel_channel_param_label_style, 0);

	lv_obj_align(ch2_mode_label_target, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 2 FLOW BACKGROUND -------------------------------------------------*/
	ch2_value_bg_target = lv_obj_create(screen);

	lv_obj_remove_style_all(ch2_value_bg_target);
	lv_obj_add_style(ch2_value_bg_target, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch2_value_bg_target, 68, 33);
	lv_obj_set_pos(ch2_value_bg_target, 212, 123);


	/* CHANNEL 2 FLOW LABEL ------------------------------------------------------*/
	ch2_value_label_target = lv_label_create(ch2_value_bg_target);

	lv_obj_remove_style_all(ch2_value_label_target);
	lv_obj_add_style(ch2_value_label_target, &panel_channel_param_label_style, 0);

	lv_obj_align(ch2_value_label_target, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 2 UNIT BACKGROUND -------------------------------------------------*/
	ch2_unit_bg_target = lv_obj_create(screen);

	lv_obj_remove_style_all(ch2_unit_bg_target);
	lv_obj_add_style(ch2_unit_bg_target, &panel_channel_param_bg_style, 0);

	lv_obj_set_size(ch2_unit_bg_target, 33, 33);
	lv_obj_set_pos(ch2_unit_bg_target, 282, 123);


	/* CHANNEL 2 UNIT LABEL ------------------------------------------------------*/
	ch2_unit_label_target = lv_label_create(ch2_unit_bg_target);

	lv_obj_remove_style_all(ch2_unit_label_target);
	lv_obj_add_style(ch2_unit_label_target, &panel_channel_param_label_style, 0);

	lv_obj_align(ch2_unit_label_target, LV_ALIGN_CENTER, 0, 0);

}


/* =========================================
 *    Settings block
 * ========================================= */

static void settings_block_create(void)
{
	/* =========================================
	 *    Settings button
	 * ========================================= */

	/* SETTINGS BUTTON BACKGROUND ------------------------------------------------*/
	settings_btn = lv_button_create(screen);
	lv_obj_add_style(settings_btn, &blue_btn_bg_style, 0);

	lv_obj_set_size(settings_btn, 93, 71);
	lv_obj_set_pos(settings_btn, 5, 165);

	lv_obj_add_event_cb(settings_btn, settings_btn_event_cb, LV_EVENT_CLICKED, NULL); // Add callback

	/* SETTING BUTTON ICON BACKGROUND --------------------------------------------*/
    settings_btn_icon = lv_label_create(settings_btn);
    lv_obj_add_style(settings_btn_icon, &settings_btn_icon_style, 0);

	lv_label_set_text(settings_btn_icon, LV_SYMBOL_SETTINGS);

    lv_obj_center(settings_btn_icon);


	/* =========================================
	 *    CH1 buttons
	 * ========================================= */

    /* CHANNEL 1 NAME BACKGROUND -------------------------------------------------*/
    ch1_name_bg_settings = lv_obj_create(screen);

    lv_obj_remove_style_all(ch1_name_bg_settings);
    lv_obj_add_style(ch1_name_bg_settings, &settings_panel_bg_style, 0);

	lv_obj_set_size(ch1_name_bg_settings, 100, 11);
	lv_obj_set_pos(ch1_name_bg_settings, 105, 165);


	/* CHANNEL 1 NAME LABEL ------------------------------------------------------*/
	ch1_name_label_settings = lv_label_create(ch1_name_bg_settings);

	lv_obj_remove_style_all(ch1_name_label_settings);
	lv_obj_add_style(ch1_name_label_settings, &settings_panel_label_style, 0);

	lv_label_set_text(ch1_name_label_settings, "CH1");

	lv_obj_align(ch1_name_label_settings, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 1 RUN BUTTON BACKGROUND -------------------------------------------*/
	ch1_run_btn = lv_button_create(screen);
	lv_obj_add_style(ch1_run_btn, &red_btn_bg_style, 0);

	lv_obj_set_size(ch1_run_btn, 100, 26);
	lv_obj_set_pos(ch1_run_btn, 105, 178);

	lv_obj_add_event_cb(ch1_run_btn, ch1_run_btn_event_cb, LV_EVENT_CLICKED, NULL); // Add callback


	/* CHANNEL 1 RUN BUTTON ICON -------------------------------------------------*/
	ch1_run_btn_icon = lv_label_create(ch1_run_btn);
    lv_obj_add_style(ch1_run_btn_icon, &general_btn_icon_style, 0);

    lv_obj_center(ch1_run_btn_icon);


	/* CHANNEL 1 BACK BUTTON BACKGROUND ------------------------------------------*/
    ch1_back_btn = lv_button_create(screen);
	lv_obj_add_style(ch1_back_btn, &green_btn_bg_style, 0);

	lv_obj_set_size(ch1_back_btn, 46, 30);
	lv_obj_set_pos(ch1_back_btn, 105, 206);

	lv_obj_add_event_cb(ch1_back_btn, ch1_back_btn_event_cb, LV_EVENT_CLICKED, NULL); // Add callback


	/* CHANNEL 1 BACK BUTTON ICON ------------------------------------------------*/
	ch1_back_btn_icon = lv_label_create(ch1_back_btn);
	lv_obj_add_style(ch1_back_btn_icon, &general_btn_icon_style, 0);

	lv_label_set_text(ch1_back_btn_icon, LV_SYMBOL_PREV);

	lv_obj_center(ch1_back_btn_icon);


	/* CHANNEL 1 FORWARD BUTTON BACKGROUND ---------------------------------------*/
	ch1_forward_btn = lv_button_create(screen);
	lv_obj_add_style(ch1_forward_btn, &green_btn_bg_style, 0);

	lv_obj_set_size(ch1_forward_btn, 46, 30);
	lv_obj_set_pos(ch1_forward_btn, 159, 206);

	lv_obj_add_event_cb(ch1_forward_btn, ch1_forward_btn_event_cb, LV_EVENT_CLICKED, NULL); // Add callback


	/* CHANNEL 1 FORWARD BUTTON ICON ---------------------------------------------*/
	ch1_forward_btn_icon = lv_label_create(ch1_forward_btn);
	lv_obj_add_style(ch1_forward_btn_icon, &general_btn_icon_style, 0);

	lv_label_set_text(ch1_forward_btn_icon, LV_SYMBOL_NEXT);

	lv_obj_center(ch1_forward_btn_icon);



	/* =========================================
	 *    CH2 buttons
	 * ========================================= */

	/* CHANNEL 2 NAME BACKGROUND -------------------------------------------------*/
	ch2_name_bg_settings = lv_obj_create(screen);

	lv_obj_remove_style_all(ch2_name_bg_settings);
	lv_obj_add_style(ch2_name_bg_settings, &settings_panel_bg_style, 0);

	lv_obj_set_size(ch2_name_bg_settings, 100, 11);
	lv_obj_set_pos(ch2_name_bg_settings, 215, 165);


	/* CHANNEL 2 NAME LABEL ------------------------------------------------------*/
	ch2_name_label_settings = lv_label_create(ch2_name_bg_settings);

	lv_obj_remove_style_all(ch2_name_label_settings);
	lv_obj_add_style(ch2_name_label_settings, &settings_panel_label_style, 0);

	lv_label_set_text(ch2_name_label_settings, "CH2");

	lv_obj_align(ch2_name_label_settings, LV_ALIGN_CENTER, 0, 0);


	/* CHANNEL 2 RUN BUTTON BACKGROUND -------------------------------------------*/
	ch2_run_btn = lv_button_create(screen);
	lv_obj_add_style(ch2_run_btn, &red_btn_bg_style, 0);

	lv_obj_set_size(ch2_run_btn, 100, 26);
	lv_obj_set_pos(ch2_run_btn, 215, 178);

	lv_obj_add_event_cb(ch2_run_btn, ch2_run_btn_event_cb, LV_EVENT_CLICKED, NULL); // Add callback


	/* CHANNEL 2 RUN BUTTON ICON -------------------------------------------------*/
	ch2_run_btn_icon = lv_label_create(ch2_run_btn);
	lv_obj_add_style(ch2_run_btn_icon, &general_btn_icon_style, 0);

	lv_obj_center(ch2_run_btn_icon);


	/* CHANNEL 2 BACK BUTTON BACKGROUND ------------------------------------------*/
	ch2_back_btn = lv_button_create(screen);
	lv_obj_add_style(ch2_back_btn, &green_btn_bg_style, 0);

	lv_obj_set_size(ch2_back_btn, 46, 30);
	lv_obj_set_pos(ch2_back_btn, 215, 206);

	lv_obj_add_event_cb(ch2_back_btn, ch2_back_btn_event_cb, LV_EVENT_CLICKED, NULL); // Add callback


	/* CHANNEL 2 BACK BUTTON ICON ------------------------------------------------*/
	ch2_back_btn_icon = lv_label_create(ch2_back_btn);
	lv_obj_add_style(ch2_back_btn_icon, &general_btn_icon_style, 0);

	lv_label_set_text(ch2_back_btn_icon, LV_SYMBOL_PREV);

	lv_obj_center(ch2_back_btn_icon);


	/* CHANNEL 2 FORWARD BUTTON BACKGROUND ---------------------------------------*/
	ch2_forward_btn = lv_button_create(screen);
	lv_obj_add_style(ch2_forward_btn, &green_btn_bg_style, 0);

	lv_obj_set_size(ch2_forward_btn, 46, 30);
	lv_obj_set_pos(ch2_forward_btn, 268, 206);

	lv_obj_add_event_cb(ch2_forward_btn, ch2_forward_btn_event_cb, LV_EVENT_CLICKED, NULL); // Add callback


	/* CHANNEL 2 FORWARD BUTTON ICON ---------------------------------------------*/
	ch2_forward_btn_icon = lv_label_create(ch2_forward_btn);
	lv_obj_add_style(ch2_forward_btn_icon, &general_btn_icon_style, 0);

	lv_label_set_text(ch2_forward_btn_icon, LV_SYMBOL_NEXT);
	lv_obj_center(ch2_forward_btn_icon);
}





/* EVENT CALLBACK FUNCTIONS ------------------------------------------------------*/

static void settings_btn_event_cb(lv_event_t * e)
{
	settings_screen_load();
}

static void ch1_run_btn_event_cb(lv_event_t * e)
{
	lv_obj_set_style_bg_color(lv_screen_active(), lv_palette_main(LV_PALETTE_YELLOW), 0);
}

static void ch1_back_btn_event_cb(lv_event_t * e)
{
	lv_obj_set_style_bg_color(lv_screen_active(), lv_palette_main(LV_PALETTE_PINK), 0);
}

static void ch1_forward_btn_event_cb(lv_event_t * e)
{
	lv_obj_set_style_bg_color(lv_screen_active(), lv_palette_main(LV_PALETTE_ORANGE), 0);
}

static void ch2_run_btn_event_cb(lv_event_t * e)
{
	lv_obj_set_style_bg_color(lv_screen_active(), lv_palette_main(LV_PALETTE_PURPLE), 0);
}

static void ch2_back_btn_event_cb(lv_event_t * e)
{
	lv_obj_set_style_bg_color(lv_screen_active(), lv_palette_main(LV_PALETTE_BROWN), 0);
}

static void ch2_forward_btn_event_cb(lv_event_t * e)
{
	lv_obj_set_style_bg_color(lv_screen_active(), lv_palette_main(LV_PALETTE_GREY), 0);
}





/* SETTERS FUNCTIONS ------------------------------------------------------------*/

/* =========================================
 *    Mode/Rate block
 * ========================================= */

void ui_update_mode_state_label(const char * mode_name)
{
    if(mode_state_label != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(mode_state_label, mode_name); // Change the text
    }
}


void ui_update_ch1_value_label_rate(const char * flow)
{
    if(ch1_value_label_rate != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch1_value_label_rate, flow); // Change the text
    }
}

void ui_update_ch1_unit_label_rate(const char * unit)
{
    if(ch1_unit_label_rate != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch1_unit_label_rate, unit); // Change the text
    }
}


void ui_update_ch2_value_label_rate(const char * flow)
{
    if(ch2_value_label_rate != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch2_value_label_rate, flow); // Change the text
    }
}

void ui_update_ch2_unit_label_rate(const char * unit)
{
    if(ch2_unit_label_rate != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch2_unit_label_rate, unit); // Change the text
    }
}


/* =========================================
 *    Target block
 * ========================================= */

void ui_update_ch1_mode_label_target(const char * mode_name)
{
    if(ch1_mode_label_target != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch1_mode_label_target, mode_name); // Change the text
    }
}


void ui_update_ch1_value_label_target(const char * flow)
{
    if(ch1_value_label_target != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch1_value_label_target, flow); // Change the text
    }
}

void ui_update_ch1_unit_label_target(const char * unit)
{
    if(ch1_unit_label_target != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch1_unit_label_target, unit); // Change the text
    }
}

void ui_update_ch2_mode_label_target(const char * mode_name)
{
    if(ch2_mode_label_target != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch2_mode_label_target, mode_name); // Change the text
    }
}


void ui_update_ch2_value_label_target(const char * flow)
{
    if(ch2_value_label_target != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch2_value_label_target, flow); // Change the text
    }
}

void ui_update_ch2_unit_label_target(const char * unit)
{
    if(ch2_unit_label_target != NULL) // Check if mode_state_label obj has been initialized
    {
        lv_label_set_text(ch2_unit_label_target, unit); // Change the text
    }
}


/* =========================================
 *    Settings block
 * ========================================= */

void ui_update_ch1_run_btn_icon_settings(int state)
{
	if(ch1_run_btn == NULL || ch1_run_btn_icon == NULL)
		return;

	switch(state)
	{
		case CHANNEL_STATE__RUNNING:
			lv_label_set_text(ch1_run_btn_icon, LV_SYMBOL_PAUSE);
			break;

		case CHANNEL_STATE__STOPPED:
			default:
				lv_label_set_text(ch1_run_btn_icon, LV_SYMBOL_PLAY);

	}
}

void ui_update_ch2_run_btn_icon_settings(int state)
{
	if(ch2_run_btn == NULL || ch2_run_btn_icon == NULL)
		return;

	switch(state)
	{
		case CHANNEL_STATE__RUNNING:
			lv_label_set_text(ch2_run_btn_icon, LV_SYMBOL_PAUSE);
			break;

		case CHANNEL_STATE__STOPPED:
			default:
				lv_label_set_text(ch2_run_btn_icon, LV_SYMBOL_PLAY);

	}
}








