#include <Geometry.h>
#include "entities/asteroid.h"
#include "entities/moving_polygone_particle.h"

Asteroid::Asteroid(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const Polygone &shape,
	double angle_acc,
	double rad,
	AsteroidSize size) : MovingPolygoneParticle(position, color, velocity, shape, angle_acc), CircleCollider(position, rad), size(size)
{
	broken = false;
}

void Asteroid::step(double s)
{
	MovingPolygoneParticle::step(s);
	this->rotateShape(s);
	// Update collider's position
	this->setPosition(coords);
}