/*
Bài 6-2:
Lập trình sử dụng cảm biến HC-SR04 cảnh báo va chạm bằng tín hiệu màu led theo qui tắc:
+ Khoảng cách > 60 cm, an toàn, bật 1 led xanh (led vàng, đỏ tắt).
+ Khoảng cách từ 30 đến 60 cm, cảnh báo, bật 2 led vàng, tắt led xanh, đỏ.
+ Khoảng cách < 30 cm, nguy hiểm, bật 3 led đỏ, tắt led xanh, vàng.
Hiển thị ra Serial Monitor thông tin theo dạng:
- “Khoảng cách __ cm. trạng thái an toàn/cảnh báo / nguy hiểm” tương ứng với khoảng cách đo được 
*/

const byte LED[6] = {9, 8, 7, 6, 5, 4};
const byte TRIG = 10;
const byte ECHO = 11;
unsigned long thoi_gian;
float khoang_cach;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  for (int i = 0; i < 6; i++) {
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
  Serial.print("cm. ");

  delay(200);

  if (khoang_cach > 60) {
    muc_1();
    Serial.print("Trang thai: AN TOAN\n");
  }
  else if (khoang_cach < 30) {
    muc_3();
    Serial.print("Trang thai: NGUY HIEM\n");
  }
  else {
    muc_2();
    Serial.print("Trang thai: CANH BAO\n");
  }

}

void muc_1() {
  digitalWrite(LED[0], HIGH);
  digitalWrite(LED[1], LOW);
  digitalWrite(LED[2], LOW);
  digitalWrite(LED[3], LOW);
  digitalWrite(LED[4], LOW);
  digitalWrite(LED[5], LOW);
}

void muc_2() {
  digitalWrite(LED[0], LOW);
  digitalWrite(LED[1], HIGH);
  digitalWrite(LED[2], HIGH);
  digitalWrite(LED[3], LOW);
  digitalWrite(LED[4], LOW);
  digitalWrite(LED[4], LOW);
}

void muc_3() {
  digitalWrite(LED[0], LOW);
  digitalWrite(LED[1], LOW);
  digitalWrite(LED[2], LOW);
  digitalWrite(LED[3], HIGH);
  digitalWrite(LED[4], HIGH);
  digitalWrite(LED[5], HIGH);
}