#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan RFID...");
}

void loop() {
  // Không có thẻ
  if (!mfrc522.PICC_IsNewCardPresent()) return;

  // Không đọc được UID
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // In UID
  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uid += 0;
    uid += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) uid += "-";
  }
  uid.toUpperCase();
  Serial.print("UID: ");
  Serial.println(uid);

  mfrc522.PICC_HaltA(); // dừng đọc
}