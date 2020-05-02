#include "entities/bullet.h"

Bullet::Bullet(
    const Vec2d &coords,
    const Color &color,
    const Vec2d &velocity,
    double radius,
    double ttl,
    double timestamp) : MovingParticle(coords, color, velocity), CircleCollider(this->coords, radius), ttl(ttl), created_time(timestamp)
{
    this->broken = false;
}

const Bullet &Bullet::step(double s)
{
    MovingParticle::step(s);
	//Update collider's position
	position = coords;

    return *this;
}