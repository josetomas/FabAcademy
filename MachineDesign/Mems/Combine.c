//
// hello.SPU0414HR5H.c
//
// SPU0414HR5H microphone hello-world
//    9600 baud FTDI interface
//
// Neil Gershenfeld 11/17/15
// (c) Massachusetts Institute of Technology 2015
//
// This work may be reproduced, modified, distributed,
// performed, and displayed for any purpose. Copyright is
// retained and must be preserved. The work is provided
// as is; no warranty is provided, and users accept all 
// liability.
//

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
#define char_delay() _delay_ms(10) // char delay
#define serial_port PORTA
#define serial_direction DDRA
#define serial_pin_out (1 << PA1)
#define NPTS 100 // points in buffer
#define admux 0b10000010

#define PWM_port PORTA
#define PWM_direction DDRA
#define PWM_pin_1 (1 << PA7)

#define loop_count 10

int trigger = 950;
int i=0;

void put_char(volatile unsigned char *port, unsigned char pin, char txchar) {
   //
   // send character in txchar on port pin
   //    assumes line driver (inverts bits)
   //
   // start bit
   //
   clear(*port,pin);
   bit_delay();
   clear(PWM_port, PWM_pin_1);
   output(PWM_direction, PWM_pin_1);
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

int main(void) {
   //
   // main
   //
   static unsigned char array_lo,array_hi;
   //
   // set clock divider to /1
   //
   CLKPR = (1 << CLKPCE);
   CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
   //
   // initialize output pins
   //
   set(serial_port, serial_pin_out);
   output(serial_direction, serial_pin_out);
   //
   // init A/D
   //
   ADMUX =  admux;
   ADCSRA = (1 << ADEN) // enable
      | (1 << ADPS2) | (1 << ADPS1) | (0 << ADPS0); // prescaler /64
   //
   // main loop
   //
      DDRA |= (1 << PA0);   
   while (1) {
      //
      // send framing
      //
      put_char(&serial_port, serial_pin_out, 1);
      char_delay();
      put_char(&serial_port, serial_pin_out, 2);
      char_delay();
      put_char(&serial_port, serial_pin_out, 3);
      char_delay();
      put_char(&serial_port, serial_pin_out, 4);
      char_delay();
      //
      // free-running sample loop
      //
         //
         // initiate conversion
         //
         ADCSRA |= (1 << ADSC);
         //
         // wait for completion
         //
         while (ADCSRA & (1 << ADSC))
            ;
         //
         // save result
         //
         array_lo = ADCL;
         array_hi = ADCH;
         int value = 256*array_hi+array_lo;
         if (value>trigger){
            while(1){
               for (i = 0; i < loop_count; ++i) {
               set(PWM_port,PWM_pin_1);
               _delay_us(1000);
               clear(PWM_port,PWM_pin_1);
               _delay_us(19000);
         }
      //
      // 1.5 ms on time, both
      //
            for (i = 0; i < loop_count; ++i) {
               set(PWM_port,PWM_pin_1);
               _delay_us(1500);
               clear(PWM_port,PWM_pin_1);
               _delay_us(18500);
         }
      //
      // 2 ms on time, both
      //
            for (i = 0; i < loop_count; ++i) {
               set(PWM_port,PWM_pin_1);
               _delay_us(2000);
               clear(PWM_port,PWM_pin_1);
               _delay_us(18000);
         }

      //
      // 1 ms on time, channel 1
      //
            for (i = 0; i < loop_count; ++i) {
               set(PWM_port,PWM_pin_1);
               _delay_us(1000);
               clear(PWM_port,PWM_pin_1);
               _delay_us(19000);
         }

      //
      // 1.5 ms on time, channel 1
      //
            for (i = 0; i < loop_count; ++i) {
               set(PWM_port,PWM_pin_1);
               _delay_us(1500);
               clear(PWM_port,PWM_pin_1);
               _delay_us(18500);
         }
      //
      // 2 ms on time, channel 1
      //
            for (i = 0; i < loop_count; ++i) {
               set(PWM_port,PWM_pin_1);
               _delay_us(2000);
               clear(PWM_port,PWM_pin_1);
               _delay_us(18000);
         }
      }
         }
         }
      }