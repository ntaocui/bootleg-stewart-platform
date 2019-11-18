#ifndef _PLATFORM_HANDLER_H
#define _PLATFORM_HANDLER_H

#include <Servo.h>

#include "Point.h"
#include "StewartPlatformModel.h"


class PlatformHandler{

public:
  PlatformHandler();
  ~PlatformHandler();

  void calibrateMotors();
  void goToPosition(point_t translation, point_t rotation);
  void moveMotors(float servoPos[6]);
  void calculateIncrements(point_t translation, point_t rotation, float servoPos[6]);
 
private:
  Servo _servo[6];
  StewartPlatform _model;
  float _prevServoPosition[6];
  float _prevXYZ[6]; // keep track of the current location in terms of translation/rotation
  float _numIncrements = 10; // number of increments to reach final location
  float _incrementAngleValues[6] = {0,0,0,0,0,0}; // the angle to move each individual servo per increment
  float _incrementalXYZ[6] = {0,0,0,0,0,0}; // first three are for translation, next three are for rotation
};

#endif // _PLATFORM_HANDLER_H
