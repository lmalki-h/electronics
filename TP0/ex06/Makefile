RM = rm 
RF = -rf
CC= avr-gcc

all: hex flash

hex:
	$(CC) -g -D F_CPU=16000000 -mmcu=atmega328p -c main.c #source to object code
	$(CC) -g -mmcu=atmega328p -o main.bin main.o
	avr-objcopy -j .text -j .data -O ihex main.bin main.hex

flash:
	avrdude -p atmega328p -c arduino -P /dev/ttyUSB0 -U flash:w:main.hex:i


clean:
	$(RM) $(RF) main.o
	$(RM) $(RF) main.hex
	$(RM) $(RF) main.bin
