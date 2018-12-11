/*  CJMCU beetle Keyboard 테스트 프로그램
*   수정 : 2018. 12. 11
*   제작 : eleparts 부설연구소
*   SW ver. 1.0.0
*/

#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  delay(1000);                                      //지연 1초
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  
  Keyboard.press(KEY_LEFT_GUI);                    // 윈도우 키
  Keyboard.write('r');
  delay(10);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("notepad");                    // 메모장 실행
  delay(2000);
  Keyboard.println("Hello Wordl!!!");             // 문자 출력
  Keyboard.println("CJMCU Leonardo Bettle Keyboard TEST");
  Keyboard.write(KEY_RETURN);
  delay(2000);
  Keyboard.println("bye~"); 
  delay(1000);
  Keyboard.press(KEY_LEFT_ALT);                   // ALT+ F (파일 메뉴)
  Keyboard.write('f');
  delay(10);
  Keyboard.releaseAll();                          // 종료
  Keyboard.write('x');
  delay(500);
  Keyboard.write('n');                            // 저장하지 않음
  Keyboard.releaseAll();                          
}

void loop() {                                       // LED 점멸 반복
  // put your main code here, to run repeatedly:
  digitalWrite(13,LOW);
  delay(1000);
  digitalWrite(13,HIGH);
  delay(1000);
}
/*

*/
