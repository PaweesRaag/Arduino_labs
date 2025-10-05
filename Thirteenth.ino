/*
  LED Brightness Control with Two Buttons
  ---------------------------------------
  - Button 1 (butI) increases brightness
  - Button 2 (butD) decreases brightness
  - LED brightness controlled using PWM (analogWrite)
  - Uses internal pull-up resistors for buttons
*/

int butI = 3;     // Button to increase brightness (digital pin 3)
int butD = 4;     // Button to decrease brightness (digital pin 4)
int led = 2;      // LED pin (must support PWM: 3, 5, 6, 9, 10, 11 on Arduino Uno)
int brightness = 0; // Current LED brightness (0–255)

void setup() {
  // Configure buttons with internal pull-up resistors
  pinMode(butI, INPUT_PULLUP);
  pinMode(butD, INPUT_PULLUP);

  // Configure LED pin as output
  pinMode(led, OUTPUT);

  // Optional: initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // -------------------------------
  // Step 1: Read buttons
  // -------------------------------
  // Buttons are LOW when pressed due to INPUT_PULLUP
  bool incPressed = (digitalRead(butI) == LOW);
  bool decPressed = (digitalRead(butD) == LOW);

  // -------------------------------
  // Step 2: Adjust brightness
  // -------------------------------
  if (incPressed && !decPressed) {   // Only increase if increment button pressed
    brightness++;
  }

  if (decPressed && !incPressed) {   // Only decrease if decrement button pressed
    brightness--;
  }

  // -------------------------------
  // Step 3: Clamp brightness
  // -------------------------------
  // Ensure brightness stays within 0–255 (PWM range)
  if (brightness > 255) brightness = 255;
  if (brightness < 0) brightness = 0;

  // -------------------------------
  // Step 4: Output PWM to LED
  // -------------------------------
  analogWrite(led, brightness);

  // -------------------------------
  // Step 5: Debugging output (optional)
  // -------------------------------
  Serial.print("Brightness: ");
  Serial.println(brightness);

  // Small delay to reduce bouncing effects (50 ms)
  delay(50);
}
