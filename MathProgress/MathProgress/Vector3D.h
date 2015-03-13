#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>

class Vector3D{
private:
    float x,y,z;
    static Vector3D _empty;
public:
    Vector3D(){
        x=0;
        y=0;
        z=0;
    }

    Vector3D(float value){
        x = y = z = value;
    }

    Vector3D(float x,float y,float z){
        this->x = x;
        this->y = y;
        this->z = z;
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

    float getZ(){
        return z;
    }

    void setZ(float z){
        this->z = z;
    }

    bool Equal(Vector3D& eq){
        return this->x == eq.x && this->y == eq.y && this->z == eq.z;
    }

    bool isEmpty(){
        return this->Equal(_empty);
    }

    Vector3D operator + (Vector3D& op2){
        return Vector3D(this->x + op2.x ,this->y + op2.y,this->z + op2.z);
    }

    Vector3D operator - (Vector3D& op2){
        return Vector3D(this->x - op2.x ,this->y - op2.y ,this->z - op2.z);
    }

    Vector3D operator * (Vector3D& op2){
        return Vector3D(this->x * op2.x ,this->y * op2.y,this->z * op2.z);
    }

    Vector3D operator / (Vector3D& op2){
        return Vector3D(this->x / op2.x ,this->y / op2.y,this->z / op2.z);
    }

    static bool IsPerpendicular(float slope1,float slope2 ){
        return slope1 * slope2 == -1;
    }

    static double Distance(Vector3D& v1,Vector3D& v2){
        return sqrt(pow(v2.x - v1.x,2) + pow(v2.y - v1.y,2) + pow(v2.z - v1.z,2));
    }

    static float Slope(Vector3D& v1,Vector3D& v2){
        return (v2.y - v1.y) / sqrtf(powf(v2.z - v1.z,2) + powf(v2.x - v1.x,2));
    }

    static float YIntersept(Vector3D& vector,float slope){
        float x = vector.x * -1;
        float y = vector.y;

        return (x * slope) + y;
    }

    static Vector3D Empty(){
        return _empty;
    }
};

Vector3D Vector3D::_empty = Vector3D(-1,-1);

#endif // VECTOR3D_H
