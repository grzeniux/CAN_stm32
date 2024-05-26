#include "app_can.h"
#include "can.h"

APP_StatusTypeDef APP_CAN_Primary_Write(uint32_t canFrameId, uint32_t canFrameLength, const uint8_t canData[])
{
    CAN_TxHeaderTypeDef TxHeader;
    TxHeader.StdId = canFrameId;
    TxHeader.DLC = canFrameLength;
    TxHeader.ExtId = 0;
    TxHeader.IDE = CAN_ID_STD;
    TxHeader.RTR = CAN_RTR_DATA;
    TxHeader.TransmitGlobalTime = DISABLE;

    // nie wiem po co ten mailbox
    uint32_t TxMailbox[8];

    return HAL_CAN_AddTxMessage(&hcan1, &TxHeader, canData, &TxMailbox[0]);
}
