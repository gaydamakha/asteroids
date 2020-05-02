#ifndef GUN_H
#define GUN_H

#include "factories/bullets_factory.h"

struct GunConfig
{
    const double bullets_radius;
    const double bullets_vel;
    const double bullets_ttl;
    const double cooldown;
    const Color bullets_color;
};

class Gun : public BulletsFactory
{
protected:
    //These properties will update with the ship's values
    //Position where the gun is "installed"
    const Vec2d &coords;
    const double &angle;
    const double cooldown;
    double last_bullet_time;

public:
    Gun(const Vec2d &, const double &, const GunConfig &);
    BulletsCollection shoot(double);
};

#endif