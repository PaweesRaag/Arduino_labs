// We will be explaining the push button

// Refer to the datasheet of push button for assistance

// Pin assignments
int buttonPin = 2;   // Pin where the push button is connected
int ledPin = 13;     // Pin where the LED is connected (built-in LED on most boards)

void setup() {
  // -------------------------------
  // Step 1: Configure the button pin
  // -------------------------------

  /* 
     We use INPUT_PULLUP mode for the button:
     - Arduino has an internal pull-up resistor (~20-50kΩ) 
       connected to the input pin when using INPUT_PULLUP.
     - This means that when the button is NOT pressed, the pin reads HIGH.
     - When the button is pressed (connected to GND), the pin reads LOW.
     - This avoids "floating" inputs which can read random values.
  */
  pinMode(buttonPin, INPUT_PULLUP);

  // -------------------------------
  // Step 2: Configure the LED pin
  // -------------------------------
  pinMode(ledPin, OUTPUT);

  // Optional: initialize LED to OFF
  digitalWrite(ledPin, LOW);

  // Start Serial Monitor for debugging (optional)
  Serial.begin(9600);
  Serial.println("Push button test starting...");
}

void loop() {
  // -------------------------------
  // Step 3: Read the button state
  // -------------------------------

  /*
     digitalRead() returns:
     - HIGH (1) if the button is NOT pressed (because of pull-up)
     - LOW (0) if the button IS pressed (connected to GND)
  */
  int state = digitalRead(buttonPin);

  // -------------------------------
  // Step 4: Control the LED
  // -------------------------------
  if (state == LOW) {           // Button pressed
    digitalWrite(ledPin, HIGH); // Turn LED ON
    Serial.println("Button Pressed!");
  } else {                      // Button released
    digitalWrite(ledPin, LOW);  // Turn LED OFF
    Serial.println("Button Released!");
  }

  // Small delay for stability (debouncing improvement)
  delay(50);
}
