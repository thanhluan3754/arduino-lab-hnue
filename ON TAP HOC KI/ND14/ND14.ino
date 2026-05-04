#include <DHT.h>
#include <LiquidCrystal_I2C.h>

DHT dht(4, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastTemp = -1;
int lastHum = -1;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  if (isnan(t) || isnan(h)) return;

  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("H: ");
  lcd.print(h);
  lcd.print("%   ");

  if (t != lastTemp || h != lastHum) {
    Serial.println("--------------------------");
    Serial.print("Nhiet do: ");
    Serial.print(t);
    Serial.print((char)223);
    Serial.println("C");
    Serial.print("Do am: ");
    Serial.print(h);
    Serial.println("%");
    lastTemp = t;
    lastHum = h;
  }

  delay(2000);
}
