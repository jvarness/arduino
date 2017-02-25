/*
Jake Varness
12-21-2013
Arduino Uno

This program is designed to work with a thermal resistor.

*/

#define ANLG_PIN 0
#define HOT_PIN 7
#define COLD_PIN 8

void setup()
{
  analogReference(DEFAULT); // completely unnecessary
  pinMode(COLD_PIN, OUTPUT);
  pinMode(HOT_PIN, OUTPUT);
}

void loop()
{
  int ana_read = analogRead(ANLG_PIN);
  
  if(ana_read > 170)
  {
    digitalWrite(COLD_PIN, LOW);
    digitalWrite(HOT_PIN, HIGH);
  }
  else
  {
    digitalWrite(COLD_PIN, HIGH);
    digitalWrite(HOT_PIN, LOW);
  }
}
