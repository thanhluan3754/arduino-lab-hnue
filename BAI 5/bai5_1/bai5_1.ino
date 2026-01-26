/*
Nguyen Thanh Luan - K74A2 KT&CN

Bài 5-1: Điều khiển LED trang trí theo tín hiệu của biến trở:
- Biến trở nhỏ hơn 25%: sáng từ LED1 → LED 8, lặp lại 3 lần.
- Biến trở lớn hơn 75%: sáng từ LED8 → LED1, lặp lại 3 lần.
- Biến trở trong khoảng 25% đến 75%: sáng từ 2 phía (LED1 →LED4 và LED8 → LED5).
*/

const byte bien_tro = A0;
const byte LED[8] = {2, 3, 4, 5, 6, 7, 8, 9};
void ct1();
void ct2();
void ct3();

void setup() {
  Serial.begin(9600);
  pinMode(bien_tro, INPUT);
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  int value = analogRead(bien_tro);
  int percent = 100.0*value / 1023;

  Serial.print("Gia tri bien tro: "); Serial.print(percent); Serial.println("%");

  if (percent < 25) {
    ct1();
  }
  else if (percent > 75) {
    ct2();
  }
  else {
    ct3();
  }

}

void ct1() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(LED[j], HIGH);
      delay(200);
    }
    for (int i = 0; i < 8; i++) {
      digitalWrite(LED[i], LOW);
    }
  }

  delay(300);

  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }

  delay(300);
}

void ct2() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(LED[7-j], HIGH);
      delay(200);
    }
    for (int i = 0; i < 8; i++) {
      digitalWrite(LED[i], LOW);
    }
  }

  delay(300);

  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }

  delay(300);
}

void ct3() {
  for(int i=0; i < 4; i++)
  {
    digitalWrite(LED[i], HIGH);
    digitalWrite(LED[7-i], HIGH);
    delay(300);
  }
  
  delay(100);
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }
}
