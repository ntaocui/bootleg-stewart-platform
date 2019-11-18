#ifndef _STEWARTPLATFORM_H
#define _STEWARTPLATFORM_H

#ifndef degToRad
#define degToRad(degree) (degree * PI / 180.0)
#endif

#ifndef radToDeg
#define radToDeg(radians)  ((radians * 180.0) / PI)
#endif

#include <Arduino.h>
#include "Config.h"
#include "Point.h"


class StewartPlatform
{
public:
	StewartPlatform();
	virtual ~StewartPlatform();
	void getServoPosition(const point_t, const point_t, float[6]);
protected:

private:
	const double beta[6];
	float alpha[6]; 
	point_t baseJoint[6], platformJoint[6], legLength[6];
	point_t translation, rotation;

	void setTranslation(const point_t);
	void setRotation(const point_t);
	void getRotationMatrix(float[3][3]);
	void getPlatformJoints();
	
	void calcLegLength();
	void calcAlpha();
	void calcServoPos(float[6]);

};

#endif // SPLATFORM_H
