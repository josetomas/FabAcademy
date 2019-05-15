#include <Wire.h>
#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1 
char c;

SoftwareSerial mySerial( rxPin,txPin);

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  mySerial.begin(9600);  // start serial for output

}

void loop() {  
  while (mySerial.available()) { // slave may send less than requested
    c = mySerial.read(); // receive a byte as character
    mySerial.println(c);
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(c);             
  }
  Wire.endTransmission(); 
  mySerial.println("Closed"); 
  delay(500);
}
