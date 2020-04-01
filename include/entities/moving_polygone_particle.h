#ifndef MOVING_POLYGONE_H
#define MOVING_POLYGONE_H

#include <Geometry.h>
#include "moving_particle.h"

class MovingPolygoneParticle: public MovingParticle
{
protected:
	Polygone shape;
	double angle_acc;
public:
	MovingPolygoneParticle(
		const Vec2d& position,
		const Color& color,
		const Vec2d& velocity,
		const Polygone& shape,
		double angle_acc);

	~MovingPolygoneParticle();
	
	inline Polygone getShape() const
	{
		return shape;
	}

	void moveTo(Vec2d);

	void step();
};

#endif