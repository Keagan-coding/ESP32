#include <Neopixel_control.h>
#include <Website_server.h>

#define BUILT_IN_LED 2

WifiServer wifi;
// NeopixelControl neopixel;

void setup() {
    Serial.begin(115200);
    
    wifi.ConnectToWifiNetwork();
    wifi.SetupWebpage();
    wifi.HandleLEDButtonPressEvents();
    wifi.SendJsonData();

    // neopixel.LED_Matrix.begin();
    // neopixel.LED_Matrix.setTextWrap(false);
    // neopixel.LED_Matrix.setBrightness(10); 
    // neopixel.LED_Matrix.setTextColor(neopixel.SetColor(neopixel.GREEN)); 
    
    pinMode(LED, OUTPUT);

}

void loop() {
    // delay(1); 
    static int count = 0;
    // neopixel.DisplayNumber(count); // Display current count on the LED matrix
    // Serial.printf("value: %d\n", count);
    // count++;
    // if (count > 9) {
    //     count = 0; // Reset count after reaching 9
    // }
    // delay(1000); // Delay for 1 second before next iteration
}

