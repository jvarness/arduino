/*
Jake Varness
3-9-2014
MakerShield Test Sketch

This sketch is designed to test all of the functionalities of the
MakerShield, developed by MakerShed.

*/

#define GRN_PIN 2
#define RED_PIN 4

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
