#include<Servo.h>

int sensorPin = A0; // select the input pin for the LDR
int sensorValue = 0; // variable to store the value coming from the sensor

Servo servo;

void setup()
{
  Serial.begin(9600);
  servo.attach(5);
  servo.write(0);
}

void loop()
{ 
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);

    if(sensorValue<600)
    {
      servo.write(90);
      delay(100);                   
      servo.write(60);
      delay(100);
    }

    else
    {
      servo.write(90);
    }
}
