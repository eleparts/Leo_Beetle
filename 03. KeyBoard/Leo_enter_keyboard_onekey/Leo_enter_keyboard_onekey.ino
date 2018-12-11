#include <Keyboard.h>
int key = LOW;
int last_key = LOW;
  
void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  delay(3000);
  pinMode(13,OUTPUT);                         // LED 설정
  digitalWrite(13,LOW);                       
  pinMode(9,INPUT);                           // 센서 입력
}

void loop() {
  // put your main code here, to run repeatedly:

  key = digitalRead(9);
  digitalWrite(13,key);                       // LED
 
  if(key == HIGH && key != last_key){         // 신호 입력시 1회 RETURN 입력
    Keyboard.write (KEY_RETURN);
  }
  last_key = key;

  delay(20);
}






