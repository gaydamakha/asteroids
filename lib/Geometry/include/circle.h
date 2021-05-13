#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "vec2.h"

class Circle : public Shape
{
    const double radius;

public:
    Circle(double radius) : radius(radius) {}

    inline const bool isClosed() const override { return true; }

    inline const Circle& translate(const Vec2d &v) override { return *this;}

    inline const Circle& rotate(const Vec2d &, double) override { return *this; }

    inline const double getRadius() const { return radius; }
};

#endif