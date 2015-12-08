int data[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void Num_Send(int d, int w);
void setup() {
  // put your setup code here, to run once:
  pinMode(4, INPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(2);
  a = a * 100 / 5;
  Num_Send(a & 0x01, 1);
  Num_Send((a >> 1) & 0x01, 2);
}
void Num_Send(int d, int w) {
  if (w == 1) digitalWrite(2, HIGH);
  else digitalWrite(3, HIGH);

  for (int i = 0; i < 8; i++) {
    digitalWrite(1, LOW);
    if (data[d] & 0x01 == 0x01) digitalWrite(0, HIGH);
    else digitalWrite(0, LOW);
    data[d] = data[d] >> 1;
    delay(1);
    digitalWrite(1, HIGH);
    

  }
  if (w == 1) digitalWrite(2, LOW);
  else digitalWrite(3, LOW);
}
