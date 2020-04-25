#ifndef COLLIDER_H
#define COLLIDER_H

#include "shape.h"

class Collider
{
protected:
    Vec2d position;
    const std::shared_ptr<Shape> shape;

public:
    Collider(const Vec2d &position, const std::shared_ptr<Shape> s) : shape(s) { this->position = position; }
    virtual const bool isCollision(const Collider &) = 0;

    inline const std::shared_ptr<Shape> getShape() const { return shape; }

    inline Vec2d getPosition() const { return position; }

    inline void setPosition(const Vec2d& p) { position = p; }
};

#endif