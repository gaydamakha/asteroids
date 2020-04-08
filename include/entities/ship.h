#ifndef SHIP_H
#define SHIP_H

#include <Geometry.h>
#include "moving_polygone_particle.h"

class Ship: public MovingPolygoneParticle
{
protected:
	double angle;
	double acc;
public:
	Ship(
		const Vec2d& position,
		const Color& color,
		const Vec2d& velocity,
		const Polygone& shape,
		double angle_jerk,
		double init_angle,
		double acc);

	void step(double);

	void slow(double);

	void accelerate();

	void rotateLeft();

	void rotateRight();

	inline double getAngle()
	{
		return angle;
	}

	void setAngle(double);
};

#endif