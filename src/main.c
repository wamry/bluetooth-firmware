#include <pic18f2550.h>
#include "config.h"
#include "usart.h"

void main() {
    char data_in;
    OSCCON = 0x72;              /* use internal oscillator frequency which is set to 8 MHz */
    TRISA = 0x3C;               /* set PINA0 & PINA1 as output ports */
    LATA  = 0x03;               /* set PINA0 & PINA1 high */
    USART_Init(9600);           /* initialize USART operation with 9600 baud rate */ 
    MSdelay(50);
    while(1){
        data_in=USART_ReceiveChar();
        if(data_in == '1') {   
            LATA0 = 1;                    /* turn ON LED */
            USART_SendString("LED_ON\n"); /* send LED ON status to terminal */
        }
        else if(data_in == '2') {
            LATA0 = 0;                   /* turn OFF LED */
            USART_SendString("LED_OFF\n");/* send LED ON status to terminal */
        }
        else {
            //USART_SendString(" select 1 or 2");/* send msg to select proper option */
            LATA1 = ~LATA1;
        }
        MSdelay(100);
    }
}
