
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>


const int stepsPerRevolution = 48;  // change this to fit the number of steps per revolution

// for your motor
int ports[24][4] = 
{
{ 8 ,9 ,10 ,11 },
{ 8 ,9 ,11 ,10 },
{ 8 ,10 ,9 ,11 },
{ 8 ,10 ,11 ,9 },
{ 8 ,11 ,9 ,10 },
{ 8 ,11 ,10 ,9 },
{ 9 ,8 ,10 ,11 },
{ 9 ,8 ,11 ,10 },
{ 9 ,10 ,8 ,11 },
{ 9 ,10 ,11 ,8 },
{ 9 ,11 ,8 ,10 },
{ 9 ,11 ,10 ,8 },
{ 10 ,8 ,9 ,11 },
{ 10 ,8 ,11 ,9 },
{ 10 ,9 ,8 ,11 },
{ 10 ,9 ,11 ,8 },
{ 10 ,11 ,8 ,9 },
{ 10 ,11 ,9 ,8 },
{ 11 ,8 ,9 ,10 },
{ 11 ,8 ,10 ,9 },
{ 11 ,9 ,8 ,10 },
{ 11 ,9 ,10 ,8 },
{ 11 ,10 ,8 ,9 },
{ 11 ,10 ,9 ,8 }
};

// initialize the stepper library on pins 8 through 11:
//Stepper myStepper(stepsPerRevolution,8,11,9,10);// kiss emoji works
Stepper* myStepper;// not working










void setup() {
  // set the speed at 60 rpm:
//  myStepper.setSpeed(100);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() 
{
  for (int i=0; i <= 23; i++)
  {
    Serial.print(i);
    Serial.print(")");
    for (int y=0; y <= 3; y++)
    {
      Serial.print(ports[i][y]);
      Serial.print(" ");
    }
      myStepper = new Stepper(stepsPerRevolution,ports[i][0],ports[i][1],ports[i][2],ports[i][3]);
      myStepper->setSpeed(100);

      // step one revolution  in one direction:
      Serial.println("forward");
      myStepper->step((stepsPerRevolution)*6);
      delay(500);
    
      // step one revolution in the other direction:
      Serial.println("backward");
      myStepper->step((-1*stepsPerRevolution)*6);
      delay(500);
    }
    Serial.println("");
  }


