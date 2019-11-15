#include "Config.h"
#include "Point.h"
#include "PlatformHandler.h"
#include "StewartPlatformModel.h"



PlatformHandler platform;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  platform.calibrateMotors();
 
}

void loop() {
  // put your main code here, to run repeatedly:
  point_t translation;
  translation.x = 0;
  translation.y = 0;
  translation.z = 0;
  point_t rotation;
  rotation.x = 0;
  rotation.y = 0;
  rotation.z = 0;
  platform.goToPosition(translation, rotation);
  delay(5000);
  Serial.println("");
//  translation.x = 0;
//  translation.y = 0;
//  translation.z = 10;
//  rotation.x = 0;
//  rotation.y = 0;
//  rotation.z = 0;
//  platform.goToPosition(translation, rotation);
//  delay(5000);
//  Serial.println("");
}
