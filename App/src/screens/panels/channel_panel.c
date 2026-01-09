/*
 ******************************************************************************
 * @file           : channel_panel.c
 * @brief          : Channel panel create function with stylization
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: Dezember, 2025
 *
 ******************************************************************************
 */


/* Private includes ----------------------------------------------------------*/
#include "screens/panels/channel_panel.h"

// Styles
#include "styles/styles.h"


/* Function implementation ----------------------------------------------------*/

void channel_panel_create(channel_panel_t * panel, lv_obj_t * parent)
{
	/* =========================================
	 *    PAGE CHANNEL
	 * ========================================= */

	/* PAGE CHANNEL BACKGROUND ---------------------------------------------------*/
	panel->bg = lv_obj_create(parent);

	lv_obj_remove_style_all(panel->bg);

	lv_obj_set_size(panel->bg, 241, 22);
	lv_obj_set_pos(panel->bg, 69, 33);


	/* PAGE CHANNEL LABEL --------------------------------------------------------*/
	panel->label = lv_label_create(panel->bg);

	lv_obj_remove_style_all(panel->label);
	lv_obj_add_style(panel->label, &page_channel_label_style, 0);

	lv_obj_center(panel->label);
	lv_obj_align(panel->label, LV_ALIGN_TOP_RIGHT, 0, 0);
	lv_obj_set_style_text_align(panel->label, LV_TEXT_ALIGN_RIGHT, 0);
}


void channel_panel_set_text(channel_panel_t * panel, const char * text)
{
	lv_label_set_text(panel->label, text);
}

