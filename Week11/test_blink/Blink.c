#include <avr/io.h>
#include <avr/delay.h>
#include <util/delay.h>
int main (void)
{
DDRA = DDRA | 0b11110111;
DDRB = 0xFF;
while(1) {
  PORTB |=(1<<PB0); //PORTx |=(the value<<number positions)
  _delay_ms (100); 
  PORTB &= ~(1<<PB0); 
  _delay_ms (100);
}
}