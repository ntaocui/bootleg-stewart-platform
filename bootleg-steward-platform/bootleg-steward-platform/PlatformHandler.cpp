#include "platformHandler.h"

platformHandler::platformHandler(){
	Servo s(D3);
	_servo.push_back(s);
	_servo.push_back(Servo(D5));
	_servo.push_back(Servo(D6));
	_servo.push_back(Servo(D9));
	_servo.push_back(Servo(D10));
	_servo.push_back(Servo(D11));
}

void platformHandler::calibrateMotors() {
	_servo[0].calibrate(0.000975,90,0.001480, false);
	_servo[1].calibrate(0.000970,90,0.001520, true);
	_servo[2].calibrate(0.000940,90,0.001600, false);
	_servo[3].calibrate(0.000800,90,0.001370, true);
	_servo[4].calibrate(0.000960,90,0.001560, false);
	_servo[5].calibrate(0.000825,90,0.001560, true);
}

void platformHandler::zeroMotors() {
	_servo[0].position(0);
	_servo[1].position(0);
	_servo[2].position(0);
	_servo[3].position(0);
	_servo[4].position(0);
	_servo[5].position(0);
}
