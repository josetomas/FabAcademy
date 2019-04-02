#include <avr/io.h>
#include <util/delay.h>

#define output(directions,pin) (directions |= pin) // set port direction for output
#define set(port,pin) (port |= pin) // set port pin
#define clear(port,pin) (port &= (~pin)) // clear port pin
#define pin_test(pins,pin) (pins & pin) // test for port pin
#define bit_test(byte,bit) (byte & (1 << bit)) // test for bit set
#define bit_delay_time 102 // bit delay for 9600 with overhead
#define bit_delay() _delay_us(bit_delay_time) // RS232 bit delay
#define half_bit_delay() _delay_us(bit_delay_time/2) // RS232 half bit delay
#define charge_delay_1() _delay_us(1) // charge delay 1
#define charge_delay_2() _delay_us(10) // charge delay 2
#define charge_delay_3() _delay_us(100) // charge delay 3
#define settle_delay() _delay_us(100) // settle delay
#define char_delay() _delay_ms(10) // char delay

#define serial_port PORTA
#define serial_direction DDRA
#define serial_pin_out (1 << PA1)
#define charge_port PORTA
#define charge_direction DDRA
#define charge_pin (1 << PA7)

#define admux 0b00000011 //REFS1,REFS0,ADLAR,REFS2,MUX3,MUX2,MUX1,MUX0


void put_char(volatile unsigned char *port, unsigned char pin, char txchar) {
   //
   // send character in txchar on port pin
   //    assumes line driver (inverts bits)
   //
   // start bit
   //
   clear(*port,pin);
   bit_delay();
   //
   // unrolled loop to write data bits
   //
   if bit_test(txchar,0)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,1)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,2)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,3)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,4)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,5)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,6)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   if bit_test(txchar,7)
      set(*port,pin);
   else
      clear(*port,pin);
   bit_delay();
   //
   // stop bit
   //
   set(*port,pin);
   bit_delay();
   //
   // char delay
   //
   bit_delay();
   }
int main (void){
 // Define clock devider
 CLKPR = (1<<CLKPCE);
 CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
 // Define ADMUX Register
 ADMUX = admux;
 //Set prescaler to 128
 ADCSRA = (1 << ADEN); // enable
 ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
   // initialize output pins
   set(serial_port, serial_pin_out);
   output(serial_direction, serial_pin_out);
   clear(charge_port, charge_pin);
   output(charge_direction, charge_pin);

   DDRB = 0xFF;

 static unsigned char up_lo, up_hi, down_lo, down_hi;

while(1){
   settle_delay();
   set(charge_port, charge_pin);
   charge_delay_1();
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC))
      ;
   up_lo = ADCL;
   up_hi = ADCH;
   settle_delay();
   clear(charge_port, charge_pin);
   charge_delay_1();
   ADCSRA |= (1<<ADSC);
   while (ADCSRA & (1<<ADSC))
      ;
   down_lo = ADCL;
   down_hi = ADCH;

   int x = 256*up_hi+up_lo;
   int y=256*down_hi+down_lo;
   int z= x-y; 
   if (z>200){
      PORTB |=(1<<PB0); //PORTx |=(the value<<number positions)
      _delay_ms (100); 
      PORTB &= ~(1<<PB0); 
      _delay_ms (100);
   }
   else{
      PORTB |=(1<<PB1); //PORTx |=(the value<<number positions)
      _delay_ms (100); 
      PORTB &= ~(1<<PB1); 
      _delay_ms (100);
   }
      
}
}
