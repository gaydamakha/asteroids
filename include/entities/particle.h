#ifndef PARTICLE_H
#define PARTICLE_H

#include <Utils.h>

class Particle
{
protected:
	Vec2d position;
	Vec2d velocity;
	Color color;
public:
	Particle(const Vec2d& position, const Vec2d& velocity, const Color& color)
	{
		this->position = position;
		this->velocity = velocity;
		this->color = color;
	}

	inline Vec2d getPosition() const
	{
		return position;
	}

	inline Vec2d getVelocity() const
	{
		return velocity;
	}

	inline Color getColor() const
	{
		return color;
	}

	//Do nothing in this basic particle
	virtual void step() {};
};

#endif