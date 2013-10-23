
#include "drivers/kmcl2.h"
#include "drivers/univ_fbk_uart.h"

#define UNIV_FBK_RXBUFF_LEN_MIN (1)
#define UNIV_FBK_RXBUFF_LEN_MAX (15)

UNIV_FBK_controlRegsOvly uart_control = (UNIV_FBK_controlRegsOvly) KNX_IP_UNIV_FBK_A_UART_CONTROL;
UNIV_FBK_TXBufferOvly uart_txbuf = (UNIV_FBK_TXBufferOvly) KNX_IP_UNIV_FBK_A_UART_TQUEUE_BASE;
UNIV_FBK_RXBufferOvly uart_rxbuf = (UNIV_FBK_RXBufferOvly) KNX_IP_UNIV_FBK_A_UART_RQUEUE_BASE;

// DIGIN driver scoped variables indicating if the instances have been initialized yet
uint8 s_IsInitInstance0 = 0;
uint8 s_IsInitInstance1 = 0;


int is_univ_fbk_uart_xmt_complete(){
	volatile uint16 bytes_remaining;
	bytes_remaining = uart_control->UNIV_FBK_UART_TBUFF;
		if (bytes_remaining>0){
			return 1;
		}
		else{
			return 0;
		}
}
void univ_fbk_uart_init_default(){
	uart_control->UNIV_FBK_UART_SERCFG = 6666;

}

 
void univ_fbk_uart_sendTestBytes(int nbytes) {
			univ_fbk_uart_init_default();
			uart_txbuf->UNIV_FBK_UART_TQUEUE01 = 0x01;
			uart_txbuf->UNIV_FBK_UART_TQUEUE02 = 0x02;
			uart_txbuf->UNIV_FBK_UART_TQUEUE03 = 0x03;
			uart_txbuf->UNIV_FBK_UART_TQUEUE04 = 0x04;
			uart_txbuf->UNIV_FBK_UART_TQUEUE05 = 0x05;
			uart_txbuf->UNIV_FBK_UART_TQUEUE06 = 0x06;
			uart_txbuf->UNIV_FBK_UART_TQUEUE07 = 0x07;
			uart_txbuf->UNIV_FBK_UART_TQUEUE08 = 0x08;
			uart_txbuf->UNIV_FBK_UART_TQUEUE09 = 0x09;
			uart_txbuf->UNIV_FBK_UART_TQUEUE10 = 0x0A;
			uart_txbuf->UNIV_FBK_UART_TQUEUE11 = 0x0B;
			uart_txbuf->UNIV_FBK_UART_TQUEUE12 = 0x0C;
			uart_txbuf->UNIV_FBK_UART_TQUEUE13 = 0x0D;
			uart_txbuf->UNIV_FBK_UART_TQUEUE14 = 0x0E;
			uart_txbuf->UNIV_FBK_UART_TQUEUE15 = 0x0F;
			uart_control->UNIV_FBK_UART_TBUFF = nbytes;
}



