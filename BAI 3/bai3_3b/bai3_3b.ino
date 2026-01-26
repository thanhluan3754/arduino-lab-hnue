#include <Keypad.h>

const byte rows = 4;
const byte columns = 4;

int holdDelay = 700;
int n = 3;
int state = 0;
char key = 0;

char keys[rows][columns] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const byte rowsPins[rows] = {9, 8, 7, 6};
const byte columnsPins[columns] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowsPins, columnsPins, rows, columns);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char temp = keypad.getKey();

  if ((int)keypad.getState() == PRESSED) {
    if (temp != 0)
    key = temp;
  }

  if ((int)keypad.getState() == HOLD) {
    state++;
    state = constrain(state, 1, n - 1);
    delay(holdDelay);
  }

  if ((int)keypad.getState() == RELEASED) {
    key += state;
    state = 0;
    Serial.println(key);
  }

  delay(100);
}
