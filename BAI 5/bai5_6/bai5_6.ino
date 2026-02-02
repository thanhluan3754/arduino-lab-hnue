const byte seg[8] = {3, 4, 5, 6, 7, 8, 9, 10};
const byte dig[2] = {11, 12};
const byte button = 2;

byte num = 0;
byte state = 0;

unsigned long lastCount = 0;
unsigned long lastPress = 0;
volatile bool btn_state = false;

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

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(seg[i], OUTPUT);
    digitalWrite(seg[i], LOW);
  }

  for (int i = 0; i < 2; i++) {
    pinMode(dig[i], OUTPUT);
    digitalWrite(dig[i], HIGH);
  }

  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), isr, FALLING);
}

void isr() {
  btn_state = true;
}

void loop() {

  if (btn_state) {
    btn_state = false;

    if (millis() - lastPress > 200) {
      lastPress = millis();

      if (state == 0) {
        state = 1;
        num = 0;
      }
      else if (state == 1) {
        state = 2;
        num = 99;
      }
      else {
        state = 1;
        num = 0;
      }
    }
  }

  if (state != 0 && millis() - lastCount > 200) {
    lastCount = millis();

    if (state == 1) {
      num = (num + 1) % 100;
    }
    else if (state == 2) {
      num = (num + 99) % 100;
    }
  }

  hien_thi(num);
}

void hien_thi(byte n) {
  byte d[2];
  d[0] = n / 10;
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
