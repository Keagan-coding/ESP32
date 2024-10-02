#ifndef WEBSITE_SERVER_H
#define WEBSITE_SERVER_H

#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include "AsyncTCP.h"

#define LED 18

class WifiServer {
    public : 
        WifiServer();
        void SetupWebpage();
        String SetLEDStateString();
        void HandleLEDButtonPressEvents();
        void ConnectToWifiNetwork ();
        void SendJsonData();
    private : 
        bool led_state = false;
        const char *ssid = "K&L_house";
        const char *password = "Myfairy31";
        AsyncWebServer server ;

};

#endif