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
#define charge_pin1 (1 << PA7)
#define charge_pin2 (1 << PA5)
#define charge_pin3 (1<<PA4)


#define Sens1 0b00000011 //TX1@PA3
#define Sens2 0b00000010 //TX2@PA2
#define Sens3 0b00000000 //TX3@PA0
#define trig 970
const int nloop=3;

int Read_Sensor(uint8_t bit, unsigned char pin, unsigned char port){
	ADMUX = bit;
	static unsigned char up_lo, up_hi, down_lo, down_hi;
	int cont,i; 
	int sum=0;
	for  (cont=0;cont< nloop; cont++){
	settle_delay();
   set(port, pin);
   charge_delay_1();
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC))
      ;
   up_lo = ADCL;
   up_hi = ADCH;
   settle_delay();
   clear(port, pin);
   charge_delay_1();
   ADCSRA |= (1<<ADSC);
   while (ADCSRA & (1<<ADSC))
      ;
   down_lo = ADCL;
   down_hi = ADCH;

   int x = 256*up_hi+up_lo;
   int y=256*down_hi+down_lo;
   int z= x+(1023-y);
   sum+=z;
	} 
	sum=sum/nloop;
   return sum;

}

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

 //Set prescaler to 128
 ADCSRA = (1 << ADEN); // enable
 ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
   // initialize output pins
   set(serial_port, serial_pin_out);
   output(serial_direction, serial_pin_out);

   DDRB = 0xFF;
   output(charge_direction, charge_pin1);
   output(charge_direction, charge_pin2);
   output(charge_direction, charge_pin3);
 
while(1){
   int z= Read_Sensor(Sens2,  charge_pin2, charge_port);//abajo
   if (z>trig){
      PORTB &= ~(1<<PB2); //PORTx |=(the value<<number positions)
   }
   else{
      PORTB |= (1<<PB2); //PORTx |=(the value<<number positions)
   }
   int x= Read_Sensor(Sens3,  charge_pin3, charge_port);//medio
   if (x>trig-10){
      PORTB &= ~(1<<PB1); //PORTx |=(the value<<number positions)
   }
   else{
      PORTB |= (1<<PB1); //PORTx |=(the value<<number positions)
   }
	int y= Read_Sensor(Sens1,  charge_pin1, charge_port);//arriba
   if (y>trig){
      PORTB &= ~(1<<PB0); //PORTx |=(the value<<number positions)
   }
   else{
      PORTB |= (1<<PB0); //PORTx |=(the value<<number positions)
   }
}
}
