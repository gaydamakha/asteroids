#ifndef SHIP_H
#define SHIP_H

#include <Geometry.h>
#include "moving_polygone_particle.h"

class Ship: public MovingPolygoneParticle
{
protected:
	Vec2d direction;
	double jerk;
public:
	Ship(
		const Vec2d& position,
		const Color& color,
		const Vec2d& velocity,
		const Vec2d& acceleration,
		double min_velocity,
		double max_velocity,
		double min_acceleration,
		double max_acceleration,
		double rotation_freq,
		const Polygone& shape,
		Vec2d direction,
		double jerk);

	void step();

	void slow(double);

	void accelerate();

	void rotateLeft();

	void rotateRight();
};

#endif