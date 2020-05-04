#ifndef RECTANGLE_COLLIDER_H
#define RECTANGLE_COLLIDER_H

#include "Geometry.h"
#include "rectangle.h"
#include "collider.h"

class RectangleCollider : public Collider
{
public:
    RectangleCollider(const Vec2d &position, double x, double y) : Collider(position, std::make_shared<Rectangle>(x, y))
    {
        this->shape->translate(position);
    }

    bool isCollision(const Collider &c)
    {
        // const std::shared_ptr<Rectangle> col1 = std::static_pointer_cast<Rectangle>(this->shape);
        // const std::shared_ptr<Shape> shape2 = c.getColliderShape();
        // if (std::shared_ptr<Circle> col2 = std::dynamic_pointer_cast<Circle>(shape2))
        // {
        //     double rad1 = col1->getRadius();
        //     double rad2 = col2->getRadius();
        //     double distance = position.getDistance(c.getPosition());
        //     return (distance <= rad1 + rad2);
        // }
        // else
        // {
        //     std::cout << "Unknown collision!" << std::endl;
        // }
        return false;
    }

    bool isInside(const Vec2d &v)
    {
        const std::shared_ptr<Rectangle> col1 = std::static_pointer_cast<Rectangle>(this->shape);
        auto vertices = col1->getVertices();
        bool res = true;
        for (auto i = vertices.begin(); i < --vertices.end(); ++i)
        {
            auto v1 = **i;
            auto v2 = **vertices.next(i);
            res = res && isPointOnLeft(v, v1, v2);
        }
        auto last = **(--vertices.end());
        auto first = **vertices.begin();
        return res && isPointOnLeft(v, last, first);
    }
};

#endif