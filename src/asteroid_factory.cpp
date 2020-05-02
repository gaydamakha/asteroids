#include "factories/asteroids_factory.h"

AsteroidsFactory::AsteroidsFactory(const AsteroidsProps& props) : props(props) {}

const AsteroidsFactory &AsteroidsFactory::setProps(const AsteroidsProps &props)
{
    this->props = props;

    return *this;
}

std::shared_ptr<Asteroid> AsteroidsFactory::create(const Vec2d &position, const AsteroidSize &size) const
{
    AsteroidsFactoryDesc desc = props.at(size);
    Vec2d velocity;
    //generate non-zero velocity vector
    do
    {
        velocity = Vec2_aleagen(-desc.max_vel, desc.max_vel, -desc.max_vel, desc.max_vel);
    } while (velocity.getX() == 0 && velocity.getY() == 0);
    // auto shape = *PolygoneFactory::createRandom(desc.min_radius, desc.max_radius, desc.granularity, desc.min_angle_vary, desc.max_angle_vary);
    // shape.translate(position);
    RandomPolygoneDesc p_desc = desc.polygone_desc;
    auto angle_vel_gen = alea_generator(-desc.max_angle_vel, desc.max_angle_vel);
    return std::make_shared<Asteroid>(position, desc.color, velocity, p_desc, angle_vel_gen(), (p_desc.min_radius + p_desc.max_radius) / 2, size);
}

const AsteroidsCollection AsteroidsFactory::broke(Asteroid &a) const
{
    a.broke();
    AsteroidsCollection parts;
    //Get the old desc
    auto old_props = props.find(a.getSize());
    AsteroidsFactoryDesc old_desc = old_props->second;
    //Get the next desc
    auto new_props = ++(old_props);
    if (new_props == props.end())
    {
        //There is no more sizes in the props, the asteroid had the smallest size
        return parts;
    }
    AsteroidSize new_size = new_props->first;

    // Make a generator of random number of parts
    int nb_split = (unsigned)alea_generator(old_desc.min_nb_split, old_desc.max_nb_split)();
    for (unsigned i = 0; i < nb_split; i++)
    {
        parts.push(*(this->create(a.getPosition(), new_size)));
    }

    return parts;
}