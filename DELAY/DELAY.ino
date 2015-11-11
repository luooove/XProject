void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  // attachInterrupt(3,Xdelay,CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(3) == 1)
  {
    digitalWrite(0, HIGH);
    delay(analogRead(1)/10);
    digitalWrite(0, LOW);
  }


}
