#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>
Servo uni;

byte sig;

AF_DCMotor motor4(4);
AF_DCMotor motor1(1);

AF_DCMotor motor3(3);


void setup()
{
  
  Serial1.begin(9600);
  
  pinMode(13, OUTPUT);
  uni.attach(9);
  
  
}

void loop()
{ 

  
  
  if(Serial1.available()>0){
    sig = Serial1.read();
    if(sig == 'w' || sig == 'W')
    {  
      front();
    }
    else if(sig == 's' || sig == 'S')
    { 
      
      back();
          }
    else if(sig == 'q' || sig == 'Q')
  {
    motor1.run(RELEASE);
    
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    
  }
  else if(sig == 'd' || sig == 'D')
  {
   
    motor1.setSpeed(255);
    
    motor3.setSpeed(150);
    motor4.setSpeed(120);
    
    
    motor1.run(FORWARD);
    
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    
  }
  else if(sig == 'a' || sig == 'A')
  {
    
    
     motor1.setSpeed(100);
  
  motor3.setSpeed(255);
  motor4.setSpeed(255);
    motor1.run(FORWARD);
  
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  }
   
    
  }
  
  
    
  
}


void front()
{
      motor1.setSpeed(255);
      motor3.setSpeed(255);
      motor4.setSpeed(255);
      
      
      motor1.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      digitalWrite(13, HIGH);  
}


void back()
{
  motor1.setSpeed(255);
      motor3.setSpeed(255);
      motor4.setSpeed(255);
      
      
      motor1.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      digitalWrite(13, HIGH); 
}

