const byte LED[3] = {7, 6, 5};
const byte TRIG = 9;
const byte ECHO = 8;
const byte BUZZER = 10;

unsigned long thoigian;
unsigned long khoangcach;

int lastDistance = -1;
bool rev = LOW;
unsigned long lastTime = 0;

const char* state;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  for (int i = 0; i < 3; i++) {
    pinMode(LED[i], OUTPUT);
  }

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  thoigian = pulseIn(ECHO, HIGH);
  khoangcach = thoigian * 0.034 / 2;

  if (khoangcach > 90) {
    digitalWrite(LED[0], HIGH);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], LOW);
    digitalWrite(BUZZER, LOW);
    state = "An toan";
  }
  else if (khoangcach > 50) {
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], HIGH);
    digitalWrite(LED[2], LOW);
    digitalWrite(BUZZER, LOW);
    state = "Canh bao";
  }
  else if (khoangcach > 30) {
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], HIGH);
    digitalWrite(BUZZER, LOW);
    state = "Nguy hiem";
  }
  else {
    state = "Va cham";
    unsigned long currentTime = millis();
    if (currentTime - lastTime >= 500) {
      rev = !rev;
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED[i], rev);
      }
      digitalWrite(BUZZER, rev);
      lastTime = currentTime;
    }
  }

  if (abs(khoangcach - lastDistance) >= 3) {
    Serial.println("-------------------");
    Serial.print("Khoang cach: ");
    Serial.print(khoangcach);
    Serial.println("cm");

    Serial.print("Tinh trang: ");
    Serial.println(state);
    lastDistance = khoangcach;
  }

  delay(100);
}
