int x;
void setup()
{
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  
  
  
}
void loop()
{
  
  x=digitalRead(7);
  if(x==LOW)
  {
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
  }
 
}

