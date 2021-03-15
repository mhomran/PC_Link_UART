/**
 * @file uart.h
 * @author Mohamed Hassanin
 * @brief A UART driver configuration header file.
 * @version 0.1
 * @date 2021-03-07
 */
#ifndef UART_CFG_H
#define UART_CFG_H

/**********************************************************************
* Preprocessor constants
**********************************************************************/
//TODO: choose the fine buffer size for your application
#define UART_BUFF_SIZE 80 /**< define the number of bytes in a UART buffer */

//TODO: choose a unique module ID
#define UART_MODULE_ID 0x01 /**< define the module id to use in error handling */
/**********************************************************************
* Typedefs
**********************************************************************/
/**
 * Defines the possible baud rate 
 */
typedef enum 
{
	/* TODO: Populate this list based on possible baudrate */
	UART_BAUDRATE_2400, 
	UART_BAUDRATE_4800,
	UART_BAUDRATE_9600,
	UART_BAUDRATE_14400,
	UART_BAUDRATE_19200,
	UART_BAUDRATE_28800,
	UART_BAUDRATE_38400,
	UART_BAUDRATE_57600,
	UART_BAUDRATE_76800,
	UART_BAUDRATE_115200,
	UART_BAUDRATE_230400,
	UART_BAUDRATE_250000,
	UART_BAUDRATE_500000,
	UART_BAUDRATE_1000000
}UartBaudrate_t;

/**
 * Defines the possible stop bits 
 */
typedef enum 
{
  /* TODO: Populate this list based on possible stop bits */
  UART_STOP_BIT_1,
  UART_STOP_BIT_2,
  UART_STOP_BIT_MAX,
}UartStopBit_t;

typedef enum
{
  UART_PARTIY_NO, 
  UART_PARTIY_EVEN, 
  UART_PARTIY_ODD, 
} UartParity_t;

/**
* Defines an enumerated list of all the uart pripherals on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
*/
typedef enum
{
  /* TODO: Populate this list based on the MCU */
  UART_0,
  UART_MAX
}Uart_t;

typedef struct
{
  Uart_t Uart; /**< the UART peripheral id */
  UartBaudrate_t Baudrate; /**< the UART baudrate */
  UartStopBit_t StopBit; /**< the UART number of stop bits */
  UartParity_t Parity; /**< the UART parity option */
}UartConfig_t;

/******************************************************************************
 * Function prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern const UartConfig_t* Uart_GetConfig(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* UART_CFG_H */
/*****************************End of File ************************************/
