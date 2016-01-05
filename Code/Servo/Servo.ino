//Servo test ok! also like a fade LED

//Author: Leo
//Date: 2015.03.12
//IDE Ver.: 1.0.3
//website: github.com/leolite
//MCU: ATMEL ATTINY13
//Programmer: usbtinyisp(@Ladyada https://learn.adafruit.com/usbtinyisp/drivers)
//hardware core: core13(@smeezekitty http://sourceforge.net/projects/ard-core13/)

/*

 This example code is in the public domain.
 */

//       ATMEL ATTINY13 / ARDUINO
//
//                      +-\/-+
// [RST]ADC0 (D 5) PB5 1|    |8 Vcc
//      ADC3 (D 3) PB3 2|    |7 PB2 (D 2) ADC1[SCK]
//      ADC2 (D 4) PB4 3|    |6 PB1 (D 1) PWM1[MISO]
//                 GND 4|    |5 PB0 (D 0) PWM0[MOSI]
//                      +----+

//Timer define
int t = 0;
int period = 120;
int pulseWidthScaled = 25;
//User data
int servoPin = 0;
int pulseStartPoint = 5; //MIN start position is 5
int pulseEndPoint = 25;  //MAX end position is 25
int overflowValueCTC = 10;

void setup(){
  pinMode(servoPin, OUTPUT);   
  setup_timer(); // Initialize the timer
}

void loop() {
int a=analogRead(2);
a=a/150+5;
pulseWidthScaled = a;
}

// TIMER0 -- Only one in attiny13
void setup_timer(void) {
  //timer 1:
  TCCR0A = 0;// set entire TCCR1A register to 0
  TCCR0B = 0;// same for TCCR1B

  // Set up the timer 
  TCCR0A |= (1 << WGM01);  // Mode: CTC
  TCCR0B |= (1 << CS01); // Prescaler: 

  // Initialize the count
  TCNT0 = 0;

  // Initialize the compare value
  OCR0A = overflowValueCTC;

  // Enable compare interrupt
  TIMSK0 |= (1 << OCIE0A);

  // Enable global interrupts
  sei();
}

//timer 1 interrupt
ISR (TIM0_COMPA_vect) {
  //increment t and reset each time it reaches period
  t += 1;
  if (t >= period){
    t = 0;
  }
  if (pulseWidthScaled <= t) {
    digitalWrite(servoPin, LOW);
  }
  else{
    digitalWrite(servoPin, HIGH);
  }
}



