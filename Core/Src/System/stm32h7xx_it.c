/**
  ******************************************************************************
  * @file    stm32h7xx_it.c
  * @brief   Interrupt Service Routines.
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
  *        Date: December, 2025
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32h7xx_it.h"

// LVGL
#include "tick/lv_tick.h"

// XPT2046
#include "xpt2046.h"


/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_spi3_tx;
extern SPI_HandleTypeDef hspi3;
extern TIM_HandleTypeDef htim6;

// Touch
extern XPT2046_Handler touch_handler;



/******************************************************************************/
/*           Cortex Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
	while (1){}
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
	while (1){}
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
	while (1){}
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
	while (1){}
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
	while (1){}
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
}



/******************************************************************************/
/* STM32H7xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32h7xx.s).                    */
/******************************************************************************/


/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(TOUCH_IRQ_Pin);
	XPT2046_EXTICallback(&touch_handler);
}

/**
  * @brief This function handles DMA1 stream0 global interrupt.
  */
void DMA1_Stream0_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_spi3_tx);
}

/**
  * @brief This function handles SPI3 global interrupt.
  */
void SPI3_IRQHandler(void)
{
	HAL_SPI_IRQHandler(&hspi3);
}

/**
  * @brief This function handles TIM6 global interrupt, DAC1_CH1 and DAC1_CH2 underrun error interrupts.
  */
void TIM6_DAC_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim6);
	lv_tick_inc(1);
	XPT2046_TIMCallback(&touch_handler);
}
