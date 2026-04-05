#include <Keypad.h>
const byte blue = 10;
const byte red = 11;
const byte rows = 4;
const byte cols = 4;
const byte rowsP[rows] = {9, 8, 7, 6};
const byte colsP[cols] = {5, 4, 3, 2};

String password = "1234";
String input = "";
String output = "";

char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowsP, colsP, rows, cols);

void setup() {
  Serial.begin(9600);
  keypad.setDebounceTime(50);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);

  Serial.println("-----------------------");
  Serial.print("Nhap mat khau: ");
}

void loop() {
  char type = keypad.getKey();

  if (type) {
    if (type == '#') {
      Serial.print("\n");
      if (input == password) {
        digitalWrite(blue, HIGH);
        digitalWrite(red, LOW);
        Serial.println("Mat khau da nhap: dung");
        Serial.println("LED duoc bat: xanh");
      }
      else {
        digitalWrite(blue, LOW);
        digitalWrite(red, HIGH);
        Serial.println("Mat khau da nhap: sai");
        Serial.println("LED duoc bat: do");
      }
      input = "";
      output = "";
      delay(2000);
      Serial.println("-----------------------");
      Serial.print("Nhap mat khau moi: ");
    }

    else {
      input += type;
      output += 'x';

      Serial.print('x');
    }
  }
}
