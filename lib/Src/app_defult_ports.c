#include "app_can.h"

__weak APP_StatusTypeDef APP_CAN_Primary_Write(uint32_t canFrameId, uint32_t canFrameLength, const uint8_t canData[])
{
    return APP_OK;
}