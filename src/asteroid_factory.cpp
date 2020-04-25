#include <Geometry.h>
#include "factories/asteroid_factory.h"

Asteroid* AsteroidFactory::create(
    const Vec2d& position,
    const Color& color,
    const Vec2d& velocity,
    double angle,
    const AsteroidDesc& desc,
    const AsteroidSize& size)
{
    auto shape = *PolygoneFactory::createRandom(position, desc[0], desc[1], desc[2], desc[3], desc[4]);
    return new Asteroid(position, color, velocity, shape, angle, (desc[0] + desc[1])/2, size);
}