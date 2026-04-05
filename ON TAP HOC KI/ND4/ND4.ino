const byte LED[8] = {11, 10, 9, 8, 7, 6, 5, 4};
const byte bientro = A4;
int lastVal = -1;

const byte so[10] = {
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000111,
  B01111111,
  B01101111
};

void hien_thi(byte n) {
  for(int i = 0; i < 8; i++) {
    digitalWrite(LED[i], !((n >> i) & 1));
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  int value = analogRead(bientro);
  int percent = map(value, 0, 1023, 0, 100);
  int number = percent / 10;
  if (number > 9) number = 9;

  hien_thi(so[number]);

  if (abs(percent - lastVal) >= 2) {
    Serial.println("------------------");

    Serial.print("Gia tri tho: ");
    Serial.println(value);

    Serial.print("Gia tri phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    Serial.print("Chu so hien thi tren LED 7 doan: ");
    Serial.println(number);

    lastVal = percent;
  }
}
