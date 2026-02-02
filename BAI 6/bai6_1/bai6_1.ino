/*
Bài 6-1: Lập trình sử dụng cảm biến HC-SR04 đo khoảng cách đến vật cản
và điều khiển mảng 8 led theo chương trình:
- Khoảng cách < 30 cm: Chương trình 1: Bật led chạy từ led1 → led8.
- Khoảng cách > 80 cm: Chương trình 2: Bật led chạy từ led8 → led 1.
- Khoảng cách từ 30 đến 80cm: Chương trình 3: Bật/ tắt 8 led với chu kỳ 1s.
Hiển thị ra Serial Monitor thông tin theo dạng sau:
- “Khoảng cách __ cm −> Chương trình __” tương ứng với khoảng cách đo được.
*/

const byte LED[8] = {9, 8, 7, 6, 5, 4, 3, 2};
const byte TRIG = 10;
const byte ECHO = 11;
unsigned long thoi_gian;
float khoang_cach;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  thoi_gian = pulseIn(ECHO, HIGH);
  khoang_cach = 0.034 * thoi_gian  / 2;

  Serial.print("Khoang cach: ");
  Serial.print(khoang_cach);
  Serial.print("cm");

  delay(200);

  if (khoang_cach < 30) {
    ct1();
    Serial.print(" -> Chuong trinh: 1\n");
  }
  else if (khoang_cach > 80) {
    ct2();
    Serial.print(" -> Chuong trinh: 2\n");
  }
  else {
    ct3();
    Serial.print(" -> Chuong trinh: 3\n");
  }
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

void ct3() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], HIGH);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], LOW);
  }
}
