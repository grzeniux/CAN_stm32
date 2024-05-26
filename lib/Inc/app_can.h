#ifndef __APP_CAN_H__
#define __APP_CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "app_defs.h"

/// @brief Send Can Frame to default master can
/// @param canFrameId StdID
/// @param canFrameLength DLC
/// @param canData byte array. Max 8 chars
/// @return status from HAL_StatusTypeDef
APP_StatusTypeDef APP_CAN_Primary_Write(uint32_t canFrameId, uint32_t canFrameLength, const uint8_t canData[]);

#ifdef __cplusplus
}
#endif
#endif

