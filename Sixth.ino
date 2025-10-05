// This is a second part to the potentiometer.......a more advanced version

// Arduino 3-LED Voltage Indicator
// Reads analog voltage from pin A3 and lights up LEDs
//   - Red LED if voltage <= 2.0 V
//   - White LED if voltage between 2.0 V and 3.0 V
//   - Green LED if voltage > 3.0 V

int v = A3;          // Analog input pin (voltage source connected here)
double v1 = 0.0;     // Raw analog reading (0–1023)
double v2 = 0.0;     // Converted voltage (0–5V)

int rpin = 3;        // Red LED on pin 3
int wpin = 2;        // White LED on pin 2
int gpin = 4;        // Green LED on pin 4

void setup()
{
  pinMode(v, INPUT);     // Set A3 as input
  pinMode(rpin, OUTPUT); // Red LED pin as output
  pinMode(wpin, OUTPUT); // White LED pin as output
  pinMode(gpin, OUTPUT); // Green LED pin as output
  Serial.begin(9600);    // Initialize Serial Monitor at 9600 baud
}

void loop()
{
  v1 = analogRead(v);          // Read raw analog value (0–1023)
  v2 = (v1 / 1023.0) * 5.0;    // Convert raw value to voltage (0–5V range)
  
  Serial.println(v2);          // Print voltage to Serial Monitor

  // Voltage-based LED logic
  if (v2 <= 2.0) {             // If voltage is <= 2.0V → Red ON
    digitalWrite(rpin, HIGH);
    digitalWrite(wpin, LOW);
    digitalWrite(gpin, LOW);
  }
  else if (v2 > 2.0 && v2 < 3.0) { // If 2.0V < voltage < 3.0V → White ON
    digitalWrite(rpin, LOW);
    digitalWrite(wpin, HIGH);
    digitalWrite(gpin, LOW);
  }
  else {                       // If voltage >= 3.0V → Green ON
    digitalWrite(rpin, LOW);
    digitalWrite(wpin, LOW);
    digitalWrite(gpin, HIGH);
  }

  delay(100); // Small delay for stability
}
