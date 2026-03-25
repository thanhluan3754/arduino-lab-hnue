#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("Quet the RFID...");
}

void loop() {
  // chưa có thẻ
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // không đọc được UID
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  delay(1000);
}