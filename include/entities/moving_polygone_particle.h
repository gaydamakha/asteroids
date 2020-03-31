#ifndef MOVING_POLYGONE_H
#define MOVING_POLYGONE_H

#include <Geometry.h>
#include "moving_particle.h"

class MovingPolygoneParticle: public MovingParticle
{
protected:
	Polygone shape;
	//Directly a frequency instead of introducing rotation speed and acceleration
	double rotation_freq;
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
		double rotation_freq,
		const Polygone& shape);

	~MovingPolygoneParticle();
	
	inline Polygone getShape() const
	{
		return shape;
	}

	void setPosition(Vec2d);

	void step();
};

#endif