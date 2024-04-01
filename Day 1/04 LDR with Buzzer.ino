int in1=34;
int in2=26;
void setup() {
  Serial.begin(9600);
  pinMode(in1, INPUT);
  pinMode(in2,OUTPUT);
}

void loop() {
int ldr = analogRead(in1);
Serial.print("LDR : ");
Serial.println(ldr);
if(ldr < 1500){
  digitalWrite(in2,HIGH);
}
delay(1000);
}// Paste your code here
