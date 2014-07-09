int TxPin = 6;
String inputString = ""; // a string to hold incoming data
boolean stringComplete = false;
int var = 1;
#include <SoftwareSerial.h>
SoftwareSerial mySerial(5,6);
void setup()
{
  Serial.begin(9600);
  //  Serial.println('a');
  //  char a = 'b';
  inputString.reserve(200);
  mySerial.begin(9600);
  pinMode(TxPin,'OUTPUT');
  digitalWrite(TxPin,'HIGH');
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
    switch (var)
    {
    case 1:
      mySerial.print("El: "); 
      var++;
      break;
    case 2:
      mySerial.println(inputString); 
      var++;
      break; 
    case 3:
      mySerial.print("Az: "); 
      var++;
      break;
    case 4:
      mySerial.println(inputString); 
      var = 1;
      break;
    }
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

    inputString += inChar;

    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    delay(5);
    if (inChar == '\n') 
    {
      stringComplete = true;
    }
  }
}












