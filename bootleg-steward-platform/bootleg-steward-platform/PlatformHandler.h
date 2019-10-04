// September 27th 2019
#include "servo.h"
//#include "constants.h"
#include "mbed.h"
#include <vector>

//Servo myservo1(D3);
//Servo myservo2(D5);
//Servo myservo3(D6);
//Servo myservo4(D9);
//Servo myservo5(D10);
//Servo myservo6(D11);

class platformHandler{

public:
	platformHandler();
	~platformHandler();

	void calibrateMotors();
	void zeroMotors();

private:
	std::vector<Servo> _servo;	
	
};
	

	


