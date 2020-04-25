#include <bits/stdc++.h>
#include <Geometry.h>
#include "game_model.h"

const std::map<AsteroidSize, AsteroidDesc> GameModel::asteroids_config = {
    {AsteroidSize::BIG, {30, 50, 20, 25, 7}},
    {AsteroidSize::MEDIUM, {20, 32, 20, 25, 7}},
    {AsteroidSize::SMALL, {10, 20, 15, 25, 7}}};

//TODO: take a config entity in parameters instead
GameModel::GameModel(unsigned game_width, unsigned game_height)
{
    this->game_width = game_width;
    this->game_height = game_height;
    //TODO: move to a config entity
    this->max_astr_vel = 50.0;       // pixels per second
    this->max_astr_angle_vel = 50.0; // degrees per second

    this->ship_acc = 0.3;       // pixels/second per second
    this->ship_angle_acc = 0.2; // Degrees per one rotation
    this->env_resistence = 0.0008;
}

void GameModel::update(double seconds)
{
    for (auto &ship : ships)
    {
        ship->step(seconds);
        ship->slow(env_resistence);
        this->checkBorders(*ship);
        for (auto a = asteroids.begin(); a < asteroids.end(); a++)
        {
            auto asteroid = *a;
            asteroid->step(seconds);
            this->checkBorders(*asteroid);
            //Check the collision - stupid way
            auto coll = std::static_pointer_cast<Circle>(asteroid->getCollider());
            double arad = coll->getRadius();
            double srad = ship->getRadius();
            double distance = asteroid->getPosition().getDistance(ship->getPosition());
            if (distance <= arad + srad)
            {
                // Split asteroids in 2 parts
                Vec2d a_position = asteroid->getPosition();
                Vec2d a_velocity = asteroid->getVelocity();
                AsteroidSize a_size = asteroid->getSize();
                auto angle_gen = alea_generator(-max_astr_angle_vel, max_astr_angle_vel);
                switch (a_size)
                {
                case AsteroidSize::BIG:
                    //create 2 medium asteroids
                    new_asteroids.push(*AsteroidFactory::create(a_position, GREEN, a_velocity.rotate(Vec2d(0., 0.), 90.), angle_gen(), asteroids_config.at(AsteroidSize::MEDIUM), AsteroidSize::MEDIUM));
                    new_asteroids.push(*AsteroidFactory::create(a_position, GREEN, a_velocity.rotate(Vec2d(0., 0.), -90.), angle_gen(), asteroids_config.at(AsteroidSize::MEDIUM), AsteroidSize::MEDIUM));
                    break;
                case AsteroidSize::MEDIUM:
                    //Create 2 small asteroids
                    new_asteroids.push(*AsteroidFactory::create(a_position, GREEN, a_velocity.rotate(Vec2d(0., 0.), 90.), angle_gen(), asteroids_config.at(AsteroidSize::SMALL), AsteroidSize::SMALL));
                    new_asteroids.push(*AsteroidFactory::create(a_position, GREEN, a_velocity.rotate(Vec2d(0., 0.), -90.), angle_gen(), asteroids_config.at(AsteroidSize::SMALL), AsteroidSize::SMALL));
                    break;
                case AsteroidSize::SMALL:
                    //Do nothing
                    break;
                }
                asteroid->broke();
                this->resetShip(*ship);
            }
        }
    }
    //Remove broken asteroid
    asteroids.filter([](std::shared_ptr<Asteroid> a) -> bool { return a->isBroken(); });
    //Push new asteroids created while breaking others
    asteroids.moveFrom(new_asteroids);
}

void GameModel::checkBorders(MovingParticle &p) const
{
    auto position = p.getPosition();
    auto x = position.getX();
    auto y = position.getY();
    if (x < 0)
    {
        p.setPosition(Vec2d(game_width, y));
    }
    else if (x > game_width)
    {
        p.setPosition(Vec2d(0., position.getY()));
    }
    if (y < 0)
    {
        p.setPosition(Vec2d(x, game_height));
    }
    else if (y > game_height)
    {
        p.setPosition(Vec2d(x, 0.));
    }
}

//TODO: make private
void GameModel::addAsteroid(AsteroidSize size)
{
    Vec2d position = Vec2_aleagen(0., (double)game_width, 0., (double)game_height);
    Vec2d velocity;
    do
    {
        velocity = Vec2_aleagen(-max_astr_vel, max_astr_vel, -max_astr_vel, max_astr_vel);
    } while (velocity.getX() == 0 && velocity.getY() == 0);

    auto angle_gen = alea_generator(-max_astr_angle_vel, max_astr_angle_vel);
    asteroids.push(*AsteroidFactory::create(position, GREEN, velocity.rotate(Vec2d(0., 0.), 90.), angle_gen(), asteroids_config.at(size), size));
}

void GameModel::addShipAtCenter(double init_angle)
{
    Vec2d position(game_width / 2, game_height / 2);
    Vec2d velocity(0., 0.);
    Polygone shape = *PolygoneFactory::create(position, Vec2d(0, -22), Vec2d(16, 22), Vec2d(0, 16), Vec2d(-16, 22));
    ships.push(Ship(position, GREEN, velocity, shape, ship_angle_acc, 22, init_angle, ship_acc));
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

void GameModel::resetShip(Ship &ship)
{
    Vec2d center(game_width / 2, game_height / 2);
    //TODO: when points system will be added, remove one life-point
    ship.setVelocity(Vec2d(0., 0.));
    ship.setPosition(center);
    //TODO:uncomment it when the view will be capable to rotate the ship
    // ship->setAngle(angle);
}

//TODO: move it somewhere?
void GameModel::splitAsteroid()
{
    auto asteroid = asteroids.begin();
    Vec2d a_position = (*asteroid)->getPosition();
    Vec2d a_velocity = (*asteroid)->getVelocity();
    AsteroidSize a_size = (*asteroid)->getSize();
    asteroids.erase(asteroid);
    auto angle_gen = alea_generator(-max_astr_angle_vel, max_astr_angle_vel);
    switch (a_size)
    {
    case AsteroidSize::BIG:
        //create 2 medium asteroids
        asteroids.push(*AsteroidFactory::create(a_position, GREEN, a_velocity.rotate(Vec2d(0., 0.), 90.), angle_gen(), asteroids_config.at(AsteroidSize::MEDIUM), AsteroidSize::MEDIUM));
        asteroids.push(*AsteroidFactory::create(a_position, GREEN, a_velocity.rotate(Vec2d(0., 0.), -90.), angle_gen(), asteroids_config.at(AsteroidSize::MEDIUM), AsteroidSize::MEDIUM));
        break;
    case AsteroidSize::MEDIUM:
        //Create 2 small asteroids
        asteroids.push(*AsteroidFactory::create(a_position, GREEN, a_velocity.rotate(Vec2d(0., 0.), 90.), angle_gen(), asteroids_config.at(AsteroidSize::SMALL), AsteroidSize::SMALL));
        asteroids.push(*AsteroidFactory::create(a_position, GREEN, a_velocity.rotate(Vec2d(0., 0.), -90.), angle_gen(), asteroids_config.at(AsteroidSize::SMALL), AsteroidSize::SMALL));
        break;
    case AsteroidSize::SMALL:
        //Do nothing
        break;
    }
}
