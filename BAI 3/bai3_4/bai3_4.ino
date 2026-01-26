#include <Keypad.h>

const byte LED[5] = {2, 3, 4, 5, 6};
const byte rows = 4;
const byte cols = 3;

char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

const byte rowsP[rows] = {13, 12, 11, 10};
const byte colsP[cols] = {9, 8, 7};

Keypad keypad = Keypad(makeKeymap(keys), rowsP, colsP, rows, cols);

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Kí tự vừa nhập: ");
    Serial.println(key);
  }

  if (key == '1') {
    digitalWrite(LED[0], HIGH);
  }
  else if (key == '2') {
    digitalWrite(LED[0], LOW);
  }
  else if (key == '3') {
    digitalWrite(LED[1], HIGH);
  }
  else if (key == '4') {
    digitalWrite(LED[1], LOW);
  }
  else if (key == '5') {
    digitalWrite(LED[2], HIGH);
  }
  else if (key == '6') {
    digitalWrite(LED[2], LOW);
  }
  else if (key == '7') {
    digitalWrite(LED[3], HIGH);
  }
  else if (key == '8') {
    digitalWrite(LED[3], LOW);
  }
  else if (key == '9') {
    digitalWrite(LED[4], HIGH);
  }
  else if (key == '0') {
    digitalWrite(LED[4], LOW);
  }

}
