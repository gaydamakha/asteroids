#ifndef ASTEROID_H
#define ASTEROID_H

#include <Geometry.h>
#include "moving_particle.h"

class Asteroid: public MovingParticle
{
	Polygone shape;
public:
	Asteroid(const Polygone& shape, const Vec2d& position, const Vec2d& velocity, const Color& color);

	~Asteroid();
	
	inline Polygone getShape() const
	{
		return shape;
	}
};

#endif