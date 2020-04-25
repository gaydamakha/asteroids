#ifndef SHAPE_VIEW_GAME_ENTITY_H
#define SHAPE_VIEW_GAME_ENTITY_H

#include <Geometry.h>
#include "game_entity.h"

class ShapeViewGameEntity : public GameEntity
{
public:
    inline const bool colliderAsView() const { return false; }
    inline const bool shapeAsView() const { return true; }
    virtual const Shape getShape() const = 0;
};
#endif