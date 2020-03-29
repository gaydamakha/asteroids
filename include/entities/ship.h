#ifndef SHIP_H
#define SHIP_H

#include <Geometry.h>
#include "moving_particle.h"

class Ship: public MovingParticle
{
	Polygone shape;
	double rotation_speed;
public:
	Ship(const Polygone& shape, const Vec2d& position, const Vec2d& velocity, const Color& color);

	~Ship();
	
	inline Polygone getShape() const
	{
		return shape;
	}

	void setPosition(double x, double y);

	void step();
};

#endif