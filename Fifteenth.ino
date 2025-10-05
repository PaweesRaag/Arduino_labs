// Now this might look a corny project but it's quite a useful one we will be mapping the LDR input to Servo output to make a Night/Day detector

#include <Servo.h>

Servo myservo;        // Servo object
int ldrPin = A0;      // LDR analog input
float ldrVoltage = 0; // LDR voltage (0–5V)
int servoAngle = 0;   // Calculated servo angle (0–180)

void setup() {
  myservo.attach(9);       // Servo signal pin
  Serial.begin(9600);      // Serial monitor for debugging
  Serial.println("LDR-based servo control starting...");
}

void loop() {
  // Read LDR analog value (0–1023)
  int ldrValue = analogRead(ldrPin);

  // Convert ADC reading to voltage (0–5V)
  ldrVoltage = ldrValue * (5.0 / 1023.0);

  // ---------------------------
  // Nonlinear mapping to servo
  // ---------------------------
  // The way ldr gets affected (linearly) can't be tracked by human senses hence using non-linear/exponential mapping
  // Using an exponential factor to emphasize changes in light intensity
  // Map voltage 0.5V–4.5V to servo 0°–180° with nonlinear scaling
  float vMin = 0.5;  // Min voltage threshold (dark)
  float vMax = 4.5;  // Max voltage threshold (bright)
  float slope = 180.0 / (vMax - vMin); // Linear slope (before exponential)
  
  // Nonlinear mapping: angle = slope*(V - Vmin) * V^3
  servoAngle = slope * (ldrVoltage - vMin) * pow(ldrVoltage, 3);

  // Clamp servo angle between 0 and 180
  if (servoAngle < 0) servoAngle = 0;
  if (servoAngle > 180) servoAngle = 180;

  // Move servo to calculated angle
  myservo.write(servoAngle);

  // Debug output
  Serial.print("LDR Voltage: ");
  Serial.print(ldrVoltage);
  Serial.print(" V → Servo Angle: ");
  Serial.println(servoAngle);

  delay(200); // small delay for smooth readings
}
