#ifndef MISC_H
#define MISC_H
#define _XTAL_FREQ 2000000					/* Device Clock speed/Frequency 2MHz */

#define _BV(NUM)				(1 << NUM)
#define toggle(LAT,PIN)			LAT		^=  _BV(PIN)
#define set_output(TRIS,PIN)	TRIS	&= ~_BV(PIN)
#define set_input(TRIS,PIN)		TRIS	|=  _BV(PIN)
#define set_high(LAT,PIN)		LAT		|=  _BV(PIN)
#define set_low(LAT,PIN)		LAT		&= ~_BV(PIN)
#define read_bin(PORT,PIN)		(PORT & _BV(PIN) == _BV(PIN))
#define change(LAT,PIN,x)		LAT ^= (-x ^ LAT) & (1 << PIN)
#define delay_ms(x)				_delay(((unsigned long)((x/4)*(_XTAL_FREQ/1000.0))))
#define delay_us(x)				_delay(((unsigned long)((x/4)*(_XTAL_FREQ/1000000.0))))
#define delay_cycles(x)			_delay(x)

#endif //MISC_H