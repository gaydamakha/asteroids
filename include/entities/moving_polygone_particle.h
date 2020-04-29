#ifndef MOVING_POLYGONE_H
#define MOVING_POLYGONE_H

#include <Geometry.h>
#include "moving_particle.h"

class MovingPolygoneParticle : public MovingParticle
{
protected:
	Polygone polygone;
	double angle_acc;

public:
	MovingPolygoneParticle(const Vec2d &, const Color &, const Vec2d &, const std::initializer_list<Vec2d> &, double);

	MovingPolygoneParticle(const Vec2d &, const Color &, const Vec2d &v, const RandomPolygoneDesc&, double);

	~MovingPolygoneParticle();

	inline const Polygone getPolygone() const { return polygone; }

	void setCoords(Vec2d);

	virtual void rotateShape(double);

	void step(double);
};

#endif