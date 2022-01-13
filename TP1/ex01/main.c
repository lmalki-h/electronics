#include <avr/io.h>

void main(void)
{
	DDRB |= ( 1 << PB1) ; //set PB1 to output mode
	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1A |= (1 << COM1A0);
	TCCR1B |= ( 1 << WGM12);

	TCCR1B |= (1 << CS12); //set 0-2 bits of TCCR1B to prescalar. see: 16.11.2 & Table 16-5.
	
	ICR1 = F_CPU / 256 - 1; //

	OCR1A = ICR1 / 10;
	for (;;) ;
}
