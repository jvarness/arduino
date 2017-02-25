/*
Jake Varness
12-21-2013

Tri-color LED thingy

Railing:
  - 
*/

#define R 11
#define G 10
#define B 9
#define IR 7
#define IG 4
#define IB 2
boolean lastR = LOW;
boolean currR = LOW;
boolean lastG = LOW;
boolean currG = LOW;
boolean lastB = LOW;
boolean currB = LOW;
int red = 255;
int green = 255;
int blue = 255;

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(IG, INPUT);
  pinMode(IB, INPUT);
}

void loop()
{ 
  currR = debounce(lastR, IR);
  currG = debounce(lastG, IG);
  currB = debounce(lastB, IB);
  
  if(currR == HIGH && lastR == LOW)
  {
    red = red - 10;
    if(red < 0)
      red = 255;
  }
  
  if(currG == HIGH && lastG == LOW)
  {
    green = green - 10;
    if(green < 0)
      green = 255;
  }
  
  if(currB == HIGH && lastB == LOW)
  {
    blue = blue - 10;
    if(blue < 0)
      blue = 255;
  }
  
  lastR = currR;
  lastB = currB;
  lastG = currG;
  
  writeRGB();
}

void writeRGB()
{
  analogWrite(R, red);
  analogWrite(G, green);
  analogWrite(B, blue);
}

boolean debounce(boolean last, int pin)
{
  boolean curr = digitalRead(pin);
  if(curr != last)
  {
    delay(5);
    curr = digitalRead(pin);
  }
  return curr;
}
