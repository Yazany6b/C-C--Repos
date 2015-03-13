#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

class Vector2D{
private:
    int x,y;
public:
    Vector2D(){
        x=0;
        y=0;
    }

    Vector2D(int value){
        x = y = value;
    }

    Vector2D(int x,int y){
        this->x = x;
        this->y = y;
    }

    int getX(){
        return x;
    }

    void setX(int x){
        this->x = x;
    }

    int getY(){
        return y;
    }

    void setY(int y){
        this->y = y;
    }

    //operator + (Vector2D& op2){
    //    return Vector2D(this->x * op2.x ,this->y * op2.y);
    //}

    //operator - (Vector2D& op2){
    //    return Vector2D(this->x * op2.x ,this->y * op2.y);
    //}
    //operator * (Vector2D& op2){
    //    return Vector2D(this->x * op2.x ,this->y * op2.y);
    //}
    //operator / (Vector2D& op2){
    //    return Vector2D(this->x / op2.x ,this->y / op2.y);
    //}

    static bool IsPerpendicular(int slope1,int slope2 ){
        return slope1 * slope2 == -1;
    }

    static double Distance(Vector2D& v1,Vector2D& v2){
		
        return sqrt((double)((v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y)));
    }

    static int Slope(Vector2D& v1,Vector2D& v2){
        return (v2.y - v1.y) / (v2.x - v1.x);
    }

    static int YIntersept(Vector2D& vector,int slope){
        int x = vector.x * -1;
        int y = vector.y;

        return (x * slope) + y;
    }
};

#endif // VECTOR2D_H
