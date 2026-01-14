/*
Nguyen Thanh Luan - 745114054

Bai 1-1: Lap trinh dieu khien den LED theo chuong trinh sau:
Bat tat LED theo quy luat: bat 1s, tat 1s lap lai 5 lan.
Bat tat LED theo quy luat: bat 3s, tat 0,5s lap lai 5 lan.
Bat tat LED theo quy luat: bat 0,5s, tat 3s lap lai 5 lan.
*/

#define led1 2

void led();

void setup() {
  pinMode(led1, OUTPUT);
	digitalWrite(led1, LOW);
}
 
void loop() {
	led(1000, 1000, 5);
  	led(3000, 500, 5); 
  	led(500, 3000, 5); 
}

void led(int bat, int tat, int lan) {
  	for(int i = 0; i < lan; i++) {
		digitalWrite(led1, HIGH);
  		delay(bat);
  		digitalWrite(led1, LOW);
  		delay(tat);	
  	}
}