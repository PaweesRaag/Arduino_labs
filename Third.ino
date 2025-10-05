//LED Fader
// So this uses PWM (pulse width modulation) pin to tweak the voltage of the LED pins so that it fades.......using for loop

int led=9;
void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  for(int i=0; i<256; i++)
  {
    analogWrite(led,i);
    delay(10);
  }
}
