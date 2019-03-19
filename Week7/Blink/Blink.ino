int Led1=2;
int Led2=7;
int Led3=8;
int Button=3;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Button, INPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(Button)==0){
  digitalWrite(Led3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(Led3, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
  }
  else{
  digitalWrite(Led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(Led2, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
  }
   
}
