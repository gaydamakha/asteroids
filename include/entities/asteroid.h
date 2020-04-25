#ifndef ASTEROID_H
#define ASTEROID_H

#include <Geometry.h>
#include "moving_polygone_particle.h"
#include "shape_view_game_entity.h"

enum class AsteroidSize
{
	BIG,
	MEDIUM,
	SMALL
};

class Asteroid : public MovingPolygoneParticle, public ShapeViewGameEntity
{
	const AsteroidSize size;
	bool broken;

public:
	Asteroid(const Vec2d &position,
			 const Color &color,
			 const Vec2d &velocity,
			 const Polygone &shape,
			 double angle_acc,
			 const std::shared_ptr<Shape> collider,
			 AsteroidSize size);

	void step(double);

	inline const AsteroidSize getSize() const { return size; }

	inline bool isBroken() const { return broken; }

	//Once asteroid is broken, it can not be restored
	inline void broke() { broken = true; }

	inline const Shape getShape() const { return polygone; }
};

#endif