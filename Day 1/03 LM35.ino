int in1=34;
int in2=26;
void setup() {
  Serial.begin(9600);
  pinMode(in1, INPUT);
  pinMode(in2,OUTPUT);
}

void loop() {
int lm35 = analogRead(in1);
Serial.print("LM35 : ");
Serial.println(lm35);
if(lm35 < 1500){
  digitalWrite(in2,HIGH);
}
delay(1000);
}
