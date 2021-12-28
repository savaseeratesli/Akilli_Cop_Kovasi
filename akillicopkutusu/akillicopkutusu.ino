#include <HCSR04.h>
#include <Servo.h>

int Trigger_Pin=11;
int Echo_Pin=10;
int ServoPin=3;

//Servo nesnesi,servo kütüphanesini özelliklerini kullanmam için
Servo Servo1;

double sure;
int mesafe;

void setup() 
{
  pinMode(Trigger_Pin,OUTPUT);
  pinMode(Echo_Pin,INPUT);

  Servo1.attach(ServoPin);//Servo çalışma pini
 
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(Trigger_Pin,HIGH);
  delayMicroseconds(500);

  digitalWrite(Trigger_Pin,LOW);

  //Ses dalgası gelis süresi
  sure=pulseIn(Echo_Pin,HIGH);
  mesafe=(sure*0.034)/2;
  
  Serial.println(mesafe);
  
  if(mesafe<50)
  {
     Servo1.write(180);
     delay(2000);
  }
  else
  {
    Servo1.write(0);//Servo 0 dereceye gelsin
  } 

  
}
