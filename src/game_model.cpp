#include <Geometry.h>
#include "game_model.h"

GameModel::GameModel(unsigned game_width, unsigned game_height)
{
    this->game_width = game_width;
    this->game_height = game_height;
    this->max_astr_vel = 0.03;
    this->max_astr_angle_vel = 2.;
}

void GameModel::update()
{
    for (auto& asteroid : asteroids)
    {
        asteroid->step();
        auto position = asteroid->getPosition();
        auto x = position.getX();
        auto y = position.getY();
        if (x < 0)
        {
            asteroid->setPosition(game_width, y);
        }
        else if (x > game_width)
        {
            asteroid->setPosition(0., position.getY());
        }
        if (y < 0)
        {
            asteroid->setPosition(x, game_height);
        }
        else if (y > game_height)
        {
            asteroid->setPosition(x, 0.);
        }
    }
}

void GameModel::addRandomAsteroidWithRandomVelocity()
{
    Vec2d position = Vec2_aleagen(0., (double)game_width, 0., (double)game_height);
    Vec2d velocity;
    do {
        velocity = Vec2_aleagen(-max_astr_vel, max_astr_vel, -max_astr_vel, max_astr_vel);
    } while (velocity.getX() == 0 && velocity.getY() == 0);

    auto angle_gen = alea_generator(-max_astr_angle_vel, max_astr_angle_vel);

    Polygone shape = *PolygoneFactory::createPolygone(position, 30, 50, 20, 25, 7);
    asteroids.push(std::make_shared<Asteroid>(shape, position, velocity, GREEN, angle_gen()));
}