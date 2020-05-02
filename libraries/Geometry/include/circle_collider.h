#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include "circle.h"
#include "collider.h"

class CircleCollider : public Collider
{
public:
    CircleCollider(const Vec2d &position, double rad) : Collider(position, std::make_shared<Circle>(rad)) {}

    bool isCollision(const Collider &c)
    {
        const std::shared_ptr<Circle> col1 = std::static_pointer_cast<Circle>(this->shape);
        const std::shared_ptr<Shape> shape2 = c.getShape();
        if (std::shared_ptr<Circle> col2 = std::dynamic_pointer_cast<Circle>(shape2))
        {
            double rad1 = col1->getRadius();
            double rad2 = col2->getRadius();
            double distance = position.getDistance(c.getPosition());
            return (distance <= rad1 + rad2);
        }
        else
        {
            std::cout << "Unknown collision!" << std::endl;
        }
        return false;
    }
};

#endif