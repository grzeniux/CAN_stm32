#include "app_tick_counter.h"

uint32_t oldValue = 0;
uint32_t APP_Read_TickFrequency_FromTimer(int probesPerSecond, uint32_t (*timerCurrentTicksFun)(void))
{
    uint32_t actualValue = timerCurrentTicksFun();
    uint32_t diff = actualValue - oldValue;
    oldValue = actualValue;
    return diff / probesPerSecond;
}
