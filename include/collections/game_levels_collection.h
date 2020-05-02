#ifndef GAME_LEVEL_COL_H
#define GAME_LEVEL_COL_H

#include <Utils.h>
#include "game_level.h"

using GameLevelsCollection = IterableCollection<GameLevel>;

//TODO: add method "fromFile"

static const GameLevel FIRST_LEVEL = {
    "Level 1", 3,
    //AsteroidsProps
    {
        {AsteroidSize::BIG, {{30, 50, 20, 25, 7}, 50, 50, 2, 2, GREEN}},
        {AsteroidSize::MEDIUM, {{20, 32, 20, 25, 7}, 50, 50, 2, 2, GREEN}},
        {AsteroidSize::SMALL, {{10, 20, 15, 25, 7}, 50, 50, 0, 0, GREEN}}
    },
    //AsteroidsAmount
    {
        {AsteroidSize::BIG, 1},
        {AsteroidSize::MEDIUM, 1},
        {AsteroidSize::SMALL, 1}
    },
    //Ship config
    {
        Vec2d(500,300),
        GREEN,
        Vec2d(0,0),
        {Vec2d(0, -22), Vec2d(16, 22), Vec2d(0, 16), Vec2d(-16, 22)},
        0.2,
        22,
        270.0,
        0.3,
        //Gun config
        {5., 350., 1.5, 0.5, GREEN}
    },
    // Environment resistence
    0.0008
};

static const GameLevel SECOND_LEVEL = {
    "Level 1", 3,
    //AsteroidsProps
    {
        {AsteroidSize::BIG, {{30, 50, 20, 25, 7}, 50, 50, 2, 2, GREEN}},
        {AsteroidSize::MEDIUM, {{20, 32, 20, 25, 7}, 50, 50, 2, 2, GREEN}},
        {AsteroidSize::SMALL, {{10, 20, 15, 25, 7}, 50, 50, 0, 0, GREEN}}
    },
    //AsteroidsAmount
    {
        {AsteroidSize::BIG, 2},
        {AsteroidSize::MEDIUM, 2},
        {AsteroidSize::SMALL, 2}
    },
    //Ship config
    {
        Vec2d(500,300),
        GREEN,
        Vec2d(0,0),
        {Vec2d(0, -22), Vec2d(16, 22), Vec2d(0, 16), Vec2d(-16, 22)},
        0.2,
        22,
        270.0,
        0.3,
        //Gun config
        {5., 350., 1.5, 0.5, GREEN}
    },
    // Environment resistence
    0.0008
};

static const GameLevelsCollection ONE_LEVEL_COLLECTION = { FIRST_LEVEL, SECOND_LEVEL};

#endif
