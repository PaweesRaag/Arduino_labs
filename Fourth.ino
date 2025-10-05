//Paraller and Serial connection
//This is kinda back to the past kind of project where we will use arduino to test the voltages across parallel and serial connections

int read=A3;
double v=0.0;
int del=500;
double v2=0.0;
void setup()
{
  pinMode(v,INPUT);
  Serial.begin(9600);
}

void loop()
{
  v=analogRead(read);
  v2=v/1024.0*5.0;
  Serial.println(v2);
  delay(del);
  
}

/* How It Works

The Arduino reads the analog value from pin A3.

The value ranges from 0–1023 (10-bit ADC).

The code converts this to a voltage between 0–5V.

The voltage is printed to the Serial Monitor every 500 ms.
*/
