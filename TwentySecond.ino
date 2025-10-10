// What this does is with the press of button the motor changes it's direction, kinda like the toggling led program

#include <AccelStepper.h>

#define STEP_PIN 3
#define DIR_PIN 4
#define BUTTON_PIN 2

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

int state = 0;
int lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(200);
  stepper.setSpeed(500); // start speed
}

void loop() {
  int button = digitalRead(BUTTON_PIN);

  // Detect button press (with simple debounce)
  if (button == LOW && lastButtonState == HIGH) {
    delay(50); // debounce delay
    state = !state; // toggle direction
    Serial.print("Direction changed: ");
    Serial.println(state ? "Reverse" : "Forward");

    // change direction
    if (state == 0)
      stepper.setSpeed(500);
    else
      stepper.setSpeed(-500);
  }

  lastButtonState = button;

  // keep running motor
  stepper.runSpeed();
}
