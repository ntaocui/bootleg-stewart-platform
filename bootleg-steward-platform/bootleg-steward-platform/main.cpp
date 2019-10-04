// Continuously sweep the servo through it's full range
#include "mbed.h"
#include "Servo.h"
//#include "PlatformHandler.h"

#include "USBSerial.h"
 
//Virtual serial port over USB
USBSerial serial;
Serial pc(USBTX, USBRX);
 
int main(void) {
    uint8_t buf[128];
    while(1)
    {
        serial.scanf("%s", buf);
        serial.printf("recv: %s", buf);
        pc.printf("recv: %s\r\n", buf);
    }
}
/*
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
//		myservo1.position(-20);
		myservo2.position(30);
		myservo3.position(30);
//		myservo4.position(-20);
//		myservo5.position(-20);
//		myservo6.position(-20);
		wait(2);
//		myservo1.position(20);
		myservo2.position(0);
		myservo3.position(0);
//		myservo4.position(20);
//		myservo5.position(20);
//		myservo6.position(20);
		wait(2);
//		myservo1.position(-90); 
//		myservo2.position(-90);
//		myservo3.position(-90);
//		myservo4.position(-90);
//		myservo5.position(-90);
//		myservo6.position(-90);
//		wait(1);
//	
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
*/