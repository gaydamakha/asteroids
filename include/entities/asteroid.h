#ifndef ASTEROID_H
#define ASTEROID_H

#include <map>
#include <Geometry.h>
#include "moving_polygone_particle.h"

enum class AsteroidSize
{
	BIG,
	MEDIUM,
	SMALL
};

class Asteroid : public MovingPolygoneParticle, public CircleCollider
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

	const Asteroid& step(double) override;

	inline const AsteroidSize getSize() const { return size; }

	//Once asteroid is broken, it can not be restored
	inline const Asteroid& broke() { broken = true; return *this;}

	inline bool isBroken() const { return broken; }

	inline bool toRemove(double timestamp) const override { return this->isBroken(); }
};

#endif