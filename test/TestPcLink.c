/**
 * @file TestPcLink.c
 * @author Mohamed Hassanin
 * @brief The test file for the PC LINK module.
 * @version 0.1
 * @date 2021-03-16
 */
/*****************************************************************************
* Includes
******************************************************************************/
/// @cond NODOC
/* Include Unity */
#include <stdio.h>
#include "unity.h"
/// @endcond

#include "pc_link.h" /**< module under the test */
#include "pc_link_cfg.h"
#include "Mock_uart.h" 

/**********************************************************************
* Functions Declarations
**********************************************************************/
static uint8_t Uart_PeekLastByteSetXOFF_Callback(const Uart_t Uart,
 uint8_t* const Data, int);
static uint8_t Uart_PeekLastByteSetXON_Callback(const Uart_t Uart,
 uint8_t* const Data, int);

/**********************************************************************
* Variable Definitions
**********************************************************************/
static PcLinkConfig_t * gConfig;

/**********************************************************************/

void 
setUp(void)
{
  const PcLinkConfig_t * config = PcLink_GetConfig();
  gConfig = (PcLinkConfig_t *)config;
  PcLink_Init(gConfig);
}

void tearDown(void)
{
}

/*****************************************************************************
* Test cases
******************************************************************************/
void 
test_SendUpdateIsCalledWheneverSendingIsAllowed(void)
{
  //given
  for(int i = 0; i < PC_LINK_MAX; i++) 
		{
      Uart_ReceiveUpdate_Expect(gConfig[i].Uart);

      Uart_PeekLastByte_StubWithCallback(Uart_PeekLastByteSetXON_Callback);
      
      Uart_ReceiveByte_IgnoreAndReturn(1);

      Uart_SendUpdate_Expect(gConfig[i].Uart);
    }

  //act
  PcLink_Update();
}

void 
test_SendUpdateIsNotCalledWheneverSendingIsNotAllowed(void)
{
  //given
  for(int i = 0; i < PC_LINK_MAX; i++) 
		{
      Uart_ReceiveUpdate_Expect(gConfig[i].Uart);

      Uart_PeekLastByte_StubWithCallback(Uart_PeekLastByteSetXOFF_Callback);
      
      Uart_ReceiveByte_IgnoreAndReturn(1);
    }

  //act
  PcLink_Update();
}
/*****************************************************************************
* Helper functions
******************************************************************************/
static uint8_t 
Uart_PeekLastByteSetXOFF_Callback(const Uart_t Uart, uint8_t* const Data, int a)
{
  *Data = PC_LINK_XOFF;
  return 1;
}

static uint8_t 
Uart_PeekLastByteSetXON_Callback(const Uart_t Uart, uint8_t* const Data, int a)
{
  *Data = PC_LINK_XON;
  return 1;
}

/*****************************End of File ************************************/

