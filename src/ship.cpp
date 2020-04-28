#include <Geometry.h>
#include "entities/ship.h"
#include "entities/moving_polygone_particle.h"
#include "entities/bullet.h"

Ship::Ship(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const Polygone &shape,
	double angle_acc,
	double radius,
	double init_angle,
	double acc,
	double bullets_cd,
	double bullets_vel,
	double bullets_size,
	double bullets_ttl,
	const Color &bullets_color) : MovingPolygoneParticle(position,
														 color,
														 velocity,
														 shape,
														 angle_acc),
								  CircleCollider(position, radius)
{
	this->acc = acc;
	this->angle = init_angle;
	this->bullets_cd = bullets_cd;
	this->bullets_vel = bullets_vel;
	this->bullets_size = bullets_size;
	this->bullets_ttl = bullets_ttl;
	this->bullets_color = bullets_color;
}

void Ship::step(double s)
{
	MovingPolygoneParticle::step(s);
	// Update collider's position
	this->setPosition(coords);
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
	polygone.rotate(coords, -angle_acc);
	angle -= angle_acc;
	if (angle < 0)
	{
		angle += 360;
	}
}

void Ship::rotateRight()
{
	polygone.rotate(coords, angle_acc);
	angle = std::fmod(angle + angle_acc, 360);
}

void Ship::setAngle(double a)
{
	double delta = a - angle;
	//TODO: rotate the shape (if it will be still in the ship)
	polygone.rotate(coords, delta);
	angle = a;
}

BulletsCollection Ship::shoot(double timestamp)
{
	BulletsCollection b;
	//Don't fire unless cooldown period has expired
	if (timestamp - last_bullet_time < bullets_cd)
	{
		return b;
	}

	last_bullet_time = timestamp;
	//Direction is the angle of the ship
	double rotangle = angle - 90;
	if (rotangle < 0)
	{
		rotangle += 360;
	}
	Vec2d vel = Vec2d(0., bullets_vel).rotate(rotangle);
	//create one new bullet at the position of the ship
	b.push(Bullet(position, bullets_color, vel, bullets_size, bullets_ttl, timestamp));
	return b;
}