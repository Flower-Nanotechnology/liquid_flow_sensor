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
#include "styles/colors.h"
#include "system/type_definitions.h"


/* Private variables ---------------------------------------------------------*/

// Screen
static lv_obj_t * screen;

/* =========================================
 *    Mode/Rate block
 * ========================================= */

// Title panel
static lv_obj_t * title_bg, * title_label;

// CH1 block
static lv_obj_t * ch1_name_bg,   * ch1_name_label,
				* ch1_value_bg,  * ch1_value_label,
				* ch1_unit_bg,   * ch1_unit_label;

// CH2 block
static lv_obj_t * ch2_name_bg,   * ch2_name_label,
				* ch2_value_bg,  * ch2_value_label,
				* ch2_unit_bg,   * ch2_unit_label;




/* Private function prototypes -----------------------------------------------*/

// Button callbacks
//static void settings_btn_event_cb(lv_event_t * e);

// Setters
void set_ch2_flow_rate(const char * flow_rate);
void set_ch2_flow_rate(const char * flow_rate);



void main_screen_create(void)
{
	screen = lv_obj_create(NULL);


	/* TITLE BACKGROUND ----------------------------------------------------------*/
	title_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(title_bg);
	lv_obj_add_style(title_bg, &secondary_blue_bg_style, 0);

	lv_obj_set_size(title_bg, 300, 28);
	lv_obj_set_pos(title_bg, 10, 10);


	/* TITLE LABEL ---------------------------------------------------------------*/
	title_label = lv_label_create(title_bg);
	lv_obj_remove_style_all(title_label);
	lv_obj_add_style(title_label, &title_label_style, 0);

	lv_label_set_text(title_label, "LIQUID FLOW SENSOR");
	lv_obj_set_style_text_font(title_label, &lv_font_montserrat_14, 0);
	lv_obj_center(title_label);


	/* CH1 NAME BACKGROUND -------------------------------------------------------*/
	ch1_name_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(ch1_name_bg);
	lv_obj_add_style(ch1_name_bg, &primary_blue_bg_style, 0);

	lv_obj_set_size(ch1_name_bg, 48, 59);
	lv_obj_set_pos(ch1_name_bg, 10, 48);


	/* CH1 NAME LABEL ------------------------------------------------------------*/
	ch1_name_label = lv_label_create(ch1_name_bg);
	lv_obj_remove_style_all(ch1_name_label);
	lv_obj_add_style(ch1_name_label, &title_label_style, 0);

	lv_label_set_text(ch1_name_label, "CH1");
	lv_obj_set_style_text_font(ch1_name_label, &lv_font_montserrat_14, 0);
	lv_obj_center(ch1_name_label);


	/* CH1 VALUE BACKGROUND ------------------------------------------------------*/
	ch1_value_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(ch1_value_bg);
	lv_obj_add_style(ch1_value_bg, &primary_grey_bg_style, 0);

	lv_obj_set_size(ch1_value_bg, 157, 59);
	lv_obj_set_pos(ch1_value_bg, 63, 48);


	/* CH1 VALUE LABEL -----------------------------------------------------------*/
	ch1_value_label = lv_label_create(ch1_value_bg);
	lv_obj_remove_style_all(ch1_value_label);
	lv_obj_add_style(ch1_value_label, &flow_rate_label_style, 0);

	lv_label_set_text(ch1_value_label, "0000.0000");
	lv_obj_set_style_text_font(ch1_value_label, &lv_font_montserrat_20, 0);
	lv_obj_center(ch1_value_label);


	/* CH1 UNIT BACKGROUND -------------------------------------------------------*/
	ch1_unit_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(ch1_unit_bg);
	lv_obj_add_style(ch1_unit_bg, &primary_grey_bg_style, 0);

	lv_obj_set_size(ch1_unit_bg, 90, 59);
	lv_obj_set_pos(ch1_unit_bg, 220, 48);


	/* CH1 UNIT LABEL ------------------------------------------------------------*/
	ch1_unit_label = lv_label_create(ch1_unit_bg);
	lv_obj_remove_style_all(ch1_unit_label);
	lv_obj_add_style(ch1_unit_label, &flow_rate_label_style, 0);

	lv_label_set_text(ch1_unit_label, "uL/min");
	lv_obj_set_style_text_font(ch1_unit_label, &lv_font_montserrat_20, 0);
	lv_obj_center(ch1_unit_label);



	/* CH2 NAME BACKGROUND -------------------------------------------------------*/
	ch2_name_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(ch2_name_bg);
	lv_obj_add_style(ch2_name_bg, &primary_blue_bg_style, 0);

	lv_obj_set_size(ch2_name_bg, 48, 59);
	lv_obj_set_pos(ch2_name_bg, 10, 117);


	/* CH2 NAME LABEL ------------------------------------------------------------*/
	ch2_name_label = lv_label_create(ch2_name_bg);
	lv_obj_remove_style_all(ch2_name_label);
	lv_obj_add_style(ch2_name_label, &title_label_style, 0);

	lv_label_set_text(ch2_name_label, "CH2");
	lv_obj_set_style_text_font(ch2_name_label, &lv_font_montserrat_14, 0);
	lv_obj_center(ch2_name_label);


	/* CH2 VALUE BACKGROUND ------------------------------------------------------*/
	ch2_value_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(ch2_value_bg);
	lv_obj_add_style(ch2_value_bg, &primary_grey_bg_style, 0);

	lv_obj_set_size(ch2_value_bg, 157, 59);
	lv_obj_set_pos(ch2_value_bg, 63, 117);


	/* CH2 VALUE LABEL -----------------------------------------------------------*/
	ch2_value_label = lv_label_create(ch2_value_bg);
	lv_obj_remove_style_all(ch2_value_label);
	lv_obj_add_style(ch2_value_label, &flow_rate_label_style, 0);

	lv_label_set_text(ch2_value_label, "0000.0000");
	lv_obj_set_style_text_font(ch2_value_label, &lv_font_montserrat_20, 0);
	lv_obj_center(ch2_value_label);


	/* CH2 UNIT BACKGROUND -------------------------------------------------------*/
	ch2_unit_bg = lv_obj_create(screen);
	lv_obj_remove_style_all(ch2_unit_bg);
	lv_obj_add_style(ch2_unit_bg, &primary_grey_bg_style, 0);

	lv_obj_set_size(ch2_unit_bg, 90, 59);
	lv_obj_set_pos(ch2_unit_bg, 220, 117);


	/* CH2 UNIT LABEL ------------------------------------------------------------*/
	ch2_unit_label = lv_label_create(ch2_unit_bg);
	lv_obj_remove_style_all(ch2_unit_label);
	lv_obj_add_style(ch2_unit_label, &flow_rate_label_style, 0);

	lv_label_set_text(ch2_unit_label, "uL/min");
	lv_obj_set_style_text_font(ch2_unit_label, &lv_font_montserrat_20, 0);
	lv_obj_center(ch2_unit_label);
}


void main_screen_load()
{
	lv_screen_load(screen);
}




///* EVENT CALLBACK FUNCTIONS ------------------------------------------------------*/
//
//static void settings_btn_event_cb(lv_event_t * e)
//{
//	// settings_screen_load(SETTING_OPTION__NO_OPTION);
//}


///* SETTER FUNCTIONS --------------------------------------------------------------*/
//
//void set_ch1_flow_rate(const char * flow_rate)
//{
//    if(ch1_flow_rate_label != NULL) // Check if ch1_flow_rate_label obj has been initialized
//    {
//        lv_label_set_text(ch1_flow_rate_label, flow_rate); // Change the text
//    }
//}
//
//
//void set_ch2_flow_rate(const char * flow_rate)
//{
//    if(ch2_flow_rate_label != NULL) // Check if ch1_flow_rate_label obj has been initialized
//    {
//        lv_label_set_text(ch2_flow_rate_label, flow_rate); // Change the text
//    }
//}







