/*
 ******************************************************************************
 * @file           : back_btn.h
 * @brief          : Back button create function with stylization
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */


/* Private includes ----------------------------------------------------------*/
#include "screens/buttons/back_btn.h"
#include "styles/styles.h"


/* Private variables ---------------------------------------------------------*/

// Back button
static lv_obj_t * back_btn_bg,
				* back_btn_icon_bg, * back_btn_icon,
				* back_btn_text_bg, * back_btn_text_label;


/* Private function prototypes -----------------------------------------------*/
static void back_btn_event_cb(lv_event_t * e);


/* Function implementation ---------------------------------------------------*/

void back_btn_create(
		lv_obj_t * screen,
		void (* back_screen_load)(void))
{
	/* =========================================
	 *    BACK BUTTON
	 * ========================================= */

	/* BACK BUTTON BACKGROUND ----------------------------------------------------*/
	back_btn_bg = lv_button_create(screen);

	lv_obj_add_style(back_btn_bg, &red_btn_bg_style, 0);

	lv_obj_set_size(back_btn_bg, 49, 44);
	lv_obj_set_pos(back_btn_bg, 10, 10);

	lv_obj_add_event_cb(back_btn_bg, back_btn_event_cb, LV_EVENT_CLICKED, back_screen_load); // Add callback


	/* BACK BUTTON ICON BACKGROUND -----------------------------------------------*/
	back_btn_icon_bg = lv_obj_create(screen);

	lv_obj_remove_style_all(back_btn_icon_bg);
	lv_obj_add_style(back_btn_icon_bg, &back_btn_icon_bg_style, 0);

	// Ensure the click is detected only by the button
	lv_obj_remove_flag(back_btn_icon_bg, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_flag(back_btn_icon_bg, LV_OBJ_FLAG_EVENT_BUBBLE);


	lv_obj_set_size(back_btn_icon_bg, 49, 32);
	lv_obj_set_pos(back_btn_icon_bg, 10, 10);

	/* BACK BUTTON ICON ----------------------------------------------------------*/
	back_btn_icon = lv_label_create(back_btn_icon_bg);

	lv_obj_remove_style_all(back_btn_icon);
	lv_obj_add_style(back_btn_icon, &back_btn_icon_style, 0);

	lv_label_set_text(back_btn_icon, LV_SYMBOL_NEW_LINE);
	lv_obj_center(back_btn_icon);


	/* BACK BUTTON TEXT BACKGROUND -----------------------------------------------*/
	back_btn_text_bg = lv_obj_create(screen);

	lv_obj_remove_style_all(back_btn_text_bg);
	lv_obj_add_style(back_btn_text_bg, &back_btn_icon_bg_style, 0);

	// Ensure the click is detected only by the button
	lv_obj_remove_flag(back_btn_text_bg, LV_OBJ_FLAG_CLICKABLE);

	lv_obj_set_size(back_btn_text_bg, 49, 16);
	lv_obj_set_pos(back_btn_text_bg, 10, 38);


	/* BACK BUTTON TEXT LABEL ----------------------------------------------------*/
	back_btn_text_label = lv_label_create(back_btn_text_bg);

	lv_obj_remove_style_all(back_btn_text_label);
	lv_obj_add_style(back_btn_text_label, &back_btn_text_style, 0);

	lv_label_set_text(back_btn_text_label, "BACK");
	lv_obj_center(back_btn_text_label);
}



/* EVENT CALLBACK FUNCTIONS ------------------------------------------------------*/

static void back_btn_event_cb(lv_event_t * e)
{
    void (*callback)(void) = lv_event_get_user_data(e);

    if(callback != NULL)
        callback();
}

