#ifndef UNIV_FBK_UART_H_
#define UNIV_FBK_UART_H_

#include <DataTypes.h>

#define FCLK (0x64280000)

#define KNX_IP_UNIV_FBK_A_UART_CONTROL				(KNX_IP_UNIV_FBK_A + 0x0300)
#define KNX_IP_UNIV_FBK_A_UART_RQUEUE_BASE			(KNX_IP_UNIV_FBK_A + 0x0310)
#define KNX_IP_UNIV_FBK_A_UART_TQUEUE_BASE			(KNX_IP_UNIV_FBK_A + 0x0332)

typedef enum UFBINSTANCEENUM
{
	UFB_INSTANCE_1 = 1,
	UFB_INSTANCE_2 = 2
} UFBInstance;

typedef enum TXSTATUS
{
	DONE = 0,
	NOTDONE = 1
} TXStatus;

typedef struct{
	volatile uint16 UNIV_FBK_UART_PLIMIT;
	volatile uint16 UNIV_FBK_UART_SERCFG;
	volatile uint16 UNIV_FBK_UART_RSTERR;
	volatile uint16 UNIV_FBK_UART_RBUFF;
	volatile uint16 UNIV_FBK_UART_UARTSTAT;
	volatile uint16 UNIV_FBK_UART_TBUFF;
}UNIV_FBK_controlRegs;

typedef struct{
	volatile uint16 UNIV_FBK_UART_TQUEUE01;
	volatile uint16 UNIV_FBK_UART_TQUEUE02;
	volatile uint16 UNIV_FBK_UART_TQUEUE03;
	volatile uint16 UNIV_FBK_UART_TQUEUE04;
	volatile uint16 UNIV_FBK_UART_TQUEUE05;
	volatile uint16 UNIV_FBK_UART_TQUEUE06;
	volatile uint16 UNIV_FBK_UART_TQUEUE07;
	volatile uint16 UNIV_FBK_UART_TQUEUE08;
	volatile uint16 UNIV_FBK_UART_TQUEUE09;
	volatile uint16 UNIV_FBK_UART_TQUEUE10;
	volatile uint16 UNIV_FBK_UART_TQUEUE11;
	volatile uint16 UNIV_FBK_UART_TQUEUE12;
	volatile uint16 UNIV_FBK_UART_TQUEUE13;
	volatile uint16 UNIV_FBK_UART_TQUEUE14;
	volatile uint16 UNIV_FBK_UART_TQUEUE15;
}UNIV_FBK_TXBuffer;

typedef struct{
	volatile uint16 UNIV_FBK_UART_RQUEUE00;
	volatile uint16 UNIV_FBK_UART_RQUEUE01;
	volatile uint16 UNIV_FBK_UART_RQUEUE02;
	volatile uint16 UNIV_FBK_UART_RQUEUE03;
	volatile uint16 UNIV_FBK_UART_RQUEUE04;
	volatile uint16 UNIV_FBK_UART_RQUEUE05;
	volatile uint16 UNIV_FBK_UART_RQUEUE06;
	volatile uint16 UNIV_FBK_UART_RQUEUE07;
	volatile uint16 UNIV_FBK_UART_RQUEUE08;
	volatile uint16 UNIV_FBK_UART_RQUEUE09;
	volatile uint16 UNIV_FBK_UART_RQUEUE10;
	volatile uint16 UNIV_FBK_UART_RQUEUE11;
	volatile uint16 UNIV_FBK_UART_RQUEUE12;
	volatile uint16 UNIV_FBK_UART_RQUEUE13;
	volatile uint16 UNIV_FBK_UART_RQUEUE14;
	volatile uint16 UNIV_FBK_UART_RQUEUE15;
}UNIV_FBK_RXBuffer;

typedef struct {
     uint16 * buf;
     int head;
     int tail;
     int size;
}UNIV_FBK_FIFOBuffer;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile UNIV_FBK_controlRegs             *UNIV_FBK_controlRegsOvly;
typedef volatile UNIV_FBK_TXBuffer             *UNIV_FBK_TXBufferOvly;
typedef volatile UNIV_FBK_RXBuffer             *UNIV_FBK_RXBufferOvly;

#ifdef __cplusplus
extern "C" {
#endif

void univ_fbk_uart_sendTestBytes(int );
void univ_fbk_uart_init_default();
//void univ_fbk_uart0_init(uint8 pLimit, uint16 baudRate, uint8 parity, uint8 parSense);
int is_univ_fbk_uart_xmt_complete(void );
//void univ_fbk_uart_buf_init(UNIV_FBK_FIFOBuffer * f, uint16 * buf, uint16 size);
//uint16 univ_fbk_uart_buf_write(UNIV_FBK_FIFOBuffer * f, const void * buf, uint16 nbytes);


#ifdef __cplusplus
}
#endif

#endif /*UNIV_FBK_UART_H_*/
