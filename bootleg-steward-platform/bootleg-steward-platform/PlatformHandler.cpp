#include "platformHandler.h"

const Servo& s1(D3);
const Servo& s2(D5);
const Servo& s3(D6);
const Servo& s4(D9);
const Servo& s5(D10);
const Servo& s6(D11);

const float back[6]  		= 	{  0,   10,   10,   0, -5, -5};
const float forward[6]  = 	{  0,  -10,  -10,   0,  5,  5};
const float left[6]  		= 	{ 10,  2.5, -2.5, -10, -5,  5};
const float right[6] 		= 	{-10, -2.5,  2.5,  10,  5, -5};

PlatformHandler::PlatformHandler(): 
	_servo1(s1), 
	_servo2(s2), 
	_servo3(s3), 
	_servo4(s4), 
	_servo5(s5), 
	_servo6(s6){
		
		_positionMapping.insert(std::make_pair(Left, std::vector<float>(left, left + sizeof(left) / sizeof(left))));
		_positionMapping.insert(std::make_pair(Right, std::vector<float>(right, right + sizeof(right) / sizeof(right))));
		_positionMapping.insert(std::make_pair(Forward, std::vector<float>(forward, forward + sizeof(forward) / sizeof(forward))));
		_positionMapping.insert(std::make_pair(Back, std::vector<float>(back, back + sizeof(back) / sizeof(back))));
}

void PlatformHandler::calibrateMotors() {
	_servo1.calibrate(0.000975,90,0.001480, false);
	_servo2.calibrate(0.000970,90,0.001520, true);
	_servo3.calibrate(0.000940,90,0.001600, false);
	_servo4.calibrate(0.000800,90,0.001370, true);
	_servo5.calibrate(0.000960,90,0.001560, false);
	_servo6.calibrate(0.000825,90,0.001560, true);
}

void PlatformHandler::zeroMotors() {
	_servo1.position(0);
	_servo2.position(0);
	_servo3.position(0);
	_servo4.position(0);
	_servo5.position(0);
	_servo6.position(0);
}

void PlatformHandler::goToPosition(Position pos) {
	const vector<float>& targetPositions = _positionMapping[pos];
	
	_servo1.position(targetPositions[0]);
	_servo2.position(targetPositions[1]);
	_servo3.position(targetPositions[2]);
	_servo4.position(targetPositions[3]);
	_servo5.position(targetPositions[4]);
	_servo6.position(targetPositions[5]);

}
