
int timesTosend=1;
int count=0;
char phone_no[]="9742507720";
void sms();

void setup()
{
  pinMode(7,INPUT);
  Serial.begin(9600);
  delay(2000);
  Serial.println("AT+CMGF=1");
  delay(200);
  
}

void loop()
{
  int s1=LOW;
  s1=digitalRead(7);
  if(s1==HIGH)
  {
    
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

