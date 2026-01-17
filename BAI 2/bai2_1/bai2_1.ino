/*
Nguyen Thanh Luan - K74A2 KT&CN

Bai 2-1: Lap trinh dieu khien led 7 doan trong cac truong hop sau:
+ Hien thi lan luot cac so tu 0 den 9, khoang tre giua cac so la 2s.
+ Hien thi cac so tu 0 – 9 va nguoc lai tu 9 – 0, khoang tre 2s.
+ Hien thi cac so chan: 0, 2, 4, 6, 8 va cac so le 1, 3, 5, 7.

Cathode Chung
*/

const int LED[8] = {2, 3, 4, 5, 6, 7, 8, 9};

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

void Hien_thi(byte n) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], bitRead(n, i));
  }
}

void setup() {
  for (int i = 0; i < 8;i++ ) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    Hien_thi(so[i]);
    delay(2000); 
  }

  for (int i = 0; i < 10; i++) {
    Hien_thi(so[i]);
    delay(1000); 
  }
  delay(2000);
  for (int i = 0; i < 10; i++) {
    Hien_thi(so[9-i]);
    delay(1000); 
  }
  delay(2000);

  for (int i = 0; i < 10; i+=2) {
    Hien_thi(so[i]);
    delay(1000); 
  }
  for (int i = 1; i < 10; i+=2) {
    Hien_thi(so[i]);
    delay(1000); 
  }
}