/*
Nguyen Thanh Luan - 745114054

Bai 2-2: Lap trinh dieu khien mo dun 4 led 7 doan:
+ Hien thi cac so tu nhien tu 0 den 9999, do tre 0.3s.
+ Hien thi cac so chan tu 0 den 9998, do tre 0.3s.

Anode Chung Module 4 LED 7 Doan
Ma: "5461BS-1"
*/

const int seg[8] = {2, 3, 4, 5, 6, 7, 8, 9};   // a b c d e f g dp
const int dig[4] = {10, 11, 12, 13};          // D1 D2 D3 D4

unsigned long E = 0;
int num = 0;
int mode = 0;

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
  for (int i = 0; i < 8; i++) {
    pinMode(seg[i], OUTPUT);
    digitalWrite(seg[i], HIGH);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(dig[i], OUTPUT);
    digitalWrite(dig[i], LOW);
  }
}

void loop() {
  hien_thi(num);

  if (millis() - E > 300) {
    E = millis();

    if (mode == 0) {
      num++;
      if (num > 9999) {
        num = 0;
        mode = 1;
      }
    }
    else {
      num += 2;
      if (num > 9998) {
        num = 0;
        mode = 0;
      }
    }
  }
}

void hien_thi(int n) {
  int d[4];
  d[0] = n / 1000;
  d[1] = (n / 100) % 10;
  d[2] = (n / 10) % 10;
  d[3] = n % 10;

  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < 4; j++) {
      digitalWrite(dig[j], LOW);
    }

    byte x = so[d[i]];

    for (int k = 0; k < 8; k++) {
      digitalWrite(seg[k], !bitRead(x, k));
    }

    digitalWrite(dig[i], HIGH);
    delayMicroseconds(1000);
  }
}
