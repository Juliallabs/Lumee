include <WiFiManager>

void wmConfig() {
    // WiFiManager, Local intialization. Once its business is done, there is no
    // need to keep it around
    WiFiManager wm;
    // wm.resetSettings(); // reset the wifi config

    bool res;
    res = wm.autoConnect("StarON");  // password protected ap

    if (!res) {
        // Serial.println("Failed to connect");
        //  ESP.restart();
    } else {
        // if you get here you have connected to the WiFi
        // Serial.println("connected...yeey :)");
    }
    // Serial.println(WiFi.localIP());
}