const byte D[8] = {11, 10, 9, 8, 7, 6, 5, 4};
String data = "";
const char* color;
const char* state;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(D[i], OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '\n') {

      if (data.length() > 1) {
        char action = toupper(data[0]);
        char num = data.substring(1).toInt();
        
        if ( (action == 'B' || action == 'T') && (num > 0 && num < 9)) {
          
          if (num > 0 && num <= 3 ) color = "xanh";
          else if (num > 3 && num <= 6) color = "vang";
          else color = "do";

          if (action == 'B') {
            digitalWrite(D[num-1], HIGH);
            state = "bat";
          }
          else {
            digitalWrite(D[num-1], LOW);
            state = "tat";
          }
        }
        else {
          Serial.println("Lenh sai!");
        }

        Serial.println("------------");
        Serial.print("Lenh vua gui: ");
        Serial.println(data);
        data.trim();
        Serial.print("Tac dong toi LED: ");
        Serial.println(color);
        Serial.print("Trang thai: ");
        Serial.println(state);

        data = "";
      }
      else {
        Serial.println("Lenh sai!");
      }
    }

    else {
      data += c;
    }
    
  }
}
