#ifndef ASTEROIDS_FACTORY_H
#define ASTEROIDS_FACTORY_H

#include <Utils.h>
#include "entities/asteroid.h"
#include "collections/asteroids_collection.h"

//TODO: implement an interface
// Contains some static properties, common to all asteroids
// And applies them while creating new asteroids
// This description could be defined for every asteroid size
struct AsteroidsFactoryDesc
{
    //For now only the random configuration could be defined (can be a union RandomPolygoneDesc or a list of Vec2d)
    RandomPolygoneDesc polygone_desc;
    double max_vel;
    double max_angle_vel;
    unsigned min_nb_split;
    unsigned max_nb_split;
    Color color;
};

//Ordering map is used on purpose to pass from one config to another while breaking an asteroid
using AsteroidsProps = std::map<AsteroidSize, AsteroidsFactoryDesc>;

class AsteroidsFactory
{
    AsteroidsProps props;
public:
    AsteroidsFactory() {}

    AsteroidsFactory(const AsteroidsProps &props);

    const AsteroidsFactory &setProps(const AsteroidsProps &props);

    std::shared_ptr<Asteroid> create(const Vec2d &, const AsteroidSize &) const;
    
    const AsteroidsCollection broke(Asteroid &) const;
};

#endif