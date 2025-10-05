// Now this is an interesting project

/*
  Push Button Toggle with Software Debounce
  -----------------------------------------
  Pressing the button toggles the LED ON/OFF.
  Includes a simple debounce to prevent multiple toggles on one press.
*/

// Pin assignments
int but = 4;      // Push button connected to digital pin 4
int led = 3;      // LED connected to digital pin 3

// Variables to store states
int state = 0;        // LED state: 0 = OFF, 1 = ON
int lastPress = HIGH; // Last button reading (initialized HIGH due to INPUT_PULLUP)

void setup() {
  // Configure button pin as input with internal pull-up
  pinMode(but, INPUT_PULLUP); 

  // Configure LED pin as output
  pinMode(led, OUTPUT);

  // Optional: ensure LED is off initially
  digitalWrite(led, LOW);
}

void loop() {
  // Read the current button state
  int press = digitalRead(but); // LOW when pressed, HIGH when released

  // Detect **rising edge**: button press occurred (HIGH -> LOW)
  if (press == LOW && lastPress == HIGH) {
    state = !state;  // Toggle LED state (ON ↔ OFF)
    delay(50);       // Simple debounce: wait 50ms to avoid multiple triggers
  }

  // Apply the LED state
  digitalWrite(led, state);

  // Update lastPress to current reading for next loop iteration
  lastPress = press;
}
