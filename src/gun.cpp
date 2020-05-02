#include "entities/gun.h"

Gun::Gun(const Vec2d &coords, const double &angle, const GunConfig &c)
    : BulletsFactory(c.bullets_radius, c.bullets_vel, c.bullets_ttl, c.bullets_color), cooldown(c.cooldown), coords(coords), angle(angle)
    {
        this->last_bullet_time = 0.;
    }

BulletsCollection Gun::shoot(double timestamp)
{
    BulletsCollection b;
	//Don't fire unless cooldown period has expired
	if (timestamp - last_bullet_time < cooldown)
	{
		return b;
	}
	last_bullet_time = timestamp;

    return b.push(*(this->create(coords, angle, timestamp)));
}