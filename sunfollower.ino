#include <Servo.h>

// Define servos
Servo servoHorizontal;
Servo servoVertical;

// Define photoresistor pins
int ldrLeft = A0;
int ldrRight = A1;
int ldrFront = A2;
int ldrBack = A3;

// Initial servo positions
int angleH = 90;
int angleV = 90;

void setup() {
  servoHorizontal.attach(9);  // Horizontal rotation
  servoVertical.attach(10);   // Vertical tilt
  servoHorizontal.write(angleH);
  servoVertical.write(angleV);
  delay(500);
}

void loop() {
  // Read LDR values
  int left = analogRead(ldrLeft);
  int right = analogRead(ldrRight);
  int front = analogRead(ldrFront);
  int back = analogRead(ldrBack);

  // Compare sides to detect brightest direction

  // Horizontal adjustment
  if (left > right) angleH++;
  else if (right > left) angleH--;

  // Vertical adjustment
  if (front >back) angleV--;
  else if (back > front) angleV++;

  // Move servos
  servoHorizontal.write(angleH);
  servoVertical.write(angleV);

  delay(100);
}
