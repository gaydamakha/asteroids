#include "entities/ship.h"

Ship::Ship(const ShipConfig &c) : MovingPolygoneParticle(c.init_position,
														 c.color,
														 c.init_velocity,
														 c.vertices,
														 c.angle_acc),
								  CircleCollider(c.init_position, c.radius), nose(polygone.getVertices()[0])
{
	this->acc = c.acc;
	this->angle = c.init_angle;
	// Put the gun at the position of the nose of the ship
	this->gun = std::make_unique<Gun>(nose, angle, c.gun_config);
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