#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//#include <DNSServer.h>
//#include <ESP8266WebServer.h>
#include "libraries/WiFiManager/WiFiManager.h"         //https://github.com/tzapu/WiFiManager


void setup() {
    Serial.begin(115200);
    WiFiManager wifiManager;
    wifiManager.autoConnect("MS-Project", "project2016");
    Serial.println("Connected");
}

void loop() {
    
}
