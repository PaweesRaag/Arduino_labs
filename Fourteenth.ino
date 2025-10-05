// Now let's step into some "Big Boy" stuff with the Servo Motor

//Wiring in Tinkercad
//Servo has 3 pins:
//Red → 5V (Arduino)
//Brown/Black → GND (Arduino)
//Orange/Yellow → Digital Pin (e.g., D9)

//⚠️ In real life, if the servo is big, you’d use an external power supply instead of Arduino’s 5V, but in Tinkercad it’s fine.

#include <Servo.h>

Servo myservo;   // Create servo object
int pos = 0;     // Variable to store the servo position (0–180°)

void setup() {
  myservo.attach(9);      // Attach servo signal wire to pin 9
  Serial.begin(9600);     // Start Serial communication
  Serial.println("Enter a servo angle (0 to 180):");
}

void loop() {
  // Check if data is available in Serial Monitor
  if (Serial.available() > 0) {
    // Read integer value from Serial
    pos = Serial.parseInt();  

    // Clamp the value between 0 and 180
    if (pos < 0) pos = 0;
    if (pos > 180) pos = 180;

    // Move servo to the desired position
    myservo.write(pos);   

    // Print feedback to Serial Monitor
    Serial.print("Moving servo to: ");
    Serial.println(pos);

    // Small delay to give the servo time to reach the position
    delay(500);  

    // Clear any remaining input in Serial buffer
    while (Serial.available() > 0) {
      Serial.read();
    }
    
    Serial.println("Enter next angle (0 to 180):");
  }
}

