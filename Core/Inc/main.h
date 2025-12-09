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


/* Private includes ----------------------------------------------------------*/

// System
#include "system_clock_config.h"
#include "mpu_config.h"
#include "error_handler.h"
#include "period_elapsed_cb.h"

// Peripherals
#include "gpio_init.h"


/* Private defines -----------------------------------------------------------*/
#define LED_PIN_Pin GPIO_PIN_10
#define LED_PIN_GPIO_Port GPIOD


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
