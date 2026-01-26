/*
Nguyen Thanh Luan - K74A2 KT&CN

Bai 3.1:
Lap trinh doc trang thai nut an va dieu khien led theo qui tac:
  - Khi nhan nut -> led bat
  - Thoi nhan nut -> led tat.
Hien thi tren Serial Monitor thong tin o dang sau:
  - Trang thai nut an: (1 - nhan, 0 - khong nhan).
  - Trang thai led: (bat / tat)
*/
const byte button = 2;
const byte LED = 13;
volatile bool led_state = false;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(button), nut_nhan, CHANGE);
}

void nut_nhan() {
  led_state = !digitalRead(button);
}

void loop() {
  digitalWrite(LED, led_state);

  Serial.print("Trang thai nut nhan: ");
  Serial.println(led_state);

  Serial.print("Trang thai led: ");
  if (led_state == 1) {
    Serial.println("bat");
  } else {
    Serial.println("tat");
  }

  delay(500);
}
