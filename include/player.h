#ifndef PLAYER_H
#define PLAYER_H

#include "entities/ship.h"

class Player
{
    unsigned lifepoints;
    unsigned scores;
    unsigned highscores;
    std::shared_ptr<Ship> ship;

public:
    Player() {}

    Player(std::shared_ptr<Ship> ship);

    Player(unsigned init_lifepoints, std::shared_ptr<Ship> ship);

    inline const Player &addScore()
    {
        scores++;
        highscores++;

        return *this;
    }
    inline const Player &resetScores()
    {
        scores = 0;
        return *this;
    }
    inline unsigned getScores() { return scores; }

    inline const Player &addLifepoint()
    {
        lifepoints++;
        return *this;
    }

    inline const Player &addLifepoints(unsigned lfs)
    {
        lifepoints += lfs;
        return *this;
    }

    inline const Player &removeLifepoint()
    {
        if (lifepoints > 0)
        {
            lifepoints--;
        }
        return *this;
    }

    inline const Player &setLifepoints(unsigned l)
    {
        lifepoints = l;
        return *this;
    }

    inline unsigned getLifepoints() { return lifepoints; }

    inline const Player &setShip(const std::shared_ptr<Ship> ship)
    {
        this->ship = ship;
        return *this;
    }

    inline const Ship &getShip() { return *ship; }

    const Player &reset(const Vec2d &ship_pos, double ship_init_angle);
};

#endif