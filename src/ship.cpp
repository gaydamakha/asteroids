#include <Geometry.h>
#include "entities/ship.h"
#include "entities/moving_polygone_particle.h"

Ship::Ship(
		const Vec2d& position,
		const Color& color,
		const Vec2d& velocity,
		const Vec2d& acceleration,
		double min_velocity,
		double max_velocity,
		double min_acceleration,
		double max_acceleration,
		double rotation_freq,
		const Polygone& shape,
		Vec2d direction,
		double jerk): MovingPolygoneParticle(
											position,
											color,
											velocity,
											acceleration,
											min_velocity,
											max_velocity,
											min_acceleration,
											max_acceleration,
											rotation_freq,
											shape)
{
	this->direction = direction;
	this->jerk = jerk;
	//TODO: calculate angle between direction and the nose of ship
	this->shape.rotate(position, 180.);
}

void Ship::step()
{
	MovingPolygoneParticle::step();
}

void Ship::accelerate()
{
	MovingParticle::accelerate(jerk * direction);
}

void Ship::slow(double k)
{
	MovingParticle::accelerate((-velocity) * k);
}

void Ship::rotateLeft()
{
	shape.rotate(position, -5.);
	// direction.rotate(position, 5.);
}

void Ship::rotateRight()
{
	shape.rotate(position, 5.);
	// direction.rotate(position, -5.);
}