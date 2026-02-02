const byte PIR = 2;
const byte RELAY = 3;

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
  delay(3000);
}

void loop() {
  int value = digitalRead(PIR);
  Serial.print("PIR: "); Serial.println(value);
  delay(500);

  if (value == 1) {
    digitalWrite(RELAY, LOW);
  }
  else {
    digitalWrite(RELAY, HIGH);
  }
}
