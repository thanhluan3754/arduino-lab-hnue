#include <Keypad.h>

const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const byte rowsP[rows] = {13, 12, 11, 10};
const byte colsP[cols] = {9, 8, 7, 6};
const byte XANH = 4;
const byte DO = 5;

Keypad keypad = Keypad(makeKeymap(keys), rowsP, colsP, rows, cols);

const char mat_khau[4] = {'2', '0', '0', '6'};
char nhap_mat_khau[5] = {'\0', '\0', '\0', '\0', '\0'};
uint8_t i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(XANH, OUTPUT);
  digitalWrite(XANH, LOW);
  pinMode(DO, OUTPUT);
  digitalWrite(DO, LOW);

  keypad.setDebounceTime(100);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print(key); Serial.print(" ");
    nhap_mat_khau[i++] = key;
  }

  if (i == 4) {
    Serial.print("\n");

    if (!strncmp(nhap_mat_khau, mat_khau, 4)) {
      Serial.println("Mat khau dung");
      digitalWrite(XANH, HIGH);
      digitalWrite(DO, LOW);
    }
    else {
      Serial.println("Mat khau sai");
      digitalWrite(DO, HIGH);
      digitalWrite(XANH, LOW);
    }

    i = 0;
  }
}
