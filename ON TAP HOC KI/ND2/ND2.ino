const byte LED = 9;
const byte bientro = A3;
int lastVal = -1;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  int value = analogRead(bientro);
  int percent = map(value, 0, 1023, 0, 100);
  int pwm = map(percent, 0, 100, 255, 0);
  if (value > 1000) pwm = 0;
  int brightness = 5 - percent / 20;
  if (brightness < 1) brightness = 1;

  if (abs(percent - lastVal) >= 2) {
    Serial.println("-------------------");

    Serial.print("Gia tri tho: ");
    Serial.println(value);

    Serial.print("Gia tri phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    Serial.print("Do sang LED: ");
    Serial.println(brightness);

    lastVal = percent;
  }

  analogWrite(LED, pwm);
}

/*
o dong 16 17 khong lam dung ham map nhe
ham map chia tuyen tinh sau do tra ve so nguyen
do do bi lam tron lech vung
*/