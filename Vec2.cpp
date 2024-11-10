#include "Vec2.h"


#include <cmath>
#include <iostream>

Vec2::Vec2() {
    x = 0.f;
    y = 0.f;
}

Vec2::Vec2(float a) {
    x = a;
    y = a;
}

Vec2::Vec2(float _x, float _y) :x(_x), y(_y) {}

Vec2::~Vec2() {
}

float Vec2::lenght() {
    return sqrtf((x * x) + (y * y));
}

void Vec2::printXY() {
    std::cout << "X is " << x << " Y is " << y << "\n";
}

Vec2 Vec2::operator+ (const Vec2& addend) {
    Vec2 sum;
    sum.x = x + addend.x;
    sum.y = y + addend.y;
    return sum;
}

Vec2 Vec2::operator- (const Vec2& subend) {
    Vec2 difference;
    difference.x = x - subend.x;
    difference.y = y - subend.y;
    return difference;
}