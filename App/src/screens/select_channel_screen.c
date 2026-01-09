/*
 ******************************************************************************
 * @file           : select_channel_screen.c
 * @brief          : Select channel creation, stylization and load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */


/* Private includes ----------------------------------------------------------*/
#include "screens/select_channel_screen.h"

// Screens
#include "screens/settings_screen.h"
#include "screens/set_unit_screen.h"
#include "screens/set_target_screen.h"
#include "screens/set_flow_rate_screen.h"

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
static lv_obj_t * ch1_btn_bg,  * ch1_btn_label,
			    * ch2_btn_bg,  * ch2_btn_label;



/* Private function prototypes -----------------------------------------------*/
static void set_unit_screen_load_cb(lv_event_t * e);
static void set_target_screen_load_cb(lv_event_t * e);
static void set_flow_rate_screen_load_cb(lv_event_t * e);





void select_channel_screen_create(void)
{
	screen = lv_obj_create(NULL);

	/* =========================================
	 *    BACK BUTTON
	 * ========================================= */

	back_btn_create(screen, settings_screen_load, SETTING_OPTION__NO_OPTION);


	/* =========================================
	 *   PAGE TITLE
	 * ========================================= */

	title_panel_create(&title, screen);


	/* =========================================
	 *    BUTTONS
	 * ========================================= */

	/* CHANNEL 1 BUTTON BACKGROUND -----------------------------------------------*/
	ch1_btn_bg = lv_button_create(screen);

	lv_obj_add_style(ch1_btn_bg, &blue_btn_bg_style, 0);

	lv_obj_set_size(ch1_btn_bg, 300, 72);
	lv_obj_set_pos(ch1_btn_bg, 10, 75);


	/* CHANNEL 1 BUTTON LABEL ----------------------------------------------------*/
	ch1_btn_label = lv_label_create(ch1_btn_bg);

	lv_obj_remove_style_all(ch1_btn_label);
	lv_obj_add_style(ch1_btn_label, &settings_op_btn_label_style, 0);

	lv_label_set_text(ch1_btn_label, "CHANNEL 1");
	lv_obj_center(ch1_btn_label);


	/* CHANNEL 2 BUTTON BACKGROUND -----------------------------------------------*/
	ch2_btn_bg = lv_button_create(screen);

	lv_obj_add_style(ch2_btn_bg, &blue_btn_bg_style, 0);

	lv_obj_set_size(ch2_btn_bg, 300, 72);
	lv_obj_set_pos(ch2_btn_bg, 10, 158);


	/* CHANNEL 2 BUTTON LABEL ----------------------------------------------------*/
	ch2_btn_label = lv_label_create(ch2_btn_bg);

	lv_obj_remove_style_all(ch2_btn_label);
	lv_obj_add_style(ch2_btn_label, &settings_op_btn_label_style, 0);

	lv_label_set_text(ch2_btn_label, "CHANNEL 2");
	lv_obj_center(ch2_btn_label);
}


void select_channel_screen_load(int selected_setting_option)
{
	if (selected_setting_option == SETTING_OPTION__SET_UNIT)
	{
		title_panel_set_text(&title, "SET UNIT");

		lv_obj_add_event_cb(ch1_btn_bg, set_unit_screen_load_cb, LV_EVENT_CLICKED, (void *)CHANNEL__CH1);
		lv_obj_add_event_cb(ch2_btn_bg, set_unit_screen_load_cb, LV_EVENT_CLICKED, (void *)CHANNEL__CH2);
	}
	else if (selected_setting_option == SETTING_OPTION__SET_TARGET)
	{
		title_panel_set_text(&title, "SET TARGET");

		lv_obj_add_event_cb(ch1_btn_bg, set_target_screen_load_cb, LV_EVENT_CLICKED, (void *)CHANNEL__CH1);
		lv_obj_add_event_cb(ch2_btn_bg, set_target_screen_load_cb, LV_EVENT_CLICKED, (void *)CHANNEL__CH2);
	}
	else if (selected_setting_option == SETTING_OPTION__SET_FLOW_RATE)
	{
		title_panel_set_text(&title, "SET FLOW RATE");

		lv_obj_add_event_cb(ch1_btn_bg, set_flow_rate_screen_load_cb, LV_EVENT_CLICKED, (void *)CHANNEL__CH1);
		lv_obj_add_event_cb(ch2_btn_bg, set_flow_rate_screen_load_cb, LV_EVENT_CLICKED, (void *)CHANNEL__CH2);
	}
	else
	{
		return;
	}

	lv_screen_load(screen);
}





/* EVENT CALLBACK FUNCTIONS ------------------------------------------------------*/

static void set_unit_screen_load_cb(lv_event_t * e)
{
	channel_t channel = (channel_t)(uintptr_t)lv_event_get_user_data(e);

	if(channel == CHANNEL__CH1)
	{
		set_unit_screen_load(CHANNEL__CH1);
	}
	else if(channel == CHANNEL__CH2)
	{
		set_unit_screen_load(CHANNEL__CH2);
	}
}

static void set_target_screen_load_cb(lv_event_t * e)
{
	channel_t channel = (channel_t)(uintptr_t)lv_event_get_user_data(e);

	if(channel == CHANNEL__CH1)
	{
		set_target_screen_load(CHANNEL__CH1);
	}
	else if(channel == CHANNEL__CH2)
	{
		set_target_screen_load(CHANNEL__CH2);
	}
}

static void set_flow_rate_screen_load_cb(lv_event_t * e)
{
	channel_t channel = (channel_t)(uintptr_t)lv_event_get_user_data(e);

	if(channel == CHANNEL__CH1)
	{
		set_flow_rate_screen_load(CHANNEL__CH1);
	}
	else if(channel == CHANNEL__CH2)
	{
		set_flow_rate_screen_load(CHANNEL__CH2);
	}
}
