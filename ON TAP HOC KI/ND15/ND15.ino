#include <Servo.h>
const byte D[2] = {10, 11};

Servo myServo;
int angle = 0;
int pot = A0;

int lastVal = -1;
int lastAngle = -1;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  for (int i = 0; i < 2; i++) {
    pinMode(D[i], OUTPUT);
  }
  myServo.write(angle);
}

void loop() {
  int value = analogRead(pot);
  int percent = map(value, 0, 1023, 0, 100);

  if (percent < 50) {
    angle = map(percent, 0, 49, 0, 90);
    digitalWrite(D[0], HIGH);
    digitalWrite(D[1], LOW);
  }
  else {
    angle = map(percent, 50, 100, 180, 90);
    digitalWrite(D[0], LOW);
    digitalWrite(D[1], HIGH);
  }

  if (abs(angle - lastAngle) >= 1) {
    myServo.write(angle);
    lastAngle = angle;
  }

  if (abs(percent - lastVal) >= 2) {
    Serial.println("------------------");

    Serial.print("Gia tri tho: ");
    Serial.println(value);

    Serial.print("Gia tri phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    Serial.print("Goc quay servo: ");
    Serial.print(angle);
    Serial.println("do");

    lastVal = percent;
  }
}