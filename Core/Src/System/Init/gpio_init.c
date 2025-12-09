/*
 ******************************************************************************
 * @file           : gpio.c
 * @brief          : GPIO initialization function
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
void MX_GPIO_Init(GPIO_InitTypeDef GPIO_InitStruct, uint16_t pin, GPIO_TypeDef* port, uint32_t mode, uint32_t pull, uint32_t speed)
{
	/* GPIO ports clock enable */
	if     (port == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();
	else if(port == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
	else if(port == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
	else if(port == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE();
	else if(port == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE();
	else if(port == GPIOF) __HAL_RCC_GPIOF_CLK_ENABLE();
	else if(port == GPIOG) __HAL_RCC_GPIOG_CLK_ENABLE();
	else if(port == GPIOH) __HAL_RCC_GPIOH_CLK_ENABLE();

	/* Configure GPIO pin Output Level */
	if(mode == GPIO_MODE_OUTPUT_PP)
		HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);

	/* Configure GPIO pin */
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = mode;
	GPIO_InitStruct.Pull = pull;
	GPIO_InitStruct.Speed = speed;
	HAL_GPIO_Init(port, &GPIO_InitStruct);
}


#ifdef __cplusplus
}
#endif

#endif /* INC_SYSTEM_INIT_GPIO_INIT_H_ */
