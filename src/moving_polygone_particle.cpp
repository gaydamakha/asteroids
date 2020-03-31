#include <Geometry.h>
#include "entities/moving_particle.h"
#include "entities/moving_polygone_particle.h"

MovingPolygoneParticle::MovingPolygoneParticle(
		const Vec2d& position,
		const Color& color,
		const Vec2d& velocity,
		const Vec2d& acceleration,
		double min_velocity,
		double max_velocity,
		double min_acceleration,
		double max_acceleration,
		double rotation_freq,
		const Polygone& shape) : MovingParticle(
												position,
												color,
												velocity,
												acceleration,
												min_velocity,
												max_velocity,
												min_acceleration,
												max_acceleration)
{
	this->shape = shape;
	this->rotation_freq = rotation_freq;
}

MovingPolygoneParticle::~MovingPolygoneParticle()
{

}

void MovingPolygoneParticle::step()
{
	MovingParticle::step();
	shape.translate(velocity);
	shape.rotate(position, rotation_freq);
}

void MovingPolygoneParticle::setPosition(Vec2d p)
{
	Vec2d delta = p - position;
	position = p;
	auto vertices = shape.getData();
	for (auto& point: vertices)
	{
		*point += delta;
	}
}
