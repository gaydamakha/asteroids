#include "entities/moving_polygone_particle.h"

MovingPolygoneParticle::MovingPolygoneParticle(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const std::initializer_list<Vec2d> &vertices,
	double angle_acc) : MovingParticle(position,
									   color,
									   velocity),
						polygone(vertices)
{
	this->angle_acc = angle_acc;
	polygone.translate(position);
}

MovingPolygoneParticle::MovingPolygoneParticle(
	const Vec2d &position,
	const Color &color,
	const Vec2d &velocity,
	const RandomPolygoneDesc &desc,
	double angle_acc) : MovingParticle(position,
									   color,
									   velocity),
						polygone(desc)
{
	this->angle_acc = angle_acc;
	polygone.translate(position);
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
	polygone.rotate(coords, angle_acc * s);
}

void MovingPolygoneParticle::setCoords(Vec2d p)
{
	Vec2d delta = p - coords;
	coords = p;
	polygone.translate(delta);
}
