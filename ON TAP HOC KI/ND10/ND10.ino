const byte touch = 2;
const byte LED[3] = {7, 6, 5};
int dem = 0;

void setup() {
  Serial.begin(9600);
  pinMode(touch, INPUT_PULLUP);
  for (int i = 0; i < 3; i++) pinMode(LED[i], OUTPUT);
}

void loop() {
  static int lastDem = -1;

  // Kiểm tra nút nhấn
  if (digitalRead(touch) == LOW) {
    dem++;
    delay(200); // debounce đơn giản
  }

  // Tính LED hiện tại
  int R = dem % 3;

  // Bật LED tương ứng, tắt các LED khác
  for (int i = 0; i < 3; i++) digitalWrite(LED[i], i == R ? HIGH : LOW);

  // In ra Serial khi có thay đổi
  if (dem != lastDem) {
    Serial.print("So lan cham: ");
    Serial.println(dem);

    Serial.print("LED duoc bat: ");
    if (R == 0) Serial.println("xanh");
    else if (R == 1) Serial.println("vang");
    else Serial.println("do");

    lastDem = dem;
  }
}