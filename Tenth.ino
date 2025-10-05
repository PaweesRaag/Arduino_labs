// Now let's explore the LDR (light detecting resistor)/ photoresistor

// Analog input pin for reading voltage (potentiometer or sensor on A0)
int v = A0;

// Variable to store the converted voltage value (in Volts)
float v1 = 0.0;

// Digital pin for buzzer output
int bpin = 5;

// Variable to hold calculated delay time
int dTime;

void setup()
{
  pinMode(v, INPUT);        // Configure A0 as input
  pinMode(bpin, OUTPUT);    // Configure buzzer pin as output
  Serial.begin(9600);       // Start serial communication at 9600 baud
}

void loop()
{
  // Read raw ADC value (0–1023)
  v1 = analogRead(v);

  // Convert ADC value to voltage (range ~0.0–5.0V)
  // Formula: Vin = (ADC reading / 1023) * 5
  v1 = v1 * (5.0 / 1023.0);

  // Voltage range considered: Vlow = 0.26 V, Vhigh = 4.76 V
  // We map this voltage linearly to delay times:
  //   At 0.26V → 1 ms delay
  //   At 4.76V → 10 ms delay
  //
  // Slope (m) = (10 - 1) / (4.76 - 0.26) = 9 / 4.5 = 2
  // Equation of line: y - y1 = m(x - x1)
  // => dTime - 1 = 2 * (v1 - 0.26)
  //
  // Exponential multiplier (pow(v1, 4)) added to emphasize
  // audible change, making the pitch shift more noticeable.
  dTime = (2.0 * (v1 - 0.26) + 1) * pow(v1, 4);

  // Debugging output on Serial Monitor
  Serial.print("Voltage: ");
  Serial.println(v1);
  Serial.print("DelayTime: ");
  Serial.println(dTime);

  // Toggle buzzer ON and OFF at calculated delay
  digitalWrite(bpin, HIGH);
  delayMicroseconds(dTime);
  digitalWrite(bpin, LOW);
  delayMicroseconds(dTime);
}
