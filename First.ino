// This is the first arduino program I've used TinkerCAD to simulate this you can directly use it using the ArduinoIDE
// This is a Simple Blinker Program akin to Hello World to IOT

// Alternate Blinking 3 LEDs

int led1 = 11;   // LED connected to pin 11
int led2 = 12;   // LED connected to pin 12
int led3 = 13;  // LED connected to pin 13

void setup() {
  // Set pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // First LED on
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(500);

  // Second LED on
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  delay(500);

  // Third LED on
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(500);
}
