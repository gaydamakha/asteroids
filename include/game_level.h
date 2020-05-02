#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <map>
#include "factories/asteroids_factory.h"

using AsteroidsAmount = std::map<AsteroidSize, unsigned>;

struct GameLevel
{
    std::string name;
    //Player's configs
	unsigned player_lifepoints;
    //Asteroids's configs
    AsteroidsProps asteroids_props;
    AsteroidsAmount asteroids_amount;
    //Ship's config
    ShipConfig ship_config;
    //Environment configs
    double env_resistence;
};

#endif