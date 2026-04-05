#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
Servo s;
int angle = 0;

#define SS_PIN 10
#define RST_PIN 8

MFRC522 mfrc522(SS_PIN, RST_PIN);

String MasterCard = "C0-FF-EE-99";

void setup() {
  Serial.begin(9600);
  s.attach(9);
  s.write(angle);
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
    angle = 90;
  }
  else {
    angle = 0;
  }
  s.write(angle);

  Serial.println("--------------");
  Serial.print("Ma the vua doc: ");
  Serial.println(uid);
  Serial.print("Goc quay: ");
  Serial.print(angle);
  Serial.println(" do");

  mfrc522.PICC_HaltA();
  delay(2000);
  s.write(0);
}