/**
  Dexterbot News reader TTGO 128x64 Oled 

*/
//#include <ArduinoJson.h>
//StaticJsonDocument<1000> doc;
#include <Wire.h>
#include "SSD1306Wire.h"
#define OLED_CLASS_OBJ  SSD1306Wire
#define OLED_ADDRESS    0x3C
#define OLED_SDA    21
#define OLED_SCL    22
#define OLED_RST    -1
#define CONFIG_MOSI 27
#define CONFIG_MISO 19
#define CONFIG_CLK  5
#define CONFIG_NSS  18
#define CONFIG_RST  23
#define CONFIG_DIO0 26
#define SDCARD_MOSI -1
#define SDCARD_MISO -1
#define SDCARD_SCLK -1
#define SDCARD_CS   -1
#include <Arduino.h>
OLED_CLASS_OBJ tft(OLED_ADDRESS, OLED_SDA, OLED_SCL);
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#define USE_SERIAL Serial
WiFiMulti wifiMulti;
#include <SPI.h>
int t = 0;
String tmp2;
void setup() {
  USE_SERIAL.begin(115200);
  //  pinMode(OLED_RST, OUTPUT);
  //  digitalWrite(OLED_RST, HIGH);
  //  delay(100);
  //  digitalWrite(OLED_RST, LOW);
  //  delay(100);
  //  digitalWrite(OLED_RST, HIGH);
  tft.init();
  tft.setTextAlignment(TEXT_ALIGN_CENTER);
  tft.flipScreenVertically();
  tft.clear();
  tft.drawString(57, 3, "! DXT RX !");
  tft.drawString(60, 20, "V1.01");
  tft.display();
  delay(2000);
  wifiMulti.addAP("SSID HERE", "WEB KEY HERE");;
}
void loop() {
  if ((wifiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    USE_SERIAL.print("[HTTP] begin...\n");
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=NVP6DSJDGEYPGZ22");
    //http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=12BB7OMBEIN3IIJJ");
    //http.begin ("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=Y8PWPLDACM1J84EQ");
    // http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BZOJWIRDNJ6GAMM6");
    int httpCode = http.GET();
    String payload = http.getString();
    char buf[1000];
    payload.toCharArray(buf, 1000);
    tmp2 = buf ;
    tmp2.trim();
    tft.clear();
    USE_SERIAL.println(tmp2);
    http.end();
  }
  for (int i = 500; i >= 0; i--) {
    tft.clear();
    tft.drawString(60, 3, "! NOS NIEUWS !");
    tft.drawString(-200 + i, 32, tmp2);
    tft.drawLine(5, 30, 128, 30);
    tft.drawLine(5, 50, 128, 50);
    tft.display();
    delay(10);
  }
  for (int i = 0; i <= 500; i++) {
    tft.clear();
    tft.drawString(60, 3, "! NOS NIEUWS !");
    tft.drawString(-200 - i, 32, tmp2);
    tft.drawLine(5, 30, 128, 30);
    tft.drawLine(5, 50, 128, 50);
    tft.display();
    delay(10);
  }
  tft.setTextAlignment(TEXT_ALIGN_CENTER);
  ///////////////////////////////////////////////////////////////////////////
  if ((wifiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    USE_SERIAL.print("[HTTP] begin...\n");
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=12BB7OMBEIN3IIJJ");
    int httpCode = http.GET();
    String payload = http.getString();
    char buf[1000];
    payload.toCharArray(buf, 1000);
    tmp2 = buf ;
    tmp2.trim();
    tft.clear();
    USE_SERIAL.println(tmp2);
    http.end();
  }
  for (int i = 500; i >= 0; i--) {
    tft.clear();
    tft.drawString(60, 3, "! P2000 !");
    tft.drawString(-200 + i, 32, tmp2);
    tft.drawLine(5, 30, 128, 30);
    tft.drawLine(5, 50, 128, 50);
    tft.display();
    delay(10);
  }
  for (int i = 0; i <= 500; i++) {
    tft.clear();
    tft.drawString(60, 3, "! P2000 !");
    tft.drawString(-200 - i, 32, tmp2);
    tft.drawLine(5, 30, 128, 30);
    tft.drawLine(5, 50, 128, 50);
    tft.display();
    delay(10);
  }
  tft.setTextAlignment(TEXT_ALIGN_CENTER);
  //////////////////////////////////////////////////////////////
  if ((wifiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    USE_SERIAL.print("[HTTP] begin...\n");
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BZOJWIRDNJ6GAMM6");
    int httpCode = http.GET();
    String payload = http.getString();
    char buf[1000];
    payload.toCharArray(buf, 1000);
    tmp2 = buf ;
    tmp2.trim();
    tft.clear();
    USE_SERIAL.println(tmp2);
    http.end();
  }
  for (int i = 500; i >= 0; i--) {
    tft.clear();
    tft.drawString(60, 3, "! De Tijdt !");
    tft.drawString(-200 + i, 32, tmp2);
    tft.drawLine(5, 30, 128, 30);
    tft.drawLine(5, 50, 128, 50);
    tft.display();
    delay(10);
  }
  for (int i = 0; i <= 500; i++) {
    tft.clear();
    tft.drawString(60, 3, "! De Tijdt !");
    tft.drawString(-200 - i, 32, tmp2);
    tft.drawLine(5, 30, 128, 30);
    tft.drawLine(5, 50, 128, 50);
    tft.display();
    delay(10);
  }
  tft.setTextAlignment(TEXT_ALIGN_CENTER);
   if ((wifiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    USE_SERIAL.print("[HTTP] begin...\n");
    http.begin("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=DXLRW4WOOIRQWZSM");
    int httpCode = http.GET();
    String payload = http.getString();
    char buf[1000];
    payload.toCharArray(buf, 1000);
    tmp2 = buf ;
    tmp2.trim();
    tft.clear();
    USE_SERIAL.println(tmp2);
    http.end();
  }
  for (int i = 1000; i >= 0; i--) {
    tft.clear();
    tft.drawString(60, 3, "! Het Weer !");
    tft.drawString(-200 + i, 32, tmp2);
    tft.drawLine(5, 30, 128, 30);
    tft.drawLine(5, 50, 128, 50);
    tft.display();
    delay(10);
  }
  for (int i = 0; i <= 1000; i++) {
    tft.clear();
    tft.drawString(60, 3, "! Het Weer !");
    tft.drawString(-200 - i, 32, tmp2);
    tft.drawLine(5, 30, 128, 30);
    tft.drawLine(5, 50, 128, 50);
    tft.display();
    delay(10);
  }
  tft.setTextAlignment(TEXT_ALIGN_CENTER);
}

