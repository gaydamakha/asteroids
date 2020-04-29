#include <Geometry.h>
#include "entities/asteroid.h"

Asteroid::Asteroid(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const RandomPolygoneDesc& desc,
	double angle_acc,
	double rad,
	AsteroidSize size) : MovingPolygoneParticle(position, color, velocity, desc, angle_acc), CircleCollider(position, rad), size(size)
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