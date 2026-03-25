#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

byte correctUID[4] = {0x45, 0x5D, 0xCA, 0xE0};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("Quet the RFID...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  Serial.print("UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // so sánh UID
  if (checkUID()) {
    Serial.println(">> THE DUNG - MO CUA");
  } else {
    Serial.println(">> THE SAI - TU CHOI");
  }

  delay(1000);
}

// hàm kiểm tra UID
bool checkUID() {
  for (byte i = 0; i < 4; i++) {
    if (mfrc522.uid.uidByte[i] != correctUID[i]) {
      return false;
    }
  }
  return true;
}