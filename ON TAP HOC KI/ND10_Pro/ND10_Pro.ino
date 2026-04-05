const byte touch = 2;
const byte LED[3] = {7, 6, 5};
volatile int dem = 0;
unsigned long lastTime = 0;
unsigned long fixedTime = 50;
const char* color;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
  attachInterrupt(0, isr, FALLING);
}

void isr() {
  if (millis() - lastTime > fixedTime) {
    dem++;
    lastTime = millis();
  }
}

void loop() {
  int R = dem % 3;
  if (R == 0) {
    digitalWrite(LED[0], HIGH);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], LOW);
    color = "xanh";
  }
  else if (R == 1) {
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], HIGH);
    digitalWrite(LED[2], LOW);
    color = "vang";
  }
  else {
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], HIGH);
    color = "do";
  }

  static int lastVal = -1;
  if (dem != lastVal) {
    Serial.print("So du: ");
    Serial.println(R);
    Serial.print("So lan cham: ");
    Serial.println(dem);
    Serial.print("LED duoc bat: ");
    Serial.println(color);
    lastVal = dem;
  } 
}