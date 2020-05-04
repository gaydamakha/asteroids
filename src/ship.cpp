#include "entities/ship.h"

Ship::Ship(const ShipConfig &c) : MovingPolygoneParticle(c.init_position,
														 c.color,
														 c.init_velocity,
														 c.vertices,
														 c.angle_acc),
								  CircleCollider(this->coords, c.radius), nose(polygone->getVertices()[0])
{
	this->acc = c.acc;
	this->angle = c.init_angle;
	// Put the gun at the position of the nose of the ship
	this->gun = std::make_unique<Gun>(nose, angle, c.gun_config);
}

const Ship &Ship::step(double s)
{
	MovingPolygoneParticle::step(s);
	//Update collider's position
	position = coords;
	
	return *this;
}

//TODO: add angle velocity
const Ship & Ship::rotateLeft()
{
	polygone->rotate(coords, -angle_acc);
	angle -= angle_acc;
	if (angle < 0)
	{
		angle += 360;
	}

	return *this;
}

const Ship &Ship::rotateRight()
{
	polygone->rotate(coords, angle_acc);
	angle = std::fmod(angle + angle_acc, 360);

	return *this;
}

const Ship &Ship::accelerate()
{
	MovingParticle::accelerate(angle, acc);

	return *this;
}

const Ship & Ship::setAngle(double a)
{
	double delta = a - angle;
	polygone->rotate(coords, delta);
	angle = a;

	return *this;
}

BulletsCollection Ship::shoot(double timestamp)
{
	return gun->shoot(timestamp);
}