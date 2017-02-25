/*
Jake Varness
12-23-2013
Arduino Uno

This program is designed to control a DC Motor using a switch.

*/

#define SWT_PIN 2

void setup()
{
  Serial.begin(9600);
  pinMode(SWT_PIN, INPUT);
}

void loop()
{
  Serial.println(digitalRead(SWT_PIN));
  delay(1000);
}
