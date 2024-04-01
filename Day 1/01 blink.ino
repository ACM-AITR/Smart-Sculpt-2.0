int in1=2;
void setup() {
  pinMode(in1, OUTPUT);
}

void loop() {
    digitalWrite(in1,HIGH);
    delay(2000);
    digitalWrite(in1,LOW);
    delay(1000);
}
