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

	inline const Vec2d& getCoords() const { return coords; }

	inline const Color& getColor() const { return color; }

	virtual inline const Particle& setCoords(Vec2d p) { coords = p; return *this; }

	virtual inline bool toRemove(double) const { return false; }

	// Do nothing in this basic particle
	virtual inline const Particle& step(double seconds) { return *this; };

};

#endif