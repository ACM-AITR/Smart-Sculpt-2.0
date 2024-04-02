#include <WiFi.h>
#include <SinricPro.h>
#include "Car.h"

#define APP_KEY    "55e595d2-014f-4dc7-9335-632bdc175f8a"
#define APP_SECRET "610a86ca-4fcb-4bb0-ad8f-b77b7e7f37c1-2280a00e-0c65-4935-9398-ffd3e4efd885"
#define DEVICE_ID  "660c2c6c38f6f4a3cdced6af"
#define SSID       "MERU"
#define PASS       "9826011467"
#define BAUD_RATE  9600
#define in1 14
#define in2 27
#define in3 26
#define in4 25

Car &car = SinricPro[DEVICE_ID];

bool globalPowerState;

// ModeController
String currentMode = "forward"; // Default mode is forward

// PowerStateController
bool onPowerState(const String &deviceId, bool &state) {
  Serial.printf("[Device: %s]: Powerstate changed to %s\r\n", deviceId.c_str(), state ? "on" : "off");
  globalPowerState = state;
  return true; // request handled properly
}

// ModeController
bool onSetMode(const String& deviceId, const String& instance, String &mode) {
  Serial.printf("[Device: %s]: Modesetting for \"%s\" set to mode %s\r\n", deviceId.c_str(), instance.c_str(), mode.c_str());
  currentMode = mode; // Update current mode
  return true;
}

void updatePowerState(bool state) {
  car.sendPowerStateEvent(state);
}

void updateMode(String instance, String mode) {
  car.sendModeEvent(instance, mode, "PHYSICAL_INTERACTION");
}

void setupSinricPro() {
  // PowerStateController
  car.onPowerState(onPowerState);
  // ModeController
  car.onSetMode("modeInstance1", onSetMode);

  SinricPro.onConnected([]{ Serial.printf("[SinricPro]: Connected\r\n"); });
  SinricPro.onDisconnected([]{ Serial.printf("[SinricPro]: Disconnected\r\n"); });
  SinricPro.begin(APP_KEY, APP_SECRET);
};

void setupWiFi() {
  WiFi.begin(SSID, PASS);
  Serial.printf("[WiFi]: Connecting to %s", SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf(".");
    delay(250);
  }
  Serial.printf("connected\r\n");
}

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Serial.begin(BAUD_RATE);
  setupWiFi();
  setupSinricPro();
}

void loop() {
  SinricPro.handle();
  
  // Based on the current mode, perform corresponding actions
  if (currentMode == "Forward") {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  } else if (currentMode == "Backward") {
    digitalWrite(in2,HIGH);
    digitalWrite(in1,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in3,LOW);
  } else if (currentMode == "Left Turn") {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  } else if (currentMode == "Right Turn") {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  } else if( currentMode == "STOP"){
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  }
}
