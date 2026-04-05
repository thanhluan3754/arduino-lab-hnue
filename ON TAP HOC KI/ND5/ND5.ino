#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte bientro = A0;
int lastVal = -1;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int value = analogRead(bientro);
  int percent = map(value, 0, 1023, 0, 100);

  if (abs(percent - lastVal) >= 2) {
    lcd.setCursor(1, 0);
    lcd.print("Gia tri tho:");
    lcd.print(value);
    lcd.print("   ");

    lcd.setCursor(2, 1);
    lcd.print("Phan tram:");
    lcd.print(percent);
    lcd.print("% ");

    Serial.println("-------------------");

    Serial.print("Gia tri tho: ");
    Serial.println(value);

    Serial.print("Gia tri phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    lastVal = percent;
  }
}