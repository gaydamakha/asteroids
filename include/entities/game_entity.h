#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <Geometry.h>

class GameEntity
{
public:
    virtual const bool colliderAsView() const = 0;
    virtual const bool shapeAsView() const = 0;
    virtual bool toRemove(double) = 0;
};

#endif