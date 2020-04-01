#ifndef PARTICLE_H
#define PARTICLE_H

#include <Utils.h>

class Particle
{
protected:
	Vec2d position;
	Color color;
public:
	Particle(const Vec2d& position, const Color& color)
	{
		this->position = position;
		this->color = color;
	}

	inline Vec2d getPosition() const
	{
		return position;
	}

	inline void setPosition(Vec2d p)
	{
		position = p;
	}

	inline Color getColor() const
	{
		return color;
	}

	//Do nothing in this basic particle
	virtual void step() {};
};

#endif