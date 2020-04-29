#ifndef ASTEROID_H
#define ASTEROID_H

#include <map>
#include <Geometry.h>
#include "moving_polygone_particle.h"
#include "shape_view_game_entity.h"

enum class AsteroidSize
{
	BIG,
	MEDIUM,
	SMALL
};

class Asteroid : public MovingPolygoneParticle, public CircleCollider, public ShapeViewGameEntity
{
	const AsteroidSize size;
	bool broken;
public:
	Asteroid(const Vec2d &,
			 const Color &,
			 const Vec2d &,
			 const RandomPolygoneDesc&,
			 double,
			 double,
			 AsteroidSize);

	void step(double);

	inline const AsteroidSize getSize() const { return size; }

	inline bool isBroken() const { return broken; }

	inline const Shape getShape() const { return polygone; }

	//Once asteroid is broken, it can not be restored
	inline const void broke() { broken = true; }

	inline bool toRemove(double timestamp) { return this->isBroken(); }
};

#endif