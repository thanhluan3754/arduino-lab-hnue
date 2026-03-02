/*
Bài 7.1:
Đọc giá trị biến trở mắc trên Arduino Uno và hiển thị kết quả trên máy tính
*/

int bt_pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int bt_giatri_tho = analogRead(bt_pin); 
  
  int bt_giatri_mV = map(bt_giatri_tho, 0, 1023, 0, 5000);
  int bt_giatri_phantram = map(bt_giatri_tho, 0, 1023, 0, 100);

  Serial.print("Doc gia tri tuong tu: ");
  Serial.print(bt_giatri_tho);
  
  Serial.print(" | Dien ap thuc: ");
  Serial.print(bt_giatri_mV);
  Serial.print("mV");
  
  Serial.print(" | Dien ap phan tram: ");
  Serial.print(bt_giatri_phantram);
  Serial.println("%");

  delay(200);
}