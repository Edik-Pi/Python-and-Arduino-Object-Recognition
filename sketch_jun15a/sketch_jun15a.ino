#include <Servo.h>
#include <Math.h>
//#include<LiquidCrystal.h>

 char x2;
 long int v;

 static int s_Base=125;
 static int s_Sobe=70;
 static int s_Frente=10;
 static int s_Garra=70;
 int RedLed=11;

// const int rs=2,en=3,d4=13,d5=12,d6=5,d7=4;
 //LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
 
 int position1=0;
 int position2=0;
 Servo Base ;
 Servo Sobe;
 Servo Frente ;
 Servo Garra ;
 Servo servo_Ga;

 float px=3.5,py=0,pz=10;

//PARAMETRO PARA O CALCULO DA CINEMATICA
  float q1real,q2real,q3real,q1,q2,q3,x,r,x1,y1=4;
  float numq3,raiznumq3,denq3;
  float cq3,cosq3num,cosq3den,Beta,numx,denx;

//LONGITUDE DAS ARTICULACOES
  float l1=15;
  float l2=19.5;
  float l3=15;

void setup() {
 // lcd.begin(16,2);
  //lcd.print("Not working");
  Base.attach(6);
  Sobe.attach(7);
  Frente.attach(8);
  Garra.attach(9);
  servo_Ga.attach(10);
  pinMode(RedLed,OUTPUT);
  

 //POSICAO INICIAL DO MANIPULADO
  Base.write(135);
  Sobe.write(60);
  Frente.write(20);
  Garra.write(70);
  Serial.begin(9600);  
}
  //CALCULO DA CINEMATICA INVERSA/
  void Calculo(float px, float py,float pz){
  //py=0,pz=10;
  float l1=15;
  float l2=19.5;
  float l3=15;
       q1=atan(py/px)*(180/3.14);
       q1real=q1;
       r=sqrt((px*px)+(py*py));
       cosq3num=r*r+(pz-l3)*(pz-l3)-((l2)*(l2));
       cosq3den=2*(l2*l3);
       cq3=cosq3num/cosq3den;
       q3=atan((sqrt(1-(cq3*cq3)))/(cq3));
       Beta=atan((pz-l2)/(r))*(180/3.1416);
       denx=(l2+13*cos(q3*(180/3.1416)));
       numx=(l3*sin(q3*(3.1416/180)));
  
       x=atan(numx/denx)*(180/3.1416);  
       q2=Beta-x;
       q2real=q2+90;//
       q2real=q2real;
       q3real=90+q3;  
}
void loop() {
 // lcd.clear();
 //lcd.print("Working");
 digitalWrite(RedLed,LOW);
 servo_Ga.write(85);
 if(Serial.available()>2){
 x2 =Serial.read();
  // v =Serial.parseInt();
  if (x2 =='a')  {
  
////Sobe

    digitalWrite(RedLed,LOW);
    for (y1=30; y1>=8; y1-=0.5){
       py=y1;px=19,pz=0;
       Calculo(px,py,pz);
       Sobe.write(q1real);
       Serial.print("Sobe q1 :");
       Serial.println(q1real);
       delay(20);
    }
    // delay(100);
     digitalWrite(RedLed,HIGH);

//Frente
    for (x1=4; x1<=14; x1+=0.5){
       px=x1,py=0,pz=10;
       Calculo(px,py,pz);
       Frente.write(q2real);
       Serial.print("Frente :");
       Serial.println(q2real);
       delay(20);
    }
   // delay(100);
     digitalWrite(RedLed,LOW);
    
    for (s_Garra=70; s_Garra>=30; s_Garra-=1){
       Garra.write(s_Garra);
       delay(20); 
       }
    digitalWrite(RedLed,HIGH);

////Sobe
    for (y1=8; y1<=30; y1+=0.5){
       py=y1;px=19,pz=0;
       Calculo(px,py,pz);
       Sobe.write(q1real);
       Serial.print("Sobe q1 :");
       Serial.println(q1real);
       delay(20);
    }
    // delay(100);
     digitalWrite(RedLed,LOW);
     
//Frente
    for (x1=14; x1>=4; x1-=0.5){
       px=x1,py=0,pz=10;
       Calculo(px,py,pz);
       Frente.write(q2real);
       Serial.print("Frente :");
       Serial.println(q2real);
       delay(20);
    }
    //delay(100);
    digitalWrite(RedLed,HIGH);

 //################################################
       for (s_Base=135; s_Base>=40; s_Base-=1){
       Base.write(s_Base);
       x =Serial.read();
       delay(20); 
       } 
      digitalWrite(RedLed,LOW);
      // delay(100);
  //################################################ 
  
////Sobe
    for (y1=30; y1>=8; y1-=0.5){
       py=y1;px=19,pz=0;
       Calculo(px,py,pz);
       Sobe.write(q1real);
       Serial.print("Sobe q1 :");
       Serial.println(q1real);
       delay(20);
    }
     //delay(100);
     digitalWrite(RedLed,HIGH);
     
//Frente
    for (x1=4; x1<=14; x1+=0.5){
       px=x1,py=0,pz=10;
       Calculo(px,py,pz);
       Frente.write(q2real);
       Serial.print("Frente :");
       Serial.println(q2real);
       delay(20);
    }
    //delay(100);
     digitalWrite(RedLed,LOW);
    
     for (s_Garra=30; s_Garra<=70; s_Garra+=1){
       Garra.write(s_Garra);
       delay(20); 
       }
     digitalWrite(RedLed,HIGH);

         ////Sobe
    for (y1=8; y1<=30; y1+=0.5){
       py=y1;px=19,pz=0;
       Calculo(px,py,pz);
       Sobe.write(q1real);
       Serial.print("Sobe q1 :");
       Serial.println(q1real);
       delay(20);
    }
     //delay(500);
    digitalWrite(RedLed,LOW);
     
//Frente
    for (x1=14; x1>=4; x1-=0.5){
       px=x1,py=0,pz=10;
       Calculo(px,py,pz);
       Frente.write(q2real);
       Serial.print("Frente :");
       Serial.println(q2real);
       delay(20);
    }
    //delay(500);
     digitalWrite(RedLed,HIGH);

     ///#############################################
       for (s_Base=40; s_Base<=135; s_Base+=1){
       Base.write(s_Base);
       x =Serial.read();
       delay(20); 
       } 
        digitalWrite(RedLed,LOW);
       //delay(500);
       ///#############################################

       for (s_Garra=30; s_Garra<=70; s_Garra+=1){
       Garra.write(s_Garra);
       delay(20); 
       }
      digitalWrite(RedLed,HIGH);
       //delay(500);
    x =Serial.read();
 }
  }
}
