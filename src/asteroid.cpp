#include <Geometry.h>
#include "entities/asteroid.h"
#include "entities/moving_polygone_particle.h"

Asteroid::Asteroid(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const Polygone &shape,
	double angle_acc,
	double radius) : MovingPolygoneParticle(position, color, velocity, shape, angle_acc), shape_radius(radius)
{
}

void Asteroid::step(double s)
{
	MovingPolygoneParticle::step(s);
	this->rotateShape(s);
}
