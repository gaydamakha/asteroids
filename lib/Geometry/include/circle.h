#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "vec2.h"

class Circle : public Shape
{
    const double radius;

public:
    Circle(double radius) : radius(radius) {}

    inline const bool isCircular() const { return true; }

    inline const void translate(const Vec2d &v) {}

    inline const void rotate(const Vec2d &, double) {}

    inline const double getRadius() const { return radius; }
};

#endif