const byte touchA = 2;
const byte touchB = 3;

const byte segPins[7] = {4, 5, 6, 7, 8, 9, 10}; // a b c d e f g

byte so[10] = {
  B1111110, // 0
  B0110000, // 1
  B1101101, // 2
  B1111001, // 3
  B0110011, // 4
  B1011011, // 5
  B1011111, // 6
  B1110000, // 7
  B1111111, // 8
  B1111011  // 9
};

int count = 0;
int lastA = LOW;
int lastB = LOW;

void displayNumber(int n) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], bitRead(so[n], 6 - i));
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(touchA, INPUT);
  pinMode(touchB, INPUT);

  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }

  displayNumber(count);
}

void loop() {
  int stateA = digitalRead(touchA);
  int stateB = digitalRead(touchB);

  if (stateA == HIGH && lastA == LOW) {
    if (count < 9) count++;
    displayNumber(count);

    Serial.print("Da cham cam bien: A, tong so lan cham: ");
    Serial.print(count);
    Serial.println(" lan.");
  }

  if (stateB == HIGH && lastB == LOW) {
    if (count > 0) count--;
    displayNumber(count);

    Serial.print("Da cham cam bien: B, tong so lan cham: ");
    Serial.print(count);
    Serial.println(" lan.");
  }

  lastA = stateA;
  lastB = stateB;

  delay(50);
}
