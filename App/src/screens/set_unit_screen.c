/*
 ******************************************************************************
 * @file           : set_unit_screen.c
 * @brief          : Set unit screen creation, stylization and load functions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */


/* Private includes ----------------------------------------------------------*/
#include "screens/set_unit_screen.h"

// Screens
#include "screens/select_channel_screen.h"

// Styles
#include "styles/styles.h"

// Panels
#include "screens/panels/title_panel.h"
#include "screens/panels/channel_panel.h"

// Buttons
#include "screens/buttons/back_btn.h"

// Type definitions
#include "system/type_definitions.h"


/* Private variables ---------------------------------------------------------*/
static lv_obj_t * screen;

// Header panel
static title_panel_t header_title;
static channel_panel_t header_channel;


//* Private function prototypes -----------------------------------------------*/





void set_unit_screen_create(void)
{
	screen = lv_obj_create(NULL);

	/* =========================================
	 *    BACK BUTTON
	 * ========================================= */

	back_btn_create(screen, select_channel_screen_load, SETTING_OPTION__SET_UNIT);


	/* =========================================
	 *    PAGE TITLE
	 * ========================================= */

	title_panel_create(&header_title, screen);
	title_panel_set_text(&header_title, "SET UNIT");


	/* =========================================
	 *    PAGE CHANNEL
	 * ========================================= */

	channel_panel_create(&header_channel, screen);
}


void set_unit_screen_load(int selected_channel_option)
{
	if(selected_channel_option == CHANNEL__CH1)
	{
		channel_panel_set_text(&header_channel, "CHANNEL 1");
	} else
	if (selected_channel_option == CHANNEL__CH2)
	{
		channel_panel_set_text(&header_channel, "CHANNEL 2");
	}

	lv_screen_load(screen);
}

