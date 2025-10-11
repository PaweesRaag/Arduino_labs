// Now what this does is the motor keeps running when you release the button, this is true toggle and needn't need to be pressed for reversing
// Seems such a minor change right?? but no the logic and the code had to be bent a lot more for this one

#include <AccelStepper.h>

#define STEP_PIN 3
#define DIR_PIN 4
#define BUTTON_PIN 2

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

int state = 0;               // 0 = forward, 1 = reverse
int lastButtonState = HIGH;  // for tracking button presses
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;  // 50 ms debounce delay

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(200);
  stepper.setSpeed(500); // initial direction (forward)

  Serial.println("Stepper running forward...");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // detect button press with debounce
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // reset debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state is stable and LOW, toggle
    if (reading == LOW && lastButtonState == HIGH) {
      state = !state;  // toggle direction
      if (state == 0) {
        stepper.setSpeed(500);
        Serial.println("Direction: FORWARD");
      } else {
        stepper.setSpeed(-500);
        Serial.println("Direction: REVERSE");
      }
    }
  }

  lastButtonState = reading;

  // keep motor running
  stepper.runSpeed();
}
