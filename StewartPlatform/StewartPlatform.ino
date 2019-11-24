#include "Config.h"
#include "Point.h"
#include "PlatformHandler.h"
#include "StewartPlatformModel.h"

const int trigPin = A0;
const int echoPin = A1;

PlatformHandler platform;
point_t translation;
point_t rotation;

void setup() {
  Serial.begin(115200);
  // setup ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  platform.calibrateMotors();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  translation.x = 0;
  translation.y = 0;
  translation.z = 0;
  rotation.x = 0;
  rotation.y = 0;
  rotation.z = 0;
  platform.goToPosition(translation, rotation);
  delay(5000);
  
  translation.x = 0;
  translation.y = 0;
  translation.z = 0;
  rotation.x = 0;
  rotation.y = 0.2;
  rotation.z = 0;
  platform.goToPosition(translation, rotation);
  delay(5000);
}
