/*
Nguyen Thanh Luan - 745114054

Bai 1-2: Lap trinh dieu khien 5 LED (chan 2 - 6 tren Uno) theo quy tac:
Bat tuan tu tu LED 1 den LED 5, khoang cach giua cac LED la 1s.
Giu cac LED sang trong 5s.
Tat tuan tu tu LED 5 den LED 1, khoang cach giua cac LED la 1s.
*/

const int led1[5] = {2, 3, 4, 5, 6};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(led1[i], OUTPUT);
    digitalWrite(led1[i], LOW);
  }
}
 
void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(led1[i], HIGH);
    delay(1000);
  }

  delay(5000);

  for (int i = 0; i < 5; i++) {
    digitalWrite(led1[4 - i], LOW);
    delay(1000);
  }
}