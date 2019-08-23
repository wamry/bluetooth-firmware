#include <xc.h>
#include "misc.h"

#pragma config FOSC = HS					/* High speed external oscillater, with PLL not allowed */
#pragma config CPUDIV = OSC4_PLL6			/* [Primary Oscillator Src: /4][96 MHz PLL Src: /6] */
#pragma config WDT = OFF					/* Watch dog off */
#pragma config LVP = OFF					/* Single-Supply ICSP disabled */

int main() {
	while(1) {
		delay_ms(700);
	}
	return 0;
}
