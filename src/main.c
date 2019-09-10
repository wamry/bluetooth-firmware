#include <xc.h>
#include "config.h"
#include "usart.h"

char UART_Buffer = 0;

void main() {
    char data_in;
    TRISA   = 0x3E;             /* set PINA0 as output ports */
    LATA    = 0x01;             /* set PINA0 high */
    USART_Init(9600);           /* initialize USART operation with 9600 baud rate */ 

    while(1){
        __delay_ms(5000);
        LATA0 = ~LATA0;         /* Toggle LED */
    }
}

void __interrupt(high_priority) BT_RCV(void){
	if (RCIF == 1) {
        UART_Buffer = RCREG;                /* Read The Received Data Buffer */
		if(UART_Buffer == '1') {
            LATA0 = 1;                      /* turn ON LED */
            USART_SendString("LED_ON\n");   /* send LED ON status to terminal */
        } else if(UART_Buffer == '2') {
            LATA0 = 0;                      /* turn OFF LED */
            USART_SendString("LED_OFF\n");  /* send LED oFF status to terminal */
        } else {
            USART_SendString("unknown");    /* send msg to select proper option */
        }
		RCIF = 0;                           /* clear flag */
	}
}