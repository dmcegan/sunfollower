#include <Servo.h>

Servo servoHorizontal;
Servo servoVertical;

int ldrLeft = A0;
int ldrRight = A1;
int ldrFront = A2;
int ldrBack = A3;

int angleH = 90;
int angleV = 90;

void setup() {
  servoHorizontal.attach(9);
  servoVertical.attach(10);
  servoHorizontal.write(angleH);
  servoVertical.write(angleV);
  delay(500);
}

void loop() {
  int left = analogRead(ldrLeft);
  int right = analogRead(ldrRight);
  int front = analogRead(ldrFront);
  int back = analogRead(ldrBack);

  if (left - right > 20) angleH++;
  else if (right - left > 20) angleH--;

  if (front - back > 20) angleV--;
  else if (back - front > 20) angleV++;

  servoHorizontal.write(angleH);
  servoVertical.write(angleV);

  delay(100);
}
