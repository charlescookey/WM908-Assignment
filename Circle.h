#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
    //This is a Vec2 for the X and Y position of the center
    Vec2 center;
public:
    float radius = 0.f;
    //Default constructor
    Circle();
    //Constructor with center and radius(float)
    Circle(Vec2 _center, float _radius);
    //Constructor with center and radius(int)
    Circle(Vec2 _center, int _radius);
    //Returns if a Vec2 is inside the circle
    bool inside(Vec2 p);
    //Returns if an X and Y position is inside the circle
    bool inside(int x, int y);
    //Returns the area of the Circle
    float area();
    //Returns the Rectangle that bounds the Circle
    class Rect getBoundingRect();
    //Returns the topLeft Position of the Rectangle that bounds the Circle
    Vec2 getStartVec();
};