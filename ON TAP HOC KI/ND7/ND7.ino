const byte LED[8] = {11, 10, 9, 8, 7, 6, 5, 4};
const byte blue = 13;
const byte red = 12;
const byte button = 2;
int lastVal = -1;

unsigned long lastTime = 0;
const unsigned long fixedVal = 220;
volatile int dem = 0;

const byte so[10] = {
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000111,
  B01111111,
  B01101111
};

void hien_thi(byte n) {
  for(int i = 0; i < 8; i++) {
    digitalWrite(LED[i], !((n >> i) & 1));
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);

  attachInterrupt(0, isr, FALLING);
}

  void isr() {
    if (millis() - lastTime > fixedVal) {
      dem++;
      lastTime = millis();
    }
  }

void loop() {
  int donvi = dem % 10;
  hien_thi(so[donvi]);

  if (dem & 1) {
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
  }

  static int lastdem = -1;
  if (dem != lastdem) {
    Serial.println("---------------");

    Serial.print("So lan nhan nut: ");
    Serial.println(dem);

    Serial.print("LED dang bat: ");
    if (dem & 1) {
      Serial.println("do");
    }
    else {
      Serial.println("xanh");
    }

    lastdem = dem;
  }
}
