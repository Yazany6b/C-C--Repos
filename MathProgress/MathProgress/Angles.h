#ifndef ANGLES_H
#define ANGLES_H

#include "Vector2DF.h"

#define PI 3.141592654
#define RadRoDeg 57.29577951f
#define DegToRad 0.017453293f

class Angle
{
public:
	Angle();
	~Angle();

	static float GetAngle(Vector2DF &v1,Vector2DF &v2){
		float diffy = v2.getY() - v1.getY();
		float diffx = v2.getX() - v1.getX();

		float tanAlpha = diffy / diffx;

		float alpha = atan(tanAlpha) * RadRoDeg;//calculate the angle

		//if the angle in the first quadrant
		if(v2.getY() < v1.getY() && v2.getX() > v1.getX())
			return alpha;
		//if the angle in the second of third quadrat
		else if((v2.getY() < v1.getY() && v2.getX() < v1.getX()) || 
			(v2.getY() > v1.getY() && v2.getX() < v1.getX()))
			return alpha + 180;
		else
			return alpha + 360;
	}
	
	static double ConvertToDegree(double radianAngle){
		return PI / 180 * radianAngle;
	}

	static double ConvertToRadian(double degreeAngle){
		return 180 / PI * degreeAngle;
	}

	static double AlphaSin(double oppsite,double hypotenuse){
		return oppsite / hypotenuse;
	}

	static double AlphaCos(double adjacent,double hypotenuse){
		return adjacent / hypotenuse;
	}

	static double AlphaTan(double oppsite,double adjacent){
		return oppsite / adjacent;
	}
private:

};

Angle::Angle()
{
}

Angle::~Angle()
{
}

#endif