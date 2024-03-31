int in1=2;
int in2=3;
void setup() {
  pinMode(in1, INPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  int tsop = digitalRead(in1);
  if(tsop == HIGH){
    digitalWrite(in2,HIGH);
  }else{
    digitalWrite(in2,LOW);
  }
}
