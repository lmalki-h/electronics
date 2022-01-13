#include <avr/io.h>
void main(void) {
	
	DDRB |= ( 1 << PB3 ); //set third bit to output mode
	DDRD = 0; //set third bit to input mode
	PORTD = 0; //set third bit to input mode
	PORTB = 0;
	for (;;) {
		if (((PIND >> PD3) & 1) == 0) {
			PORTB ^= (1 << PD3);
			while (((PIND >> PD3) & 1) == 0) ;
			for (uint32_t delay = 0; delay < 16000; delay++) ;
		}
	} 
}
