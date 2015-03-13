#ifndef COLOR_H
#define COLOR_H

struct Color
{
private:
	float r;
	float g;
	float b;
	float a;
	Color(float r,float g,float b,float a){
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

public:
	Color(){
		r=a=b=g=0;
	}
	float R(){
		return r;
	}
	float B(){
		return b;
	}
	float G(){
		return g;
	}
	float A(){
		return a;
	}

#pragma region Static Colors

	static const Color Red;
	static const Color Blue;
	static const Color Black;
	static const Color Green;
	static const Color Gray;

#pragma endregion

};

const Color Color::Red(1,0,0,0);
const Color Color::Blue(0,0,1,0);
const Color Color::Black(0,0,0,0);
const Color Color::Green(0,0,1,0);
const Color Color::Gray(.5f,.5f,.5f,0);
#endif