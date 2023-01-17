#include <WiFiManager.h>
#include "./HTML.h"
#include "./JS.h"
#include "./STYLE.h"
ESP8266WebServer server(80);


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

void wmConfig() {
    // WiFiManager, Local intialization. Once its business is done, there is no
    // need to keep it around
    WiFiManager wm;
     wm.resetSettings(); // reset the wifi config

    bool res;
    res = wm.autoConnect("Lumee");  // password protected ap

    if (!MDNS.begin("Lumee")) {  // Start the mDNS responder for esp8266.local
        Serial.println("Error setting up MDNS responder!");
    }
    MDNS.addService("http", "tcp", 80);
    WiFi.hostname("Lumee");

    server.on("/", hendleIndex);
    server.on("/style.css", handleStyle);
    server.on("/js", handlejs);
    server.begin();
}
