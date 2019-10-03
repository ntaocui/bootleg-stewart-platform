#include "platformHandler.h"

platformHandler::platformHandler(){
	_servo.push_back(Servo(D3));
	_servo.push_back(Servo(D5));
	_servo.push_back(Servo(D6));
	_servo.push_back(Servo(D9));
	_servo.push_back(Servo(D10));
	_servo.push_back(Servo(D11));	
}