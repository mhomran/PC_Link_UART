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
#include "uart.h"
/******************************************************************************
 * Definitions
 ******************************************************************************/
#define PC_LINK_XOFF 19
#define PC_LINK_XON 17
/******************************************************************************
 * Module variable definitions
 ******************************************************************************/
static PcLinkConfig_t * gConfig;
/******************************************************************************
 * Function Definitions
 ******************************************************************************/
extern void 
PcLink_Init(PcLinkConfig_t * const Config)
{
  if(!(Config != 0x00))
    {
      //TODO: Handle Error
      return;
    }

	for(int i = 0; i < PC_LINK_MAX; i++) 
		{
			Config[i].PcLinkSendAllow = PC_LINK_SEND_ALLOW_ON;
		}

  gConfig = Config;  
}

extern void 
PcLink_Update(void)
{
  uint8_t i;
  uint8_t Res;
  uint8_t Rcv;

  //update the uart receive buffers
  Uart_ReceiveUpdate();

  for(i = 0; i < PC_LINK_MAX; i++) 
		{
      Res = Uart_PeekLastByte(gConfig[i].Uart, &Rcv);
      
      if(Res == 1) 
        { 
          gConfig[i].PcLinkSendAllow = PC_LINK_SEND_ALLOW_ON;
          if(Rcv == PC_LINK_XOFF)
            {
              gConfig[i].PcLinkSendAllow = PC_LINK_SEND_ALLOW_OFF;
              Uart_ReceiveByte(gConfig[i].Uart, &Rcv);
            }
        }
    }
    
}

/*****************************End of File ************************************/
