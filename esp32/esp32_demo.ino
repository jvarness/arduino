#include <ArduinoJson.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>

#define A_BUTTON 15
#define B_BUTTON 32
#define C_BUTTON 14

Adafruit_SSD1306 display = Adafruit_SSD1306(128,32,&Wire);

const char* host = "api.scryfall.com";
const String endpoint = "/cards/random";
const String request = "GET " + endpoint + " HTTP/1.1\r\n" +
                       "Host: " + host + "\r\n" +
                       "Connection: keep-alive\r\n\r\n";

WiFiClientSecure client;
unsigned long calls = 0;


void setup() {  
  pinMode(A_BUTTON, INPUT_PULLUP);
  pinMode(B_BUTTON, INPUT_PULLUP);
  pinMode(C_BUTTON, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  WiFi.begin("SSID", "password123");

  display.print("No data yet...");
  display.setCursor(0,12);
  display.print("Connecting wifi...");
  display.display();

  while (WiFi.status() != WL_CONNECTED) {
    
  }

  if(!client.connect(host, 443)) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Couldn't connect to Scryfall");
    display.display();
    return;
  } else {
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Connected! Getting a card...");
    display.display();
  }

  Serial.begin(9600);
}

void loop() {
  client.print(request);

  delay(350);

  while(client.available()) {
    String swiftspear = client.readStringUntil('\r');
    swiftspear.trim();
    if(swiftspear.charAt(0) == '{') {
      DynamicJsonBuffer buffer(3500);
      JsonObject& obj = buffer.parseObject(swiftspear);
    
      if(obj.success()) {
        display.clearDisplay();
        display.setCursor(0,0);
        const char* cardName = obj["name"];
        display.print(cardName);
        display.setCursor(0,10);
        const char* mana = obj["mana_cost"];
        display.print(mana);
        display.setCursor(0,20);
        const char* type = obj["type_line"];
        display.print(type);
        display.display();
      }
      else {
        display.clearDisplay();
        display.setCursor(0,0);
        display.print("Could not parse");
        display.display();
      }
      buffer.clear();
      break;
    }
  }

  calls++;
  Serial.println(calls);
}
