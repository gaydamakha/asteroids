#include "factories/bullets_factory.h"

BulletsFactory::BulletsFactory(
    double radius,
    double vel,
    double ttl,
    const Color &color) : bullets_radius(radius), bullets_vel(vel), bullets_ttl(ttl), bullets_color(color) {}

std::shared_ptr<Bullet> BulletsFactory::create(const Vec2d &pos, double angle, double timestamp) const
{
    Vec2d vel = Vec2d(bullets_vel, 0.).rotate(angle);
    return std::make_shared<Bullet>(pos, bullets_color, vel, bullets_radius, bullets_ttl, timestamp);
}
