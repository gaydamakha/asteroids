#ifndef ASTEROID_H
#define ASTEROID_H

#include <Geometry.h>
#include "moving_polygone_particle.h"

class Asteroid: public MovingPolygoneParticle
{
public:
	using MovingPolygoneParticle::MovingPolygoneParticle;

	void step();
};

#endif