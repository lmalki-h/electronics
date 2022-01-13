#include <avr/io.h>
	// DDRB = (1 << PIN3); //set pin3 to output mode LED
	// DDRD &= ~(1 << PIN3); //set pin3 to input mode button
   	
	// TCNT1 = 0; //set timer value to 0
	// TIMSK1 |= (1 << OCIE1A); //enable compare with output A
	// OCR1A = F_CPU / 256 - 1; //set max value to 500ms
	// TCCR1B |= (1 << WGM12); //enable CTC 16.7.2
	// TCCR1B |= (1 << WGM13); //enable CTC for OCR1
	// OCIE1x = 1;
	//TIMER1_COMPA_vect
void main(void) {
	TCCR1A = 0;
	TCCR1B = 0;
	COM1A1 = 1; //clear OCR1A on Compare Match (CTC mode). see: 16.11.1 & Table 16-11
	TCCR1A |= (1 << WGM12); //set CTC mode
	TCCR1B |= ;
	TCCR1B |= (1 << CS12); //set 0-2 bits of TCCR1B to prescalar. see: 16.11.2 & Table 16-5.
	
	for (;;) ;
}
