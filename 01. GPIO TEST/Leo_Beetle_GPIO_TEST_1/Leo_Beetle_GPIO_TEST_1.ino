/*  CJMCU beetle GPIO 테스트 프로그램
*   수정 : 2018. 12. 03
*   제작 : eleparts 부설연구소
*   SW ver. 1.0.0
*   
*   GPIO에 각각 LED 연결
*   LED 1개 좌 -> 우 방향으로 반복 이동 (HIGH)
*/
#define LOOP_GPIO 10    // 연결된 GPIO의 개수

char gpio_list[] = {3,2,0,1,11,10,9,A0,A1,A2};
// GPIO list - SCL, SDA, Rx, Tx, D11, D10, D9, A0, A1, A2
int loop_cnt = 0;
	
void setup() {
	// put your setup code here, to run once:
	
	for(int i=0;i<LOOP_GPIO;i++)      // gpio_list 배열에 저장된 포트 OUTPUT 모드로 정의 
		pinMode(gpio_list[i], OUTPUT); 
		
	pinMode(13, OUTPUT);              // 보드 내장 LED  
	digitalWrite(13, HIGH); 
}

void loop() {
	// put your main code here, to run repeatedly:
	
	for(int i=0;i<LOOP_GPIO;i++){     // LED 좌 -> 우 
		if(loop_cnt == i){              // LED High/Low 설정
			digitalWrite(gpio_list[i], HIGH); 
		}else{
			digitalWrite(gpio_list[i], LOW); 
		}
	}
	
	loop_cnt < LOOP_GPIO-1 ? loop_cnt++ : loop_cnt = 0;         
	
	delay(200);
}


