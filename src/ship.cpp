#include <Geometry.h>
#include "entities/ship.h"
#include "entities/moving_polygone_particle.h"

Ship::Ship(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const Polygone &shape,
	double angle_acc,
	double radius,
	double init_angle,
	double acc) : MovingPolygoneParticle(position,
										 color,
										 velocity,
										 shape,
										 angle_acc), shape_radius(radius)
{
	this->acc = acc;
	this->angle = init_angle;
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
	polygone.rotate(position, -angle_acc);
	angle -= angle_acc;
	if (angle < 0)
	{
		angle += 360;
	}
}

void Ship::rotateRight()
{
	polygone.rotate(position, angle_acc);
	angle = std::fmod(angle + angle_acc, 360);
}

void Ship::setAngle(double a)
{
	double delta = a - angle;
	//TODO: rotate the shape (if it will be still in the ship)
	// shape.rotate(position, delta);
	angle = a;
}