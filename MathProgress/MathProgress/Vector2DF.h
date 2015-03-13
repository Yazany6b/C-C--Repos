#ifndef Vector2DF_H
#define Vector2DF_H

#include <math.h>

class Vector2DF{
private:
    float x,y;
    static Vector2DF _empty;
public:
    Vector2DF(){
        x=0;
        y=0;
		
    }

    Vector2DF(float value){
        x = y = value;
    }

    Vector2DF(float x,float y){
        this->x = x;
        this->y = y;
    }

    float getX(){
        return x;
    }

    void setX(float x){
        this->x = x;
    }

    float getY(){
        return y;
    }

    void setY(float y){
        this->y = y;
    }

    bool Equal(Vector2DF& eq){
        return this->x == eq.x && this->y == eq.y;
    }

    bool isEmpty(){
        return this->Equal(_empty);
    }

    Vector2DF operator + (Vector2DF& op2){
        return Vector2DF(this->x * op2.x ,this->y * op2.y);
    }

    Vector2DF operator - (Vector2DF& op2){
        return Vector2DF(this->x * op2.x ,this->y * op2.y);
    }

    Vector2DF operator * (Vector2DF& op2){
        return Vector2DF(this->x * op2.x ,this->y * op2.y);
    }

    Vector2DF operator / (Vector2DF& op2){
        return Vector2DF(this->x / op2.x ,this->y / op2.y);
    }

    static bool IsPerpendicular(float slope1,float slope2 ){
        return slope1 * slope2 == -1;
    }

    static bool IsRightTriangle(Vector2DF& A,Vector2DF& B,Vector2DF& C){
        float AB = Vector2DF::Distance(A,B);
        float BC = Vector2DF::Distance(B,C);

        float AC = Vector2DF::Distance(A,C);

        return powf(AB,2) + powf(BC,2) == powf(AC,2);
    }

    static double Distance(Vector2DF& v1,Vector2DF& v2){
        return sqrt(pow(v2.x - v1.x,2) + pow(v2.y - v1.y,2));
    }

    static float Slope(Vector2DF& v1,Vector2DF& v2){
        return (v2.y - v1.y) / (v2.x - v1.x);
    }

    static float YIntersept(Vector2DF& vector,float slope){
        float x = vector.x * -1;
        float y = vector.y;

        return (x * slope) + y;
    }



    static Vector2DF Empty(){
        return _empty;
    }
};

Vector2DF Vector2DF::_empty = Vector2DF(-1,-1);

#endif // Vector2DFF_H
