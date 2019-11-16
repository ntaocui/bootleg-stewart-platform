#include "PlatformHandler.h"

PlatformHandler::PlatformHandler(){

}

PlatformHandler::~PlatformHandler(){

}

void PlatformHandler::calibrateMotors() {
  _servo[0].attach(3, 670, 2625);  // (pin #, how far the "0" degree position reaches; the lower, the further it goes, how far the "180" degree position goes; the greater, the further it goes)
  _servo[1].attach(5, 410, 2360);
  _servo[2].attach(6, 500, 2390);
  _servo[3].attach(9, 678, 2225);
  _servo[4].attach(10, 480, 2420);
  _servo[5].attach(11, 650, 2300);
}

void PlatformHandler::goToPosition(point_t translation, point_t rotation){
  float servosPos[6] = {0};
  _model.getServoPosition(translation, rotation, servosPos);
  
  Serial.println(servosPos[0]);
  Serial.println(servosPos[1]);
  Serial.println(servosPos[2]);
  Serial.println(servosPos[3]);
  Serial.println(servosPos[4]);
  Serial.println(servosPos[5]);

//  TODO: do this mapping properly, will need to alter calibrations as well
  _servo[0].write(servosPos[5]);
  _servo[1].write(servosPos[0]);
  _servo[2].write(servosPos[1]);
  _servo[3].write(servosPos[2]);
  _servo[4].write(servosPos[3]);
  _servo[5].write(servosPos[4]);


//  for(int i = 0; i < 6; ++i){
//    _servo[i].write(servosPos[i]);
//  }
}
