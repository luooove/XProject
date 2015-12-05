void setup() {
  // put your setup code here, to run once:
pinMode(0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(0,analogRead(2)/4);
//  if (digitalRead(3) == 1)
//    analogWrite(0, analogRead(2) / 4); //some problem in this pin
//  else
//    analogWrite(0, 0);

int a=analogRead(2);
if(a>950)
digitalWrite(0,HIGH);
else if(a<75)
digitalWrite(0,LOW);
else
{
  digitalWrite(0,HIGH);
delayMicroseconds(a*34);
digitalWrite(0,LOW);
delayMicroseconds(35000-a*34);
  }

}
