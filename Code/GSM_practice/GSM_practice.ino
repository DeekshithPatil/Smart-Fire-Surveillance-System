#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
char msg;
char call;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("GSM SIM800A BEGIN");
  Serial.println("Enter character for control option:");
  Serial.println("h : to disconnect a call");
  Serial.println("i : to receive a call");
  Serial.println("s : to send message");
  Serial.println("r : to receive a message");
  Serial.println("c : to make a call");  
  Serial.println("e : to redial");
  Serial.println();
  delay(100);
}

void loop()
{  
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
      case 'r':
      ReceiveMessage();
      break;
    case 'c':
      MakeCall();
      break;
    case 'h':
      HangupCall();
      break;
    case 'e':
      RedialCall();
      break;
    case 'i':
      ReceiveCall();
      break;
  }
 if (mySerial.available()>0)
 Serial.write(mySerial.read());
}

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"9742507720\"\r"); // Replace x with mobile number
  delay(100);
  mySerial.println("hi good morning");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(100);
}

void ReceiveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  if (mySerial.available()>0)
  {
    msg=mySerial.read();
    Serial.print(msg);
   // Serial.println(mySerial.read());
  }
}

void MakeCall()
{
  mySerial.println("ATD+919742507720;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}


void HangupCall()
{
  mySerial.println("ATH");
  Serial.println("Hangup Call");
  delay(1000);
}

void ReceiveCall()
{
  mySerial.println("ATA");
  delay(1000);
  {
    call=mySerial.read();
    Serial.print(call);
  }
}

void RedialCall()
{
  mySerial.println("ATDL");
  Serial.println("Redialing");
  delay(1000);
}
