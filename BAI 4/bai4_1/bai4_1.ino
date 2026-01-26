/*
Nguyen Thanh Luan - K74A2 KT&CN;

Bai 4-1:
Lap mach va lap trinh doc gia tri dien ap tren bien tro
xuat ra Serial monitor o cac dang sau:
- Gia tri tho (doc duoc tu chan analog)
- Gia tri dien ap (V)
- Gia tri bien tro o dang phan tram (%)
*/

const byte bien_tro = A0;

void setup() {
  Serial.begin(9600);
  pinMode(bien_tro, INPUT);
}

void loop() {
  int value = analogRead(bien_tro);
  int volt = 5.0*value / 1023;
  int percent = 100.0*value / 1023;
  Serial.print("Gia tri tho: "); Serial.println(value);
  Serial.print("Gia tri dien ap: "); Serial.print(volt); Serial.println(" V");
  Serial.print("Gia tri phan tram: "); Serial.print(percent); Serial.println(" %");
  delay(200);
}
