int x=0;
int y=0;

int timesTosend=2;
int count=0;
char phone_no[]="9742507720";

void sms();
void setup() {
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(8,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(11,LOW);
   Serial.begin(9600);
  delay(2000);
  Serial.println("AT+CMGF=1");
  delay(200);

}

void loop() 
{
x=digitalRead(6);
y=digitalRead(7);
if(x==LOW)
{
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);  
  sms();
}
if(y==LOW)
{
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  sms();
}

}

void sms()
{
  while(count<timesTosend){
  delay(50);
  Serial.print("AT+CMGS=\"");
  Serial.print(phone_no);
  Serial.println("\"");
  while(Serial.read()!='>');
  {
    Serial.print("Fire in the building. Second Floor, room 3. GPRS:- https://www.google.co.in/maps/place/R.+V.+College+of+Engineering/@12.9237129,77.4964991,17z/data=!3m1!4b1!4m5!3m4!1s0x3bae15eda6d8161d:0x860a7edf6da62413!8m2!3d12.9237077!4d77.4986878?hl=en");
    delay(50);
    Serial.write(0x1A);
    Serial.write(0x0D);
    Serial.write(0x0A);
    delay(50);
  }
  count++;
 }
 
}
