/*
 ******************************************************************************
 * @file           : settings_screen.c
 * @brief          : Settings screen creation, stylization and load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */


/* Private includes ----------------------------------------------------------*/
#include "screens/settings_screen.h"

// Screens
#include "screens/main_screen.h"
#include "screens/select_channel_screen.h"

// Styles
#include "styles/styles.h"

// Panels
#include "screens/panels/title_panel.h"

// Buttons
#include "screens/buttons/back_btn.h"

// Type definitions
#include "system/type_definitions.h"


/* Private variables ---------------------------------------------------------*/
static lv_obj_t * screen;

// Page title panel
static title_panel_t title;

// Option buttons
static lv_obj_t * set_unit_btn_bg,         * set_unit_btn_label,
			    * set_target_btn_bg,       * set_target_btn_label,
			    * set_flow_rate_btn_bg,    * set_flow_rate_btn_label;


/* Private function prototypes -----------------------------------------------*/
static void set_unit_event_cb(lv_event_t * e);
static void set_target_event_cb(lv_event_t * e);
static void set_flow_rate_event_cb(lv_event_t * e);





void settings_screen_create(void)
{
	screen = lv_obj_create(NULL);

	/* =========================================
	 *    BACK BUTTON
	 * ========================================= */

	back_btn_create(screen, main_screen_load, SETTING_OPTION__NO_OPTION);


	/* =========================================
	 *    PAGE TITLE
	 * ========================================= */

	title_panel_create(&title, screen);
	title_panel_set_text(&title, "SETTINGS");


	/* =========================================
	 *    BUTTONS
	 * ========================================= */

	/* UNIT SELECTION BACKGROUND -------------------------------------------------*/
	set_unit_btn_bg = lv_button_create(screen);
	lv_obj_add_event_cb(set_unit_btn_bg, set_unit_event_cb, LV_EVENT_CLICKED, NULL); // Add callback

	lv_obj_add_style(set_unit_btn_bg, &blue_btn_bg_style, 0);

	lv_obj_set_size(set_unit_btn_bg, 300, 45);
	lv_obj_set_pos(set_unit_btn_bg, 10, 75);


	/* UNIT SELECTION LABEL ------------------------------------------------------*/
	set_unit_btn_label = lv_label_create(set_unit_btn_bg);

	lv_obj_remove_style_all(set_unit_btn_label);
	lv_obj_add_style(set_unit_btn_label, &settings_op_btn_label_style, 0);

	lv_label_set_text(set_unit_btn_label, "SET UNIT");
	lv_obj_center(set_unit_btn_label);


	/* SET TARGET BACKGROUND -----------------------------------------------------*/
	set_target_btn_bg = lv_button_create(screen);
	lv_obj_add_event_cb(set_target_btn_bg, set_target_event_cb, LV_EVENT_CLICKED, NULL); // Add callback

	lv_obj_add_style(set_target_btn_bg, &blue_btn_bg_style, 0);

	lv_obj_set_size(set_target_btn_bg, 300, 45);
	lv_obj_set_pos(set_target_btn_bg, 10, 130);


	/* SET TARGET LABEL ----------------------------------------------------------*/
	set_target_btn_label = lv_label_create(set_target_btn_bg);

	lv_obj_remove_style_all(set_target_btn_label);
	lv_obj_add_style(set_target_btn_label, &settings_op_btn_label_style, 0);

	lv_label_set_text(set_target_btn_label, "SET TARGET");
	lv_obj_center(set_target_btn_label);


	/* FLOW RATE BACKGROUND ------------------------------------------------------*/
	set_flow_rate_btn_bg = lv_button_create(screen);
	lv_obj_add_event_cb(set_flow_rate_btn_bg, set_flow_rate_event_cb, LV_EVENT_CLICKED, NULL); // Add callback

	lv_obj_add_style(set_flow_rate_btn_bg, &blue_btn_bg_style, 0);

	lv_obj_set_size(set_flow_rate_btn_bg, 300, 45);
	lv_obj_set_pos(set_flow_rate_btn_bg, 10, 185);


	/* FLOW RATE LABEL -----------------------------------------------------------*/
	set_flow_rate_btn_label = lv_label_create(set_flow_rate_btn_bg);

	lv_obj_remove_style_all(set_flow_rate_btn_label);
	lv_obj_add_style(set_flow_rate_btn_label, &settings_op_btn_label_style, 0);

	lv_label_set_text(set_flow_rate_btn_label, "SET FLOW RATE");
	lv_obj_center(set_flow_rate_btn_label);
}


void settings_screen_load(int selected_setting_option)
{
	lv_screen_load(screen);
}





/* EVENT CALLBACK FUNCTIONS ------------------------------------------------------*/

static void set_unit_event_cb(lv_event_t * e)
{
	select_channel_screen_load(SETTING_OPTION__SET_UNIT);
}

static void set_target_event_cb(lv_event_t * e)
{
	select_channel_screen_load(SETTING_OPTION__SET_TARGET);
}

static void set_flow_rate_event_cb(lv_event_t * e)
{
	select_channel_screen_load(SETTING_OPTION__SET_FLOW_RATE);
}
