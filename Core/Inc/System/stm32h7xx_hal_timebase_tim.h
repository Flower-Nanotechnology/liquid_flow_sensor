/*
 ******************************************************************************
 * @file           : stm32h7xx_hal_timebase_tim.h
 * @brief          : FreeRTOS timerbase configuration prototype
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: 06 de dezembro de 2025
 *
 ******************************************************************************
 */

#ifndef INC_SYSTEM_STM32H7XX_HAL_TIMEBASE_TIM_H_
#define INC_SYSTEM_STM32H7XX_HAL_TIMEBASE_TIM_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_tim.h"

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef        htim6;

/* Private functions ---------------------------------------------------------*/
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);


#ifdef __cplusplus
}
#endif


#endif /* INC_SYSTEM_STM32H7XX_HAL_TIMEBASE_TIM_H_ */
