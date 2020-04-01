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
		double angle_jerk,
		const Polygone& shape,
		Vec2d init_direction,
		double jerk): MovingPolygoneParticle(
											position,
											color,
											velocity,
											acceleration,
											min_velocity,
											max_velocity,
											min_acceleration,
											max_acceleration,
											angle_jerk,
											shape)
{
	this->jerk = jerk;
	auto vertices = this->shape.getData();
	nose = vertices[0];
    direction = *nose - this->position; //Nose of this ship will be his direction
	direction.normalize();

	double angle = angle_b_2vec(init_direction, direction);
	this->shape.rotate(position, angle);
	direction.rotate(Vec2d(0.,0.), angle);
}

void Ship::step()
{
	//TODO: remove this hack after adding rotation acceleration
	double tmp = angle_jerk;
	angle_jerk = 0.;
	MovingPolygoneParticle::step();
	angle_jerk = tmp;
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
	shape.rotate(position, -angle_jerk);
	direction = normalize(*nose - position);
}

void Ship::rotateRight()
{
	shape.rotate(position, angle_jerk);
	direction = normalize(*nose - position);
}