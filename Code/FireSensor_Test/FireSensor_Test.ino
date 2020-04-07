void setup() {
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);

}

void loop() {
  int x=0;
  x= digitalRead(7);
  if(x==LOW)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
  
}
