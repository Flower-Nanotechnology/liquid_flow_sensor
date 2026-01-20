/*
 * display_block_title.c
 *
 *  Created on: Jan 6, 2026
 *      Author: thiago
 */


/* Private includes ----------------------------------------------------------*/
#include "styles/styles.h"
#include "styles/colors.h"


/* Private variables ---------------------------------------------------------*/
lv_style_t primary_blue_bg_style;
lv_style_t secondary_blue_bg_style;
lv_style_t primary_grey_bg_style;

lv_style_t title_label_style;
lv_style_t flow_rate_label_style;



/* Private function prototypes -----------------------------------------------*/
static void primary_blue_bg_style_init(void);
static void secondary_blue_bg_style_init(void);
static void primary_grey_bg_style_init(void);

static void title_label_style_init(void);
static void flow_rate_label_init(void);



void styles_init()
{
	primary_blue_bg_style_init();
	secondary_blue_bg_style_init();
	title_label_style_init();
	primary_grey_bg_style_init();
	flow_rate_label_init();
}


/* Function implementation ---------------------------------------------------*/

/* PRIMARY BLUY BACKGROUND ---------------------------------------------------*/
static void primary_blue_bg_style_init(void)
{
	lv_style_init(&primary_blue_bg_style);
	lv_style_set_bg_color(&primary_blue_bg_style, lv_color_hex(PRIMARY_BLUE));
	lv_style_set_bg_opa(&primary_blue_bg_style, LV_OPA_COVER);
}

/* SECONDARY BLUE BACKGROUND -------------------------------------------------*/
static void secondary_blue_bg_style_init(void)
{
	lv_style_init(&secondary_blue_bg_style);
	lv_style_set_bg_color(&secondary_blue_bg_style, lv_color_hex(SECONDARY_BLUE));
	lv_style_set_bg_opa(&secondary_blue_bg_style, LV_OPA_COVER);
}

/* PRIMARY GREY BACKGROUND ---------------------------------------------------*/
static void primary_grey_bg_style_init(void)
{
	lv_style_init(&primary_grey_bg_style);
	lv_style_set_bg_color(&primary_grey_bg_style, lv_color_hex(PRIMARY_GREY));
	lv_style_set_bg_opa(&primary_grey_bg_style, LV_OPA_COVER);
}



/* TITLE LABEL ---------------------------------------------------------------*/
static void title_label_style_init(void)
{
	lv_style_init(&title_label_style);
	lv_style_set_text_color(&title_label_style, lv_color_white());
	lv_style_set_text_opa(&title_label_style, LV_OPA_COVER);
}

/* FLOW RATE LABEL -----------------------------------------------------------*/
static void flow_rate_label_init(void)
{
	lv_style_init(&flow_rate_label_style);
	lv_style_set_text_color(&flow_rate_label_style, lv_color_black());
	lv_style_set_text_opa(&flow_rate_label_style, LV_OPA_COVER);
}

