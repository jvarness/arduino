/*

Jake Varness
11-23-2013
Arduino Hello World Project

This sketch is designed to blink a single LED.

The LED on the board is on pin 13.

*/

// LED Pin
#define LED_PIN 5
#define SWT_PIN 8
boolean lastButton = LOW;
boolean currButton = LOW;
int led = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWT_PIN, INPUT);
}

void loop()
{
  currButton = debounce(lastButton);
  if(lastButton == LOW && currButton == HIGH)
  {
    led = led + 50;
    if(led >= 255)
      led = 0;
  }
  lastButton = currButton;
  analogWrite(LED_PIN, led);
}

boolean debounce(boolean last)
{
  boolean curr = digitalRead(SWT_PIN);
  if(curr != last)
  {
    delay(5);
    curr = digitalRead(SWT_PIN);
  }
  return curr;
}
