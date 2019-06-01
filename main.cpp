#include <Arduino.h>

int freq = 2000;
int channel = 0;
int resolution = 8;

void setup()
{

  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(18, channel);
}

void loop()
{
  for (int dutyCycle = 0; dutyCycle <= 250; dutyCycle = dutyCycle + 5)
  {
    ledcWrite(channel, dutyCycle);
    delay(20);
  }

  for (int dutyCycle = 250; dutyCycle >= 0; dutyCycle = dutyCycle - 5)
  {
    ledcWrite(channel, dutyCycle);
    delay(20);
  }
}