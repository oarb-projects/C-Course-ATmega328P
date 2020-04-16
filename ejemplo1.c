/*
* codigoc1.c
*
* Created: 4/15/2020 9:00:39 PM
* Author : oscar
*/ 

//LIBRARIES
#include <avr/io.h>
#include <util/delay.h>

//CONSTANTS
#define value1 0xff
#define value2 0b00010000
#define mySwitch 2
#define DELAY 1000
#define F_CPU 1000000UL  // 1 MHz

//VARIABLES
unsigned char status;
unsigned char cpr;

void main(void)
{
    while (1) 
    {
		DDRC=(1<<PORTC5);   
		DDRD=value2;
        //decomposing status =  (PINB & (1<<mySwitch) != 0);
		cpr=(1<<mySwitch);
		status =  (PINB & cpr) != 0;
		asm("NOP");
		if(status){
			//PORTD4=1 is not the same as the bottom instruction;
			PORTD ^= (1 << 4);
			_delay_ms(250);
			_delay_ms(250);
			PORTD ^= (1 << 4);
		}
    }
}

