
#include <Wire.h>
#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1


SoftwareSerial mySerial( rxPin,txPin);
void setup() {   
  mySerial.begin(9600); 
}

void loop() {
    mySerial.print(":*");         
  delay(500);
}
