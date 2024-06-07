#ifndef CAN_LIB_H_
#define CAN_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"
#define CAN_DLC_MAX_VALUE   8

typedef struct CAN_RX_TX {
    CAN_HandleTypeDef hcan;

    CAN_TxHeaderTypeDef TxHeader;

    CAN_FilterTypeDef canfilterconfig;
} CAN_RX_TX;

int cl_send(CAN_RX_TX * cl_rx_tx, unsigned id, void * data, unsigned length);
int cl_read(CAN_RX_TX * cl_rx_tx);
void cl_set_filter(CAN_RX_TX * cl_rx_tx, uint32_t id, uint32_t id_mask);

#ifdef __cplusplus
}
#endif
#endif

