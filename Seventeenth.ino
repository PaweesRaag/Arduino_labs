// Now here where we start a bit of robotics.......we'd be controlling 2 servos with a joystick
// let's imagine this we mount one servo upon other, where up-down controls the bottom and left-right controls the top
// we can design a basic arm module with this

#include <Servo.h>

int x = A1;  // Joystick X-axis
int y = A0;  // Joystick Y-axis
int s = 8;   // Joystick button (switch pin)

int xVal;    // store X-axis value
int yVal;    // store Y-axis value
int sVal;    // store button state

Servo servo1;  // Servo for X-axis
Servo servo2;  // Servo for Y-axis

int pos1;    // angle for servo1
int pos2;    // angle for servo2

int dt = 200; // delay between updates

void setup() {
  Serial.begin(9600);
  
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(s, INPUT_PULLUP); // safer than using digitalWrite HIGH
  
  // attach servos to pins
  servo1.attach(5);
  servo2.attach(3);
  
  Serial.println("Joystick Servo Controller Ready");
}

void loop() {
  // Read joystick analog values (0–1023)
  xVal = analogRead(x);
  yVal = analogRead(y);
  sVal = digitalRead(s); // button press (LOW = pressed)

  // Map joystick values to servo angles (0–180)
  pos1 = map(xVal, 0, 1023, 0, 180);
  pos2 = map(yVal, 0, 1023, 0, 180);

  // Move servos
  servo1.write(pos1);
  servo2.write(pos2);

  // Print values to serial monitor
  Serial.print("X = ");
  Serial.print(xVal);
  Serial.print("  -> Servo1 Angle: ");
  Serial.print(pos1);
  Serial.print(" | Y = ");
  Serial.print(yVal);
  Serial.print("  -> Servo2 Angle: ");
  Serial.print(pos2);
  Serial.print(" | Button: ");
  Serial.println(sVal == LOW ? "Pressed" : "Released");

  delay(dt);
}
