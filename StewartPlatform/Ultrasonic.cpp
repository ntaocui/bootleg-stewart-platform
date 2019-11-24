#include "Ultrasonic.h"
#include "Arduino.h"

const int trigPin = A0;
const int echoPin = A1;

float ultrasonicGetDistance(){
  float distance, duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return distance;
}
