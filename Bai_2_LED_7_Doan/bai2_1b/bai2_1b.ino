const int LED[8] = {2, 3, 4, 5, 6, 7, 8, 9};

#define A  B00000001
#define B  B00000010
#define C  B00000100
#define D  B00001000
#define E  B00010000
#define F  B00100000
#define G  B01000000
#define DP B10000000

const byte so[10] = {
  ~(A|B|C|D|E|F),
  ~(B|C),
  ~(A|B|D|E|G),
  ~(A|B|C|D|G),
  ~(B|C|F|G),
  ~(A|C|D|F|G),
  ~(A|C|D|E|F|G),
  ~(A|B|C),
  ~(A|B|C|D|E|F|G),
  ~(A|B|C|D|F|G)
};

void Hien_thi(byte n) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED[i], bitRead(n, i));
  }
}

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], HIGH);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    Hien_thi(so[i]);
    delay(2000);
  }

  for (int i = 0; i < 10; i++) {
    Hien_thi(so[i]);
    delay(1000);
  }
  delay(2000);
  for (int i = 0; i < 10; i++) {
    Hien_thi(so[9 - i]);
    delay(1000);
  }
  delay(2000);

  for (int i = 0; i < 10; i += 2) {
    Hien_thi(so[i]);
    delay(1000);
  }

  for (int i = 1; i < 10; i += 2) {
    Hien_thi(so[i]);
    delay(1000);
  }
}
