#ifndef ASTEROID_H
#define ASTEROID_H

#include <Geometry.h>
#include "moving_polygone_particle.h"

enum class AsteroidSize
{
	BIG,
	MEDIUM,
	SMALL
};

class Asteroid : public MovingPolygoneParticle
{
	//TODO: remove it
	const double shape_radius;
	const AsteroidSize size;
	bool broken;

public:
	Asteroid(const Vec2d &position,
			 const Color &color,
			 const Vec2d &velocity,
			 const Polygone &shape,
			 double angle_acc,
			 double radius,
			 AsteroidSize size);

	void step(double);

	inline const AsteroidSize getSize() const { return size; }

	inline bool isBroken() const { return broken; }

	//Once asteroid is broken, it can not be restored
	inline void broke() { broken = true; }

	inline const double getRadius() const { return shape_radius; }
};

#endif