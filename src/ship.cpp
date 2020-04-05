#include <Geometry.h>
#include "entities/ship.h"
#include "entities/moving_polygone_particle.h"

Ship::Ship(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const Polygone &shape,
	double angle_jerk,
	double init_angle,
	double acc) : MovingPolygoneParticle(position,
										 color,
										 velocity,
										 shape,
										 angle_jerk)
{
	this->acc = acc;
	auto vertices = this->shape.getData();

	this->angle = init_angle;
	this->shape.rotate(position, 180.0);
}

void Ship::step(double s)
{
	MovingPolygoneParticle::step(s);
}

void Ship::accelerate()
{
	MovingParticle::accelerate(angle, acc);
}

void Ship::slow(double k)
{
	velocity -= velocity * k;
}

//TODO: add angle velocity
void Ship::rotateLeft()
{
	shape.rotate(position, -angle_acc);
	angle -= angle_acc;
	if (angle < 0)
	{
		angle += 360;
	}
}

void Ship::rotateRight()
{
	shape.rotate(position, angle_acc);
	angle = std::fmod(angle + angle_acc, 360);
}