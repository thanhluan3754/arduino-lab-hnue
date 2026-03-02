/*
Bài 7.3:
Giao tiếp Serial giữa 2 board Arduino

SLAVE

*/

const int LED = 13;
String data = "";

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    
    if (c == '\n') {
      if (data == "on") {
        digitalWrite(LED, HIGH);
      } else if (data == "off") {
        digitalWrite(LED, LOW);
      }
      data = "";
    } else {
      data = data + c;
    }
  }
}