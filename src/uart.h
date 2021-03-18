/**
 * @file uart.h
 * @author Mohamed Hassanin
 * @brief A UART driver header file.
 * @version 0.1
 * @date 2021-03-07
 */
#ifndef UART_H
#define UART_H

/******************************************************************************
 * typedefs
 ******************************************************************************/

/**
 * @brief A service id for error handling
 */
typedef enum
{
  UART_INIT_ID,
  UART_SEND_UPDATE_ID,
  UART_RECEIVE_UPDATE_ID,
  UART_SEND_BYTE_ID,
  UART_RECEIVE_BYTE_ID,
  UART_SEND_STRING_ID,
  UART_RECEIVE_STRING_ID,
  UART_PEEK_LAST_BYTE_ID
} UartServiceId_t;

/**
 * @brief types of possible realtime errors 
 */
typedef enum
{
  UART_E_PARAM, /**< An invalid parameter passed to a function */
  UART_E_FRAME, /**< The Uart frame is wrong */
  UART_E_OVERRUN, /**< Overrun error (wasted received value) */
  UART_E_PARITY, /**< parity error */
  UART_E_TB_NEMPTY /**< transmit buffer not empty */
} UartError_t;

/******************************************************************************
 * Includes
 ******************************************************************************/
#include <inttypes.h>
#include "uart_cfg.h"
/******************************************************************************
 * Function prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern void Uart_Init(const UartConfig_t * const Config);

extern void Uart_SendUpdate(const Uart_t Uart);
extern void Uart_ReceiveUpdate(const Uart_t Uart);

extern uint8_t Uart_SendByte(const Uart_t Uart, const uint8_t Data);
extern uint8_t Uart_ReceiveByte(const Uart_t Uart, uint8_t* const Data);
extern uint8_t Uart_PeekLastByte(const Uart_t Uart, uint8_t* const Data);

extern uint8_t Uart_SendString(const Uart_t Uart, const uint8_t * const Data, const uint8_t DataSize);
extern uint8_t Uart_ReceiveString(const Uart_t Uart, uint8_t * const Data, const uint8_t DataSize);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* UART_H */
/*****************************End of File ************************************/
