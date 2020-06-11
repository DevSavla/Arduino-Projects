#include <AFMotor.h> //Import Motor.h Library

AF_DCMotor motor(4, MOTOR12_64KHZ); // Define motor #2, 64KHz pwm
/* AF_DCMotor motor(2);*/ //Another way to define

void setup() {
  Serial.begin(9600); // Open Serial communication at baud rate 9600 bps
  Serial.println("Testing the Motor");
  
  motor.setSpeed(500); // Set the motor speed at 200 to 255 PWM
}

void loop() {
  Serial.print("....TURNING.... "); 
  
  motor.run(FORWARD);      // turn it on going forward
  delay(1000); // delay at 1 second

  Serial.print("Turning Backward");
  motor.run(BACKWARD);     // the other way
  delay(1000); // delay at 1 second
  
  Serial.print("Release or Stop");
  motor.run(RELEASE);      // Motor will stop
  delay(1000); // delay at 1 second
}
