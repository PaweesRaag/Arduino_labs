// Now this is a mammoth task behold the BIG STEPPER, UNDERGROUND METHOD............Stepper Motor

// | A4988 Pin           | Connects To                       | Description        |
// | ------------------- | --------------------------------- | ------------------ |
// | **VMOT**            | +12 V                             | Motor power supply |
// | **GND (near VMOT)** | Power supply GND                  | Motor power ground |
// | **2B, 2A, 1A, 1B**  | Stepper motor wires               | Two coils of motor |
// | **VDD**             | 5 V (from Arduino)                | Logic power        |
// | **GND (near VDD)**  | Arduino GND                       | Common ground      |
// | **STEP**            | Arduino pin 3                     | Step pulse input   |
// | **DIR**             | Arduino pin 4                     | Rotation direction |
// | **EN (Enable)**     | Optional, tie to GND (active low) |                    |


#include <AccelStepper.h>

#define DIR_PIN 4
#define STEP_PIN 3

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  stepper.setMaxSpeed(100);  // steps per second
  stepper.setAcceleration(200);
}

void loop() {
  stepper.moveTo(200);       // defines where to go.
  stepper.runToPosition();   // makes it actually go there (blocking).
  delay(1000);
  stepper.moveTo(00);
  stepper.runToPosition();
  delay(1000);
}

// this just get the stepper running nothing much 
