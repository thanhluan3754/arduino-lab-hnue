const byte button = 2;
const byte LED = 13;
volatile int dem = 0;
unsigned long last = 0;
const unsigned long D = 200;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  attachInterrupt(digitalPinToInterrupt(button), cnt, FALLING);
}

void cnt() {
  if (millis() - last > D) {
    dem++;
    last = millis();
  }
}

void loop() {
  static int last_count = - 1;
  if (dem != last_count) {
    Serial.print("So lan: ");
    Serial.println(dem);
    last_count = dem;
  }

  if (dem % 2 != 0) {
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED, HIGH);
  }
}
