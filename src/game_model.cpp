#include <Geometry.h>
#include "sdl_timer.h"
#include "game_model.h"
#include "entities/bullet.h"

//TODO: define it using config entity?

//TODO: take a config entity in parameters instead
GameModel::GameModel(unsigned game_width, unsigned game_height)
{
    this->game_width = game_width;
    this->game_height = game_height;
    //TODO: fetch numbers from config entity
    this->asteroids_factory = std::make_unique<AsteroidsFactory>(50.0, 50.0, 2, 2, GREEN);
    //TODO: fetch numbers from config entity
	this->ship_init_angle = 270.0;
    this->ship_acc = 0.3;       // pixels/second per second
    this->ship_angle_acc = 0.2; // Degrees per one rotation
    this->bullet_cd = 0.5;       // seconds
    this->bullets_vel = 300.;
    this->bullets_ttl = 2.;
    this->bullets_size = 5.;
    this->env_resistence = 0.0008;
    timer = std::make_unique<SdlTimer>();
}

void GameModel::update()
{
    //Get number of seconds passed in the previous loop (0 if it's the first iteration)
    double seconds = timer->getDelta();
    ship->step(seconds);
    ship->slow(env_resistence);
    this->checkBorders(*ship);

    AsteroidsCollection new_asteroids;

    for (auto& bullet: bullets)
    {
        bullet->step(seconds);
        this->checkBorders(*bullet);
        //Check if bullet is shot into
        for (auto &asteroid: asteroids)
        {
            if (asteroid->isCollision(*bullet))
            {
                new_asteroids = asteroids_factory->broke(*asteroid);
                bullet->broke();
            }
        }
    }

    for (auto &asteroid : asteroids)
    {
        asteroid->step(seconds);
        this->checkBorders(*asteroid);
        //Check if ship is crashed into asteroid
        if (asteroid->isCollision(*ship))
        {
            new_asteroids = asteroids_factory->broke(*asteroid);
            this->resetShip();
        }
    }

    //Remove broken asteroids
    asteroids.filter([this](std::shared_ptr<Asteroid> a) -> bool { return a->toRemove(timer->getTimestamp()); });
    bullets.filter([this](std::shared_ptr<Bullet> b) -> bool { return b->toRemove(timer->getTimestamp()); });
    //Push new asteroids created while breaking others
    asteroids.moveFrom(new_asteroids);
}

void GameModel::checkBorders(MovingParticle &p) const
{
    auto position = p.getCoords();
    auto x = position.getX();
    auto y = position.getY();
    if (x < 0)
    {
        p.setCoords(Vec2d(game_width, y));
    }
    else if (x > game_width)
    {
        p.setCoords(Vec2d(0., position.getY()));
    }
    if (y < 0)
    {
        p.setCoords(Vec2d(x, game_height));
    }
    else if (y > game_height)
    {
        p.setCoords(Vec2d(x, 0.));
    }
}

//TODO: make private and called during config processing
void GameModel::addAsteroid(AsteroidSize size)
{
    //TODO: verify that asteroid won't collide with ship on the spawn
    Vec2d position = Vec2_aleagen(0., (double)game_width, 0., (double)game_height);
    asteroids.push(*asteroids_factory->create(position, size));
}

//TODO: make it private and called during config processing
void GameModel::addShipAtCenter()
{
    Vec2d position(game_width / 2, game_height / 2);
    Vec2d velocity(0., 0.);
    Polygone shape = *PolygoneFactory::create(position, Vec2d(0, -22), Vec2d(16, 22), Vec2d(0, 16), Vec2d(-16, 22));
    ship = std::make_shared<Ship>(
        position,
        GREEN,
        velocity,
        shape,
        ship_angle_acc,
        22,
        ship_init_angle,
        ship_acc,
        bullet_cd,
        bullets_vel,
        bullets_size,
        bullets_ttl,
        GREEN);
}

void GameModel::accelerateShip()
{
    ship->accelerate();
}

void GameModel::rotateShipLeft()
{
    ship->rotateLeft();
}

void GameModel::rotateShipRight()
{
    ship->rotateRight();
}

void GameModel::resetShip()
{
    Vec2d center(game_width / 2, game_height / 2);
    //TODO: when points system will be added, remove one life-point
    ship->setVelocity(Vec2d(0., 0.));
    ship->setCoords(center);
    //TODO:uncomment it when the view will be capable to rotate the ship
    ship->setAngle(ship_init_angle);
}

void GameModel::shoot()
{
    BulletsCollection new_bullets = ship->shoot(timer->getTimestamp());
    bullets.moveFrom(new_bullets);
}
