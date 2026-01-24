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

// BACKGROUNDS
lv_style_t primary_blue_bg_style;
lv_style_t secondary_blue_bg_style;
lv_style_t primary_grey_bg_style;
lv_style_t green_bg_style;
lv_style_t red_bg_style;

lv_style_t primary_grey_with_stroke_bg_style;

// LABELS
lv_style_t white_text_style;
lv_style_t black_text_style;



/* Private function prototypes -----------------------------------------------*/

// BACKGROUNDS
static void primary_blue_bg_style_init(void);
static void secondary_blue_bg_style_init(void);
static void primary_grey_bg_style_init(void);
static void green_bg_style_init(void);
static void red_bg_style_init(void);

static void primary_grey_with_stroke_bg_style_init(void);

// LABELS
static void white_text_style_init(void);
static void black_text_style_init(void);



void styles_init()
{
	// BACKGROUNDS
	primary_blue_bg_style_init();
	secondary_blue_bg_style_init();
	primary_grey_bg_style_init();
	green_bg_style_init();
	red_bg_style_init();

	primary_grey_with_stroke_bg_style_init();

	// LABELS
	white_text_style_init();
	black_text_style_init();
}



// ===================================
//     COLORED BACKGROUND
// ===================================

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

/* GREEN BACKGROUND ----------------------------------------------------------*/
static void green_bg_style_init(void)
{
	lv_style_init(&green_bg_style);
	lv_style_set_bg_color(&green_bg_style, lv_color_hex(GREEN));
	lv_style_set_bg_opa(&green_bg_style, LV_OPA_COVER);
}

/* RED BACKGROUND ------------------------------------------------------------*/
static void red_bg_style_init(void)
{
	lv_style_init(&red_bg_style);
	lv_style_set_bg_color(&red_bg_style, lv_color_hex(RED));
	lv_style_set_bg_opa(&red_bg_style, LV_OPA_COVER);
}



// ===================================
//     CUSTOMIZED BACKGROUND
// ===================================

/* PRIMARY GREY BACKGROUND WITH STOKE ----------------------------------------*/
static void primary_grey_with_stroke_bg_style_init(void)
{
	lv_style_init(&primary_grey_with_stroke_bg_style);

	lv_style_set_bg_color(&primary_grey_with_stroke_bg_style, lv_color_hex(PRIMARY_GREY));
	lv_style_set_bg_opa(&primary_grey_with_stroke_bg_style, LV_OPA_COVER);

	lv_style_set_border_width(&primary_grey_with_stroke_bg_style, 5);
	lv_style_set_border_color(&primary_grey_with_stroke_bg_style, lv_color_hex(SECONDARY_BLUE));
	lv_style_set_border_opa(&primary_grey_with_stroke_bg_style, LV_OPA_COVER);
}



// ===================================
//     COLORED TEXT
// ===================================

/* WHITE TEXT ----------------------------------------------------------------*/
static void white_text_style_init(void)
{
	lv_style_init(&white_text_style);
	lv_style_set_text_color(&white_text_style, lv_color_white());
	lv_style_set_text_opa(&white_text_style, LV_OPA_COVER);
}

/* BLACK TEXT ---- -----------------------------------------------------------*/
static void black_text_style_init(void)
{
	lv_style_init(&black_text_style);
	lv_style_set_text_color(&black_text_style, lv_color_black());
	lv_style_set_text_opa(&black_text_style, LV_OPA_COVER);
}

