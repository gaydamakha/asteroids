#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <Geometry.h>

class GameEntity
{
    const std::shared_ptr<Shape> collider;

public:
    GameEntity(const std::shared_ptr<Shape> c) : collider(c) {}
    inline const std::shared_ptr<Shape> getCollider() const { return collider; }

    virtual const bool colliderAsView() const = 0;
    virtual const bool shapeAsView() const = 0;
};

#endif