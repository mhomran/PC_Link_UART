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

/**********************************************************************
* Variable Definitions
**********************************************************************/
static PcLinkConfig_t * gConfig;

/**********************************************************************/

void setUp(void)
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
test_SendingAllowedAfterInit(void) 
{
	for(int i = 0; i < PC_LINK_MAX; i++) 
		{
			TEST_ASSERT_EQUAL(gConfig[i].PcLinkSendAllow, PC_LINK_SEND_ALLOW_ON);
		}
}


/*****************************End of File ************************************/

