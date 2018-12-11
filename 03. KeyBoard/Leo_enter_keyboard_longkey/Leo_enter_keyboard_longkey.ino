/*  CJMCU beetle keyboard 테스트 프로그램
*   수정 : 2018. 12. 11
*   제작 : eleparts 부설연구소
*   SW ver. 1.0.0
*   
*   GPIO D9 에 키 입력용 센서 연결
*/

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
 
  if(key == HIGH && key != last_key){         // 키 입력 
    Keyboard.press(KEY_RETURN);
  }else if(key == LOW && key != last_key){    // 키 입력 종료
    Keyboard.release(KEY_RETURN);
  }
  last_key = key;

  delay(20);
}

