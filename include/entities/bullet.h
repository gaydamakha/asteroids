#ifndef BULLET_H
#define BULLET_H

#include <Geometry.h>
#include "moving_particle.h"
#include "sprint_view_game_entity.h"

class Bullet : public MovingParticle, public CircleCollider, public SprintViewGameEntity
{
protected:
    const double created_time;
    const double ttl;
    bool broken;
public:
    Bullet(const Vec2d &coords, const Color &color, const Vec2d &velocity, double radius, double ttl, double timestamp);

    void step(double);

    inline bool toRemove(double timestamp)
    {
        return (this->isBroken()) || (timestamp - created_time >= ttl);
    }

    inline void broke() { broken = true; }

    inline bool isBroken() { return broken; }
};

#endif