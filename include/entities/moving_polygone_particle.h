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
	MovingPolygoneParticle(const Vec2d &, const Color &, const Vec2d &, const VerticesArray&, double);

	MovingPolygoneParticle(const Vec2d &, const Color &, const Vec2d &v, const RandomPolygoneDesc &, double);

	inline const Polygone getPolygone() const { return polygone; }

	const MovingPolygoneParticle &setCoords(Vec2d) override;

	const MovingPolygoneParticle &step(double) override;

protected:
	virtual const MovingPolygoneParticle &rotateShape(double);
};

#endif