#include <Arduino.h>
#include <WiFiManager.h>
#include <ESP8266mDNS.h>
#include "./infrastructure.h"

void setup() {
    WiFi.mode(WIFI_STA);
    Serial.begin(115200);
    wmConfig(); // infrastructure.h
    

}

void loop() {
    MDNS.update();
    server.handleClient();
}