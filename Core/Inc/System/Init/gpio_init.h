/*
 ******************************************************************************
 * @file           : gpio.h
 * @brief          : GPIO initialization function prototype
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */

#ifndef INC_SYSTEM_INIT_GPIO_INIT_H_
#define INC_SYSTEM_INIT_GPIO_INIT_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private functions prototype -----------------------------------------------*/

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(GPIO_InitTypeDef GPIO_InitStruct, uint16_t pin, GPIO_TypeDef* port, uint32_t mode, uint32_t pull, uint32_t speed);


#ifdef __cplusplus
}
#endif

#endif /* INC_SYSTEM_INIT_GPIO_INIT_H_ */
