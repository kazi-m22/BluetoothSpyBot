#include <AFMotor.h>
byte incomingByte;

AF_DCMotor leftBack(1);
AF_DCMotor leftFront(2);
AF_DCMotor rightFront(3);
AF_DCMotor rightBack(4);

void setup()
{
  leftBack.setSpeed(200);
  leftFront.setSpeed(200);
  rightBack.setSpeed(200);
  rightFront.setSpeed(200);
  Serial.begin(9600);
}

void loop() {
        // send data only when you receive data:
    if (Serial.available() > 0) {
        incomingByte = Serial.read();         // read the incoming byte:
                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte);
        }
        
    if (incomingByte == 'w' || incomingByte == 'W') front();
    else if (incomingByte == 's' || incomingByte == 'S') back();
    else if (incomingByte == 'a' || incomingByte == 'A') left();
    else if (incomingByte == 'd' || incomingByte == 'D') right();
        
} 

void front()
{
  leftBack.run(FORWARD);
  rightBack.run(FORWARD);
  leftFront.run(FORWARD);
  rightFront.run(FORWARD);
}


void back()
{
  leftBack.run(BACKWARD);
  rightBack.run(BACKWARD);
  leftFront.run(BACKWARD);
  rightFront.run(BACKWARD);
}

void right()
{
  leftBack.run(FORWARD);
  leftFront.run(FORWARD);
  rightBack.run(RELEASE);
  rightFront.run(RELEASE);
}

void left()
{
  leftBack.run(RELEASE);
  leftFront.run(RELEASE);
  rightBack.run(FORWARD);
  rightFront.run(FORWARD);
}


