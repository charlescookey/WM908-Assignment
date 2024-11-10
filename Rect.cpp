#include "Rect.h"
Rect::Rect() {
    start = Vec2();
    end = Vec2();
}

Rect::Rect(Vec2 _s, Vec2 _e) {
    start = _s;
    end = _e;
}

Rect::Rect(Vec2 _s, float width, float height) {
    start = _s;
    end = _s;
    end.x += width;
    end.y += height;
}
/// <summary>
/// Returns if a Vec2 points is inside the rectange
/// </summary>
/// <param name="p">Vec2 point p</param>
/// <returns>true if the Point is inside the rectangle</returns>
bool Rect::inside(Vec2 p) {
    if (p.x <= end.x && p.x >= start.x) {
        if (p.y <= end.y && p.y >= start.y) {
            return true;
        }
    }
    return false;
}
/// <summary>
/// Returns if a point X and Y is inside the rectange
/// </summary>
/// <param name="a">X position</param>
/// <param name="b">Y poistion</param>
/// <returns>true if the Point is inside the rectangle</returns>
bool Rect::inside(int a, int b) {
    float X = static_cast<float>(a);
    float Y = static_cast<float>(b);

    if (X <= end.x && X >= start.x) {
        if (Y <= end.y && Y >= start.y) {
            return true;
        }
    }
    return false;
};


float Rect::area() {
    float xs;
    float ys;

    xs = end.x - start.x;
    ys = end.y - start.y;
    return (xs * ys);
}

float Rect::getHeight() {
    return end.y - start.y;
};

float Rect::getWidth() {
    return end.x - start.x;
};