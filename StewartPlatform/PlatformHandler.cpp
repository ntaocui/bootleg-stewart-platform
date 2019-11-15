#include "PlatformHandler.h"

PlatformHandler::PlatformHandler(){

}

PlatformHandler::~PlatformHandler(){

}

void PlatformHandler::calibrateMotors() {
  _servo[0].attach(3, 600, 1150);  
  _servo[1].attach(5);
  _servo[2].attach(6);
  _servo[3].attach(9);
  _servo[4].attach(10);
  _servo[5].attach(11);
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
  
  for(int i = 0; i < 6; ++i){
    _servo[i].write(servosPos[i]);
  }
}
