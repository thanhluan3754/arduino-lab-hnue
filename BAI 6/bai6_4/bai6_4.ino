#include <DHT.h>
const byte LED[5] = {3, 4, 5};
const byte DHT_PIN = 2;
const byte DHT_TYPE = DHT11;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Nhiet do: ");
  Serial.print(t); Serial.print("°C");
  Serial.print(". ");
  Serial.print("Do am: ");
  Serial.print(h); Serial.println("%");
  Serial.println();
  
  if ((t < 27) && (h < 65))
  {
    Serial.println("Led Xanh");
    digitalWrite(LED[0], HIGH);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], LOW);
  }

  else if (((t < 27) && (h > 65)) || ((t > 27) && (h < 65)))
  {
    Serial.println("Led Vàng");
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], HIGH);
    digitalWrite(LED[2], LOW);
  }

  else if ((t > 27) && (h > 65))
  {
    Serial.println("Led Đỏ");
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], HIGH);
  }
  delay(1000);
}
