#include <Geometry.h>
#include "game_model.h"

void GameModel::update()
{
    for (auto& asteroid : asteroids)
    {
        asteroid->step();
    }
}

void GameModel::addRandomAsteroidWithRandomVelocity()
{
    Vec2d position = Vec2_aleagen(0., (double)game_width, 0., (double)game_height);
    Vec2d velocity;
    do {
        velocity = Vec2_aleagen(-max_astr_vel, max_astr_vel, -max_astr_vel, max_astr_vel);
    } while (velocity.getX() == 0 && velocity.getY() == 0);

    using namespace PolygoneFactory;
    Polygone shape = *PolygoneFactory::createPolygone(30, 50, 20, 25, 7);
    asteroids.push(std::make_shared<Asteroid>(shape, position, velocity, GREEN));
}