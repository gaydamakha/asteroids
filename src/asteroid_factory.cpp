#include "factories/asteroids_factory.h"

AsteroidsFactory::AsteroidsFactory(double max_vel, double max_angle_vel, unsigned min_nb_split, unsigned max_nb_split, const Color &color)
{
    this->max_vel = max_vel;
    this->angle_vel_gen = std::make_unique<RandomGenerator<double>>(alea_generator(-max_angle_vel, max_angle_vel));
    this->nb_split_gen = std::make_unique<RandomGenerator<int>>(alea_generator((int)min_nb_split, (int)max_nb_split));
    this->color = color;
}

std::shared_ptr<Asteroid> AsteroidsFactory::create(const Vec2d &position, const AsteroidSize &size) const
{
    Vec2d velocity;
    //generate non-zero velocity vector
    do
    {
        velocity = Vec2_aleagen(-max_vel, max_vel, -max_vel, max_vel);
    } while (velocity.getX() == 0 && velocity.getY() == 0);

    AsteroidDesc desc = Asteroid::props.at(size);
    auto shape = *PolygoneFactory::createRandom(position, desc.min_radius, desc.max_radius, desc.granularity, desc.min_angle_vary, desc.max_angle_vary);
    return std::make_shared<Asteroid>(position, color, velocity, shape, (*angle_vel_gen)(), (desc.min_radius + desc.max_radius) / 2, size);
}

const AsteroidsCollection AsteroidsFactory::broke(Asteroid &a) const
{
    a.broke();
    AsteroidsCollection parts;
    //Get the next desc
    auto new_props = ++(Asteroid::props.find(a.getSize()));
    if (new_props == Asteroid::props.end())
    {
        //There is no more sizes in the props, the asteroid had the smallest size
        return parts;
    }
    AsteroidSize new_size = new_props->first;
    AsteroidDesc new_desc = new_props->second;
    for (unsigned i = 0; i < (*nb_split_gen)(); i++)
    {
        parts.push(*(this->create(a.getPosition(), new_size)));
    }

    return parts;
}