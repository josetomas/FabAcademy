#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1


SoftwareSerial mySerial( rxPin,txPin);

int brightness = 120;    // how bright the LED is, start at half brightness
int fadeAmount = 10;    // how many points to fade the LED by
unsigned long currentTime;
unsigned long loopTime;
const int pin_A = 3;  // pin 12
const int pin_B = 2;  // pin 11
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;

void setup()  {
    mySerial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(9, OUTPUT);
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  currentTime = millis();
  loopTime = currentTime; 
} 

void loop()  {
    encoder_A = digitalRead(pin_A);    // Read encoder pins
    encoder_B = digitalRead(pin_B);   
    if((!encoder_A) && (encoder_A_prev)){
      // A has gone from high to low 
      if(encoder_B!= encoder_A) {
        // B is high so clockwise
        // increase the brightness, dont go over 255
        if(brightness + fadeAmount <= 255) brightness += fadeAmount;               
      }   
      else {
        // B is low so counter-clockwise      
        // decrease the brightness, dont go below 0
        if(brightness - fadeAmount >= 0) brightness -= fadeAmount;               
      }   

    }   
    encoder_A_prev = encoder_A;     // Store value of A for next time    
    
    // set the brightness of pin 9:
    mySerial.println(brightness);
    analogWrite(7, brightness);   
  // Other processing can be done here
                           
}
