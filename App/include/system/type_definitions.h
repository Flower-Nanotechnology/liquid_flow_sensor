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
