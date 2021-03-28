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
 * Module variable definitions
 ******************************************************************************/
PcLinkSendAllow_t PcLinkSendAllow[PC_LINK_MAX]; /**< is it allowed to send */

const PcLinkConfig_t* gConfig; /** a pointer to the configuration table */
/******************************************************************************
 * Function Definitions
 ******************************************************************************/
/******************************************************************************
* Function : PcLink_Init()
*//**
* \b Description: Initialization function for the PC link module<br/>
* \b PRE-CONDITION: Configuration table is populated<br/>
* @param Config a pointer to the configuration table of the links.
* @return void 
******************************************************************************/
extern void 
PcLink_Init(const PcLinkConfig_t* const Config)
{
  if(!(Config != 0x00))
    {
      //TODO: Handle Error
      return;
    }

	for(int i = 0; i < PC_LINK_MAX; i++) 
		{
			PcLinkSendAllow[i] = PC_LINK_SEND_ALLOW_ON;
		}

  gConfig = Config;  
}

/******************************************************************************
* Function : PcLink_Update()
*//**
* \b Description: Update function to control the PC links sending and
* receiving<br/>
* \b PRE-CONDITION: PcLink_Init is called correctly<br/>
* \b POST-CONDITION: The uart peripherals would send or receive correctly
* depending on the received data.<br/>
* @return void 
******************************************************************************/
extern void 
PcLink_Update(void)
{
  uint8_t i;
  uint8_t Res;
  uint8_t Rcv;

  //update the uart receive buffers

  for(i = 0; i < PC_LINK_MAX; i++) 
		{
      Uart_ReceiveUpdate(gConfig[i].Uart);
      Res = Uart_PeekLastByte(gConfig[i].Uart, &Rcv);
      
      if(Res == 1) 
        { 
          if(Rcv == PC_LINK_XOFF)
            {
              PcLinkSendAllow[i] = PC_LINK_SEND_ALLOW_OFF;
              Uart_ReceiveByte(gConfig[i].Uart, &Rcv);
            }
          else if (Rcv == PC_LINK_XON)
            {
              PcLinkSendAllow[i] = PC_LINK_SEND_ALLOW_ON;
              Uart_ReceiveByte(gConfig[i].Uart, &Rcv);
            }
          else
            {
              //DO NOTHING
            }  
        }

      if(PcLinkSendAllow[i] == PC_LINK_SEND_ALLOW_ON)
        {
          Uart_SendUpdate(gConfig[i].Uart);
        }
    }

}

/*****************************End of File ************************************/
