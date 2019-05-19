#include <Servo.h>

Servo servo;

Servo servo2;

int P1=30;
int P2=150;
int tl=0;
int x = 30;
boolean stat = false;
boolean stat2 = false;

boolean ON = false;
//M1
int enA = A0;
int in1 = 2;
int in2 = 3;
//M2
int enB = A1;
int in3 = 12;
int in4 = 13;

int choice;

int motorSpeed = 1000;  //variable to set stepper speed /////////////////////////////////////////////////////////////CHANGE SPEED /////////////
int count = 0;          // count of steps made
int countsperrev = 250; // number of steps per full revolution ////////////////////////////////////////////////////////CHANGE THE ANGLE ////////
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};
int pos = 0;  
//////////////////////////////////////////////////////////////////////////////
void setup() {
  //declare the motor pins as outputs
servo.attach(9);
servo2.attach(8);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
servo.write(140);
servo2.write(40);

  Serial.begin(9600);
}

//////////////////////////////////////////////////////////////////////////////
void loopx() {

   
if(P2>140){
  P2=140; 
  stat2=true;  
  }

  if(P2<40){
  P2=40;   
  stat2=false;
  }

  if(stat2){
    P2--;;
    }

     if(stat2==false){
    P2++;
    }

//////////////////////////////////

  
if(P1>140){
  P1=140; 
  stat=true;  
  }

  if(P1<40){
  P1=40;   
  stat=false;
  }

  if(stat){
    P1--;;
    }

     if(stat==false){
    P1++;
    }
servo.write(P1);
servo2.write(P2);

  delay(15);  


  
  }



void loop() {

  if (Serial.available()) {
    choice = Serial.read();
  }

  if (choice == '1') {
    Serial.println("Forward...");
  //  mpower(1, 1, 255 );
   // mpower(2, 1, 255 );
    //  delay(2000);
     digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);

     
      digitalWrite(in3,LOW);
     digitalWrite(in4,HIGH);
  }
  if (choice == '0') {

    Serial.println("Reverse...");
   // mpower(1, -1, 255 );
   // mpower(2, -1, 255);
    // delay(2000);
    digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);

      digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW);

  }

  if (choice == '2') {

    Serial.println("stop...");
   digitalWrite(in1,LOW);
     digitalWrite(in2,LOW);

      digitalWrite(in3,LOW);
     digitalWrite(in4,LOW);


  }

    if (choice == '3') {

    Serial.println("left...");
   digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);

      digitalWrite(in3,LOW);
     digitalWrite(in4,HIGH);


  }
      if (choice == '40') {

    Serial.println("Right...");
   digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);

      digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW);


  }

  if (choice == '8') {

   
if(P2>140){
  P2=140; 
  stat2=true;  
  }

  if(P2<40){
  P2=40;   
  stat2=false;
  }

  if(stat2){
    P2--;;
    }

     if(stat2==false){
    P2++;
    }

//////////////////////////////////

  
if(P1>140){
  P1=140; 
  stat=true;  
  }

  if(P1<40){
  P1=40;   
  stat=false;
  }

  if(stat){
    P1--;;
    }

     if(stat==false){
    P1++;
    }
servo.write(P1);
servo2.write(P2);

  delay(15);  


  }

  if (choice == '6') {
    

  }
  if (choice == '5') {
  

  }
  if (choice == '4') {


  }


}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)
void anticlockwise()
{
  for (int i = 30; i < 150; i++)
  {
   
    servo.write(i);

    delay(50);
    // delay(2000);


  }
}

void clockwise()
{
  for (int i = 150; i >= 30; i--)
  {
    servo.write(i);

    delay(50);
    // delay(2000);

  }
}

void anticlockwise2()
{
  for (int i = 30; i < 150; i++)
  {
   
    servo2.write(i);

    delay(50);
    // delay(2000);


  }
}

void clockwise2()
{
  for (int i = 150; i >= 30; i--)
  {
    servo2.write(i);

    delay(50);
    // delay(2000);

  }
}
