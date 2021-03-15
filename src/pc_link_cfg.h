/**
 * @file pc_link.h
 * @author Mohamed Hassanin
 * @brief A software pattern used to transfer data from microcontrollers 
 * and some form of personal computer (PC, notebook or similar) using UART
 * communication protocol.
 * @version 0.1
 * @date 2021-03-15 
 */
#ifndef PC_LINK_CFG_H
#define PC_LINK_CFG_H

/**********************************************************************
* Typedefs
**********************************************************************/

/**
* Defines an enumerated list of all the pc links on the system
*/
typedef enum
{
  /* TODO: Populate this list based on your application */
  PC_LINK_0,
  PC_LINK_MAX
}PcLink_t;

typedef struct
{
  PcLink_t PcLink; /**< the UART peripheral id */
} PcLinkConfig_t;

/******************************************************************************
 * Function prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern const PcLinkConfig_t* PcLink_GetConfig(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* PC_LINK_CFG_H */
/*****************************End of File ************************************/
