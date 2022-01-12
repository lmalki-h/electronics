#include <avr/io.h>

void main(void) {
	DDRB |= ( 1 << PB3 ); //set third bit to output mode
	PORTB |= ( 1 << PB3 ); //set third bit to high mode
	for (;;);   
}
