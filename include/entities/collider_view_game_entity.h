#ifndef COLLIDER_VIEW_GAME_ENTITY_H
#define COLLIDER_VIEW_GAME_ENTITY_H

#include <Geometry.h>
#include "game_entity.h"

class ColliderViewGameEntity : public GameEntity
{
public:
    ShapeViewGameEntity(const std::shared_ptr<Shape> collider): GameEntity(collider) {}
    inline const bool colliderAsView() const { return true; }
    inline const bool shapeAsView() const { return false; }
};
#endif