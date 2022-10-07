
#include <AccelStepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 5  //D1
#define IN2 4  //D2
#define IN3 14 //D5
#define IN4 12 //D6

// AccelStepper::HALF4WIRE -> to indicate we’re controlling the stepper motor with four wires
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

void setup() {
  // initialize the serial port
  Serial.begin(115200);
  
  // set the speed and acceleration
  stepper.setMaxSpeed(500);
  stepper.setAcceleration(100);
  // set target position
  stepper.moveTo(stepsPerRevolution);
}

void loop() {
  // check current stepper motor position to invert direction
  if (stepper.distanceToGo() == 0){
    stepper.moveTo(-stepper.currentPosition());
    Serial.println("Changing direction");
  }
  // move the stepper motor (one step at a time)
  stepper.run();
}


