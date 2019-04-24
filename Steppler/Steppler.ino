int motorPin1 = 8;    // Blue   - 28BYJ48 pin 1
int motorPin2 = 9;    // Pink   - 28BYJ48 pin 2
int motorPin3 = 10;    // Yellow - 28BYJ48 pin 3
int motorPin4 = 11;    // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
int motor2Pin1 = 4;    // Blue   - 28BYJ48 pin 1
int motor2Pin2 = 5;    // Pink   - 28BYJ48 pin 2
int motor2Pin3 = 6;    // Yellow - 28BYJ48 pin 3
int motor2Pin4 = 7;    // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)

int motorSpeed = 1000;  //variable to set stepper speed /////////////////////////////////////////////////////////////CHANGE SPEED /////////////
int count = 0;          // count of steps made
int countsperrev = 250; // number of steps per full revolution ////////////////////////////////////////////////////////CHANGE THE ANGLE ////////
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

//////////////////////////////////////////////////////////////////////////////
void setup() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor2Pin3, OUTPUT);
  pinMode(motor2Pin4, OUTPUT);
  Serial.begin(9600);
}

//////////////////////////////////////////////////////////////////////////////
void loop(){
  if(count < countsperrev ){
    clockwise();
    anticlockwise2();}
  else if (count == countsperrev * 2){
    count = 0;}
  else{
    anticlockwise();
    clockwise2();}
  count++;
}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)
void anticlockwise()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void clockwise()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void anticlockwise2()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput2(i);
    delayMicroseconds(motorSpeed);
  }
}

void clockwise2()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput2(i);
    delayMicroseconds(motorSpeed);
  }
}

void setOutput(int out)
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}

void setOutput2(int out)
{
  digitalWrite(motor2Pin1, bitRead(lookup[out], 0));
  digitalWrite(motor2Pin2, bitRead(lookup[out], 1));
  digitalWrite(motor2Pin3, bitRead(lookup[out], 2));
  digitalWrite(motor2Pin4, bitRead(lookup[out], 3));
}
