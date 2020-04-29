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
	const GunConfig& gun_config) : MovingPolygoneParticle(position,
														 color,
														 velocity,
														 shape,
														 angle_acc),
								  CircleCollider(position, radius), nose(polygone.getVertices()[0])
{
	this->acc = acc;
	this->angle = init_angle;
	// Put the gun at the position of the nose of the ship
	this->gun = std::make_unique<Gun>(nose, angle, gun_config);
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
	polygone.rotate(coords, delta);
	angle = a;
}

BulletsCollection Ship::shoot(double timestamp)
{
	return gun->shoot(timestamp);
}