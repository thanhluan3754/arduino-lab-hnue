/*
Bài 7.3:
Giao tiếp Serial giữa 2 board Arduino

MASTER

*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("on\n");
  delay(1000);
  Serial.print("off\n");
  delay(1000);
}
