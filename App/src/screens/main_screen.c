/*
 ******************************************************************************
 * @file           : main_screen.c
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

#include "styles/styles.h"
#include "styles/fonts.h"

#include "system/type_definitions.h"


/* Private variables ---------------------------------------------------------*/

// Screen
static lv_obj_t * screen;

/* =========================================
 *    Mode/Rate block
 * ========================================= */

// Title panel
static lv_obj_t * page_title_bg, * page_title_label;

// Flow rate visualization panel
static lv_obj_t * flow_rate_bg,
				* value_bg,      * value_label,
				* unit_bg,       * unit_label;

// Warnings panel
static lv_obj_t * warnings_title_bg,  * warnings_title_label,

				* high_flow_text_bg,   * high_flow_text_label,
				* high_flow_result_bg, * high_flow_result_label,

				* air_text_bg,        * air_text_label,
				* air_result_bg,      * air_result_label;



void main_screen_load()
{
	lv_screen_load(screen);
}


void main_screen_create(void)
{
	screen = lv_obj_create(NULL);


	// ===================================
	//     TITLE
	// ===================================

	/* TITLE BACKGROUND ----------------------------------------------------------*/
	page_title_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(page_title_bg);
	lv_obj_add_style(page_title_bg, &secondary_blue_bg_style, 0);

	lv_obj_set_size(page_title_bg, 220, 57);
	lv_obj_set_pos(page_title_bg, 10, 10);


	/* TITLE LABEL ---------------------------------------------------------------*/
	page_title_label = lv_label_create(page_title_bg);
	lv_obj_remove_style_all(page_title_label);
	lv_obj_add_style(page_title_label, &white_text_style, 0);

	lv_label_set_text(page_title_label, "LIQUID FLOW SENSOR");
	lv_obj_set_style_text_font(page_title_label, &montserrat_bold_20, 0);

	lv_obj_set_width(page_title_label, 220);
	lv_label_set_long_mode(page_title_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(page_title_label, LV_TEXT_ALIGN_CENTER, 0);

	lv_obj_center(page_title_label);


	// ===================================
	//     FLOW RATE PANEL
	// ===================================

	/* FLOW RATE BACKGROUND ------------------------------------------------------*/
	flow_rate_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(flow_rate_bg);
	lv_obj_add_style(flow_rate_bg, &primary_grey_with_stroke_bg_style, 0);

	lv_obj_set_size(flow_rate_bg, 220, 91);
	lv_obj_set_pos(flow_rate_bg, 10, 77);


	/* FLOW RATE VALUE BACKGROUND ------------------------------------------------*/
	value_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(value_bg);

	lv_obj_set_size(value_bg, 135, 85);
	lv_obj_set_pos(value_bg, 13, 80);


	/* FLOW RATE VALUE LABEL -----------------------------------------------------*/
	value_label = lv_label_create(value_bg);
	lv_obj_remove_style_all(value_label);
	lv_obj_add_style(value_label, &black_text_style, 0);

	lv_label_set_text(value_label, "00.0");
	lv_obj_set_style_text_font(value_label, &montserrat_bold_26, 0);
	lv_obj_center(value_label);


	/* FLOW RATE UNIT BACKGROUND -------------------------------------------------*/
	unit_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(unit_bg);

	lv_obj_set_size(unit_bg, 59, 76);
	lv_obj_set_pos(unit_bg, 133, 89);


	/* FLOW RATE UNIT LABEL ------------------------------------------------------*/
	unit_label = lv_label_create(unit_bg);
	lv_obj_remove_style_all(unit_label);
	lv_obj_add_style(unit_label, &black_text_style, 0);

	lv_label_set_text(unit_label, "mL/min");
	lv_obj_set_style_text_font(unit_label, &montserrat_bold_14, 0);
	lv_obj_center(unit_label);



	// ===================================
	//     WARNINGS
	// ===================================

	/* WARNINGS TITLE BACKGROUND -------------------------------------------------*/
	warnings_title_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(warnings_title_bg);
	lv_obj_add_style(warnings_title_bg, &secondary_blue_bg_style, 0);

	lv_obj_set_size(warnings_title_bg, 220, 32);
	lv_obj_set_pos(warnings_title_bg, 10, 178);


	/* WARNINGS TITLE LABEL ------------------------------------------------------*/
	warnings_title_label = lv_label_create(warnings_title_bg);
	lv_obj_remove_style_all(warnings_title_label);
	lv_obj_add_style(warnings_title_label, &white_text_style, 0);

	lv_label_set_text(warnings_title_label, "WARNING FLAGS");
	lv_obj_set_style_text_font(warnings_title_label, &montserrat_bold_14, 0);
	lv_obj_center(warnings_title_label);


	/* OVERFLOW TEXT BACKGROUND --------------------------------------------------*/
	high_flow_text_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(high_flow_text_bg);
	lv_obj_add_style(high_flow_text_bg, &primary_grey_bg_style, 0);

	lv_obj_set_size(high_flow_text_bg, 117, 40);
	lv_obj_set_pos(high_flow_text_bg, 10, 220);


	/* OVERFLOW TEXT LABEL -------------------------------------------------------*/
	high_flow_text_label = lv_label_create(high_flow_text_bg);
	lv_obj_remove_style_all(high_flow_text_label);
	lv_obj_add_style(high_flow_text_label, &black_text_style, 0);

	lv_label_set_text(high_flow_text_label, "HIGH FLOW");
	lv_obj_set_style_text_font(high_flow_text_label, &montserrat_bold_14, 0);
	lv_obj_center(high_flow_text_label);


	/* OVERFLOW RESULT BACKGROUND ------------------------------------------------*/
	high_flow_result_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(high_flow_result_bg);
	lv_obj_add_style(high_flow_result_bg, &green_bg_style, 0);

	lv_obj_set_size(high_flow_result_bg, 93, 40);
	lv_obj_set_pos(high_flow_result_bg, 137, 220);


	/* OVERFLOW RESULT LABEL -----------------------------------------------------*/
	high_flow_result_label = lv_label_create(high_flow_result_bg);
	lv_obj_remove_style_all(high_flow_result_label);
	lv_obj_add_style(high_flow_result_label, &black_text_style, 0);

	lv_label_set_text(high_flow_result_label, "NO");
	lv_obj_set_style_text_font(high_flow_result_label, &montserrat_bold_14, 0);
	lv_obj_center(high_flow_result_label);


	/* AIR TEXT BACKGROUND -------------------------------------------------------*/
	air_text_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(air_text_bg);
	lv_obj_add_style(air_text_bg, &primary_grey_bg_style, 0);

	lv_obj_set_size(air_text_bg, 117, 40);
	lv_obj_set_pos(air_text_bg, 10, 270);


	/* AIR TEXT LABEL ------------------------------------------------------------*/
	air_text_label = lv_label_create(air_text_bg);
	lv_obj_remove_style_all(air_text_label);
	lv_obj_add_style(air_text_label, &black_text_style, 0);

	lv_label_set_text(air_text_label, "AIR IN LINE");
	lv_obj_set_style_text_font(air_text_label, &montserrat_bold_14, 0);
	lv_obj_center(air_text_label);


	/* AIR RESULT BACKGROUND -----------------------------------------------------*/
	air_result_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(air_result_bg);
	lv_obj_add_style(air_result_bg, &green_bg_style, 0);

	lv_obj_set_size(air_result_bg, 93, 40);
	lv_obj_set_pos(air_result_bg, 137, 270);


	/* AIR RESULT LABEL ----------------------------------------------------------*/
	air_result_label = lv_label_create(air_result_bg);
	lv_obj_remove_style_all(air_result_label);
	lv_obj_add_style(air_result_label, &black_text_style, 0);

	lv_label_set_text(air_result_label, "NO");
	lv_obj_set_style_text_font(air_result_label, &montserrat_bold_14, 0);
	lv_obj_center(air_result_label);
}


/* SETTER FUNCTIONS --------------------------------------------------------------*/

void set_flow_rate_on_display(char * value)
{
	if(value_label != NULL)
	{
		lv_label_set_text(value_label, value);
	}
}

void set_high_flow_state_on_display(int state)
{
    if(high_flow_result_bg != NULL && high_flow_result_label != NULL)
    {
    	if(state == WARNING_FLAG__HIGH_FLOW_YES)
    	{
			lv_obj_add_style(high_flow_result_bg, &red_bg_style, 0);
			lv_label_set_text(high_flow_result_label, "YES");
    	}
    	else if(state == WARNING_FLAG__HIGH_FLOW_NO)
    	{
    		lv_obj_add_style(high_flow_result_bg, &green_bg_style, 0);
			lv_label_set_text(high_flow_result_label, "NO");
    	}
    }
}

void set_air_in_line_state_on_display(int state)
{
    if(air_result_bg != NULL && air_result_label != NULL)
    {
    	if(state == WARNING_FLAG__AIR_YES)
    	{
			lv_obj_add_style(air_result_bg, &red_bg_style, 0);
			lv_label_set_text(air_result_label, "YES");
    	}
    	else if(state == WARNING_FLAG__AIR_NO)
    	{
    		lv_obj_add_style(air_result_bg, &green_bg_style, 0);
			lv_label_set_text(air_result_label, "NO");
    	}
    }
}






