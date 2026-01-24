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



/* UNIT --------------------------------------------------------------------------*/
typedef enum {
	WARNING_FLAG__HIGH_FLOW_YES,
	WARNING_FLAG__HIGH_FLOW_NO,
	WARNING_FLAG__AIR_YES,
	WARNING_FLAG__AIR_NO
} warning_flag_t;


#ifdef __cplusplus
extern }
#endif

#endif /* INCLUDE_SYSTEM_TYPE_DEFINITIONS_H_ */
