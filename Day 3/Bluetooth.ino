#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
char ch;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Arduino Mega"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
    ch =(char)SerialBT.read();
    if(ch == 'h'){
      Serial.println("Hi...");
    } else if(ch == 'b'){
      Serial.println("Bye...");
    }
  }
  delay(20);
}
