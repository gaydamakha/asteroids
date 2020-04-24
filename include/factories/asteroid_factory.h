#ifndef ASTEROID_FACTORY_H
#define ASTEROID_FACTORY_H

#include <array>
#include "entities/asteroid.h"

using AsteroidDesc = std::array<double, 5>;

namespace AsteroidFactory
{
Asteroid* create(const Vec2d&, const Color&, const Vec2d&, double, const AsteroidDesc&, const AsteroidSize&);
}

#endif