#pragma once
class Vec2
{
public:
    float x = 0.f;
    float y = 0.f;
    Vec2();

    Vec2(float a);

    Vec2(float _x, float _y);

    ~Vec2();

    float lenght();

    void printXY();

    Vec2 operator+ (const Vec2& addend);

    Vec2 operator- (const Vec2& subend);
};