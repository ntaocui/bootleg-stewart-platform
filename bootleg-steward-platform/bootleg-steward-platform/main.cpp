// Continuously sweep the servo through it's full range
#include "mbed.h"
#include "Servo.h"

Servo myservo(D5);

int main() {
    while(1) {
        for(int i=0; i<100; i++) {
            myservo = i/100.0;
            wait(0.01);
        }
        for(int i=100; i>0; i--) {
            myservo = i/100.0;
            wait(0.01);
        }
    }
}
