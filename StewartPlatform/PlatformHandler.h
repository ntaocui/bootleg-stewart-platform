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
 
private:
  Servo _servo[6];
  StewartPlatform _model;
};

#endif // _PLATFORM_HANDLER_H
