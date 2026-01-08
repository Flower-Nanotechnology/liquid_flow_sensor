/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  *
  * Modified by: Thiago Oliveira
  * Date: December, 2025
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
#include "core_cm7.h"


/* Private defines -----------------------------------------------------------*/

// Hardware localization: LCD PINS
#define LCD_SDI_Pin GPIO_PIN_12
#define LCD_SDI_Port GPIOC

#define LCD_SCK_Pin GPIO_PIN_10
#define LCD_SCK_Port GPIOC

#define LCD_CS_Pin GPIO_PIN_9
#define LCD_CS_GPIO_Port GPIOG

#define LCD_DCX_Pin GPIO_PIN_2
#define LCD_DCX_GPIO_Port GPIOD

#define LCD_RESET_Pin GPIO_PIN_5
#define LCD_RESET_GPIO_Port GPIOD


// Hardware localization: TOUCH PINS
#define TOUCH_SCK_Pin GPIO_PIN_5
#define TOUCH_SCK_GPIO_Port GPIOA

#define TOUCH_SDO_Pin GPIO_PIN_6
#define TOUCH_SDO_GPIO_Port GPIOA

#define TOUCH_SDI_Pin GPIO_PIN_7
#define TOUCH_SDI_GPIO_Port GPIOA

#define TOUCH_CS_Pin GPIO_PIN_5
#define TOUCH_CS_GPIO_Port GPIOE

#define TOUCH_IRQ_Pin GPIO_PIN_5
#define TOUCH_IRQ_GPIO_Port GPIOC
#define TOUCH_IRQ_EXTI_IRQn EXTI9_5_IRQn


// ILI9341 driver callbacks
#define  BUS_SPI3_POLL_TIMEOUT  0x1000U


// Display params
#define  LCD_H_RES  240
#define  LCD_V_RES  320

/* Debug defines -------------------------------------------------------------*/
#define DEBUG_TOUCH 1


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
