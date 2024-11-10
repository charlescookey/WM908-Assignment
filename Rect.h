#pragma once
#include "Shape.h"

class Rect : public Shape {
private:

public:
    //This is a Vec2 for the X and Y position of the Top left
    Vec2 start;
    //This is a Vec2 for the X and Y position of the Bottom Right
    Vec2 end;
    //Default constructor
    Rect();
    //Constructor with start and end
    Rect(Vec2 _s, Vec2 _e);
    //Constructor with start and width and height
    Rect(Vec2 _s, float width, float height);

    //Returns if a Vec2 is inside the rectangle
    bool inside(Vec2 p);
    //Returns if an X and Y position is inside the rectangle
    bool inside(int a, int b);
    //Returns the area of the Rectangle
    float area();
    //Returns the Height
    float getHeight();
    //Returns the Width
    float getWidth();
};