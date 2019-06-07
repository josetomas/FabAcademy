
int pot=2;
int motor1=7;


void setup() {   

  pinMode(motor1,OUTPUT); 
  
}

void loop() {
  int val = analogRead(pot);
  val=map(val,0,1023,0,255);
  analogWrite(motor1,val); 
  delay(1);
}
