// Arduino Binary LED Display
// This program reads a number (0–7) from the Serial Monitor
// and lights up 3 LEDs to represent that number in binary.
//
// Example:
//   Input: 3 → LEDs = 0 1 1 (binary of 3)
//   Input: 5 → LEDs = 1 0 1 (binary of 5)
//
// Connections:
//   r1 → LED for bit2 (MSB, value 4) → Pin 6
//   r2 → LED for bit1 (middle, value 2) → Pin 5
//   r3 → LED for bit0 (LSB, value 1) → Pin 4

int r1 = 6;   // LED for bit 2 (MSB)
int r2 = 5;   // LED for bit 1
int r3 = 4;   // LED for bit 0 (LSB)
int n;        // Number input (0–7)

void setup() {
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  Serial.begin(9600);   // Start Serial Monitor at 9600 baud
  Serial.println("Enter a number between 0 and 7:");
}

void loop() {
  // Wait for serial input
  if (Serial.available() > 0) {
    n = Serial.parseInt();     // Read integer from Serial input

    // Validate input (only allow 0–7)
    if (n >= 0 && n <= 7) {
      Serial.print("You entered: ");
      Serial.println(n);

      // Set LED states according to binary representation
      digitalWrite(r1, (n >> 2) & 1);  // Extract bit 2
      digitalWrite(r2, (n >> 1) & 1);  // Extract bit 1
      digitalWrite(r3, n & 1);         // Extract bit 0
    } 
    else {
      Serial.println("Invalid input! Enter a number between 0 and 7.");
    }
  }
}
