#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1

const int potmotor=2;
const int motor1=7;
const int potair=3;
const int air=8;

SoftwareSerial mySerial(rxPin,txPin);
void setup() {   
  mySerial.begin(9600);
  pinMode(motor1,OUTPUT);
  pinMode(air,OUTPUT); 
  
}

void loop() {
  int val = analogRead(potmotor);
  int val2=analogRead(potair);
  val2=map(val2,0,1023,0,255);
  val=map(val,0,1023,0,255);
  analogWrite(motor1,val);
  if (air>195){
    analogWrite(air,195); 
  }
  else{
    analogWrite(air,val2);
  } 
  delay(1);
  mySerial.print(val);
  mySerial.print(",");
  mySerial.println(val2);
}
