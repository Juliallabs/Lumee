#include <Arduino.h>
#include <WiFiManager.h>
#include <ESP8266mDNS.h>
#include <Adafruit_NeoPixel.h>
#include "./infrastructure.h"
#include"./html.h"
#include"./js.h"
#include"./style.h"

// LED config

#define PIN 2
#define NUMPIXELS 9
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

ESP8266WebServer server(80);
String corRGB ="";

void hendleIndex() {                           // send HTML to the page
    Serial.println("GET /");
    server.send(200, "text/html", postForms);  // check HTML.h file
}
void handleStyle() {                           // send HTML to the page
    Serial.println("GET /style.css");
    server.send(200, "text/css", style);  // check HTML.h file
}
void handlejs() {                           // send HTML to the page
    Serial.println("GET /js");
    server.send(200, "application/javascript", js);  // check HTML.h file
}
void handleGetParam() {
 if (server.hasArg("cor")) {
    String corRGB = server.arg("cor");
    String r = corRGB.substring(4,corRGB.indexOf(','));
    corRGB = corRGB.substring(corRGB.indexOf(',')+1);
    String g = corRGB.substring(0,corRGB.indexOf(','));
    corRGB = corRGB.substring(corRGB.indexOf(',')+1);
    String b = corRGB.substring(0,corRGB.length()-1);
    pixels.fill(pixels.Color(r.toInt(),g.toInt(),b.toInt()));
    pixels.show();
    Serial.print("r: ");
    Serial.println(r.toInt());
    Serial.print("g: ");
    Serial.println(g.toInt());    
    Serial.print("b: ");
    Serial.println(b.toInt());
 }

}   

void setup() {
    WiFi.mode(WIFI_STA);
    Serial.begin(115200);
    wmConfig(); // infrastructure.h

    //init server
    server.on("/", hendleIndex);
    server.on("/style.css", handleStyle);
    server.on("/js", handlejs);
    server.on("/cor", handleGetParam);
    server.begin();

    //init leds
    pixels.begin();
    pixels.clear();
    pixels.setPixelColor(0,pixels.Color(0,255,0));
    //pixels.fill(0,pixels.Color(0,255,0));
    pixels.show();
    delay(30);
    

}

void loop() {
    MDNS.update();
    server.handleClient();
}