
/* PIC18F2550 USART Header File */
 
#ifndef USART_HEADER_FILE_H
#define	USART_HEADER_FILE_H

void USART_Init(long);
void USART_TransmitChar(char);
void USART_SendString(const char *);
void MSdelay(unsigned int val);
char USART_ReceiveChar();

#define BaudValue(desired_baud_rate) (((float)(_XTAL_FREQ/64)/(float)desired_baud_rate)-1)

#endif	/* USART_HEADER_FILE_H */

