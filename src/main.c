/* Interface HC-05 Bluetooth module with PIC18F2550 */

/************* HC-05 *************
	Supported buad rates: 9600, 19200, 38400, 57600, 115200, 230400, 460800
    Default Data Mode Baud Rate: 9600, 8, N, 1
	Default Command Mode Baud Rate: 38400, 8, N, 1
	BLINKING
	Blink once in 2 sec: Module has entered Command Mode
	Repeated Blinking: Waiting for connection in Data Mode
	Blink twice in 1 sec: Connection successful in Data Mode
*/

#include "usart.h"
#include "misc.h"

#define LED_LATCH LATA0
#define LED_TRIS TRISA

void main()
{
    OSCCON=0x72;              /* use internal oscillator frequency
                                 which is set to * MHz */
    char data_in;
    LED_TRIS = 0;                /* set PORT as output port */
    USART_Init(9600);         /* initialize USART operation with 9600 baud rate */ 
    MSdelay(50);
    while(1)
    {
        data_in=USART_ReceiveChar();
        if(data_in=='1')
        {   
            LED_LATCH = 0;                    /* turn ON LED */
            USART_SendString("LED_ON"); /* send LED ON status to terminal */
        }
        else if(data_in=='2')
                
        {
            LED_LATCH = 1;                    /* turn OFF LED */
            USART_SendString("LED_OFF");/* send LED ON status to terminal */
        }
        else
        {
            USART_SendString(" select 1 or 2");/* send msg to select proper option */
        }
        MSdelay(100);
    }
    
}
