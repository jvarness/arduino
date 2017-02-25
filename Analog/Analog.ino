/*
Jake Varness
12-21-2013
Arduino Uno

This program is designed to take analog input from a
photo-resistor and print it's value to the screen.

Railing:
  - 5V pin to + rail
  - GND pin to - rail
  - Photo-resistor to + rail
  - Voltage divider on photo-resistor (10k resistor)
  - PWM pin 10 to 330 Ohmn resistor
  - LED to GND and 330 Ohmn resistor
  
*/

#define ANLG_PIN 0
#define LED_PIN 10

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  analogReference(DEFAULT); // not necessary
}

void loop()
{
  int val = analogRead(ANLG_PIN);
  int ana_read = constrain(val, 300, 750);
  
  int level = map(ana_read, 300, 750, 255, 0);
 
  analogWrite(LED_PIN, level); 
}
