#include "PlatformHandler.h"
#include "Ultrasonic.h"

PlatformHandler::PlatformHandler(){
}

PlatformHandler::~PlatformHandler(){

}

void PlatformHandler::calibrateMotors() {
  _servo[0].attach(3, 460, 2425);  // (pin #, how far the "0" degree position reaches; the lower, the further it goes, how far the "180" degree position goes; the greater, the further it goes)
  _servo[1].attach(5, 490, 2430);
  _servo[2].attach(6, 425, 2330);
  _servo[3].attach(9, 760, 2285);
  _servo[4].attach(10, 410, 2350);
  _servo[5].attach(11, 740, 2370);

  // set to 0 position
  _servo[0].write(90);
  _servo[1].write(90);
  _servo[2].write(90);
  _servo[3].write(90);
  _servo[4].write(90);
  _servo[5].write(90);

  _prevServoPosition[0] = 90;
  _prevServoPosition[1] = 90;
  _prevServoPosition[2] = 90;
  _prevServoPosition[3] = 90;
  _prevServoPosition[4] = 90;
  _prevServoPosition[5] = 90;

  _prevXYZ[0] = 0;
  _prevXYZ[1] = 0;
  _prevXYZ[2] = 0;
  _prevXYZ[3] = 0;
  _prevXYZ[4] = 0;
  _prevXYZ[5] = 0;
  
}

void PlatformHandler::goToPosition(point_t translation, point_t rotation){
  float servosPos[6] = {0};
  _model.getServoPosition(translation, rotation, servosPos);
  
//  Serial.println(servosPos[0]);
//  Serial.println(servosPos[1]);
//  Serial.println(servosPos[2]);
//  Serial.println(servosPos[3]);
//  Serial.println(servosPos[4]);
//  Serial.println(servosPos[5]);

//  TODO: do this mapping properly, will need to alter calibrations as well
  _servo[0].write(servosPos[5]);
  _servo[1].write(servosPos[0]);
  _servo[2].write(servosPos[1]);
  _servo[3].write(servosPos[2]);
  _servo[4].write(servosPos[3]);
  _servo[5].write(servosPos[4]);

  calculateIncrements(translation, rotation, servosPos);
  moveMotors(servosPos);

  // now that you've reached the final destination, update the prevServoPosition array
  _prevServoPosition[0] = servosPos[0];
  _prevServoPosition[1] = servosPos[1];
  _prevServoPosition[2] = servosPos[2];
  _prevServoPosition[3] = servosPos[3];
  _prevServoPosition[4] = servosPos[4];
  _prevServoPosition[5] = servosPos[5];
  
}

void PlatformHandler::calculateIncrements(point_t translation, point_t rotation, float servosPos[6]){

  // calculate for servo increments
  _incrementAngleValues[0] = (servosPos[0] - _prevServoPosition[0])/ _numIncrements; // divide by number of increments
  _incrementAngleValues[1] = (servosPos[1] - _prevServoPosition[1])/ _numIncrements;
  _incrementAngleValues[2] = (servosPos[2] - _prevServoPosition[2])/ _numIncrements;
  _incrementAngleValues[3] = (servosPos[3] - _prevServoPosition[3])/ _numIncrements;
  _incrementAngleValues[4] = (servosPos[4] - _prevServoPosition[4])/ _numIncrements;
  _incrementAngleValues[5] = (servosPos[5] - _prevServoPosition[5])/ _numIncrements;

  // calculate for translation/rotation increments
  _incrementalXYZ[0] = (translation.x - _prevXYZ[0] )/_numIncrements;
  _incrementalXYZ[1] = (translation.y - _prevXYZ[1] )/_numIncrements;
  _incrementalXYZ[2] = (translation.z - _prevXYZ[2] )/_numIncrements;
  _incrementalXYZ[3] = (rotation.x - _prevXYZ[3] )/_numIncrements;
  _incrementalXYZ[4] = (rotation.y - _prevXYZ[4] )/_numIncrements;
  _incrementalXYZ[5] = (rotation.z - _prevXYZ[5] )/_numIncrements;
  
}

// move the motors incrementally to its location while sending serial data about its location every increment
void PlatformHandler::moveMotors(float servosPos[6]){
  for(int i = _numIncrements - 1; i >= 0; i--){
      _servo[0].write(servosPos[0] - _incrementAngleValues[0]*i);
      _servo[1].write(servosPos[1] - _incrementAngleValues[1]*i);
      _servo[2].write(servosPos[2] - _incrementAngleValues[2]*i);
      _servo[3].write(servosPos[3] - _incrementAngleValues[3]*i);
      _servo[4].write(servosPos[4] - _incrementAngleValues[4]*i);
      _servo[5].write(servosPos[5] - _incrementAngleValues[5]*i);

      // calculate approximate current translation and rotation values in terms of XYZ
      _prevXYZ[0] = _prevXYZ[0] + _incrementalXYZ[0];
      _prevXYZ[1] = _prevXYZ[1] + _incrementalXYZ[1];
      _prevXYZ[2] = _prevXYZ[2] + _incrementalXYZ[2];
      _prevXYZ[3] = _prevXYZ[3] + _incrementalXYZ[3];
      _prevXYZ[4] = _prevXYZ[4] + _incrementalXYZ[4];
      _prevXYZ[5] = _prevXYZ[5] + _incrementalXYZ[5];

      float distance = getDistance();
//      Serial.println(distance);
//      Serial.print("The z rotation is: ");
//      Serial.println(_prevXYZ[5]);
//      Serial.print("The x rotation is: ");
//      Serial.println(_prevXYZ[3]);
      // delay(50);
      // send data over serial here to python script
  }
}
