#include <avr/io.h>
void main(void) {
	
	DDRB |= ( 1 << PB3 ); //set third bit to output mode
	DDRD |= (0 << PD3); //set third bit to input mode
	PORTD |= (0 << PD3); //set third bit to input mode
	for (;;) {
		uint8_t bit = ~ (PIND >> PD3) & 1;
		PORTB &= ~(1 << PB3);
		PORTB |= (bit << PB3);
		//PORTB = ~PIND & (1 << PIN3);
	} 
}
