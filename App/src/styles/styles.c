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
lv_style_t panel_block_bg_style;
lv_style_t panel_title_bg_style;
lv_style_t panel_title_label_style;
lv_style_t panel_channel_param_bg_style;
lv_style_t panel_channel_param_label_style;

lv_style_t settings_btn_icon_style;
lv_style_t settings_op_btn_label_style;

lv_style_t settings_panel_bg_style;
lv_style_t settings_panel_label_style;

lv_style_t blue_btn_bg_style;
lv_style_t red_btn_bg_style;
lv_style_t green_btn_bg_style;

lv_style_t general_btn_icon_style;

lv_style_t back_btn_icon_bg_style;
lv_style_t back_btn_icon_style;
lv_style_t back_btn_text_style;

lv_style_t page_title_label_style;
lv_style_t page_channel_label_style;


/* Private function prototypes -----------------------------------------------*/

/* =========================================
 *    MODE/RATE/TARGET PANELS
 * ========================================= */

static void panel_block_bg_style_init(void);
static void panel_title_bg_style_init(void);
static void panel_title_label_style_init(void);
static void panel_channel_param_bg_style_init(void);
static void panel_channel_param_label_style_init(void);

/* =========================================
 *    SETTINGS BUTTON
 * ========================================= */

static void settings_btn_icon_style_init(void);
static void settings_op_btn_label_style_init(void);

/* =========================================
 *    CHANNEL CONTROL PANEL
 * ========================================= */

static void setting_panel_bg_style_init(void);
static void setting_panel_label_style_init(void);

/* =========================================
 *    SIMPLE BUTTONS BACKGROUND
 * ========================================= */

static void blue_btn_bg_style_init(void);
static void red_btn_bg_style_init(void);
static void green_btn_bg_style_init(void);

static void general_btn_icon_style_init(void);

/* =========================================
 *    BACK BUTTON
 * ========================================= */

static void back_btn_icon_style_init(void);
static void back_btn_icon_bg_style_init(void);
static void back_btn_text_style_init(void);

/* =========================================
 *    PAGE TITLE
 * ========================================= */

static void page_title_label_style_init(void);
static void page_channel_label_style_init(void);



void styles_init()
{
	/* =========================================
	 *    MODE/RATE/TARGET PANELS
	 * ========================================= */

	panel_block_bg_style_init();
	panel_title_bg_style_init();
	panel_title_label_style_init();
	panel_channel_param_bg_style_init();
	panel_channel_param_label_style_init();

	/* =========================================
	 *    SETTINGS BUTTON
	 * ========================================= */

	settings_btn_icon_style_init();
	settings_op_btn_label_style_init();

	/* =========================================
	 *    CHANNEL CONTROL PANEL
	 * ========================================= */

	setting_panel_bg_style_init();
	setting_panel_label_style_init();

	/* =========================================
	 *    SIMPLE BUTTONS BACKGROUND
	 * ========================================= */

	// Colored
	blue_btn_bg_style_init();
	red_btn_bg_style_init();
	green_btn_bg_style_init();

	// Non-colored
	general_btn_icon_style_init();

	/* =========================================
	 *    BACK BUTTON
	 * ========================================= */

	back_btn_icon_bg_style_init();
	back_btn_icon_style_init();
	back_btn_text_style_init();

	/* =========================================
	 *    PAGE TITLE
	 * ========================================= */

	page_title_label_style_init();
	page_channel_label_style_init();
}


/* Function implementation ---------------------------------------------------*/

/* =========================================
 *    MODE/RATE/TARGET PANELS
 * ========================================= */

static void panel_block_bg_style_init(void)
{
	lv_style_init(&panel_block_bg_style);
	lv_style_set_bg_color(&panel_block_bg_style, lv_color_hex(MAIN_GREY));
	lv_style_set_bg_opa(&panel_block_bg_style, LV_OPA_COVER);
}

static void panel_title_bg_style_init(void)
{
	lv_style_init(&panel_title_bg_style);
	lv_style_set_bg_color(&panel_title_bg_style, lv_color_hex(BLUE));
	lv_style_set_bg_opa(&panel_title_bg_style, LV_OPA_COVER);
	lv_style_set_border_width(&panel_title_bg_style, 3);
	lv_style_set_border_color(&panel_title_bg_style, lv_color_black());
}

static void panel_title_label_style_init(void)
{
	lv_style_init(&panel_title_label_style);
	lv_style_set_text_color(&panel_title_label_style, lv_color_white());
	lv_style_set_text_opa(&panel_title_label_style, LV_OPA_COVER);
}

static void panel_channel_param_bg_style_init(void)
{
	lv_style_init(&panel_channel_param_bg_style);
	lv_style_set_bg_color(&panel_channel_param_bg_style, lv_color_black());
	lv_style_set_bg_opa(&panel_channel_param_bg_style, LV_OPA_COVER);
}

static void panel_channel_param_label_style_init(void)
{
	lv_style_init(&panel_channel_param_label_style);
	lv_style_set_text_color(&panel_channel_param_label_style, lv_color_white());
	lv_style_set_text_opa(&panel_channel_param_label_style, LV_OPA_COVER);
	lv_style_set_text_font(&panel_channel_param_label_style, &lv_font_montserrat_14);
}


/* =========================================
 *    SETTINGS BUTTON
 * ========================================= */

static void settings_btn_icon_style_init(void)
{
	lv_style_init(&settings_btn_icon_style);
	lv_style_set_text_font(&settings_btn_icon_style,  &lv_font_montserrat_32);
	lv_style_set_text_color(&settings_btn_icon_style, lv_color_white());
	lv_style_set_text_opa(&settings_btn_icon_style, LV_OPA_COVER);
}

