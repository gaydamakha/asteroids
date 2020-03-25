#ifndef MOVING_PARTICLE_H
#define MOVING_PARTICLE_H

#include "particle.h"

class MovingParticle : public Particle
{
public:
	using Particle::Particle;

	void step()
	{
		position += velocity;
	}
};

#endif