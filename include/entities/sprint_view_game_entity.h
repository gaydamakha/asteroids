#ifndef SPRINT_VIEW_GAME_ENTITY_H
#define SPRINT_VIEW_GAME_ENTITY_H

#include <Geometry.h>
#include "game_entity.h"

class SprintViewGameEntity : public GameEntity
{
public:
    inline const bool colliderAsView() const { return false; }
    inline const bool shapeAsView() const { return false; }
};
#endif