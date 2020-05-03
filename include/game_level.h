#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <map>
#include <nlohmann/json.hpp>
#include "entities/ship.h"
#include "factories/asteroids_factory.h"

using namespace nlohmann;

using AsteroidsAmount = std::map<AsteroidSize, unsigned>;

struct GameLevel
{
    std::string name;
    unsigned order;
    //Player's configs
    unsigned player_lifepoints;
    //Asteroids's configs
    AsteroidsProps asteroids_props;
    AsteroidsAmount asteroids_amount;
    //Ship's config
    ShipConfig ship_config;
    //Environment configs
    double env_resistance;

    bool operator <(const GameLevel& obj) const
    {
        return order < obj.order;
    }
};

void from_json(const json &j, GameLevel &l);
void from_json(const json &j, AsteroidsAmount &a);
void from_json(const json &j, AsteroidsFactoryDesc &d);
void from_json(const json &j, AsteroidsProps &p);
void from_json(const json &j, ShipConfig &s);
void from_json(const json &j, VerticesArray &s);
void from_json(const json &j, RandomPolygoneDesc &d);
void from_json(const json &j, GunConfig &g);
void from_json(const json &j, Vec2d &v);
void from_json(const json &j, Color &c);

#endif