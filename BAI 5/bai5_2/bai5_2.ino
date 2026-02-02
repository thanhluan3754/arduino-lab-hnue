/*
Nguyen Thanh Luan - K74A2 KT&CN

Bài 5-2: Điều khiển số lượng LED sáng theo tín hiệu biến trở:
- Khoảng chia biến trở 10% 
- Biến trở >= 20% → LED1 sáng
- Mỗi 10% tăng thêm giá trị biến trở tăng thêm 1 LED.
*/

const byte bien_tro = A0;
const byte LED[8] = {2, 3, 4, 5, 6, 7, 8, 9};

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

  if (percent < 10) {
    percent = 10;
  }
  int so_led = percent / 10 - 1;
  if (so_led > 8)
    so_led = 8;

  Serial.print("Gia tri bien tro: "); Serial.print(value); Serial.print(" -> ");
  Serial.print(percent); Serial.println("%");
  Serial.print("So LED bat: "); Serial.println(so_led);

  for (int i = 0; i < so_led; i++) {
    digitalWrite(LED[i], HIGH);
  }
  for (int j = so_led; j < 8; j++) {
    digitalWrite(LED[j], LOW);
  }
  delay(200);
}
