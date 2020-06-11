#include <SoftwareSerial.h>

int trigPin=1;
int echoPin=2;
int motor1=3;

void setup()
{
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(motor1,OUTPUT);
    
    Serial.begin(9600);
}

void loop()
{   
    long duration,inches,cm;
    long microsecondstoInches(long microseconds);
    long microsecondstoCm(long microseconds);
    digitalWrite(trigPin,LOW);
    delay(2);
    digitalWrite(trigPin,HIGH);
    delay(10);
    digitalWrite(trigPin,LOW);
    duration=pulseIn(echoPin, HIGH);

    inches=duration/74/2;

    cm=duration/29/2;

    Serial.print("\nInches is ");
    Serial.print(inches);

    Serial.print("\nCm is ");
    Serial.print(cm);

    if(cm>=5)
    {
        digitalWrite(motor1,HIGH);
    }

    else if(cm<5)
    {
        digitalWrite(motor1,LOW);
    }
    
}
