#include <Servo.h>

Servo servo;

Servo servo2;

int x = 30;
boolean stat = false;
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

//////////////////////////////////////////////////////////////////////////////
void setup() {
  //declare the motor pins as outputs
servo.attach(9);
servo2.attach(10);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


  Serial.begin(9600);
}

//////////////////////////////////////////////////////////////////////////////
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

    if (count < countsperrev ) {
      clockwise();
      anticlockwise2();
    }
    else if (count == countsperrev * 2) {
      count = 0;
    }
    else {
      anticlockwise();
      clockwise2();
    }
    count++;
  }

  if (choice == '6') {
    clockwise();
    anticlockwise2();

  }
  if (choice == '5') {
    anticlockwise();
    clockwise2();

  }
  if (choice == '4') {

    setOutput(0);

    setOutput2(0);

  }


}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)
void anticlockwise()
{
  for (int i = 0; i < 150; i++)
  {
   
    servo.write(i);

    delay(50);
    // delay(2000);


  }
}

void clockwise()
{
  for (int i = 150; i >= 0; i--)
  {
    servo.write(i);

    delay(50);
    // delay(2000);

  }
}
