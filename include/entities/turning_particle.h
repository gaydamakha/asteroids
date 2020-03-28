#ifndef TURNING_PARTICLE_H
#define TURNING_PARTICLE_H

#include <Geometry.h>
#include "particle.h"

class TurningParticle : public Particle
{
	double rotation_speed;
	Vec2d rotation_center;
public:
	using Particle::Particle;

	TurningParticle(const Vec2d& position, const Vec2d& velocity, const Color& color, double rotdeg), : Particle(position, velocity, color)
	{
		rotation_speed = Geometry::degtorad(rotdeg);
	}

	inline void step()
	{
		
	}
};

#endif