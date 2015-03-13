#ifndef DRAWABLEBASE_H
#define DRAWABLEBASE_H

#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif

#include "Pen.h"


class DrawableBase
{
public:
	virtual void Draw(Pen & p) = 0;
private:

};
#endif