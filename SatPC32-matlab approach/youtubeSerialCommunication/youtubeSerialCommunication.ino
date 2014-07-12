int TxPin = 6;
int upLed = 3;
int downLed = 9;
String inputString = ""; // a string to hold incoming data
boolean stringComplete = false;
int var = 1;
#include <SoftwareSerial.h>
SoftwareSerial mySerial(5,TxPin);
void setup()
{
  Serial.begin(9600);
  //  Serial.println('a');
  //  char a = 'b';
  inputString.reserve(200);
  mySerial.begin(9600);
  pinMode(upLed, 'OUTPUT');
  pinMode(downLed,'OUTPUT');
  pinMode(TxPin,'OUTPUT');
  digitalWrite(upLed, LOW);
  digitalWrite(downLed, LOW);
  digitalWrite(TxPin, 'HIGH');
  mySerial.write(22);
  mySerial.write(12);
  //  while (a != 'a')
  //  {
  //    a = Serial.read();
  //  }
  //  mySerial.print("a= ");
  //  mySerial.write(a);
}
void loop() 
{
  // print the string when a newline arrives:
  if (stringComplete)
  {
    mySerial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() 
{
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    delay(5);
    switch (inChar)
    {
    case 'e':
      mySerial.print("El: "); 
      break;
    case 'a':
      mySerial.print("Az: ");
      break;
    case 'u':
      inputString += " up";
      digitalWrite(downLed, LOW);
      digitalWrite(upLed, HIGH);
      break;
    case 'd':
      inputString += " down";
      digitalWrite(upLed, LOW);
      digitalWrite(downLed, HIGH);
      break;
    case 's':
      inputString += "        ";
      digitalWrite(upLed, LOW);
      digitalWrite(downLed, LOW);
      break;
    default:
      inputString += inChar;
      // if the incoming character is a newline, set a flag
      // so the main loop can do something about it:
      delay(5);
      if (inChar == '\n') 
      {
        stringComplete = true;
      }
      break;
    }
  }
}

























