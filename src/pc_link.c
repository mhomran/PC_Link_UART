/**
 * @file pc_link.c
 * @author Mohamed Hassanin
 * @brief A software pattern used to transfer data from microcontrollers 
 * and some form of personal computer (PC, notebook or similar) using UART
 * communication protocol.
 * @version 0.1
 * @date 2021-03-16 
 */

/******************************************************************************
 * Includes
 ******************************************************************************/
#include "pc_link.h"

/******************************************************************************
 * Function Definitions
 ******************************************************************************/
extern void 
PcLink_Init(PcLinkConfig_t * const Config)
{
	for(int i = 0; i < PC_LINK_MAX; i++) 
		{
			Config[i].PcLinkSendAllow = PC_LINK_SEND_ALLOW_ON;
		}
}

/*****************************End of File ************************************/
