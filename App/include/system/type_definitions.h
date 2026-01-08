/*
 ******************************************************************************
 * @file           : type_definitions.h
 * @brief          : Type definitions
 ******************************************************************************
 *
 * Author: Thiago Oliveira
 *   Date: December, 2025
 *
 ******************************************************************************
 */

#ifndef INCLUDE_SYSTEM_TYPE_DEFINITIONS_H_
#define INCLUDE_SYSTEM_TYPE_DEFINITIONS_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
	CHANNEL_STATE__RUNNING = 0,
	CHANNEL_STATE__STOPPED = 1
} channel_state_t;


typedef enum {
	SETTING_OPTION__SET_UNIT = 0,
	SETTING_OPTION__SET_TARGET = 1,
	SETTING_OPTION__SET_FLOW_RATE = 2
} setting_option_t;


typedef enum {
	CHANNEL__CH1 = 0,
	CHANNEL__CH2 = 1,
} channel_t;


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SYSTEM_TYPE_DEFINITIONS_H_ */
