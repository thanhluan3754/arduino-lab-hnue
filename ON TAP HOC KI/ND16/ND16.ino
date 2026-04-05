#include <Servo.h>

Servo myServo;

const int trigPin = 5;
const int echoPin = 6;

const int ledGreen = 10;
const int ledRed = 11;

long duration;
int distance;

int lastDistance = -1;

unsigned long previousMillis = 0;
bool ledState = false;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  distance = getDistance();

  int angle = 0;
  String ledStatus = "";

  if (distance >= 20 && distance <= 50) {
    angle = 60;
    myServo.write(angle);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    ledStatus = "xanh";
  } 
  else if (distance >= 60 && distance <= 90) {
    angle = 120;
    myServo.write(angle);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    ledStatus = "do";
  } 
  else {
    angle = 0;
    myServo.write(angle);

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 250) {
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(ledGreen, ledState);
      digitalWrite(ledRed, ledState);
    }
    ledStatus = "nhay";
  }

  if (distance != lastDistance) {
    Serial.print("Khoang cach do duoc: ");
    Serial.print(distance);
    Serial.println(" cm");

    Serial.print("Goc quay servo: ");
    Serial.print(angle);
    Serial.println(" do");

    Serial.print("Led bao hieu: ");
    Serial.println(ledStatus);
    Serial.println();

    lastDistance = distance;
  }

  delay(100);
}