#ifndef BULLET_H
#define BULLET_H

#include <Geometry.h>
#include "moving_particle.h"

class Bullet : public MovingParticle, public CircleCollider
{
protected:
    const double created_time;
    const double ttl;
    bool broken;

public:
    Bullet(const Vec2d &coords, const Color &color, const Vec2d &velocity, double radius, double ttl, double timestamp);

    const Bullet &step(double) override;

    inline bool toRemove(double timestamp) { return (this->isBroken()) || (timestamp - created_time >= ttl); }

    inline const Bullet &broke() { broken = true; return *this; }

    inline bool isBroken() { return broken; }
};

#endif