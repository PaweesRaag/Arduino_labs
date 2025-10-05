// Binary Blinker (with the decimal switching with pushbuttons the LED reflects as the binary output)
// This the second to the lot it shows 2 versions "bruteforced" and "optimized"

// Brute-Forced
int led1=13;
int led2=12;
int led3=11;

int swi0=8;
int swi1=9;
int swi2=2;
int swi3=3;
int swi4=4;
int swi5=5;
int swi6=6;
int swi7=7;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(swi0, INPUT);
  pinMode(swi1, INPUT);
  pinMode(swi2, INPUT);
  pinMode(swi3, INPUT);
  pinMode(swi4, INPUT);
  pinMode(swi5, INPUT);
  pinMode(swi6, INPUT);
  pinMode(swi7, INPUT);
  
}

void loop()
{
  //0
  int bS0 = digitalRead(swi0);
  if (bS0 == HIGH)
  {
    digitalWrite(led3,LOW);
  	digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
  }
  //1
  int bS1 = digitalRead(swi1);
  if (bS1 == HIGH)
  {
    digitalWrite(led3,HIGH);
  	digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
  }
  //2
  int bS2 = digitalRead(swi2);
  if (bS2 == HIGH)
  {
    digitalWrite(led3,LOW);
  	digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
  }
  //3
  int bS3 = digitalRead(swi3);
  if (bS3 == HIGH)
  {
    digitalWrite(led3,HIGH);
  	digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
  }
  //4
  int bS4 = digitalRead(swi4);
  if (bS4 == HIGH)
  {
    digitalWrite(led3,LOW);
  	digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
  }
  //5
  int bS5 = digitalRead(swi5);
  if (bS5 == HIGH)
  {
    digitalWrite(led3,HIGH);
  	digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
  }
  //6
  int bS6 = digitalRead(swi6);
  if (bS6 == HIGH)
  {
    digitalWrite(led3,LOW);
  	digitalWrite(led2,HIGH);
    digitalWrite(led1,HIGH);
  }
  //7
  int bS7 = digitalRead(swi7);
  if (bS7 == HIGH)
  {
    digitalWrite(led3,HIGH);
  	digitalWrite(led2,HIGH);
    digitalWrite(led1,HIGH);
  }
  
}

//Optimized
int led1 = 13; // Green
int led2 = 12; // Yellow
int led3 = 11; // Red

// Switches on pins 2–9
int switches[] = {2,3,4,5,6,7,8,9};

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(switches[i], INPUT_PULLUP); // safer input
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    if (digitalRead(switches[i]) == LOW) {  // pressed = LOW
      digitalWrite(led1, (i >> 2) & 1); // Green
      digitalWrite(led2, (i >> 1) & 1); // Yellow
      digitalWrite(led3, i & 1);        // Red
    }
  }
}

