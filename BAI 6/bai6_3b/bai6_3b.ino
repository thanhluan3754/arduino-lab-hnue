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
  khoang_cach = thoi_gian * 0.034 / 2;

  if (khoang_cach < 20)
    khoang_cach = 20;

  int so_led = (khoang_cach - 20) / 10 + 1;

  if (so_led > 8) so_led = 8;

  for (int i = 0; i < so_led; i++)
    digitalWrite(LED[i], HIGH);

  for (int i = so_led; i < 8; i++)
    digitalWrite(LED[i], LOW);

  Serial.print("Khoang cach ");
  Serial.print(khoang_cach);
  Serial.print(" cm. So led bat ");
  Serial.println(so_led);

  delay(200);
}
