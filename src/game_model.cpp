#include <Geometry.h>
#include "game_model.h"

GameModel::GameModel(unsigned game_width, unsigned game_height)
{
    this->game_width = game_width;
    this->game_height = game_height;
    //TODO: move to a config entity
    this->max_astr_vel = 0.05;
    this->max_astr_angle_vel = 0.05;

    this->max_ship_vel = 0.3;
    this->max_ship_acc = 0.5;
    this->ship_jerk = 0.0005;
    // this->max_ship_angle_vel = 3.;
    // this->ship_angle_acc_step = 0.02;
    this->env_resistence = 0.00005;
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

    for (auto& ship: ships)
    {
        ship->step();
        //fix it
        // ship->slow(env_resistence);
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
    Vec2d acceleration(0., 0.);
    do {
        velocity = Vec2_aleagen(-max_astr_vel, max_astr_vel, -max_astr_vel, max_astr_vel);
    } while (velocity.getX() == 0 && velocity.getY() == 0);

    auto angle_gen = alea_generator(-max_astr_angle_vel, max_astr_angle_vel);

    Polygone shape = *PolygoneFactory::createRandomPolygone(position, 30, 50, 20, 25, 7);
    asteroids.push(std::make_shared<Asteroid>(
                                    position,
                                    GREEN,
                                    velocity,
                                    acceleration,
                                    0., max_astr_vel,
                                    0., 0.,
                                    angle_gen(),
                                    shape));
}

void GameModel::addShipAtCenter(Vec2d direction)
{
    Vec2d position(game_width/2, game_height/2);
    Vec2d velocity(0., 0.);
    Vec2d acceleration(0., 0.);
    Polygone shape = *PolygoneFactory::createPolygone(position, Vec2d(0, 22), Vec2d(-16, -22), Vec2d(0, -16), Vec2d(16, -22));
    auto vertices = shape.getData();
	double angle;
    ships.push(std::make_shared<Ship>(
                                    position,
                                    GREEN,
                                    velocity,
                                    acceleration,
                                    0, max_ship_vel,
                                    0, max_ship_acc,
                                    0.,
                                    shape,
                                    direction,
                                    ship_jerk));
}

void GameModel::accelerateShips()
{
    for (auto& ship : ships)
    {
        ship->accelerate();
    }
}

void GameModel::rotateShipsLeft()
{
    for (auto& ship : ships)
    {
        ship->rotateLeft();
    }
}

void GameModel::rotateShipsRight()
{
    for (auto& ship : ships)
    {
        ship->rotateRight();
    }
}