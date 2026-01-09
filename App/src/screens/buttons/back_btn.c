/*
 ******************************************************************************
 * @file           : back_btn.c
 * @brief          : Back button create function with stylization
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */


/* Private includes ----------------------------------------------------------*/

// Buttons
#include "screens/buttons/back_btn.h"

// Styles
#include "styles/styles.h"

// Parameters
#include "ui_config.h"

// Type definitions
#include "system/type_definitions.h"


/* Private variables ---------------------------------------------------------*/

// Back button
static lv_obj_t * back_btn_bg,
				* back_btn_icon_bg, * back_btn_icon,
				* back_btn_text_bg, * back_btn_text_label;


/* Private function prototypes -----------------------------------------------*/
static void back_btn_with_label_create(
		lv_obj_t * screen,
		back_btn_cb_t back_screen_load,
		int selected_setting_option);

static void back_btn_no_label_create(
		lv_obj_t * screen,
		back_btn_cb_t back_screen_load,
		int selected_setting_option);

static void back_btn_event_cb(lv_event_t * e);
static void back_btn_delete_cb(lv_event_t * e);


/* Function implementation ---------------------------------------------------*/

void back_btn_create(
		lv_obj_t * screen,
		back_btn_cb_t back_screen_load,
		int selected_setting_option)
{
#if BACK_BTN_WITH_LABEL
	back_btn_with_label_create(screen, back_screen_load, selected_setting_option);
#else
	back_btn_no_label_create(screen, back_screen_load, selected_setting_option);
#endif
}


static void back_btn_with_label_create(
		lv_obj_t * screen,
		back_btn_cb_t back_screen_load,
		int selected_setting_option)
{
	// Create back button callback context on the heap
	back_btn_cb_ctx_t * back_btn_cb_ctx =
	    lv_malloc(sizeof(back_btn_cb_ctx_t));

	LV_ASSERT_MALLOC(back_btn_cb_ctx);

	back_btn_cb_ctx->cb = back_screen_load;
	back_btn_cb_ctx->op = selected_setting_option;


	/* =========================================
	 *    BACK BUTTON
	 * ========================================= */

	/* BACK BUTTON BACKGROUND ----------------------------------------------------*/
	back_btn_bg = lv_button_create(screen);

	lv_obj_add_style(back_btn_bg, &red_btn_bg_style, 0);

	lv_obj_set_size(back_btn_bg, 49, 45);
	lv_obj_set_pos(back_btn_bg, 10, 10);

	lv_obj_add_event_cb(back_btn_bg, back_btn_event_cb, LV_EVENT_CLICKED, &back_btn_cb_ctx); // Add callback


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

	lv_obj_set_size(back_btn_text_bg, 49, 15);
	lv_obj_set_pos(back_btn_text_bg, 10, 38);


	/* BACK BUTTON TEXT LABEL ----------------------------------------------------*/
	back_btn_text_label = lv_label_create(back_btn_text_bg);

	lv_obj_remove_style_all(back_btn_text_label);
	lv_obj_add_style(back_btn_text_label, &back_btn_text_style, 0);

	lv_label_set_text(back_btn_text_label, "BACK");
	lv_obj_center(back_btn_text_label);

	lv_obj_set_x(back_btn_text_label, 1);
}


void back_btn_no_label_create(
		lv_obj_t * screen,
		back_btn_cb_t back_screen_load,
		int selected_setting_option)
{
	// Create back button callback context
	back_btn_cb_ctx_t * back_btn_cb_ctx =
	    lv_malloc(sizeof(back_btn_cb_ctx_t));

	LV_ASSERT_MALLOC(back_btn_cb_ctx);

	back_btn_cb_ctx->cb = back_screen_load;
	back_btn_cb_ctx->op = selected_setting_option;


	/* =========================================
	 *    BACK BUTTON
	 * ========================================= */

	/* BACK BUTTON BACKGROUND ----------------------------------------------------*/
	back_btn_bg = lv_button_create(screen);

	lv_obj_add_style(back_btn_bg, &red_btn_bg_style, 0);

	lv_obj_set_size(back_btn_bg, 49, 45);
	lv_obj_set_pos(back_btn_bg, 10, 10);

	lv_obj_add_event_cb(back_btn_bg, back_btn_event_cb, LV_EVENT_CLICKED, back_btn_cb_ctx);
	lv_obj_add_event_cb(back_btn_bg, back_btn_delete_cb, LV_EVENT_DELETE, back_btn_cb_ctx);



	/* BACK BUTTON ICON BACKGROUND -----------------------------------------------*/
	back_btn_icon_bg = lv_obj_create(screen);

	lv_obj_remove_style_all(back_btn_icon_bg);
	lv_obj_add_style(back_btn_icon_bg, &back_btn_icon_bg_style, 0);

	// Ensure the click is detected only by the button
	lv_obj_remove_flag(back_btn_icon_bg, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_flag(back_btn_icon_bg, LV_OBJ_FLAG_EVENT_BUBBLE);


	lv_obj_set_size(back_btn_icon_bg, 49, 45);
	lv_obj_set_pos(back_btn_icon_bg, 10, 10);

	/* BACK BUTTON ICON ----------------------------------------------------------*/
	back_btn_icon = lv_label_create(back_btn_icon_bg);

	lv_obj_remove_style_all(back_btn_icon);
	lv_obj_add_style(back_btn_icon, &back_btn_icon_style, 0);

	lv_label_set_text(back_btn_icon, LV_SYMBOL_NEW_LINE);
	lv_obj_center(back_btn_icon);
}


/* EVENT CALLBACK FUNCTIONS ------------------------------------------------------*/

static void back_btn_event_cb(lv_event_t * e)
{
	// Get back button callback context on the heap
    back_btn_cb_ctx_t * back_btn_cb_ctx = lv_event_get_user_data(e);

    // Check if it and its .cb is NULL
    if(back_btn_cb_ctx == NULL || back_btn_cb_ctx->cb == NULL)
    {
        return;
    }

	back_btn_cb_ctx->cb(back_btn_cb_ctx->op);
}


static void back_btn_delete_cb(lv_event_t * e)
{
    back_btn_cb_ctx_t * ctx = lv_event_get_user_data(e);
    lv_free(ctx);
}

