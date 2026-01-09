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

/* CHANNEL -----------------------------------------------------------------------*/
typedef enum {
	CHANNEL__CH1 = 0,
	CHANNEL__CH2 = 1,
} channel_t;


/* CHANNEL STATE -----------------------------------------------------------------*/
typedef enum {
	CHANNEL_STATE__RUNNING = 0,
	CHANNEL_STATE__STOPPED = 1
} channel_state_t;


/* SETTING OPTION ----------------------------------------------------------------*/
typedef enum {
	SETTING_OPTION__NO_OPTION = 0,
	SETTING_OPTION__SET_UNIT = 1,
	SETTING_OPTION__SET_TARGET = 2,
	SETTING_OPTION__SET_FLOW_RATE = 3
} setting_option_t;


/* UNIT --------------------------------------------------------------------------*/
typedef enum {
	// per hour
	UNIT__ML_PER_H = 0,
	UNIT__UL_PER_H = 1,
	UNIT__NL_PER_H = 2,
	UNIT__PL_PER_H = 3,

	// per minute
	UNIT__ML_PER_MIN = 4,
	UNIT__UL_PER_MIN = 5,
	UNIT__NL_PER_MIN = 6,
	UNIT__PL_PER_MIN = 7,

	// per second
	UNIT__ML_PER_S = 8,
	UNIT__UL_PER_S = 9,
	UNIT__NL_PER_S = 10,
	UNIT__PL_PER_S = 11
} unit_t;


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SYSTEM_TYPE_DEFINITIONS_H_ */
