#ifndef ASTEROID_H
#define ASTEROID_H

#include <Geometry.h>
#include "moving_particle.h"

class Asteroid: public MovingParticle
{
	Polygone shape;
	double rotation_speed;
public:
	Asteroid(const Polygone& shape, const Vec2d& position, const Vec2d& velocity, const Color& color, double degrot);

	~Asteroid();
	
	inline Polygone getShape() const
	{
		return shape;
	}

	void turnShape();

	void step();
};

#endif