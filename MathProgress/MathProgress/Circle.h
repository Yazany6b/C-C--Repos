#ifndef CIRCLE_H
#define CIRCLE_H

#include "Vector2D.h"
#include "DrawableBase.h"
class Circle : DrawableBase
{
private:
	Vector2D center;
	float radius;
public:
	Circle(float x,float y,float r);
	~Circle();

	int X(){
		return center.getX();
	}

	int Y(){
		return center.getY();
	}

	int R(){
		return radius;
	}

	void Draw(Pen & p){
		
		glLineWidth(p.GetWidth());

		glColor3f(p.GetColor().R(), p.GetColor().G(), p.GetColor().B());

		int h = X();
		int k = Y();
		int r = R();

		glBegin(GL_LINES);

		for (float i = 0;i < 180;i++){
		
			float x = r * cosf(i) - h;
			float y = r * sin(i) + k;

			glVertex3f(x + k,y - h,0);

			x = r * cos(i + 0.1) - h;
			y = r * sin(i + 0.1) + k;

			glVertex3f(x + k,y - h,0);
		}

		glEnd();
	}
};

Circle::Circle(float x,float y,float r)
{
	center = Vector2D(x,y);
	radius = r;
}

Circle::~Circle()
{
}

#endif