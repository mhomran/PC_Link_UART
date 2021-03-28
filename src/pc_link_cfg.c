/**
 * @file pc_link_cfg.c
 * @author Mohamed Hassanin
 * @brief A configuration layer for the PC_LINK module
 * @version 0.1
 * @date 2021-03-16
 */

/*****************************************************************************
* Includes
******************************************************************************/
#include "pc_link_cfg.h"
/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static const PcLinkConfig_t PcLinkConfig[PC_LINK_MAX] = {
  { .PcLink = PC_LINK_0, .Uart = UART_0 },
};
/**********************************************************************
* Function Definitions
**********************************************************************/
/**
 * @brief return the configuration structure holding the configuration table 
 * of the module
 */
extern const PcLinkConfig_t* const
PcLink_GetConfig(void)
{
  return PcLinkConfig;
}

/*****************************End of File ************************************/
