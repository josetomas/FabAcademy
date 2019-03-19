#define F_CPU               20000000
#define BAUDRATE            9600
#define CYCLES_PER_BIT      ( F_CPU / BAUDRATE )

#if (CYCLES_PER_BIT > 255)
#define DIVISOR             8
#define PRESCALE            2
#else
#define DIVISOR             1
#define PRESCALE            1
#endif
#define FULL_BIT_TICKS      ( CYCLES_PER_BIT / DIVISOR )

DDRA &= ~(1 << DDA1);          // Set pin PA1 to input
PORTA|= 1 << PA1;             // Enable internal pull-up on pin PA1

USICR = 0;                     // Disable USI

GIMSK |= 1<<PCIE;               // Enable pin change interrupts
PCMSK |= 1<<PCINT1;             // Enable pin change on pin PA1

ISR (PCINT1_vect)
{
  uint8_t pinbVal = PINA;
  if (!(pinbVal & 1<<PINA1))   // Trigger if DI is Low
  {
    onSerialPinChange();
  }
}
