#include <avr/io.h>

//nombre magic 42
void EEPROM_write(unsigned int uiAddress, unsigned char ucData) {
    while (EECR & (1 << EEPE)) ;

    EEAR = uiAddress;
    EEDR = ucData;

    EECR |= ( 1 << EEMPE);

    EECR |= ( 1 << EEPE);

}

unsigned char EEPROM_read(unsigned int uiAddress) {

    while (EECR & (1 << EEPE)) ;

    EEAR = uiAddress;

    EECR |= ( 1 << EERE );

    return EEDR;
}

void main(void)
{
	DDRB = 0xff; //set all pins to output mode

	DDRD = 0; //set PD2 as button
    if (EEPROM_read(0x0) == 0) { //will read 
        EEPROM_write(0x0, 1); //
        EEPROM_write(0x1, 0);
    }

	uint8_t last_state = (PIND >> PD2) & 1;
	for (;;)
	{
		uint8_t new_state = (PIND >> PD2) & 1;
		if (last_state != new_state)
		{
			if (new_state == 0) {
                uint8_t counter = (uint8_t)EEPROM_read(0x1);
				PORTB = counter ;
                EEPROM_write(0x1, counter + 1);
            }
			for (uint32_t delay = 0; delay < 50000; delay++) ;
			last_state = new_state;
		}
	}	
}
