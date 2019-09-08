/* PIC18F2550 USART Source File */
#include <xc.h>
#include "usart.h"

/*******************USART Initialization*************************************/
void USART_Init(long baud_rate){
    TRISC6 = 0;                       /*Make Tx pin as output*/
    TRISC7 = 1;                       /*Make Rx pin as input*/
    SPBRG = (int)BaudValue(baud_rate);                /*baud rate=9600, SPBRG = (F_CPU /(64*9600))-1*/
    TXSTA = 0x20;                     /*Transmit Enable(TX) enable*/ 
    RCSTA = 0x90;                     /*Receive Enable(RX) enable and serial port enable */
}
/*******************RECEIVE FUNCTION*****************************************/
char USART_ReceiveChar(){
    while(RCIF == 0);                 /*wait for receive interrupt flag*/
    return(RCREG);                  /*receive data is stored in RCREG register and return to main program */
}
/******************TRANSMIT FUNCTION*****************************************/ 
void USART_TransmitChar(char out){     
        while(TXIF == 0);            /*wait for transmit interrupt flag*/
        TXREG = out;                 /*wait for transmit interrupt flag to set which indicates TXREG is ready
                                    for another transmission*/    
}
void USART_SendString(const char *out){
   while(*out!='\0'){       
        USART_TransmitChar(*out);
        out++;
   }
}