#define data 0
#define clock 1
#define com1 3
#define com2 2
void led_display(int,int);
//int d[10]={0x81,0xf9,0x25,0x29,0x59,0xb,0x3,0xb9,0x1,0x9};
int d[10]={0x0c,0x3f,0x45,0x25,0x36,0xa4,0x84,0x3d,0x04,0x24};
int i=0,num=0;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(clock, OUTPUT); // make the clock pin an output
  pinMode(data , OUTPUT); // make the data pin an output3
  pinMode(com1 , OUTPUT); // make the data pin an output3
  pinMode(com2 , OUTPUT); // make the data pin an output3
}

void loop() 
{
  // put your main code here, to run repeatedly:
 if(i>=70){
   num=int(analogRead(2)*25/256);  
   i=0;}
 i++;
  led_display(num%10,com1); 
  led_display(num/10,com2);

}
void led_display(int num,int com){ 
  shiftOut(data, clock, LSBFIRST, d[num]);
  digitalWrite(com,HIGH);
  delay(10);
  digitalWrite(com,LOW);

  }
