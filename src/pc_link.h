/**
 * @file pc_link.h
 * @author Mohamed Hassanin
 * @brief A software pattern used to transfer data from microcontrollers 
 * and some form of personal computer (PC, notebook or similar) using UART
 * communication protocol.
 * @version 0.1
 * @date 2021-03-15 
 */
#ifndef PC_LINK_H
#define PC_LINK_H
/******************************************************************************
 * Includes
 ******************************************************************************/
#include "pc_link_cfg.h"

/******************************************************************************
 * Function prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern void PcLink_Init(PcLinkConfig_t Config);
extern void PcLink_Update(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* PC_LINK_H */
/*****************************End of File ************************************/
