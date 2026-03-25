// Slave
#include <Wire.h>
#define pinLed 13
void setup() {
  Wire.begin(3);
  Wire.onReceive(receiveEvent);
    pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);
}

void loop() {
  // NULL
}

void receiveEvent() {
  while (Wire.available()) {
    char c = Wire.read();
    if (c == 'H')
        digitalWrite(pinLed, HIGH);
    else if (c == 'L')
      digitalWrite(pinLed, LOW);
  }
}