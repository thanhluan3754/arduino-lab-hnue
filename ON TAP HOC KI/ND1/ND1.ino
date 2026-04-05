const byte LED[8] = {13, 12, 11, 10, 9, 8, 7, 6};
const byte bientro = A2;
int lastVal = -1;

void off() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  int value = analogRead(bientro);
  int percent = map(value, 0, 1023, 0, 100);

  if (abs(percent - lastVal) >= 2) {
    Serial.println("-------------------");

    Serial.print("Gia tri tho: ");
    Serial.println(value);

    Serial.print("Gia tri phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    lastVal = percent;
  }

  off();
  delay(200);

  if (percent <= 25) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(LED[i], HIGH);
      delay(100);
    }
  }
  else if (percent > 25 && percent <= 50) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(LED[7-i], HIGH);
      delay(100);
    }
  }
  else if (percent > 50 && percent <= 75) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(LED[4+i], HIGH);
      digitalWrite(LED[3-i], HIGH);
      delay(200);
    }
  }
  else {
    for (int i = 0; i < 4; i++) {
      digitalWrite(LED[7-i], HIGH);
      digitalWrite(LED[i], HIGH);
      delay(200);
    }
  }
}
