// Now we will be introducing to the joystick module............The next one will be a pumped up project

int x = A1;   // Joystick X-axis connected to A1
int y = A0;   // Joystick Y-axis connected to A0
int s = 8;    // Joystick button (SW pin) connected to D8

int xVal;     // store X-axis value
int yVal;     // store Y-axis value
int sVal;     // store button state
int dt = 200; // delay time (ms)

void setup() {
  Serial.begin(9600);      // Start serial monitor
  pinMode(x, INPUT);       // X-axis is analog input
  pinMode(y, INPUT);       // Y-axis is analog input
  pinMode(s, INPUT_PULLUP);// Button as input with pull-up (safer than using digitalWrite HIGH)
}

void loop() {
  // Read joystick values
  xVal = analogRead(x);    // Range 0–1023
  yVal = analogRead(y);    // Range 0–1023
  sVal = digitalRead(s);   // HIGH = not pressed, LOW = pressed

  // Print values
  Serial.print("X = ");
  Serial.println(xVal);
  Serial.print("Y = ");
  Serial.println(yVal);
  Serial.print("S = ");
  Serial.println(sVal);

  delay(dt);               // Small delay to avoid flooding serial
}
