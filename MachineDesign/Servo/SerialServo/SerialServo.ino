#include<SoftwareServo.h>

SoftwareServo myServopan; //create a servo object.
int angle = 0;
void setup()
{
myServopan.attach(7); //attach the servo to pin 3
myServopan.write(angle);
}
//sweep the servo
void loop()
{
// scan from 0 to 180 degrees
for(angle = 0; angle < 180; angle++)
{
myServopan.write(angle);
delay(15);
SoftwareServo::refresh();
}
// now scan back from 180 to 0 degrees
for(angle = 180; angle > 0; angle--)
{
myServopan.write(angle);
delay(15);
SoftwareServo::refresh();
}
} 
