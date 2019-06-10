#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1

int pot=2;
int motor1=7;

SoftwareSerial mySerial( rxPin,txPin);
void setup() {   
  mySerial.begin(9600);
  pinMode(motor1,OUTPUT); 
  
}

void loop() {
  int val = analogRead(pot);
  val=map(val,0,1023,0,255);
  analogWrite(motor1,val); 
  delay(1);
  mySerial.println(val);
}
