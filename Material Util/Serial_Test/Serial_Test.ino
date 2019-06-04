
#include <Wire.h>
#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1
int pot=2;
int motor1=2;
int motor2=3;


SoftwareSerial mySerial( rxPin,txPin);
void setup() {   
  mySerial.begin(9600);
  //pinMode(motor1,OUTPUT); 
  pinMode(motor2,OUTPUT); 
  
}

void loop() {
  //digitalWrite(motor1,HIGH);
  digitalWrite(motor2,HIGH); 
  delay(1);
}
