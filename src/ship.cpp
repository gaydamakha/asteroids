#include <Geometry.h>
#include "entities/ship.h"

Ship::Ship(const Polygone& shape, const Vec2d& position, const Vec2d& velocity, const Color& color): MovingParticle(position, velocity, color)
{
	this->shape = shape;
	this->rotation_speed = 0;
}

Ship::~Ship()
{

}

void Ship::step()
{
	MovingParticle::step();
	auto vertices = shape.getData();
	for (auto& point: vertices)
	{
		*point += velocity;
		point->turn(position, rotation_speed);
	}
}

void Ship::setPosition(double x, double y)
{
	Vec2d pos_new(x,y);
	Vec2d delta = pos_new - position;
	position = pos_new;
	auto vertices = shape.getData();
	for (auto& point: vertices)
	{
		*point += delta;
	}
}