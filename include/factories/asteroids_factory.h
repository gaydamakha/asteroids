#ifndef ASTEROIDS_FACTORY_H
#define ASTEROIDS_FACTORY_H

#include <Utils.h>
#include "entities/asteroid.h"
#include "collections/asteroids_collection.h"
//TODO: implement an interface
// Contains some static properties, common to all asteroids
// And applies them while creating new asteroids
class AsteroidsFactory
{
    double max_vel;
    Color color;
    std::unique_ptr<RandomGenerator<int>> nb_split_gen;
    std::unique_ptr<RandomGenerator<double>> angle_vel_gen;
public:
    AsteroidsFactory(double, double, unsigned, unsigned, const Color&);
    std::shared_ptr<Asteroid>  create(const Vec2d &, const AsteroidSize &) const;
    const AsteroidsCollection broke(Asteroid&) const;
};

#endif