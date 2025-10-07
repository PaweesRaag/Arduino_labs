// If you used the previous code you know that the motors reset as soon as the joystick is left the "arm" resets
// which isn't very ideal so this code as 'Persistance'

// What this new version does
// The joystick no longer sets the servo absolutely.
// Instead, it nudges it slightly each time you tilt.
// Releasing the joystick keeps the current position — persistent state.
// deadzone prevents small analog fluctuations from jittering the servo.

#include <Servo.h>

int x = A1;
int y = A0;
int s = 8;

int xVal, yVal, sVal;

Servo servo1;
Servo servo2;

int pos1 = 90;  // start centered
int pos2 = 90;

int dt = 50; // smaller delay for smoother motion
int deadzone = 100; // ignore small movements near center

void setup() {
  Serial.begin(9600);
  
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(s, INPUT_PULLUP);
  
  servo1.attach(5);
  servo2.attach(3);

  servo1.write(pos1);
  servo2.write(pos2);

  Serial.println("Joystick Persistent Servo Ready");
}

void loop() {
  xVal = analogRead(x);
  yVal = analogRead(y);
  sVal = digitalRead(s);

  // Move servo1 (X axis)
  if (xVal < 512 - deadzone) pos1--;       // move left
  else if (xVal > 512 + deadzone) pos1++;  // move right

  // Move servo2 (Y axis)
  if (yVal < 512 - deadzone) pos2--;       // move up
  else if (yVal > 512 + deadzone) pos2++;  // move down

  // Limit servo angles between 0 and 180
  pos1 = constrain(pos1, 0, 180);
  pos2 = constrain(pos2, 0, 180);

  // Write to servos
  servo1.write(pos1);
  servo2.write(pos2);

  // Debug info
  Serial.print("Servo1: ");
  Serial.print(pos1);
  Serial.print(" | Servo2: ");
  Serial.println(pos2);

  delay(dt);
}
