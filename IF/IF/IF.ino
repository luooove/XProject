/*
AND OR

  modified 11 November 2015
  by xiaoxiang luo
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(3) == 1) // AND Mode
  {

    digitalWrite(0, HIGH);
  }
  else  //OR Mode
  {
    digitalWrite(0, LOW);
  }

  if (digitalRead(4) == 1) // AND Mode
  {

    digitalWrite(1, HIGH);
  }
  else  //OR Mode
  {
    digitalWrite(1, LOW);
  }
}
