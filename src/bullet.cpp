#include "entities/bullet.h"

Bullet::Bullet(
    const Vec2d &coords,
    const Color &color,
    const Vec2d &velocity,
    double radius,
    double ttl,
    double timestamp) : MovingParticle(coords, color, velocity), CircleCollider(coords, radius), ttl(ttl), created_time(timestamp)
{
    this->broken = false;
}

void Bullet::step(double s)
{
    MovingParticle::step(s);
    // Update collider's position
    this->setPosition(coords);
}