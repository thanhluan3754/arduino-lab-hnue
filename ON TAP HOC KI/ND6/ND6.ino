const byte LED[8] = {11, 10, 9, 8, 7, 6, 5, 4};
const byte bientro = A1;
int lastVal = -1;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  int value = analogRead(bientro);
  int percent = map(value, 0, 1023, 0, 100);
  int numLED = percent / 10;
  if (numLED > 8) numLED = 8;

  if (abs(percent - lastVal) >= 2) {
    Serial.println("-------------------");

    Serial.print("Gia tri tho: ");
    Serial.println(value);

    Serial.print("Gia tri phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    Serial.print("So luong LED bat: ");
    Serial.println(numLED);

    lastVal = percent;
  }

  for (int i = 0; i < numLED; i++) {
    digitalWrite(LED[i], HIGH);
  }
  for (int i = numLED; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }
}