#ifndef PEN_H
#define PEN_H
#include "Color.h"

class Pen {
private:
	float width;
	Color color;	

public:
	Pen(float w){
		width = w;
		color = Color::Black;
	}

	Pen(float w,const Color& c){
		width = w;
		color = c;
	}


	float GetWidth(){
		return width;
	}

	void SetWidth(float w){
		width = w;
	}

	Color GetColor(){
		return color;
	}

	void SetColor(Color &c){
		this->color = c;
	}
};

#endif