const byte LED[8] = {9, 8, 7, 6, 5, 4, 3, 2};
const byte TRIG = 10;
const byte ECHO = 11;

unsigned long thoigian;
unsigned long khoangcach;

int lastDistance = -1;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  thoigian = pulseIn(ECHO, HIGH);
  khoangcach = thoigian * 0.034 / 2;

  int numLED = khoangcach / 10;
  if (khoangcach > 80) numLED = 8;

  for (int i = 0; i < numLED; i++) {
    digitalWrite(LED[i], HIGH);
  }
  for (int i = numLED; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }

  if (abs(khoangcach - lastDistance) >= 5) {
    Serial.println("-------------------");
    Serial.print("Khoang cach: ");
    Serial.print(khoangcach);
    Serial.println("cm");

    Serial.print("So LED bat: ");
    Serial.println(numLED);
  }

  delay(200);
}
