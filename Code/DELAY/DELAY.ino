//       ATMEL ATTINY13 / ARDUINO
//
//                      +-\/-+
// [RST]ADC0 (D 5) PB5 1|    |8 Vcc
//      ADC3 (D 3) PB3 2|    |7 PB2 (D 2) ADC1[SCK]
//      ADC2 (D 4) PB4 3|    |6 PB1 (D 1) PWM1[MISO]
//                 GND 4|    |5 PB0 (D 0) PWM0[MOSI]
//                      +----+

void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  // attachInterrupt(3,Xdelay,CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(3) == 1)
  {
    if (digitalRead(2) == 1) // second
  {
    digitalWrite(0, HIGH);
    delay(analogRead(2) *5);
    digitalWrite(0, LOW);
    delay(analogRead(2) *5);
  }
  else   //0.1 second
  {
    digitalWrite(0, HIGH);
    delay(analogRead(2)/2 );
    digitalWrite(0, LOW);
    delay(analogRead(2)/2 );
  }
  }
  else
  {
    digitalWrite(0, LOW);
  }
  


}
