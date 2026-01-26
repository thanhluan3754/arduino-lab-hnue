#include <Keypad.h>

const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const byte rowsP[rows] = {9, 8, 7, 6};
const byte colsP[cols] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowsP, colsP, rows, cols);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Kí tự vừa nhập: ");
    Serial.println(key);
  }

}
