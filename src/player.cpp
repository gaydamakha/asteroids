#include "player.h"

#include <utility>

Player::Player()
{
    lifepoints = 0;
    scores = 0;
}

Player::Player(std::shared_ptr<Ship>& newShip)
{
    ship = newShip;
    lifepoints = 0;
    scores = 0;
}

Player::Player(unsigned init_lifepoints, std::shared_ptr<Ship>& newShip)
{
    this->ship = newShip;
    lifepoints = init_lifepoints;
    scores = 0;
}

const Player &Player::reset(const Vec2d &ship_pos, double ship_init_angle)
{
    ship->setVelocity(Vec2d(0., 0.));
    ship->setCoords(ship_pos);
    ship->setAngle(ship_init_angle);
    this->removeLifepoint();

    return *this;
}
