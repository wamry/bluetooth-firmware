
/* PIC18F2550 USART Header File */
 
#ifndef USART_HEADER_FILE_H
#define	USART_HEADER_FILE_H
#define FOSC 8000000

void USART_Init(long);
void USART_TransmitChar(char);
void USART_SendString(const char *);
void MSdelay(unsigned int val);
char USART_ReceiveChar();

#define Baud_value (((float)(FOSC/64)/(float)baud_rate)-1)
//#define Baud_value (((float)(F_CPU)/(float)64*baud_rate)-1)

#endif	/* USART_HEADER_FILE_H */

