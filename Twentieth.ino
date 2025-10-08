// This is another functionality with the stepper

#include <AccelStepper.h>

#define DIR_PIN 4
#define STEP_PIN 3
int motion=0;
int but = 2;

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  stepper.setMaxSpeed(100);  // steps per second
  stepper.setAcceleration(200);
  pinMode(but, INPUT_PULLUP);
}

void loop() {
  int butRead = digitalRead(but);
  if (butRead == 0){
    stepper.setSpeed(500);
    stepper.runSpeed();
  }
}
