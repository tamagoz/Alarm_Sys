/*
  Examples : Arduino Experiment Examples By....ETT CO.,LTD
  Program : Computer LAB4
  Hardware : Connect Volume to Analog-0
  : Connect LED to Digital-9
  : Connect LED to Digital-13
  Function : Arduino Display Bargraph on Computer
  : Read Analog & Dimmer LED,Send Data[0..255] to PC
*/
int ledPin1 = 9; //Dimmer LED
int ledPin2 = 13; //Status LED

int Volume = A1; //Volume = Analog Pin-A1
int Volume1 = A2; //Volume = Analog Pin-A2
int Volume2 = A3; //Volume = Analog Pin-A2



void setup() //Setup Function
{
  pinMode(ledPin1, OUTPUT); //ledPin1 = Output
  pinMode(ledPin2, OUTPUT); //ledPin2 = Output
  Serial.begin(9600); //Start Serial=9600
}
void loop() //Main Function
{
  int tempMeter = analogRead(Volume);
  int humiMeter = analogRead(Volume1);
  int nc = analogRead(Volume2);
  {
    if (Serial.available()) {
      int b = Serial.read();
      if (b = 0) {
        digitalWrite(ledPin2, 0);
        Serial.println('F');
      }
      if (b = 1) {
        digitalWrite(ledPin2, 1);
        Serial.println('N');

      }
    }
  }
  /*  if (Serial.available()) {
      char b = Serial.read();
      switch (b) {
        case '0' :
          digitalWrite(ledPin2, 0);
          Serial.println('F');
          break;
        case '1' :
          digitalWrite(ledPin2, 1);
          Serial.println('N');
          break;
        default :
          break;
      }
    }
  */
  tempMeter = map(tempMeter, 0, 1023, 0, 255); //Convert 0..1023 to 0..255
  humiMeter = map(humiMeter, 0, 1023, 0, 255); //Convert 0..1023 to 0..255
  nc = map(nc, 0, 1023, 0, 255); //Convert 0..1023 to 0..255

  Serial.print (tempMeter); //Dimmer LED = 0..255 Scale
  Serial.print (",");
  Serial.print (humiMeter); //Dimmer LED = 0..255 Scale
  Serial.print (",");
  Serial.print (nc); //Dimmer LED = 0..255 Scale
  Serial.println (",");
  delay(100); //Byte Delay
}




