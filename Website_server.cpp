#include <Website_server.h>
#include <Neopixel_control.h>

// NeopixelControl neopixel;

WifiServer::WifiServer() : server(80){
    Serial.println("In wifi initializer");
}

void WifiServer::ConnectToWifiNetwork() {
    WiFi.begin(ssid, password);
    
    // Use millis() for non-blocking delay
    unsigned long startAttemptTime = millis();

    // Try connecting to Wi-Fi for 10 seconds
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
        Serial.println("Connecting to WiFi...");
        delay(1000);  // Reduce or remove delay if possible
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected to WiFi");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
       
    } 
    else {
        Serial.println("Failed to connect to WiFi");
    }
}
String WifiServer::SetLEDStateString() {
    return led_state ? "ON" : "OFF";
}

void WifiServer::SetupWebpage() {
    // Make sure SPIFFS is initialized
    if (!SPIFFS.begin(true)) {
        Serial.println("An error occurred while mounting SPIFFS");
        return;
    }

    // Serve HTML file
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/webpage.html", "text/html");
    });

    // Serve CSS file
    server.on("/webpage.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/webpage.css", "text/css");
    });

    // Serve image file
    server.on("/pool.png", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/pool.png", "image/png");
    });

    // Serve JS file
    server.on("/webpage.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/webpage.js", "text/javascript");
    });

     server.begin();  // Start the server
}

void WifiServer::SendJsonData() {
        
     server.on("/Dropdowndata", HTTP_GET, [](AsyncWebServerRequest *request) {
        // Create a JSON document
        DynamicJsonDocument colordropdown(200); // Choose a suitable size for the document

        // Populate the JSON document with color values from neopixel
        colordropdown["RED"] = 1;
        colordropdown["GREEN"] = 2;
        colordropdown["BLUE"] = 3;
        colordropdown["LIGHT_BLUE"] = 4;
        colordropdown["WHITE"] = 5;

        String jsonString;
        serializeJson(colordropdown, jsonString);
        request->send(200, "application/json", jsonString);
    });

}
void WifiServer::HandleLEDButtonPressEvents() {
    // Handle turning LED on
    server.on("/on", HTTP_GET, [this](AsyncWebServerRequest *request) {
        this->led_state = true;
        digitalWrite(LED, HIGH);
        request->send(200, "text/plain", "LED is ON");
    });

    // Handle turning LED off
    server.on("/off", HTTP_GET, [this](AsyncWebServerRequest *request) {
        this->led_state = false;
        digitalWrite(LED, LOW);
        request->send(200, "text/plain", "LED is OFF");
    });

    // Provide LED state in response
    server.on("/state", HTTP_GET, [this](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", this->SetLEDStateString());
    });
}
// void WifiServer::HandleGetColors(AsyncWebServerRequest *request) {
//   StaticJsonDocument<200> jsonDoc;
//   JsonObject jsonObj = jsonDoc.to<JsonObject>();

//   jsonObj["RED"] = RED;
//   jsonObj["GREEN"] = GREEN;
//   jsonObj["BLUE"] = BLUE;
//   jsonObj["LIGHT_BLUE"] = LIGHT_BLUE;
//   jsonObj["WHITE"] = WHITE;

//   String jsonString;
//   serializeJson(jsonDoc, jsonString);
//   request->send(200, "application/json", jsonString);
// }