#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

String MasterCard = "C0-FF-EE-99";
const char* state;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan RFID...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;

  if (!mfrc522.PICC_ReadCardSerial()) return;

  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uid += 0;
    uid += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) uid += "-";
  }
  uid.toUpperCase();

  if (uid == MasterCard) {
    state = "Dung";
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else {
    state = "Sai";
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }

  Serial.println("--------------");
  Serial.print("Ma the vua doc: ");
  Serial.println(uid);
  Serial.print("The chu: ");
  Serial.println(state);

  mfrc522.PICC_HaltA();
  delay(1000);
}