#include <Geometry.h>
#include "entities/moving_particle.h"
#include "entities/moving_polygone_particle.h"

MovingPolygoneParticle::MovingPolygoneParticle(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const Polygone &polygone,
	double angle_acc) : MovingParticle(position,
									 color,
									 velocity)
{
	this->polygone = polygone;
	this->angle_acc = angle_acc;
}

MovingPolygoneParticle::~MovingPolygoneParticle()
{
}

void MovingPolygoneParticle::step(double s)
{
	MovingParticle::step(s);
	polygone.translate(velocity * s);
}

void MovingPolygoneParticle::rotateShape(double s)
{
	polygone.rotate(position, angle_acc * s);	
}

void MovingPolygoneParticle::setPosition(Vec2d p)
{
	Vec2d delta = p - position;
	position = p;
	polygone.translate(delta);
}
