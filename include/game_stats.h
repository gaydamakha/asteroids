#ifndef GAME_STATS_H
#define GAME_STATS_H

#include <string>

struct GameStats
{
    unsigned player_lifepoints;
    unsigned player_scores;
    unsigned player_highscores;
    std::string level_name;
};

#endif