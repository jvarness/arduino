/*

Jake Varness
6-27-2014
LCD Screen Hello World!

This is a program that uses a potentiometer and
an LCD screen to do a Hello World program.

This sketch was made using the Arduino Micro.

*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
  lcd.print("hello, world!");
}

void loop()
{
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
}
