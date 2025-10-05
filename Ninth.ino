// We will be simulating the buzzer with the potentiometer first the basic buzzer

/*int bpin=11;
void setup()
{
  pinMode(bpin, OUTPUT);
}

void loop()
{
  for(int i=0; i<256; i++){
    analogWrite(bpin,i);
    delay(1000);
  }
}*/
/*
int bpin=11;
int pot=2;
int v;
void setup(){
  pinMode(bpin, OUTPUT);
  pinMode(pot, INPUT);
}
void loop(){
  v=analogRead(pot);
  v=map(v, 0, 1023, 0, 255);
  analogWrite(bpin,v);
  delay(50);
}
*/

// Define the potentiometer input pin (A2 in this case)  
int potPin = 2;    

// Define the buzzer output pin (digital pin 11)  
int buzzer = 11;  

void setup() {
  // Set buzzer pin as an output so we can generate sound  
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Read analog value from potentiometer (range: 0–1023)  
  int sensorValue = analogRead(potPin);

  // Normalize sensor value to range 0.0 – 1.0  
  float norm = sensorValue / 1023.0;

  // Map normalized value to frequency using exponential scaling:  
  // At norm = 0 → 100 Hz  
  // At norm = 1 → ~2000 Hz (100 * 20^1 = 2000)  
  int freq = 100 * pow(20, norm);

  // Generate a tone on the buzzer at the calculated frequency  
  tone(buzzer, freq);

  // Small delay to make the change in frequency smoother  
  delay(100);
}
