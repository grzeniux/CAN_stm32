#ifndef __APP_TICK_COUNTER_H__
#define __APP_TICK_COUNTER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

/// @brief Calculate frequncy from timer
/// @param probesPerSecond 
/// @param timerCurrentTicksFun Function to get current timer value
/// @return 
uint32_t APP_Read_TickFrequency_FromTimer(int probesPerSecond, uint32_t (*timerCurrentTicksFun)(void) );


#ifdef __cplusplus
}
#endif
#endif

