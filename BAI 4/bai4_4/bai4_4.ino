/*
Nguyen Thanh Luan - K74A2 KT&CN;

Bai 4-4: Lap trinh dieu khien che do bat tat 7 LED (cac chan 2 den 8 tren Uno)
theo gia tri bien tro va hien thi che do hien thoi tren Serial Monitor.
- Gia tri bien tro < 30%
  + che do 1: Bat lan luot tu trai den phai (2 den 8)
- Gia tri bien tro > 70%
  + che do 2: Bat lan luot tu phai den trai (8 den 2)
- Gia tri bien tro 31% den 69%
  + che do 3: Bat lan luot tu led giua sang hai phia (5 den 8 va 5 den 2)

- Hien thi tren Serial Monitor cac thong tin sau:
  + Gia tri bien tro
  + Che do hien hanh
*/

const byte bien_tro = A0;
const byte LED[7] = {2, 3, 4, 5, 6, 7, 8};
void ct1();
void ct2();
void ct3();

void setup() {
  Serial.begin(9600);
  pinMode(bien_tro, INPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  int value = analogRead(bien_tro);
  int percent = 100.0*value / 1023;

  Serial.print("Gia tri bien tro: "); Serial.print(percent); Serial.println("%");

  if (percent < 30) {
    ct1();
    Serial.println("Che do 1");
  }
  else if (percent > 70) {
    ct2();
    Serial.println("Che do 2");
  }
  else {
    ct3();
    Serial.println("Che do 3");
  }

}

void ct1() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(LED[i], HIGH);
    delay(500);
  }

  delay(100);

  for (int i = 0; i < 7; i++) {
    digitalWrite(LED[i], LOW);
  }
}

void ct2() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(LED[6-i], HIGH);
    delay(500);
  }

  delay(100);

  for (int i = 0; i < 7; i++) {
    digitalWrite(LED[i], LOW);
  }
}

void ct3() {
  for(int i=0; i < 4; i++)
  {
    digitalWrite(LED[i+3], HIGH);
    digitalWrite(LED[3-i], HIGH);
    delay(500);
  }
  
  delay(100);
  
  for (int i = 0; i < 7; i++) {
    digitalWrite(LED[i], LOW);
  }
}
