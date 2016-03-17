//*****************************************************************************
//Light Sword V1.0
//阿布拉機的3D列印與機器人
//http://arbu00.blogspot.tw/
//
//2016/03/17 Writen By Ashing Tsai
//
//
//******************************************************************************
#include <Timer.h>     
const int led2=2;
const int led3=3;
const int led4=4;
const int led5=5;
const int led6=6;
const int led7=7;
const int led8=8;
const int led9=9;

const int pin10=10;
const int speakerA=11;
const int speakerB=12;
const int ModePin=13;

Timer t1,t2,t3,t4,t5,t6,t7;
int modeflag=0;
int modecounter=0;
int Hitflag=0;
int PWM_PIN,PWM_T0;
int ledpin;
void setup()
{ 

   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(led4,OUTPUT);
   pinMode(led5,OUTPUT);
   pinMode(led6,OUTPUT);
   pinMode(led7,OUTPUT);
   pinMode(led8,OUTPUT);
   pinMode(led9,OUTPUT);
   
   pinMode(speakerA,OUTPUT);
   pinMode(speakerB,OUTPUT);
   pinMode(ModePin,INPUT);
   
      digitalWrite(led2,HIGH); 
      delay(100);
      digitalWrite(led3,HIGH);
      delay(100);
      digitalWrite(led4,HIGH);
      delay(100);
      digitalWrite(led5,HIGH);
      delay(100);
      digitalWrite(led6,HIGH); 
      delay(100);
      digitalWrite(led7,HIGH);
      delay(100);
      digitalWrite(led8,HIGH);
      delay(100);
      digitalWrite(led9,HIGH);
 
  Serial.begin(9600);
  t1.every(20, takeReading);
  t2.every(20, takeReading2);
  t3.every(2, MY_PWM);
  t4.every(100, LEDMODE0);
  t6.every(100, LEDMODE3);
}  
void loop()
{
  t1.update();
  //t2.update();

switch(modecounter)
 {
  case 0:
  t4.update();
  break;
   case 1:
    t5.update();
    t5.oscillate(led2, 500, HIGH);
    t5.oscillate(led3, 500, HIGH);
    t5.oscillate(led4, 500, HIGH);
    t5.oscillate(led5, 500, HIGH);
    t5.oscillate(led6, 500, HIGH);
    t5.oscillate(led7, 500, HIGH);
    t5.oscillate(led8, 500, HIGH);
    t5.oscillate(led9, 500, HIGH);
  
  break;
   case 2:
    t7.update();
    t7.pulse(led2, 100, HIGH);
    t7.pulse(led3, 100, HIGH);
    t7.pulse(led4, 100, HIGH);
    t7.pulse(led5, 100, HIGH);
    t7.pulse(led6, 100, HIGH);
    t7.pulse(led7, 100, HIGH);
    t7.pulse(led8, 100, HIGH);
    t7.pulse(led9, 100, HIGH);
    t7.pulse(led2, 100, LOW);
    t7.pulse(led3, 100, LOW);
    t7.pulse(led4, 100, LOW);
    t7.pulse(led5, 100, LOW);
    t7.pulse(led6, 100, LOW);
    t7.pulse(led7, 100, LOW);
    t7.pulse(led8, 100, LOW);
    t7.pulse(led9, 100, LOW);
    
  break;
   case 3:
    t6.update();
     break;
  default:
   break;
  }
}  
void Speakersound() 
{

      digitalWrite(led2,HIGH); 
      digitalWrite(led3,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led6,HIGH); 
      digitalWrite(led7,HIGH);
      digitalWrite(led8,HIGH);
      digitalWrite(led9,HIGH);
    tone(speakerA,320);
    delay(700);
    noTone(speakerA);

}

void takeReading()
{
   modeflag=  digitalRead(ModePin); 
  Serial.println(modeflag);
  if (modeflag==1){   //press down =1
     delay(3);
     while(digitalRead(ModePin)==1)
     { Serial.println("dead!");}
     modecounter=modecounter+1;
  }
  if(modecounter>=4)
  {modecounter=0;}
 Serial.println(modecounter);

}

void takeReading2()
{
    Hitflag= digitalRead(pin10); 
  Serial.println(Hitflag);
  if (Hitflag==1){ 
     Speakersound() ;
     Hitflag=0;
  }
}
void MY_PWM() //2ms  PWM
{
    LEDONOFF(PWM_PIN,PWM_T0);

}

void LEDONOFF(int pin,int t_on) //2ms  PWM
{
    
  if(t_on<=255){
      for(int i=0;i<=255;i++)
     {
      if(i<=t_on){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
     
       }
      else{
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      }
     }
  }

}
void LEDMODE0() //mode0
{
 for(int i=10;i<255;i++)
  {
    

      PWM_T0=i;
      t1.update();
     // t2.update();
      t3.update();
      i=i+2;
   }
 for(int j=255;j>10;j--)
  {

     PWM_T0=j;
     t1.update();
    // t2.update();
     t3.update();
     j=j-2;
  }
  
}

void LEDMODE3() //mode3
{
for(int i=2;i<=9;i++)
  {
      digitalWrite(i,HIGH);
      t1.update();
      t2.update();
      delay(100);
  }
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      delay(100);
}
