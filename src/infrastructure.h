#include <WiFiManager.h>


void wmConfig() {
    // WiFiManager, Local intialization. Once its business is done, there is no
    // need to keep it around
    WiFiManager wm;
     //wm.resetSettings(); // reset the wifi config

    bool res;
    res = wm.autoConnect("Lumee");  // password protected ap

    if (!MDNS.begin("Lumee")) {  // Start the mDNS responder for esp8266.local
        Serial.println("Error setting up MDNS responder!");
    }
    MDNS.addService("http", "tcp", 80);
    WiFi.hostname("Lumee");

}
