#include <Geometry.h>
#include "entities/moving_particle.h"
#include "entities/moving_polygone_particle.h"

MovingPolygoneParticle::MovingPolygoneParticle(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const Polygone &shape,
	double angle_acc) : MovingParticle(position,
									 color,
									 velocity)
{
	this->shape = shape;
	this->angle_acc = angle_acc;
}

MovingPolygoneParticle::~MovingPolygoneParticle()
{
}

void MovingPolygoneParticle::step(double s)
{
	MovingParticle::step(s);
	shape.translate(velocity * s);
}

void MovingPolygoneParticle::rotateShape(double s)
{
	shape.rotate(position, angle_acc * s);	
}

void MovingPolygoneParticle::moveTo(Vec2d p)
{
	Vec2d delta = p - position;
	position = p;
	auto vertices = shape.getData();
	for (auto &point : vertices)
	{
		*point += delta;
	}
}
