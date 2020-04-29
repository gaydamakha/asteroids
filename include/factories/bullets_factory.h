#ifndef BULLETS_FACTORY_H
#define BULLETS_FACTORY_H

#include <Utils.h>
#include "entities/bullet.h"
#include "collections/bullets_collection.h"
//TODO: implement an interface
// Contains some static properties, common to all bullets
// And applies them while creating new bullets
class BulletsFactory
{
    const double bullets_radius;
    const double bullets_vel;
    const double bullets_ttl;
    const Color& bullets_color;
public:
    BulletsFactory(double, double, double, const Color&);
    //Position, angle(to define velocity direction) and timestamp should be defined dynamically
    std::shared_ptr<Bullet> create(const Vec2d &, double angle, double timestamp) const;
};

#endif