/*
 ******************************************************************************
 * @file           : period_elapsed_cb.h
 * @brief          : Period elapsed callback function prototype
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */

#ifndef INC_SYSTEM_HANDLERS_PERIOD_ELAPSED_CB_H_
#define INC_SYSTEM_HANDLERS_PERIOD_ELAPSED_CB_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_tim.h"


/* Private functions prototype -----------------------------------------------*/

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);


#ifdef __cplusplus
}
#endif

#endif /* INC_SYSTEM_HANDLERS_PERIOD_ELAPSED_CB_H_ */
