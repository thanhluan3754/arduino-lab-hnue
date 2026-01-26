/*
Nguyen Thanh Luan - K74A2 KT&CN

Bài 5-3: Điều khiển LED trang trí theo tín hiệu nút ấn
- Nhấn 1 lần: LED trang trí sáng từ LED1 → LED8
- Nhấn 2 lần: LED trang trí sáng từ LED8 → LED1
- Nhấn 3 lần: Hoạt động như nhấn 1 lần
- Nhấn 4 lần: Hoạt động như nhấn 2 lần
*/

const byte button = 2;
const byte LED[8] = {3, 4, 5, 6, 7, 8, 9, 10};
unsigned long last = 0;
unsigned long D = 200;
volatile int dem = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }

  attachInterrupt(0, isr, FALLING);
}

void isr() {
  unsigned long now = millis();
  if (now - last > D) {
    dem++;
    last = now;
  }
}

void loop() {
  static int last_cnt = - 1;
  if (dem != last_cnt) {
    Serial.print("So lan: "); Serial.println(dem);
    last_cnt = dem;
  }

  if (dem % 2 != 0)
    ct1();
  else
    ct2();
}

void ct1() {
  for (int j = 0; j < 8; j++) {
    digitalWrite(LED[j], HIGH);
    delay(200);
  }

  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }
}

void ct2() {
  for (int j = 0; j < 8; j++) {
    digitalWrite(LED[7-j], HIGH);
    delay(200);
  }

  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }
}
