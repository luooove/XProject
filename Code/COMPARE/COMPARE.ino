void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(3) > analogRead(2))
  { digitalWrite(0, HIGH);
  }
  else
  {
    digitalWrite(0, LOW);
  }

}
