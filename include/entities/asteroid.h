#ifndef ASTEROID_H
#define ASTEROID_H

#include <Geometry.h>
#include "moving_polygone_particle.h"

class Asteroid : public MovingPolygoneParticle
{
	const double shape_radius;

public:
	Asteroid(const Vec2d &position,
			 const Color &color,
			 const Vec2d &velocity,
			 const Polygone &shape,
			 double angle_acc,
			 double radius);

	void step(double);
};

#endif