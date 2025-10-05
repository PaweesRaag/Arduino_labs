// Here we would be introducing potentiometer and the varied inputs to perform different functions

// Arduino Potentiometer Controlled LED Brightness
// This program reads the value of a potentiometer from analog pin A3
// and adjusts the brightness of an LED connected to digital pin 9 using PWM.

// Pin definitions
int potPin = A3;       // Potentiometer is connected to analog pin A3
double potVal = 0.0;   // Variable to store raw potentiometer reading (0–1023)
double LEDval = 0.0;   // Variable to store mapped LED brightness value (0–255)
int rpin = 9;          // LED is connected to digital pin 9 (PWM capable)

void setup()
{
  pinMode(potPin, INPUT);   // Set potentiometer pin as input
  pinMode(rpin, OUTPUT);    // Set LED pin as output
  Serial.begin(9600);       // Initialize Serial Monitor at 9600 baud
}

void loop()
{
  potVal = analogRead(potPin);          // Read raw value from potentiometer (0–1023)
  
  LEDval = (255.0 / 1023.0) * potVal;   // Convert range (0–1023) → (0–255) for PWM
  
  analogWrite(rpin, LEDval);            // Write PWM value to LED (controls brightness)
  
  Serial.println(LEDval);               // Print LED brightness value to Serial Monitor
  
  delay(1000);                          // Wait 1 second before next reading
}
