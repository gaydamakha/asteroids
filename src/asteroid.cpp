#include <Geometry.h>
#include "entities/asteroid.h"

//Ordering map is used on purpose to pass from one config to another while breaking an asteroid
const std::map<AsteroidSize, AsteroidDesc> Asteroid::props = {
	{AsteroidSize::BIG, {30, 50, 20, 25, 7}},
	{AsteroidSize::MEDIUM, {20, 32, 20, 25, 7}},
	{AsteroidSize::SMALL, {10, 20, 15, 25, 7}}};

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