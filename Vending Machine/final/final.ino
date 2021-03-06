//I have added the possibilities of testing
//The values of analogRead could be changed for trouble shooting

//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define lefts A4 
#define rights A5 

//defining motors
/*AF_DCMotor motor1(4, MOTOR12_8KHZ); 
AF_DCMotor motor2(3, MOTOR12_8KHZ);*/

AF_DCMotor motor1(3, MOTOR12_8KHZ); 
AF_DCMotor motor2(4, MOTOR12_8KHZ);

int max=60;

void setup() 
{
  //setting the speed of motors
  motor1.setSpeed(500);
  motor2.setSpeed(500);
  //declaring pin types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  //begin serial communication
  Serial.begin(9600);
}

void loop()
{
  //printing values of the sensors to the serial monitor
  Serial.println(analogRead(lefts));
  Serial.println(analogRead(rights));

  if(analogRead(lefts)<=max && analogRead(rights)<=max)
  {
    //go forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }

  else if(analogRead(lefts)>max || analogRead(rights)>max)
  {
    //turn right
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }
}
