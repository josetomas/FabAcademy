#include <avr/io.h>
#include <avr/delay.h>
int main (void)
{
DDRA = DDRA | B11110111;
DDRB = 0xFF;
while(1) {
if (!(PINA & (1<<PA3))) {
  PORTB |=(1<<PB2); 
  _delay_ms (250); 
  PORTB &= ~(1<<PB2); 
  _delay_ms (250);
}
  else {
    PORTA |= (1 << PA2);
  _delay_ms (250); 
  PORTA &= ~(1<<PA2); 
  _delay_ms (250);
  }
};
}
