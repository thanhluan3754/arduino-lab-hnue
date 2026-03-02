/*
Bài 7.2:
Gửi dữ liệu từ máy tính đến board Arduino Uno qua Serial Monitor
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
      Serial.print("Send to Arduino: ");
      Serial.println(data);

      if (data == "on") {
        digitalWrite(LED, HIGH);
      }
      if (data == "off") {
        digitalWrite(LED, LOW);
      }
      
      data = "";
    } else {
      data = data + c;
    }
  }
}