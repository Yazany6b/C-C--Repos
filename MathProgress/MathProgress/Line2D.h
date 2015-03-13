#ifndef LINE_H
#define LINE_H

#include "Vector2DF.h"
#include "DrawableBase.h"

class Line2D : DrawableBase{
private :
    Vector2DF startVector;
    Vector2DF endVector;
public:
    Line2D(){
        startVector = Vector2DF::Empty();
        endVector = Vector2DF::Empty();
    }

    Line2D(Vector2DF start,Vector2DF end){
        startVector = start;
        endVector = end;
		
    }

    Line2D(float x1,float y1,float x2,float y2){
        startVector = Vector2DF(x1,y1);
        endVector = Vector2DF(x2,y2);
    }

    Vector2DF GetStartVector(){
        return startVector;
    }

    Vector2DF GetEndVector(){
        return endVector;
    }

    Vector2DF GetMidVetor(){
        return Vector2DF( (GetX1() + GetX2())/2 , (GetY1() + GetY2())/2 );
    }

    void SetStartVector(Vector2DF &v){
        startVector = v;
    }

    void SetEndVector(Vector2DF& v){
        endVector = v;
    }

	void Draw(Pen & p){
		glLineWidth(p.GetWidth());

		glColor3f(p.GetColor().R(), p.GetColor().G(), p.GetColor().B());


		glBegin(GL_LINE);

		glVertex2f(GetX1(),GetY1());
		glVertex2f(GetX2(),GetY2());

		glEnd();
	}

    double GetLength(){
        return Vector2DF::Distance(startVector,endVector);
    }

    float GetX1(){
        return startVector.getX();
    }

    float GetX2(){
        return endVector.getX();
    }

    float GetY1(){
        return startVector.getY();
    }

    float GetY2(){
        return endVector.getY();
    }

    float GetRunValue(){
        return endVector.getX() - startVector.getX();
    }

    float GetRaiseValue(){
        return endVector.getY() - startVector.getY();
    }

    float GetSlope(){
        return Vector2DF::Slope(startVector,endVector);
    }

    float GetYIntersept(){
        return Vector2DF::YIntersept(startVector,this->GetSlope());
    }

    float GetPerpendicularLineSlope(){
        return -1 / this->GetSlope();
    }

    bool IsPerpendicularTo(Line2D& line){
        return Vector2DF::IsPerpendicular(this->GetSlope(),line.GetSlope());
    }

    static bool HasLineToLineCollision(Line2D& l1,Line2D& l2){
        float slope1 = l1.GetSlope();
        float slope2 = l2.GetSlope();

        float yinter1 = l1.GetYIntersept();
        float yinter2 = l2.GetYIntersept();

        return !(slope1 == slope2 && yinter1 != yinter2);
    }

    static bool IsParallel(Line2D& l1,Line2D& l2){
        float slope1 = l1.GetSlope();
        float slope2 = l2.GetSlope();

        float yinter1 = l1.GetYIntersept();
        float yinter2 = l2.GetYIntersept();

        return slope1 == slope2 && yinter1 != yinter2;
    }

    static bool IsPerpendicular(Line2D& l1,Line2D& l2){
        float slope1 = l1.GetSlope();
        float slope2 = l2.GetSlope();

        return slope1 * slope2 == -1;
    }

    static Vector2DF FindIntersection(Line2D& l1,Line2D& l2){
        if(IsParallel(l1,l2))
            return Vector2DF::Empty();

        float slope1 = l1.GetSlope();

        float slope2 = l2.GetSlope();

        float x = (l2.startVector.getY() - l1.startVector.getY() - slope2 * l2.startVector.getX() + slope1 * l1.startVector.getX()) / (slope1 - slope2);

        float y = slope1 * x - slope1 * l1.startVector.getX() + l1.startVector.getY();

        return Vector2DF(x,y);
    }


    static Vector2DF FindIntersection2(Line2D& l1,Line2D& l2){
        if(IsParallel(l1,l2))
            return Vector2DF::Empty();

        float slope1 = l1.GetSlope();

        float slope2 = l2.GetSlope();

        float x = (slope1 * l1.GetX1() - slope2 * l2.GetX1() + l2.GetY1() - l1.GetY1()) / (slope1 - slope2);

        float y = slope1*(x - l1.GetX1()) + l1.GetY1();

        return Vector2DF(x,y);
    }
};

#endif // LINE_H
