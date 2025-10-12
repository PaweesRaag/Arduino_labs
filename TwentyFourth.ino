// This is a bit of a complicated program on stepper
// There is a push button which controls the direction of the flow and a regulator (Pot) which controls the speed

#include <AccelStepper.h>

#define STEP 4
#define DIR 5
#define BUT 2
#define POT 3

AccelStepper stepper1(AccelStepper::DRIVER, STEP, DIR);

int direction = 1;           // 1 = forward, -1 = reverse
int lastButtonState = HIGH;  // track button press
unsigned long lastDebounce = 0;
const int debounceDelay = 50;

void setup() {
  pinMode(BUT, INPUT_PULLUP);
  pinMode(POT, INPUT);
  Serial.begin(9600);

  stepper1.setMaxSpeed(5000);
  stepper1.setAcceleration(100);
}

void loop() {
  // Read potentiometer (0–1023) → map to speed (0–1000)
  int potRead = analogRead(POT);
  int speed =(int) ((1000.0/1023.0)*potRead);
  
  // Read button
  int reading = digitalRead(BUT);

  // Debounce logic
  if (reading != lastButtonState) {
    
    if (reading == LOW && lastButtonState == HIGH) {
      direction *= -1;  // toggle direction
      Serial.print("Direction changed to: ");
      Serial.println(direction == 1 ? "FORWARD" : "REVERSE");
    }
  }

  lastButtonState = reading;

  // Set speed according to potentiometer and direction
  stepper1.setSpeed(speed * direction);

  // Keep the stepper running smoothly
  stepper1.runSpeed();

  // Debug info
  Serial.print("Speed: ");
  Serial.print(speed);
  Serial.print(" | Direction: ");
  Serial.println(direction == 1 ? "Forward" : "Reverse");
}
