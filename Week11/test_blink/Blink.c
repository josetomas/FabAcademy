#include <avr/io.h>
#include <util/delay.h>
int main (void)
{
DDRA = 0xFF;
DDRB = 0xFF;
while(1) {
  PORTA |=(1<<PA7); //PORTx |=(the value<<number positions)
  _delay_ms (100); 
  PORTA &= ~(1<<PA7); 
  _delay_ms (100);
}
}