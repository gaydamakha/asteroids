#ifndef MOVING_POLYGONE_H
#define MOVING_POLYGONE_H

#include <Geometry.h>
#include "moving_particle.h"

class MovingPolygoneParticle: public MovingParticle
{
protected:
	Polygone shape;
	//TODO: imitate rotation acceleration
	double angle_jerk;
public:
	MovingPolygoneParticle(
		const Vec2d& position,
		const Color& color,
		const Vec2d& velocity,
		const Vec2d& acceleration,
		double min_velocity,
		double max_velocity,
		double min_acceleration,
		double max_acceleration,
		double angle_jerk,
		const Polygone& shape);

	~MovingPolygoneParticle();
	
	inline Polygone getShape() const
	{
		return shape;
	}

	void moveTo(Vec2d);

	void step();
};

#endif