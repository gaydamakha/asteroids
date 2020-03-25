#include "entities/asteroid.h"

Asteroid::Asteroid(const Polygone& shape, const Vec2d& position, const Vec2d& velocity, const Color& color): MovingParticle(position, velocity, color)
{
	this->shape = shape;
}

Asteroid::~Asteroid()
{

}