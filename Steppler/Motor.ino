void mpower(int motor, int rotation, int spd) {
  int pwm;
  int pA;
  int pB;
  if (motor == 1) {
    pwm = enA;
    pA = in1;
    pB = in2;
  } else if (motor == 2) {
    pwm = enB;
    pA = in3;
    pB = in4;
  } else {
    return;
  }

  if (rotation == 0) {
    digitalWrite(pA, LOW);
    digitalWrite(pB, LOW);
  } else if (rotation == 1) {
    digitalWrite(pA, HIGH);
    digitalWrite(pB, LOW);
  } else if (rotation == -1) {
    digitalWrite(pA, LOW);
    digitalWrite(pB, HIGH);
  }
  analogWrite(pwm, spd);

}
