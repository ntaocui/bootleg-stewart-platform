#include <iostream>

#include "stewart-platform.h"
#include "config.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	StewartPlatform sp;

	float servosPosition[6];
	
	point_t translation = {}, rotation = {};
	
	sp.getServoPosition(translation, rotation, servosPosition);
	  
	for(int i = 0; i <6; i++) {
		std::cout << servosPosition[i] << std::endl;
	}  
	
	return 0;
}
