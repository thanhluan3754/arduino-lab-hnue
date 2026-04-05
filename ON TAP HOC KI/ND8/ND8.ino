const byte LED[8] = {11, 10, 9, 8, 7, 6, 5, 4};
const byte button2 = 2;
const byte button3 = 3;
int lastVal = -1;

unsigned long lastTime0 = 0;
unsigned long lastTime1 = 0;
const unsigned long fixedVal = 200;
volatile int dem = 0;

String state = " ";

const byte so[10] = {
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000111,
  B01111111,
  B01101111
};

void hien_thi(byte n) {
  for(int i = 0; i < 8; i++) {
    digitalWrite(LED[i], !((n >> i) & 1));
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
  }
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  attachInterrupt(0, isr0, FALLING);
  attachInterrupt(1, isr1, FALLING);
}

  void isr0() {
    unsigned long current = millis();
    if (current - lastTime0 > fixedVal) {
      dem--;
      if (dem < 0) dem = 0;
      state = "giam";
      lastTime0 = current;
    }
  }

  void isr1() {
    unsigned long current = millis();
    if (current - lastTime1 > fixedVal) {
      dem++;
      state = "tang";
      lastTime1 = current;
    }
  }

void loop() {
  int donvi = dem % 10;
  hien_thi(so[donvi]);

  static int lastdem = -1;
  if (dem != lastdem) {
    Serial.println("---------------");

    Serial.print("So lan nhan nut: ");
    Serial.print(dem);
    Serial.println(" lan");

    Serial.print("Nut vua nhan: ");
    Serial.println(state);

    lastdem = dem;
  }
}
