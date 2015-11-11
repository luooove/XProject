/*
NOT

  modified 11 November 2015
  by Scott Fitzgerald
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(3, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(0,!digitalRead(3));
}
