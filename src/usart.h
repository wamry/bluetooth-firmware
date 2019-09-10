
/* PIC18F2550 USART Header File */
 
#ifndef USART_HEADER_FILE_H
#define	USART_HEADER_FILE_H

void USART_Init(long);
void USART_TransmitChar(char);
void USART_SendString(const char *);

//_XTAL_FREQ 16000000 defined in compile command
#define SPBRG_HighSpeed(baud_rate) (((float)(_XTAL_FREQ/16)/(float)baud_rate)-1)
#define SPBRG_LowSpeed(baud_rate) (((float)(_XTAL_FREQ/64)/(float)baud_rate)-1)

#endif	/* USART_HEADER_FILE_H */

