#include <Arduino.h>
#include <WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID         "MERU"    
#define WIFI_PASS         "9826011467"
#define APP_KEY           "55e595d2-014f-4dc7-9335-632bdc175f8a"     
#define APP_SECRET        "610a86ca-4fcb-4bb0-ad8f-b77b7e7f37c1-2280a00e-0c65-4935-9398-ffd3e4efd885" 
#define SWITCH_ID         "660c213460d81635d1d49c9e" 
#define BAUD_RATE         115200               
#define LED_PIN           14                 

bool onPowerState(const String& deviceId, bool &state) {
  digitalWrite(LED_PIN, state ? HIGH : LOW);
  return true; 
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }

  SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];
  mySwitch.onPowerState(onPowerState);

  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}

void loop() {
  SinricPro.handle();
}
