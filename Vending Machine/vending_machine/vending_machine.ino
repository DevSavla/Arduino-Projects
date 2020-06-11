#include <SoftwareSerial.h>

int trigPin1=1;
int echoPin1=2;
int motor1=3;

int trigPin2=8;
int echoPin2=9;
int motor2=10;

void setup()
{
    pinMode(trigPin1,OUTPUT);
    pinMode(echoPin1,INPUT);
    pinMode(motor1,OUTPUT);

    pinMode(trigPin2,OUTPUT);
    pinMode(echoPin2,INPUT);
    pinMode(motor2,OUTPUT);

    Serial.begin(9600);
}

void loop()
{   
    long duration1,inches1,cm1;
    long microsecondstoInches(long microseconds1);
    long microsecondstoCm(long microseconds1);
    digitalWrite(trigPin1,LOW);
    delay(2);
    digitalWrite(trigPin1,HIGH);
    delay(10);
    digitalWrite(trigPin1,LOW);
    duration1=pulseIn(echoPin1, HIGH);

    inches1=duration1/74/2;

    cm1=duration1/29/2;

    Serial.print("\nInches is ");
    Serial.print(inches1);

    Serial.print("\nCm is ");
    Serial.print(cm1);

    if(cm1>4)
    {
        digitalWrite(motor1,HIGH);
    }

    else if(cm1<=4)
    {
        digitalWrite(motor1,LOW);
    }

    long duration2,inches2,cm2;
    long microsecondstoInches(long microseconds2);
    long microsecondstoCm(long microseconds2);
    digitalWrite(trigPin2,LOW);
    delay(2);
    digitalWrite(trigPin2,HIGH);
    delay(10);
    digitalWrite(trigPin2,LOW);
    duration2=pulseIn(echoPin2, HIGH);

    inches2=duration2/74/2;

    cm2=duration2/29/2;

    Serial.print("\nInches is ");
    Serial.print(inches2);

    Serial.print("\nCm is ");
    Serial.print(cm2);

    if(cm2>4)
    {
        digitalWrite(motor2,HIGH);
    }

    else if(cm2<=4)
    {
        digitalWrite(motor2,LOW);
    }
}
