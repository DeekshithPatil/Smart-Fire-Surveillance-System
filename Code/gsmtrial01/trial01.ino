int timesTosend=1;
int count=0;
char phone_no[]="9742507720";

void sms();

void setup()
{
   Serial.begin(9600);
  delay(2000);
  Serial.println("AT+CMGF=1");
  delay(200);

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
  int x=0;
  x=digitalRead(7);
  if(x==LOW)
  {
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    sms();
  }
 
}

void sms()
{
  while(count<timesTosend){
  delay(1500);
  Serial.print("AT+CMGS=\"");
  Serial.print(phone_no);
  Serial.println("\"");
  while(Serial.read()!='>');
  {
    Serial.print("Testing Successful");
    delay(500);
    Serial.write(0x1A);
    Serial.write(0x0D);
    Serial.write(0x0A);
    delay(5000);
  }
  count++;
 }
}



