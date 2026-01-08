/*
 ******************************************************************************
 * @file           : title_panel.h
 * @brief          : Title panel create function with stylization
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */



/* Private includes ----------------------------------------------------------*/
#include "screens/panels/title_panel.h"

// Styles
#include "styles/styles.h"
#include "styles/colors.h"


/* Private variables ----------------------------------------------------------*/
// Page title
static lv_obj_t * page_title_bg, * page_title_label;


/* Function implementation ---------------------------------------------------*/

void title_panel_create(lv_obj_t * screen)
{
	/* =========================================
	 *    PAGE TITLE
	 * ========================================= */

	/* PAGE TITLE BACKGROUND -----------------------------------------------------*/
	page_title_bg = lv_obj_create(screen);

	lv_obj_remove_style_all(page_title_bg);

	lv_obj_set_size(page_title_bg, 241, 44);
	lv_obj_set_pos(page_title_bg, 69, 10);


	/* PAGE TITLE LABEL ----------------------------------------------------------*/
	page_title_label = lv_label_create(page_title_bg);

	lv_obj_remove_style_all(page_title_label);
	lv_obj_add_style(page_title_label, &simple_page_title_label_style, 0);

	lv_obj_center(page_title_label);
	lv_obj_align(page_title_label, LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_set_style_text_align(page_title_label, LV_TEXT_ALIGN_RIGHT, 0);
}


void ui_update_page_title_label(char * text)
{
	lv_label_set_text(page_title_label, text);
}

