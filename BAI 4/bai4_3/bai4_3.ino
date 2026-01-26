/*
Nguyen Thanh Luan - K74A2 KT&CN;

Bai 4-3: Viet chuong trinh dieu khien toc do nhay cua den led
bang gia tri bien tro, chu ky bat / tat led
tu 0,1s (tuong ung voi gia tri bien tro bang 1023)
den 1s (tuong ung voi gia tri bien tro bang 0).
Hien thi tren Serial Monitor thong tin sau:
- Gia tri bien tro o dang phan tram
- Che do bat / tat LED hien hanh
- Thoi gian mot chu ky (bang thoi gian bat + thoi gian tat)
*/

const byte bien_tro = A0;
const byte LED = 3;

void setup() {
  Serial.begin(9600);
  pinMode(bien_tro, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  int value = analogRead(bien_tro);
  int do_tre = map(value, 0, 1023, 1000, 100);
  int percent = 100.0*value / 1023;

  digitalWrite(LED, HIGH);
  delay(do_tre);
  digitalWrite(LED, LOW);
  delay(do_tre);

  Serial.print("Gia tri bien tro: "); Serial.print(percent); Serial.println("%");
  // Serial.print("Gia tri da xu ly: "); Serial.print(percent); Serial.println("%");
  Serial.print("Chu ki: "); Serial.print(do_tre*2); Serial.println("ms");

  delay(100);
}
