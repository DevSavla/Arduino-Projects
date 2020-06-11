#include <SoftwareSerial.h>

int sensorPin = A0; // select the input pin for the LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int light=5;

void setup()
{
  pinMode(light,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);

  if (sensorValue < 100)
  {
      digitalWrite(light,LOW);
  }

  else
  {
      digitalWrite(light,HIGH);
  }
}
