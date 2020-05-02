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
	polygone.translate(coords);
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
	polygone.translate(coords);
}

const MovingPolygoneParticle &MovingPolygoneParticle::step(double s)
{
	MovingParticle::step(s);
	polygone.translate(velocity * s);

	return *this;
}

const MovingPolygoneParticle &MovingPolygoneParticle::rotateShape(double s)
{
	polygone.rotate(coords, angle_acc * s);

	return *this;
}

const MovingPolygoneParticle &MovingPolygoneParticle::setCoords(Vec2d p)
{
	Vec2d delta = p - coords;
	coords = p;
	polygone.translate(delta);

	return *this;
}
