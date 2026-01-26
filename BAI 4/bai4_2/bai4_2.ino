/*
Nguyen Thanh Luan - K74A2 KT&CN;

Bai 4-2:
Lap mach va lap trinh dieu khien do sang cua den led
theo gia tri doc tu bien tro bang phuong phap bam xung PWM.
Hien thi tren Serial Monitor cac thong tin sau:
- Gia tri tho (doc duoc tu chan noi bien tro)
- Gia tri da xu ly (phan tram)
- Gia tri dien ap dau ra tren chan dieu khien LED (tinh theo V)
*/

const byte bien_tro = A0;
const byte LED = 3;

void setup() {
  Serial.begin(9600);
  pinMode(bien_tro, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int value = analogRead(bien_tro);
  int pwm = map(value, 0, 1023, 0, 255);
  int percent = 100.0*value / 1023;
  int volt = 5.0*value / 1023;
  analogWrite(LED, pwm);

  Serial.print("Gia tri tho: "); Serial.println(value);
  Serial.print("Gia tri da xu ly: "); Serial.print(percent); Serial.println("%");
  Serial.print("Gia tri dien ap dau ra tren chan dieu khien LED: "); Serial.print(volt); Serial.println("V");

  delay(300);
}
