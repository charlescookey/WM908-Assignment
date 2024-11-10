#include "Circle.h"
#include "Rect.h"


# define PI_F           3.14159265358979323846

Circle::Circle() {
    center = Vec2();
    radius = 0.f;
};

Circle::Circle(Vec2 _center, float _radius) {
    center = _center;
    radius = _radius;
};

Circle::Circle(Vec2 _center, int _radius) {
    center = _center;
    radius = static_cast<float>(_radius);
};

bool Circle::inside(Vec2 p) {
    Vec2 distVec = p - center;
    float dist = distVec.lenght();
    return dist < radius;
};

bool Circle::inside(int x, int y) {
    Vec2 p(x, y);
    Vec2 distVec = p - center;
    float dist = distVec.lenght();
    return dist < radius;
};

float Circle::area() {
    return PI_F * radius * radius;
};


/// <summary>
/// Returns the rectangle that bounds the circle
/// </summary>
/// <returns>Rectangle bounding the circle</returns>
Rect Circle::getBoundingRect() {
    Vec2 start = center - Vec2(radius);
    Vec2 end = center - Vec2(radius);
    return Rect(start, end);
};

/// <summary>
/// Returns the topLeft Position of the Rectangle that bounds the Circle
/// </summary>
/// <returns>Vec2 of top left</returns>
Vec2 Circle::getStartVec() {
    return center - Vec2(radius);

};