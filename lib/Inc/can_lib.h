#ifndef CAN_LIB_H_
#define CAN_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"
#define CAN_DLC_MAX_VALUE   8

typedef struct CAN_RX_TX {
    // set this to the appropriate hcan interface
    CAN_HandleTypeDef hcan;

    // The only parameters that should be set in this struct are:
    // IDE(CAN_ID_STD), RTR(CAN_RTR_DATA), TransmitGlobalTime(DISABLE).
    CAN_TxHeaderTypeDef TxHeader;

    // please change this through the cl_setup_filter & cl_activate_filter functions
    CAN_FilterTypeDef canfilterconfig;
} CAN_RX_TX;

int cl_send(CAN_RX_TX * cl_rx_tx, unsigned id, void * data, unsigned length);
// int cl_read(CAN_RX_TX * cl_rx_tx);
void cl_setup_filter(CAN_RX_TX * cl_rx_tx, uint32_t id, uint32_t id_mask);
void cl_activate_filter(CAN_RX_TX * cl_rx_tx);
void cl_disable_filter(CAN_RX_TX * cl_rx_tx);

#ifdef __cplusplus
}
#endif
#endif

