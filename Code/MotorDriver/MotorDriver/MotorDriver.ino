
//                      +-\/-+
// [RST]ADC0 (D 5) PB5 1|    |8 Vcc
//      ADC3 (D 3) PB3 2|    |7 PB2 (D 2) ADC1[SCK]
//      ADC2 (D 4) PB4 3|    |6 PB1 (D 1) PWM1[MISO]
//                 GND 4|    |5 PB0 (D 0) PWM0[MOSI]
//                      +----+

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);  //dir

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(3) == 1)
  {
    if (digitalRead(1) == 1)
    {
      digitalWrite(2, HIGH);
      analogWrite(0, 255 - analogRead(2) / 4); //some problem in this pin
    }

    else
    {
      digitalWrite(2, LOW);
      analogWrite(0, analogRead(2) / 4); //some problem in this pin
    }

  }
  else
  {
    analogWrite(0, 0);
  }
}
