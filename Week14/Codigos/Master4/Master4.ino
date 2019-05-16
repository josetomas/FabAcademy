
#include <Wire.h>
#include <SoftwareSerial.h>

#define rxPin 1
#define txPin 0


SoftwareSerial mySerial( rxPin,txPin);
void setup() {
  Wire.begin();        
  mySerial.begin(9600); 
}

void loop() {
  Wire.requestFrom(8,5);    // request 6 bytes from slave device #8

  while (Wire.available()) { 
    char c = Wire.read(); 
    mySerial.print(c);         
  }
  delay(500);
}
