void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(0,analogRead(2)/4);
analogWrite(1,analogRead(3)/4);//some problem in this pin
}
