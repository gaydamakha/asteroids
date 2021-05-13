#include <Geometry.h>
#include "sdl_timer.h"
#include "game_model.h"

GameModel::GameModel(unsigned game_width, unsigned game_height, GameLevelsCollection &levels)
{
    this->game_over = false;
    this->game_began = false;
    this->game_width = game_width;
    this->game_height = game_height;
    this->levels.moveFrom(levels);
    this->levels.sort();
    player = std::make_unique<Player>();
    asteroids_factory = std::make_unique<AsteroidsFactory>();
}

const GameModel &GameModel::setLevel(const GameLevelsCollection::Iterator &level)
{
    asteroids.clear();
    bullets.clear();
    current_level = level;
    //No way to create a ship without config -> rebuild the ship
    ship.reset(); //the reset of the shared pointer
    ship = std::make_shared<Ship>((*current_level)->ship_config);
    player->addLifepoints((*current_level)->player_lifepoints);
    player->setShip(ship);
    asteroids_factory->setProps((*current_level)->asteroids_props);
    //Add asteroids
    for (auto &config : (*current_level)->asteroids_amount)
    {
        for (int i = 0; i < config.second; i++)
        {
            this->addAsteroid(config.first);
        }
    }
    return *this;
}

void GameModel::begin()
{
    if (game_began)
    {
        return;
    }
    if (levels.getSize() == 0)
    {
        std::cerr << "No level is loaded!" << std::endl;
        return;
    }
    this->setLevel(levels.begin());
    //At last, rebuild a timer
    timer.reset();
    timer = std::make_unique<SdlTimer>();
    game_began = true;
    game_over = false;
}

void GameModel::update()
{
    //Forbid to update the game until it is began
    if (!game_began || game_over)
    {
        return;
    }
    //Get number of seconds passed in the previous loop (0 if it's the first iteration)
    double seconds = timer->getDelta();
    ship->step(seconds);
    ship->slow((*current_level)->env_resistance);
    this->checkBorders(*ship);

    AsteroidsCollection new_asteroids;

    for (auto &bullet : bullets)
    {
        bullet->step(seconds);
        this->checkBorders(*bullet);
        //Check if bullet is shot into
        for (auto &asteroid : asteroids)
        {
            if (asteroid->isCollision(*bullet))
            {
                player->addScore();
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
            this->resetPlayer();
        }
    }

    //Remove broken asteroids
    asteroids.filter([this](std::shared_ptr<Asteroid> a) -> bool { return a->toRemove(timer->getTimestamp()); });
    bullets.filter([this](std::shared_ptr<Bullet> b) -> bool { return b->toRemove(timer->getTimestamp()); });
    //Push new asteroids created while breaking others
    asteroids.moveFrom(new_asteroids);

    //All asteroids are broken -> pass to the next level
    if (asteroids.getSize() == 0)
    {
        //If not the last level
        auto next_level = levels.next(current_level);
        if (next_level != levels.end())
        {
            this->setLevel(next_level);
        }
        else
        {
            game_began = false;
        }
    }
}

const Particle &GameModel::checkBorders(Particle &p) const
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

    return p;
}

void GameModel::addAsteroid(AsteroidSize size)
{
    //TODO: verify that asteroid won't collide with ship on the spawn
    Vec2d position = Vec2_aleagen(0., (double)game_width, 0., (double)game_height);
    asteroids.push(*asteroids_factory->create(position, size));
}

void GameModel::accelerateShip()
{
    if (!game_began || game_over)
    {
        return;
    }
    ship->accelerate();
}

void GameModel::rotateShipLeft()
{
    if (!game_began || game_over)
    {
        return;
    }
    ship->rotateLeft();
}

void GameModel::rotateShipRight()
{
    if (!game_began || game_over)
    {
        return;
    }
    ship->rotateRight();
}

void GameModel::resetPlayer()
{
    ShipConfig sc = (*current_level)->ship_config;
    player->reset(sc.init_position, sc.init_angle);
    if (player->getLifepoints() == 0)
    {
        game_began = false;
        game_over = true;
        player->resetScores();
    }
}

void GameModel::shoot()
{
    if (!game_began || game_over)
    {
        return;
    }
    BulletsCollection new_bullets = ship->shoot(timer->getTimestamp());
    bullets.moveFrom(new_bullets);
}

GameStats GameModel::getStats() const
{
    return {
        player->getLifepoints(),
        player->getScores(),
        player->getHighscores(),
        (*current_level)->name
    };
}
