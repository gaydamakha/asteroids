#include <Geometry.h>
#include "game_model.h"

GameModel::GameModel(unsigned game_width, unsigned game_height)
{
    this->game_width = game_width;
    this->game_height = game_height;
    //TODO: move to a config entity
    this->max_astr_vel = 50.0;       // pixels per second
    this->max_astr_angle_vel = 40.0; // degrees per second

    this->ship_acc = 0.6;       // pixels/second per second
    this->ship_angle_acc = 0.1; // Degrees per one rotation
    this->env_resistence = 0.001;
}

void GameModel::update(double seconds)
{
    for (auto &asteroid : asteroids)
    {
        asteroid->step(seconds);
        auto position = asteroid->getPosition();
        auto x = position.getX();
        auto y = position.getY();
        if (x < 0)
        {
            asteroid->setPosition(Vec2d(game_width, y));
        }
        else if (x > game_width)
        {
            asteroid->setPosition(Vec2d(0., position.getY()));
        }
        if (y < 0)
        {
            asteroid->setPosition(Vec2d(x, game_height));
        }
        else if (y > game_height)
        {
            asteroid->setPosition(Vec2d(x, 0.));
        }
    }

    for (auto &ship : ships)
    {
        ship->step(seconds);
        ship->slow(env_resistence);
        auto position = ship->getPosition();
        auto x = position.getX();
        auto y = position.getY();
        if (x < 0)
        {
            ship->setPosition(Vec2d(game_width, y));
        }
        else if (x > game_width)
        {
            ship->setPosition(Vec2d(0., position.getY()));
        }
        if (y < 0)
        {
            ship->setPosition(Vec2d(x, game_height));
        }
        else if (y > game_height)
        {
            ship->setPosition(Vec2d(x, 0.));
        }
    }
}

void GameModel::addRandomAsteroidWithRandomVelocity()
{
    Vec2d position = Vec2_aleagen(0., (double)game_width, 0., (double)game_height);
    Vec2d velocity;
    do
    {
        velocity = Vec2_aleagen(-max_astr_vel, max_astr_vel, -max_astr_vel, max_astr_vel);
    } while (velocity.getX() == 0 && velocity.getY() == 0);

    auto angle_gen = alea_generator(-max_astr_angle_vel, max_astr_angle_vel);

    Polygone shape = *PolygoneFactory::createRandomPolygone(position, 30, 50, 20, 25, 7);
    asteroids.push(Asteroid(position, GREEN, velocity, shape, angle_gen()));
}

void GameModel::addShipAtCenter(double init_angle)
{
    Vec2d position(game_width / 2, game_height / 2);
    Vec2d velocity(0., 0.);
    Polygone shape = *PolygoneFactory::createPolygone(position, Vec2d(0, -22), Vec2d(16, 22), Vec2d(0, 16), Vec2d(-16, 22));
    ships.push(Ship(position, GREEN, velocity, shape, ship_angle_acc, init_angle, ship_acc));
}

void GameModel::accelerateShips()
{
    for (auto &ship : ships)
    {
        ship->accelerate();
    }
}

void GameModel::rotateShipsLeft()
{
    for (auto &ship : ships)
    {
        ship->rotateLeft();
    }
}

void GameModel::rotateShipsRight()
{
    for (auto &ship : ships)
    {
        ship->rotateRight();
    }
}

void GameModel::resetShips(double angle)
{
    Vec2d center(game_width / 2, game_height / 2);
    for (auto &ship : ships)
    {
        //TODO: when points system will be added, remove one life-point
        ship->setVelocity(Vec2d(0., 0.));
        ship->setPosition(center);
        //TODO:uncomment it when the view will be capable to rotate the ship
        // ship->setAngle(angle);
    }
}