#include "../Inc/can_lib.h"
#include "stm32l4xx_hal.h"


int cl_send(CAN_RX_TX * cl_rx_tx, unsigned id, void * data, unsigned length) {
    uint32_t TxMailbox;
     cl_rx_tx->TxHeader.StdId = id;
    cl_rx_tx->TxHeader.DLC = length > CAN_DLC_MAX_VALUE ? CAN_DLC_MAX_VALUE : length;
    return HAL_CAN_AddTxMessage(&cl_rx_tx->hcan, &cl_rx_tx->TxHeader, data, &TxMailbox);
}

int cl_read(CAN_RX_TX * cl_rx_tx) {
    return 0;
}

void cl_set_filter(CAN_RX_TX * cl_rx_tx, uint32_t id, uint32_t id_mask) {
  cl_rx_tx->canfilterconfig.FilterActivation = CAN_FILTER_ENABLE;
  // 14 banks for 1 CAN interface devices(only CAN1), 28 banks for 2 interface devices(CAN1 & CAN2)
  cl_rx_tx->canfilterconfig.FilterBank = 10;  // which filter bank to use from the assigned ones (default 0-13)
  cl_rx_tx->canfilterconfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
  cl_rx_tx->canfilterconfig.FilterIdHigh = 0;
  cl_rx_tx->canfilterconfig.FilterIdLow = 0;
  cl_rx_tx->canfilterconfig.FilterMaskIdHigh = 0;
  cl_rx_tx->canfilterconfig.FilterMaskIdLow = 0;
  cl_rx_tx->canfilterconfig.FilterMode = CAN_FILTERMODE_IDMASK;
  cl_rx_tx->canfilterconfig.FilterScale = CAN_FILTERSCALE_32BIT;
  cl_rx_tx->canfilterconfig.SlaveStartFilterBank = 0;  // how many filters to assign to the CAN1 (master can)

  HAL_CAN_ConfigFilter(&cl_rx_tx->hcan, &cl_rx_tx->canfilterconfig);
}

/*
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
*/