/*
Nguyen Thanh Luan K74A2 - KT&CN

Bai 2-3: Lap trinh dieu khien module 4 led 7 doan IC 74HC595 hien thi cac noi dung sau:
+ Hien thi tu 0 - 9 tren tat ca cac chu so cua Led
+ Hien thi tang tu 0 - 9999 tre 0,2s
+ Hien thi giam tu 9999 - 0 tre 0,2s
+ Nhay ca 4 led trong 4 lan chu ky nhay 2s.

Cathode chung

Cach noi:
-------------------------------------------------------
| IC       | 74HC595	| LED KEM MODULE | Arduino      |
-------------------------------------------------------
| DS       | (pin 14)	| DATA           | D2           |
| SHCP     | (pin 11)	| CLOCK          | D3           |
| STCP     | (pin 12)	| LATCH          | D4           |
| MR + VCC | 10 + 16  | VCC            | 5V hoac 3.3V |
| OE + GND | 13 + 8   | GND            | GND          |
-------------------------------------------------------
*/

#include <ShiftRegister74HC595.h>

ShiftRegister74HC595<4> sr(2, 3, 4);

const int MAX_NUMBER = 9999;

uint8_t so[] = {
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
}

void loop() {
  hienThi0_9();
  delay(1000);

  demTang();
  delay(1000);

  demGiam();
  delay(1000);

  nhayLed();
  delay(1000);
}

void hienThi0_9() {
  for (int i = 0; i <= 9; i++) {
    uint8_t data[] = {so[i], so[i], so[i], so[i]};
    sr.setAll(data);
    delay(500);
  }
}

void demTang() {
  for (int i = 0; i <= MAX_NUMBER; i++) {
    hienThiSo(i);
    delay(200);
  }
}

void demGiam() {
  for (int i = MAX_NUMBER; i >= 0; i--) {
    hienThiSo(i);
    delay(200);
  }
}

void nhayLed() {
  for (int i = 0; i < 4; i++) {
    sr.setAllHigh();
    delay(1000);
    sr.setAllLow();
    delay(1000);
  }
}

void hienThiSo(int value) {
  uint8_t d[4];
  d[0] = so[value % 10];
  d[1] = so[(value / 10) % 10];
  d[2] = so[(value / 100) % 10];
  d[3] = so[(value / 1000) % 10];
  sr.setAll(d);
}