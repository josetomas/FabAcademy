// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <SoftwareSerial.h>
#define rxPin 0
#define txPin 1

SoftwareSerial mySerial(rxPin,txPin);
void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  mySerial.begin(9600);  
}

byte x = 0;

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  mySerial.println(x);
  x++;
  delay(500);
}
