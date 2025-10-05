// Using RGB light module we shall be simulating the entire colour spectrum
// It has both basic and advanced version.......try to go through the basic slowly and try to write the advanced on your own

/*
int r=7;
int g=6;
int b=5;
void setup()
{
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop()
{
  for(int i = 0; i< 10; i++){
    digitalWrite(r,1);
    digitalWrite(g,0);
    digitalWrite(b,0);
    delay(500);
  }
  for(int i = 0; i< 10; i++){
    digitalWrite(r,0);
    digitalWrite(g,1);
    digitalWrite(b,0);
    delay(500);
  }
  for(int i = 0; i< 10; i++){
    digitalWrite(r,0);
    digitalWrite(g,0);
    digitalWrite(b,1);
    delay(500);
  }
}
*/
/* Basic RGB
int r=7;
int g=5;
int b=6;
String colour;
void setup()
{
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Enter the colour");
  while(Serial.available()==0){}
  colour=Serial.readString();
  if(colour.equalsIgnoreCase("blue")){
    digitalWrite(r,0);
    digitalWrite(g,0);
    digitalWrite(b,1);
    delay(500);
  }
  if(colour.equalsIgnoreCase("red")){
    digitalWrite(r,1);
    digitalWrite(g,0);
    digitalWrite(b,0);
    delay(500);
  }
  if(colour.equalsIgnoreCase("green")){
    digitalWrite(r,0);
    digitalWrite(g,1);
    digitalWrite(b,0);
    delay(500);
  }
}
*/

//--------------------------------------------------------------------------------


// Arduino RGB LED Controller (Advanced Version)
// Control an RGB LED using serial input by typing color names.
// Uses PWM pins so brightness mixing is possible (for custom colors).
//
// Supported colors: red, green, blue, yellow, cyan, magenta, white,
// orange, purple, pink, lime, teal, violet, brown, gray.
//
// Hardware Setup:
//   - Common cathode RGB LED
//   - Red pin   → Arduino digital pin 9 (PWM)
//   - Green pin → Arduino digital pin 5 (PWM)
//   - Blue pin  → Arduino digital pin 6 (PWM)
//   - Common cathode → GND (with resistors in series ~220Ω each)

int r = 9;   // Red LED pin (PWM)
int g = 5;   // Green LED pin (PWM)
int b = 6;   // Blue LED pin (PWM)
String colour; // String to store user input

void setup()
{
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  Serial.begin(9600);
  Serial.print("Enter a colour name: ");
}

// Helper function to set RGB LED color
// Takes values 0–255 for each channel
void setColor(int red, int green, int blue) {
  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);
}

void loop()
{
  // Wait until the user types something
  while (Serial.available() == 0) {}

  // Read the typed string
  colour = Serial.readString();
  colour.trim(); // Remove extra spaces or newlines

  // Match color names (case-insensitive)
  if (colour.equalsIgnoreCase("red"))         setColor(255, 0, 0);
  else if (colour.equalsIgnoreCase("green"))  setColor(0, 255, 0);
  else if (colour.equalsIgnoreCase("blue"))   setColor(0, 0, 255);
  else if (colour.equalsIgnoreCase("yellow")) setColor(255, 255, 0);
  else if (colour.equalsIgnoreCase("cyan"))   setColor(0, 255, 255);
  else if (colour.equalsIgnoreCase("magenta"))setColor(255, 0, 255);
  else if (colour.equalsIgnoreCase("white"))  setColor(255, 255, 255);
  else if (colour.equalsIgnoreCase("orange")) setColor(255, 165, 0);
  else if (colour.equalsIgnoreCase("purple")) setColor(128, 0, 128);
  else if (colour.equalsIgnoreCase("pink"))   setColor(255, 105, 180);
  else if (colour.equalsIgnoreCase("lime"))   setColor(191, 255, 0);
  else if (colour.equalsIgnoreCase("teal"))   setColor(0, 128, 128);
  else if (colour.equalsIgnoreCase("violet")) setColor(148, 0, 211);
  else if (colour.equalsIgnoreCase("brown"))  setColor(139, 69, 19);
  else if (colour.equalsIgnoreCase("gray"))   setColor(128, 128, 128);
  else {
    Serial.println("❌ Unknown colour! Try again.");
    setColor(0, 0, 0); // Turn LED OFF
  }

  // Print back the recognized color
  Serial.print("You selected: ");
  Serial.println(colour);

  // Prompt again
  delay(1000);
  Serial.print("Enter next colour: ");
}

