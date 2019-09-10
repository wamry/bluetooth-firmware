/* PIC18F2550 USART Source File */
#include <xc.h>
#include "usart.h"

/*******************USART Initialization*************************************/
void USART_Init(long baud_rate){
	TRISC6  = 0;                                /*Make Tx pin as output*/
	TRISC7  = 1;                                /*Make Rx pin as input*/
	BRGH    = 0;                                /*Set For High-Speed Baud Rate*/
	SPBRG   = (int)SPBRG_LowSpeed(baud_rate);  	/*baud rate=9600, SPBRG = (F_CPU /(64*9600))-1*/
	TXSTA   = 0x20;                             /*Transmit Enable(TX) enable*/ 
	RCSTA   = 0x90;                             /*Receive Enable(RX) enable and serial port enable */

	SYNC = 0;									/*Enable Asynchronous mode*/
  	SPEN = 1;									/*Enable Serial Port for communication*/
	RCIE = 1;									/*UART Receving Interrupt Enable Bit*/
	PEIE = 1;									/*Peripherals Interrupt Enable Bit*/
	GIE	 = 1;									/*Global Interrupt Enable Bit*/
	CREN = 1;									/*Enable Data Reception*/
}
/******************TRANSMIT FUNCTION*****************************************/ 
void USART_TransmitChar(char out){     
		while(TXIF == 0);                       /*wait for transmit interrupt flag*/
		TXREG = out;                            /*wait for transmit interrupt flag to set which indicates TXREG is ready
												for another transmission*/    
}
void USART_SendString(const char *out){
   while(*out!='\0'){
		USART_TransmitChar(*out);
		out++;
   }
}