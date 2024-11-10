#pragma once
#include "Vec2.h"

/// <summary>
/// This is the abstract base class for all shapes
/// </summary>
class Shape {
public:
    //returns if a vector is inside the shape
    virtual bool inside(Vec2 p) = 0;
    //returns the area of the shape
    virtual float area() = 0;
};
