/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <Stepper.h>

#define LINE_BUFFER_LENGTH 512

const int penZUp = 120; // old 80//200
const int penZDown = 40; // old 120//120


const int penServoPin = 6;

const int stepsPerRevolution = 48; 

Servo penServo;  

Stepper myStepperY(stepsPerRevolution, 2,3,4,5);            
Stepper myStepperX(stepsPerRevolution, 11,10,8,9);  

struct point { 
  float x; 
  float y; 
  float z; 
};

struct point actuatorPos;

float StepInc = 1;
int StepDelay = 0;
int LineDelay = 50;
int penDelay = 50;

float StepsPerMillimeterX = 6.0;
float StepsPerMillimeterY = 6.0;

float Xmin = 0;
float Xmax = 40;
float Ymin = 0;
float Ymax = 40;
float Zmin = 0;
float Zmax = 1;

float Xpos = Xmin;
float Ypos = Ymin;
float Zpos = Zmax; 

boolean verbose = true;

void setup() {
  Serial.begin( 9600 );
  
  penServo.attach(penServoPin);
  penServo.write(penZUp);
  delay(200);
}

void loop() 
{
   penUp();
   delay(10000);
   penDown();
   delay(10000);
}
void penUp() 
{ 
  penServo.write(penZUp+50); 
  delay(LineDelay); 
  Zpos=Zmax; 
  if (verbose) 
  { 
    Serial.println("Pen up!"); 
  } 
}
void penDown() 
{ 
  penServo.write(penZDown); 
  delay(LineDelay); 
  Zpos=Zmin; 
  if (verbose) 
  { 
    Serial.println("Pen down."); 
  } 
}
