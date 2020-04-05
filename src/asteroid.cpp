#include <Geometry.h>
#include "entities/asteroid.h"
#include "entities/moving_polygone_particle.h"

void Asteroid::step(double s)
{
	MovingPolygoneParticle::step(s);
	this->rotateShape(s);
}
