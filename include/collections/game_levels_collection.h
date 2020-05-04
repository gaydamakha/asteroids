#ifndef GAME_LEVEL_COL_H
#define GAME_LEVEL_COL_H

#include <nlohmann/json.hpp>
#include <nlohmann/json-schema.hpp>
#include <Utils.h>
#include "schemas/level_schema.h"
#include "game_level.h"

using namespace nlohmann;

class GameLevelsCollection : public IterableCollection<GameLevel>
{
protected:
    const json_schema::json_validator validator;
public:
    using IterableCollection::IterableCollection;
    GameLevelsCollection(): validator(LEVEL_SCHEMA) {}

    const GameLevelsCollection& push(const json& config);
};

#endif
