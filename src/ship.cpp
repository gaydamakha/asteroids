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

void Ship::step()
{
	double tmp = angle_acc;
	angle_acc = 0.;
	MovingPolygoneParticle::step();
	angle_acc = tmp;
}

void Ship::accelerate()
{
	MovingParticle::accelerate(angle, acc);
}

void Ship::slow(double k)
{
	velocity -= velocity * k;
}

void Ship::rotateLeft()
{
	shape.rotate(position, -angle_acc);
	angle -= angle_acc;
	std::cout << angle << std::endl;
}

void Ship::rotateRight()
{
	shape.rotate(position, angle_acc);
	angle += angle_acc;
	std::cout << angle << std::endl;
}