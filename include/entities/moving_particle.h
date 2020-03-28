#ifndef MOVING_PARTICLE_H
#define MOVING_PARTICLE_H

#include "particle.h"

class MovingParticle : public Particle
{
public:
	using Particle::Particle;

	inline void step()
	{
		position += velocity;
	}
};

#endif