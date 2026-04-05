const byte LED[8] = {11, 10, 9, 8, 7, 6, 5, 4};

const byte trigPin = 2;
const byte echoPin = 3;

int lastDistance = -1;

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
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], !((n >> i) & 1));
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int kc = getDistance();

  int hangChuc = kc / 10;
  if (hangChuc > 9) hangChuc = 9;
  if (hangChuc < 0) hangChuc = 0;

  hien_thi(so[hangChuc]);

  if (kc != lastDistance) {
    Serial.println("------------------");

    Serial.print("Khoang cach: ");
    Serial.print(kc);
    Serial.println(" cm");

    Serial.print("Chu so hien thi: ");
    Serial.println(hangChuc);

    lastDistance = kc;
  }

  delay(100);
}