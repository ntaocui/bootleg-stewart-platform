#include "PlatformHandler.h"

int main() {
	PlatformHandler boardHandler;
	boardHandler.calibrateMotors();
	boardHandler.zeroMotors();
	wait(2);
	while(1){
		boardHandler.goToPosition(Forward);
		wait(2);
		boardHandler.goToPosition(Back);
		wait(2);
		boardHandler.goToPosition(Left);
		wait(2);
		boardHandler.goToPosition(Right);
		wait(2);
	}
}
