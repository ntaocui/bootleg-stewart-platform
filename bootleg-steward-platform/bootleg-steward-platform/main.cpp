// Continuously sweep the servo through it's full range
#include "mbed.h"
#include "Servo.h"
//#include "PlatformHandler.h"

Servo myservo1(D3);
Servo myservo2(D5);
Servo myservo3(D6);
Servo myservo4(D9);
Servo myservo5(D10);
Servo myservo6(D11);


void calibrateMotors(){
	myservo1.calibrate(0.000975,90,0.001480, false);
	myservo2.calibrate(0.000970,90,0.001520, true);
	myservo3.calibrate(0.000940,90,0.001600, false);
	myservo4.calibrate(0.000800,90,0.001370, true);
	myservo5.calibrate(0.000960,90,0.001560, false);
	myservo6.calibrate(0.000825,90,0.001560, true);
}

int main() {
	calibrateMotors();
	myservo1.position(0);
	myservo2.position(0);
	myservo3.position(0);
	myservo4.position(0);
	myservo5.position(0);
	myservo6.position(0);
	wait(2);
	while(1){
		//down
		myservo1.position(0);
		myservo2.position(10);
		myservo3.position(10);
		myservo4.position(0);
		myservo5.position(-5);
		myservo6.position(-5);
		wait(2);
		
		myservo1.position(0);
		myservo2.position(0);
		myservo3.position(0);
		myservo4.position(0);
		myservo5.position(0);
		myservo6.position(0);
		wait(2);
		
		//up
		myservo1.position(0);
		myservo2.position(-10);
		myservo3.position(-10);
		myservo4.position(0);
		myservo5.position(5);
		myservo6.position(5);
		wait(2);
		
		myservo1.position(0);
		myservo2.position(0);
		myservo3.position(0);
		myservo4.position(0);
		myservo5.position(0);
		myservo6.position(0);
		wait(2);
		
		//left
		myservo1.position(10);
		myservo2.position(2.5);
		myservo3.position(-2.5);
		myservo4.position(-10);
		myservo5.position(-5);
		myservo6.position(5);
		wait(2);
		
		myservo1.position(0);
		myservo2.position(0);
		myservo3.position(0);
		myservo4.position(0);
		myservo5.position(0);
		myservo6.position(0);
		wait(2);
		
		//right
		myservo1.position(-10);
		myservo2.position(-2.5);
		myservo3.position(2.5);
		myservo4.position(10);
		myservo5.position(5);
		myservo6.position(-5);
		wait(2);
		
		myservo1.position(0);
		myservo2.position(0);
		myservo3.position(0);
		myservo4.position(0);
		myservo5.position(0);
		myservo6.position(0);
		wait(2);
	}
}
