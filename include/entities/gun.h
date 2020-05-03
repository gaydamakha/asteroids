#ifndef GUN_H
#define GUN_H

#include "factories/bullets_factory.h"

struct GunConfig
{
    double bullets_radius;
    double bullets_vel;
    double bullets_ttl;
    double cooldown;
    Color bullets_color;
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