#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Ho va ten SV:");
  lcd.setCursor(2, 1);
  lcd.print("SV - lop");
  delay(200);
}
