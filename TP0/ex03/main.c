#include <avr/io.h>

void main(void) {
	
	DDRB |= ( 1 << PB3 ); //set third bit to output mode
	for (;;) {
			
		PORTB ^= ( 1 << PB3 ); //set third bit to low mode
		for (uint32_t delay = 0; delay < 160000; delay++) ; //F_CPU is defined as 16Mhz 
	} 
}
