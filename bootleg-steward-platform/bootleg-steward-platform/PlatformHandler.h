// September 27th 2019
#include "servo.h"
#include "mbed.h"
#include <vector>
#include <map>

enum Position {Left, Right, Forward, Back};

class PlatformHandler{

public:
	PlatformHandler();
	~PlatformHandler();

	void calibrateMotors();
	void zeroMotors();
	void goToPosition(Position pos);

private:
	Servo _servo1;
	Servo _servo2;
	Servo _servo3;
	Servo _servo4;
	Servo _servo5;
	Servo _servo6;

std::map<Position, std::vector<float> > _positionMapping;
};
	

	


