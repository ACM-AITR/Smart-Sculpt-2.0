#define in1 33
#define in2 32
#define in3 26
#define in4 25
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
char ch;

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP 32"); //Bluetooth device name - You can give any name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
    ch =(char)SerialBT.read();
    if(ch == 'f'){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    } else if(ch == 'b'){
      digitalWrite(in2,HIGH);
      digitalWrite(in1,LOW);
      digitalWrite(in4,HIGH);
      digitalWrite(in3,LOW);
    } else if(ch == 's'){
      digitalWrite(in2,LOW);
      digitalWrite(in1,LOW);
      digitalWrite(in4,LOW);
      digitalWrite(in3,LOW);
    } else if(ch == 'l'){
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }else if(ch == 'r'){
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }
  }
  delay(20);
}
