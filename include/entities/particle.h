#ifndef PARTICLE_H
#define PARTICLE_H

#include <Utils.h>

class Particle
{
protected:
	Vec2d coords;
	Color color;
public:
	Particle(const Vec2d& coords, const Color& color)
	{
		this->coords = coords;
		this->color = color;
	}

	inline Vec2d getCoords() const { return coords; }

	virtual inline void setCoords(Vec2d p) { coords = p; }

	inline Color getColor() const { return color; }

	// Do nothing in this basic particle
	virtual void step(double seconds) {};
};

#endif