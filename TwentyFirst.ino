// This will clarify all the questions related to the various "acceleration" functions of the stepper motor

#include <AccelStepper.h>

#define STEP_PIN 3
#define DIR_PIN 4
#define BUTTON_PIN 2

// DRIVER type means we only use STEP and DIR pins
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

  // Set max speed and acceleration
  stepper.setMaxSpeed(1000);       // maximum possible speed (steps/sec)
  stepper.setAcceleration(200);    // how fast it ramps up/down
  stepper.setSpeed(500);           // speed used in constant-speed mode
}

void loop() {
  int button = digitalRead(BUTTON_PIN);

  if (button == LOW) {
    // Accelerated movement: gradually ramps up and down to target
    Serial.println("Running with acceleration...");
    stepper.moveTo(1000); // move 1000 steps forward
    while (stepper.distanceToGo() != 0) {
      stepper.run();  // uses acceleration
    }

    delay(1000);

    stepper.moveTo(-1000); // move 1000 steps backward
    while (stepper.distanceToGo() != 0) {
      stepper.run();  // uses acceleration
    }
  } 
  else {
    // Constant-speed rotation (no acceleration)
    Serial.println("Running at constant speed...");
    stepper.runSpeed(); // spins continuously at 500 steps/sec
  }
}

