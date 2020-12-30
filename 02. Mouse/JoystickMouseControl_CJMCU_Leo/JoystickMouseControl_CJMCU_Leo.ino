/*
	본 예제는 아두이노의 JoystickMouseControl 예제를 아래 링크의 조이스틱 모듈과 사용하기 위해 수정한 예제입니다.
	CJMCU Leonardo Beetle

	Joystick Module
	https://www.eleparts.co.kr/EPXJ6B3F

	원본 예제 코드는 아래 링크에서 확인 가능합니다.
	http://www.arduino.cc/en/Tutorial/JoystickMouseControl

	H/W
	Mouse on/off SW : D10, D11 (jumper)
	Mouse button : D9
	joystick X : A1
	joystick Y : A0

	최종 수정일 : 2018-12-04
*/

#include "Mouse.h"

// set pin numbers for switch, joystick axes, and LED:
const int switchPin = 10;      // switch to turn on and off mouse control
const int mouseButton = 9;    // input pin for the mouse pushButton
const int xAxis = A0;         // joystick X axis
const int yAxis = A1;         // joystick Y axis
const int ledPin = 13;         // Mouse control LED

// parameters for reading the joystick:
int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;       // resting position value

boolean mouseIsActive = false;    // whether or not to control the mouse

 
void setup() {

	delay(2000);                              // mouse start delay
	pinMode(11, OUTPUT);                      
	digitalWrite(11, LOW);                    // mouse on/off LOW signal pin
	pinMode(ledPin, OUTPUT);                  // the LED pin
	pinMode(switchPin, INPUT_PULLUP);         // mouse on/off switch pin (PULL UP)
	pinMode(mouseButton, INPUT_PULLUP);       // mouse Button pin        (PULL UP)

	// take control of the mouse:
	Mouse.begin();
}

void loop() {
	// read the switch:
	int switchState = digitalRead(switchPin);
	// if HIGH, useing mouse
	if (switchState != mouseIsActive) {
		mouseIsActive = switchState;
		// turn on LED to indicate mouse state:
		digitalWrite(ledPin, mouseIsActive);
	}

	// read and scale the two axes:
	int xReading = (readAxis(A0) * -1);          // Direction reversal
	int yReading = readAxis(A1);

	// if the mouse control state is active, move the mouse:
	if (mouseIsActive) {
		Mouse.move(xReading, yReading, 0);
	}

	// read the mouse button and click or not click:
	// if the mouse button is pressed:
	if (!(digitalRead(mouseButton)) == HIGH) {     // default : HIGH (PULLUP) / SW on : LOW -> Direction reversal
		// if the mouse is not pressed, press it:
		if (!Mouse.isPressed(MOUSE_LEFT)) {
			Mouse.press(MOUSE_LEFT);
		}
	}
	// else the mouse button is not pressed:
	else {
		// if the mouse is pressed, release it:
		if (Mouse.isPressed(MOUSE_LEFT)) {
			Mouse.release(MOUSE_LEFT);
		}
	}

	delay(responseDelay);
}

/*
	reads an axis (0 or 1 for x or y) and scales the analog input range to a range
	from 0 to <range>
*/

int readAxis(int thisAxis) {
	// read the analog input:
	int reading = analogRead(thisAxis);

	// map the reading from the analog input range to the output range:
	reading = map(reading, 0, 1023, 0, range);

	// if the output reading is outside from the rest position threshold, use it:
	int distance = reading - center;

	if (abs(distance) < threshold) {
		distance = 0;
	}

	// return the distance for this axis:
	return distance;
}

