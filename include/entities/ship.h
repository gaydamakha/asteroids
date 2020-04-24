#ifndef SHIP_H
#define SHIP_H

#include <Geometry.h>
#include "moving_polygone_particle.h"

class Ship : public MovingPolygoneParticle
{
protected:
	double angle;
	double acc;
	const double shape_radius;

public:
	Ship(
		const Vec2d &position,
		const Color &color,
		const Vec2d &velocity,
		const Polygone &shape,
		double angle_acc,
		double radius,
		double init_angle,
		double acc);

	void step(double);

	void slow(double);

	void accelerate();

	void rotateLeft();

	void rotateRight();

	inline double getAngle() { return angle; }

	inline const double getRadius() const { return shape_radius; }

	void setAngle(double);
};

#endif