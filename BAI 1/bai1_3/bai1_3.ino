/*
Nguyen Thanh Luan - K74A2 KT&CN

Bai 1-3: Lap trinh dieu khien 5 LED (chan 2 - 6 tren Uno) theo quy tac:
Duy nhat mot LED sang, chay tu LED 1 den LED 5 voi thoi gian tre 1s.
Duy nhat mot LED sang chay tu LED 5 den LED 1 voi thoi gian tre 0,5s.
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
    digitalWrite(led1[i], LOW);
  }

  for (int i = 0; i < 5; i++) {
    digitalWrite(led1[4-i], HIGH);
    delay(500);
    digitalWrite(led1[4-i], LOW);
  }
}