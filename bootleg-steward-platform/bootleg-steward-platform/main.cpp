// Continuously sweep the servo through it's full range
#include "mbed.h"
#include "Servo.h"
#include "PlatformHandler.h"

Servo myservo1(D3);
Servo myservo2(D5);
Servo myservo3(D6);
Servo myservo4(D9);
Servo myservo5(D10);
Servo myservo6(D11);

int main() {
	while(1){
		myservo1.position(0);
		myservo2.position(0);
		myservo3.position(0);
		myservo4.position(0);
		myservo5.position(0);
		myservo6.position(0);
		wait(1);
		myservo1.position(90);
		myservo2.position(90);
		myservo3.position(90);
		myservo4.position(90);
		myservo5.position(90);
		myservo6.position(90);
		wait(1);
	
	}
//    while(1) {
//        for(int i=0; i<100; i++) {
//					myservo1 = i/100.0;
//          myservo2 = i/200.0;
//					myservo3 = i/300.0;
//					myservo4 = i/400.0;
//					myservo5 = i/500.0;
//					myservo6 = i/600.0;
//					wait(0.02);
//        }
//				for(int i=100; i>0; i--) {
//					myservo1 = i/600.0;
//					myservo2 = i/500.0;
//					myservo3 = i/400.0;
//					myservo4 = i/300.0;
//					myservo5 = i/200.0;
//					myservo6 = i/100.0;
//					wait(0.02);
//        }
//    }
}
