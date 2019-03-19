#include <avr/io.h>
#include <avr/delay.h>
#include <util/delay.h>
int main (void)
{
DDRA = DDRA | 0b11110111;
DDRB = 0xFF;
while(1) {
if (!(PINA & (1<<PA3))) {
  PORTB |=(1<<PB2); //PORTx |=(the value<<number positions)
  _delay_ms (100); 
  PORTB &= ~(1<<PB2); 
  _delay_ms (100);
}
  else {
    PORTA |= (1 << PA2);
  _delay_ms (10); 
  PORTA &= ~(1<<PA2); 
  _delay_ms (10);
  }
};
}