static void settings_op_btn_label_style_init(void)
{
	lv_style_init(&settings_op_btn_label_style);
	lv_style_set_text_font(&settings_op_btn_label_style,  &lv_font_montserrat_24);
	lv_style_set_text_color(&settings_op_btn_label_style, lv_color_white());
	lv_style_set_text_opa(&settings_op_btn_label_style, LV_OPA_COVER);
}

/* =========================================
 *    CHANNEL CONTROL PANEL
 * ========================================= */

static void setting_panel_bg_style_init(void)
{
	lv_style_init(&settings_panel_bg_style);
	lv_style_set_bg_color(&settings_panel_bg_style, lv_color_hex(SECONDARY_GREY));
	lv_style_set_bg_opa(&settings_panel_bg_style, LV_OPA_COVER);
}

static void setting_panel_label_style_init(void)
{
	lv_style_init(&settings_panel_label_style);
	lv_style_set_text_font(&settings_panel_label_style,  &lv_font_montserrat_10);
	lv_style_set_text_color(&settings_panel_label_style, lv_color_black());
	lv_style_set_text_opa(&settings_panel_label_style, LV_OPA_COVER);
}


/* =========================================
 *    SIMPLE BUTTONS BACKGROUND - COLORED
 * ========================================= */

static void blue_btn_bg_style_init(void)
{
	lv_style_init(&blue_btn_bg_style);
	lv_style_set_radius(&blue_btn_bg_style, 0);
	lv_style_set_pad_all(&blue_btn_bg_style, 0);
	lv_style_set_border_width(&blue_btn_bg_style, 0);
	lv_style_set_outline_width(&blue_btn_bg_style, 0);
	lv_style_set_shadow_width(&blue_btn_bg_style, 0);
	lv_style_set_bg_color(&blue_btn_bg_style, lv_color_hex(BLUE));
	lv_style_set_bg_opa(&blue_btn_bg_style, LV_OPA_COVER);
}

static void red_btn_bg_style_init(void)
{
	lv_style_init(&red_btn_bg_style);
	lv_style_set_radius(&red_btn_bg_style, 0);
	lv_style_set_border_width(&red_btn_bg_style, 0);
	lv_style_set_shadow_width(&red_btn_bg_style, 0);
	lv_style_set_outline_width(&red_btn_bg_style, 0);
	lv_style_set_pad_all(&red_btn_bg_style, 0);
	lv_style_set_bg_color(&red_btn_bg_style, lv_color_hex(RED));
	lv_style_set_bg_opa(&red_btn_bg_style, LV_OPA_COVER);
}

static void green_btn_bg_style_init(void)
{
	lv_style_init(&green_btn_bg_style);
	lv_style_set_radius(&green_btn_bg_style, 0);
	lv_style_set_border_width(&green_btn_bg_style, 0);
	lv_style_set_shadow_width(&green_btn_bg_style, 0);
	lv_style_set_outline_width(&green_btn_bg_style, 0);
	lv_style_set_pad_all(&green_btn_bg_style, 0);
	lv_style_set_bg_color(&green_btn_bg_style, lv_color_hex(GREEN));
	lv_style_set_bg_opa(&green_btn_bg_style, LV_OPA_COVER);
}

/* =========================================
 *    SIMPLE BUTTON ICON
 * ========================================= */

static void general_btn_icon_style_init(void)
{
	lv_style_init(&general_btn_icon_style);
	lv_style_set_text_font(&general_btn_icon_style,  &lv_font_montserrat_22);
	lv_style_set_text_color(&general_btn_icon_style, lv_color_white());
	lv_style_set_text_opa(&general_btn_icon_style, LV_OPA_COVER);
}


/* =========================================
 *    BACK BUTTON
 * ========================================= */

static void back_btn_icon_bg_style_init(void)
{
	lv_style_init(&back_btn_icon_bg_style);
	lv_style_set_pad_all(&back_btn_icon_bg_style, 0);
	lv_style_set_border_width(&back_btn_icon_bg_style, 0);
	lv_style_set_outline_width(&back_btn_icon_bg_style, 0);
	lv_style_set_shadow_width(&back_btn_icon_bg_style, 0);
	lv_style_set_bg_opa(&back_btn_icon_bg_style, LV_OPA_TRANSP);
}

static void back_btn_icon_style_init(void)
{
	lv_style_init(&back_btn_icon_style);
	lv_style_set_text_font(&back_btn_icon_style,  &lv_font_montserrat_24);
	lv_style_set_text_color(&back_btn_icon_style, lv_color_white());
	lv_style_set_text_opa(&back_btn_icon_style, LV_OPA_COVER);
}

static void back_btn_text_style_init(void)
{
	lv_style_init(&back_btn_text_style);
	lv_style_set_text_font(&back_btn_text_style,  &lv_font_montserrat_12);
	lv_style_set_text_color(&back_btn_text_style, lv_color_black());
	lv_style_set_text_opa(&back_btn_text_style, LV_OPA_COVER);
}


/* =========================================
 *    PAGE TITLE
 * ========================================= */

static void page_title_label_style_init(void)
{
	lv_style_init(&page_title_label_style);
	lv_style_set_text_font(&page_title_label_style,  &lv_font_montserrat_20);
	lv_style_set_text_color(&page_title_label_style, lv_color_black());
	lv_style_set_text_opa(&page_title_label_style, LV_OPA_COVER);
}

static void page_channel_label_style_init(void)
{
	lv_style_init(&page_channel_label_style);
	lv_style_set_text_font(&page_channel_label_style,  &lv_font_montserrat_14);
	lv_style_set_text_color(&page_channel_label_style, lv_color_hex(RED));
	lv_style_set_text_opa(&page_channel_label_style, LV_OPA_COVER);
}
