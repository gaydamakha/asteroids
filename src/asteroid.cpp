#include <Geometry.h>
#include "entities/asteroid.h"

Asteroid::Asteroid(const Polygone& shape, const Vec2d& position, const Vec2d& velocity, const Color& color, double degrot): MovingParticle(position, velocity, color)
{
	this->shape = shape;
	this->rotation_speed = degrot;
}

Asteroid::~Asteroid()
{

}

void Asteroid::step()
{
	MovingParticle::step();
	auto vertices = shape.getData();
	for (auto& point: vertices)
	{
		*point = *point + velocity;
		point->turn(position, rotation_speed);
	}
}