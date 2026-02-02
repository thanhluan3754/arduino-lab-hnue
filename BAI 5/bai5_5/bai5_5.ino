const byte seg[8] = {3, 4, 5, 6, 7, 8, 9, 10};
const byte dig[2] = {11, 12};
const byte button = 2;
byte num = 1;
volatile int dem = 0;

unsigned long last = 0;

const byte so[10] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111  // 9
};


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(seg[i], OUTPUT);
    digitalWrite(seg[i], LOW);
  }

  for (int i = 0; i < 2; i++) {
    pinMode(dig[i], OUTPUT);
    digitalWrite(dig[i], HIGH);
  }

  pinMode(button, INPUT_PULLUP);

  attachInterrupt(0, isr, FALLING);
}

void isr() {
  if (millis() - last > 200) {
    dem++;
    if (dem == 99) {
      dem = 0;
    }
    last = millis();
  }
}

void loop() {
  static int last_count = -1;
  if (dem != last_count) {
    last_count = dem;
  }
  hien_thi(dem);
}

void hien_thi(int n) {
  int d[2];
  d[0] = (n / 10) % 10;
  d[1] = n % 10;

  for (int i = 0; i < 2; i++) {

    digitalWrite(dig[0], HIGH);
    digitalWrite(dig[1], HIGH);

    byte x = so[d[i]];
    for (int k = 0; k < 8; k++) {
      digitalWrite(seg[k], bitRead(x, k));
    }

    digitalWrite(dig[i], LOW);

    delayMicroseconds(1000);
  }
}

