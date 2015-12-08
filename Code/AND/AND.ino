/*
AND OR

  modified 11 November 2015
  by Scott Fitzgerald
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);  //select function
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2) == 1) // AND Mode
  {
    
    digitalWrite(0,(digitalRead(3))&&(digitalRead(4)));
  }
  else  //OR Mode
  {
    digitalWrite(0,(digitalRead(3))||(digitalRead(4)));
  }
}
